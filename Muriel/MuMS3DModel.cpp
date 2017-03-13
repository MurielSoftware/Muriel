#include "stdafx.h"
#include "MuMS3DModel.h"
#include "MuVertexPosNormTex.h"
#include "MuVertexBuffer.h"
#include "MuIndexBuffer.h"
#include <cfloat>

namespace Muriel
{
	MS3DModel::MS3DModel(const string& name)
		: Model(name)
	{
		_vertices = NULL;
		_triangles = NULL;
		_meshes = NULL;
		_materials = NULL;
		_joints = NULL;
	}

	MS3DModel::~MS3DModel()
	{
		delete[] _vertices;
		delete[] _triangles;
		delete[] _meshes;
		delete[] _materials;
		delete[] _joints;

		_vertices = NULL;
		_triangles = NULL;
		_meshes = NULL;
		_materials = NULL;
		_joints = NULL;
	}

	void MS3DModel::Setup()
	{
		for (int i = 0; i < _jointsCount; i++)
		{
			_joints[i].parentIndex = -1;
			for (int j = 0; j < _jointsCount; j++)
			{
				if (strcmp(_joints[i].parent, _joints[j].name) == 0)
				{
					_joints[i].parentIndex = j;
					break;
				}
			}
		}

		for (int i = 0; i < _jointsCount; i++)
		{
			if (_joints[i].parentIndex != -1)
			{
				_joints[i].absoluteQuaternion = _joints[_joints[i].parentIndex].absoluteQuaternion * _joints[i].localQuaternion;
				_joints[i].absoluteVector = (_joints[_joints[i].parentIndex].absoluteQuaternion * _joints[i].localVector) + _joints[_joints[i].parentIndex].absoluteVector;
			}
			else
			{
				_joints[i].absoluteQuaternion = _joints[i].localQuaternion;
				_joints[i].absoluteVector = _joints[i].localVector;
			}
			_joints[i].finalQuaternion = _joints[i].absoluteQuaternion;
			_joints[i].finalVector = _joints[i].absoluteVector;
		}

		for (int i = 0; i < _verticesCount; i++)
		{
			if (_vertices[i].bone == -1)
			{
				continue;
			}
			MS3DJoint* joint = &_joints[_vertices[i].bone];
			_vertices[i].vert = Glml::Quat::INVERT(joint->finalQuaternion) * (_vertices[i].vert - joint->finalVector);
		}
	}

	void MS3DModel::CreateBuffers()
	{
		int verticesInformationIndex = 0;
		VertexPosNormTex* vertices = new VertexPosNormTex[_verticesCount];

		for (unsigned i = 0; i < _verticesCount; i++)
		{
			Vec3 position = Vec3(_vertices[i].vert.x, _vertices[i].vert.y, _vertices[i].vert.z);
			vertices[verticesInformationIndex++] = VertexPosNormTex(position);
		}

		for (unsigned i = 0; i < _meshesCount; i++)
		{
			int indicesCount = _meshes[i].numTris * 3;
			unsigned short* indices = new unsigned short[indicesCount];
			int indicesIndex = 0;
			for (unsigned j = 0; j < _meshes[i].numTris; j++)
			{
				int triangleIndex = _meshes[i].indices[j];
				MS3DTriangle* triangle = &_triangles[triangleIndex];
				for (unsigned k = 0; k < 3; k++)
				{
					unsigned short verticesIndex = triangle->vertIndices[k];
					indices[indicesIndex++] = verticesIndex;
					vertices[verticesIndex].SetNormal(Vec3(triangle->normals[k].x, triangle->normals[k].y, triangle->normals[k].z));
					vertices[verticesIndex].SetTexCoord(Vec2(triangle->texCoords[0][k], 1.0f - triangle->texCoords[1][k]));
				}
			}
			_meshes[i].indexBuffer = new IndexBuffer((void*)indices, sizeof(unsigned short), indicesCount, GraphicsDataType::UnsignedShort());
		}

		_vertexBuffer = new VertexBuffer(BufferType::ArrayBuffer(), BufferUsage::StaticDraw(), (void*)vertices, sizeof(VertexPosNormTex), _verticesCount);
		_vertexBuffer->AddVertexAttributeInformation(0, 3, GraphicsDataType::Float(), false, sizeof(VertexPosNormTex), 0);
		_vertexBuffer->AddVertexAttributeInformation(1, 3, GraphicsDataType::Float(), false, sizeof(VertexPosNormTex), sizeof(Vec3));
		_vertexBuffer->AddVertexAttributeInformation(2, 2, GraphicsDataType::Float(), false, sizeof(VertexPosNormTex), sizeof(Vec3) * 2);
	}

	void MS3DModel::CreateBoundingBox()
	{
		static Vec3 min = Vec3(FLT_MAX, FLT_MAX, FLT_MAX);
		static Vec3 max = Vec3(FLT_MIN, FLT_MIN, FLT_MIN);
		for (unsigned i = 0; i < _verticesCount; i++)
		{
			Vec3 vert = _vertices[i].vert;
			if (vert.x < min.x) 
			{
				min.x = vert.x;
			}
			if (vert.y < min.y)
			{
				min.y = vert.y;
			}
			if (vert.z < min.z)
			{
				min.z = vert.z;
			}
			if (vert.x > max.x)
			{
				max.x = vert.x;
			}
			if (vert.y > max.y)
			{
				max.y = vert.y;
			}
			if (vert.z > max.z)
			{
				max.z = vert.z;
			}
		}
		_boundingBox = BoundingBox((max + min) / 2.0f, max - min);
	}

	void MS3DModel::Animate(float dt)
	{
		for (int i = 0; i < _jointsCount; i++)
		{
			unsigned int frame = 0;
			MS3DJoint* joint = &_joints[i];
			if (joint->rotateKeyFramesCount == 0 && joint->translateKeyFramesCount == 0)
			{
				joint->finalQuaternion = joint->absoluteQuaternion;
				joint->finalVector = joint->absoluteVector;
				continue;
			}

			while (frame < joint->translateKeyFramesCount && joint->translateKeyFrames[frame].time < dt)
			{
				frame++;
			}
			Glml::Vec3 translation;
			float delta = 1.0f;
			float interpolation = 0.0f;

			if (frame == 0)
			{
				translation = joint->translateKeyFrames[0].param;
			}
			else if (frame == joint->translateKeyFramesCount)
			{
				translation = joint->translateKeyFrames[frame - 1].param;
			}
			else
			{
				MS3DKeyFrameTranslate* currentKeyFrameTranslate = &joint->translateKeyFrames[frame];
				MS3DKeyFrameTranslate* previousKeyFrameTranslate = &joint->translateKeyFrames[frame - 1];

				delta = currentKeyFrameTranslate->time - previousKeyFrameTranslate->time;
				interpolation = (dt - previousKeyFrameTranslate->time) / delta;

				translation = previousKeyFrameTranslate->param + (currentKeyFrameTranslate->param - previousKeyFrameTranslate->param) * interpolation;
			}

			frame = 0;
			while (frame < joint->rotateKeyFramesCount && joint->rotateKeyFrames[frame].time < dt)
			{
				frame++;
			}
			Glml::Quat rotation;
			if (frame == 0)
			{
				rotation = joint->rotateKeyFrames[0].param;
			}
			else if (frame == joint->rotateKeyFramesCount)
			{
				rotation = joint->rotateKeyFrames[frame - 1].param;
			}
			else
			{
				MS3DKeyFrameRotate* currentKeyFrameRotate = &joint->rotateKeyFrames[frame];
				MS3DKeyFrameRotate* previousKeyFrameRotate = &joint->rotateKeyFrames[frame - 1];

				delta = currentKeyFrameRotate->time - previousKeyFrameRotate->time;
				interpolation = (dt - previousKeyFrameRotate->time) / delta;

				rotation = Glml::Quat::SLERP(previousKeyFrameRotate->param, currentKeyFrameRotate->param, interpolation);
			}

			Glml::Quat finalRotation = joint->localQuaternion * rotation;
			Glml::Vec3 finalTranslation = (joint->localQuaternion * translation) + joint->localVector;

			if (joint->parentIndex == -1)
			{
				joint->finalQuaternion = finalRotation;
				joint->finalVector = finalTranslation;
			}
			else
			{
				joint->finalQuaternion = _joints[joint->parentIndex].finalQuaternion * finalRotation;
				joint->finalVector = (_joints[joint->parentIndex].finalQuaternion * finalTranslation) + _joints[joint->parentIndex].finalVector;
			}
		}
		//if (_jointsCount > 0)
		//{
		//	float* q = new float[_jointsCount * 4];
		//	float* v = new float[_jointsCount * 3];
		//	for (int i = 0, vi = 0, qi = 0; i < _jointsCount; i++)
		//	{
		//		q[qi++] = _joints[i].finalQuaternion.x;
		//		q[qi++] = _joints[i].finalQuaternion.y;
		//		q[qi++] = _joints[i].finalQuaternion.z;
		//		q[qi++] = _joints[i].finalQuaternion.w;

		//		v[vi++] = _joints[i].finalVector.x;
		//		v[vi++] = _joints[i].finalVector.y;
		//		v[vi++] = _joints[i].finalVector.z;
		//	}

		//	/*	ShaderManager::GetInstance()->Get(MODEL_ANIMATION_SHADER)->Uniform4fArray("rotation", q, _jointsCount);
		//	ShaderManager::GetInstance()->Get(MODEL_ANIMATION_SHADER)->Uniform3fArray("translation", v, _jointsCount);*/

		//	delete[] q;
		//	delete[] v;
		//}
	}


	 //CPU
	//void MS3DModel::Render()
	//{
	////	static float act = 1.0f;
	//////	this->Animate(act / 100.0f);
	////	act += 1.f;

	////	if (act == 100.0f) act = 0.0f;

	//	for (int i = 0; i < _meshesCount; i++)
	//	{
	//		int materialIndex = _meshes[i].material;
	//		if (materialIndex >= 0)
	//		{
	//			//TextureManager::GetInstance()->Get(_materials[materialIndex].textureName)->Bind();
	//		}
	//		glBegin(GL_TRIANGLES);
	//		for (int j = 0; j < _meshes[i].numTris; j++)
	//		{
	//			int triangleIndex = _meshes[i].indices[j];
	//			const MS3DTriangle* pTri = &_triangles[triangleIndex];

	//			for (int k = 0; k < 3; k++)
	//			{
	//				const MS3DVertex* vertex = &_vertices[pTri->vertIndices[k]];
	//				//if (vertex->bone == -1)
	//				//{
	//					glTexCoord2f(pTri->texCoords[0][k], 1 - pTri->texCoords[1][k]);
	//					glVertex3f(vertex->vert.x, vertex->vert.y, vertex->vert.z);
	//				//}
	//				//else
	//				//{
	//				//	const MS3DJoint* joint = &_joints[vertex->bone];
	//				//	glTexCoord2f(pTri->texCoords[0][k], 1 - pTri->texCoords[1][k]);
	//				//	Glml::Vec3 transformedVector = (joint->finalQuaternion * vertex->vert) + joint->finalVector;
	//				//	Glml::Vec3 transformedNormal = (joint->finalQuaternion * pTri->normals[k]) + joint->finalVector;
	//				//	glNormal3f(transformedNormal.x, transformedNormal.y, transformedNormal.z);
	//				//	glVertex3f(transformedVector.x, transformedVector.y, transformedVector.z);
	//				//}
	//			}
	//		}
	//		glEnd();
	//	}

	//	glDisable(GL_DEPTH_TEST);
	//	glColor3f(1.0f, 0.0f, 0.0f);
	//	glLineWidth(3.0f);
	//	glBegin(GL_LINES);
	//	//for (int x = 1; x < this->_jointsCount; x++)
	//	//{
	//	//	glVertex3f(this->_joints[x].finalVector.x, this->_joints[x].finalVector.y, this->_joints[x].finalVector.z);
	//	//	glVertex3f(this->_joints[this->_joints[x].parentIndex].finalVector.x, this->_joints[this->_joints[x].parentIndex].finalVector.y, this->_joints[this->_joints[x].parentIndex].finalVector.z);
	//	//}
	//	glEnd();
	//	glEnable(GL_DEPTH_TEST);
	//	glColor3f(1.0f, 1.0f, 1.0f);
	//}

	// vbo + shader
	void MS3DModel::Render()
	{
		_vertexBuffer->Bind();
		for (unsigned i = 0; i < _vertexBuffer->GetVertexAttributeInfosCount(); i++)
		{
			const VertexAttributeInformation vertexAttributeInformation = _vertexBuffer->GetVertexAttributeInformation(i);
			GL::EnableVertexAttribute(vertexAttributeInformation.GetIndex());
			GL::SetVertexAttribute(vertexAttributeInformation.GetIndex(), vertexAttributeInformation.GetSize(), vertexAttributeInformation.GetGraphicsDataType(), vertexAttributeInformation.GetNormalized(), vertexAttributeInformation.GetStride(), vertexAttributeInformation.GetOffset());
		}
		for (unsigned i = 0; i < _meshesCount; i++)
		{
			_meshes[i].indexBuffer->Bind();
			GL::DrawElements(GraphicsPrimitiveType::Triangles(), _meshes[i].indexBuffer->GetNumberOfElements(), _meshes[i].indexBuffer->GetIndexDataType(), (void*)0);
			_meshes[i].indexBuffer->Unbind();
		}
		for (unsigned i = 0; i < _vertexBuffer->GetVertexAttributeInfosCount(); i++)
		{
			GL::DisableVertexAttribute(_vertexBuffer->GetVertexAttributeInformation(i).GetIndex());
		}
		_vertexBuffer->Unbind();
		//static float act = 1.0f;
		//this->Animate(act / 100.0f);
		//act += 1.f;
	
		//if (act == 100.0f) act = 0.0f;
	
		//ShaderManager::GetInstance()->Get(MODEL_ANIMATION_SHADER)->Activate();
		//for (int i = 0; i < _meshesCount; i++)
		//{
		//	int materialIndex = _meshes[i].material;
		//	if (materialIndex >= 0)
		//	{
		//		TextureManager::GetInstance()->Get(_materials[materialIndex].textureName)->Bind();
		//	}
		//	_meshes[i].vertexBufferObject->Render();
		//}
		//ShaderManager::GetInstance()->Get(MODEL_ANIMATION_SHADER)->Deactivate();
	
		//glDisable(GL_DEPTH_TEST);
		//glColor3f(1.0f, 0.0f, 0.0f);
		//glLineWidth(3.0f);
		//glBegin(GL_LINES);
		//for (int x = 1; x < this->_jointsCount; x++)
		//{
		//	glVertex3f(this->_joints[x].finalVector.x, this->_joints[x].finalVector.y, this->_joints[x].finalVector.z);
		//	glVertex3f(this->_joints[this->_joints[x].parentIndex].finalVector.x, this->_joints[this->_joints[x].parentIndex].finalVector.y, this->_joints[this->_joints[x].parentIndex].finalVector.z);
		//}
		//glEnd();
		//glEnable(GL_DEPTH_TEST);
		//glColor3f(1.0f, 1.0f, 1.0f);
	}
}