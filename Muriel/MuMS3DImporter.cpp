#include "stdafx.h"
#include "MuMS3DImporter.h"
#include "MuMS3DModel.h"
#include <fstream>

namespace Muriel
{
	Model* MS3DImporter::Import(const string& name, const string& path)
	{
		ifstream file(path, ios::binary | ios::in);
		if (!file.is_open())
		{
			return NULL;
		}
		MS3DModel* model = new MS3DModel(name);
		LoadHeader(model, file);
		Loadvertices(model, file);
		LoadTriangles(model, file);
		LoadMeshes(model, file);
		LoadMaterials(model, file);
		LoadAnimationInfo(model, file);
		LoadJoints(model, file);
		file.close();
		//model->Setup();
		model->CreateBuffers();
		return model;
	}

	void MS3DImporter::LoadHeader(MS3DModel* model, ifstream& file)
	{
		MS3DHeader header;
		file.read((char*)&header, sizeof(MS3DHeader));
	}

	void MS3DImporter::Loadvertices(MS3DModel* model, ifstream& file)
	{
		//BoundingBox boundingBox;
		unsigned short numVertices;
		file.read((char*)&numVertices, sizeof(unsigned short));
		MS3DVertex* vertices = new MS3DVertex[numVertices];
		for (int i = 0; i < numVertices; i++)
		{
			file.read((char*)&vertices[i], sizeof(MS3DVertex));
			//axisAlignedBox.Update(vertices[i].vert);
		}
		//model->SetBoundingBox(boundingBox);
		model->SetVerticesCount(numVertices);
		model->SetVertices(vertices);
	}

	void MS3DImporter::LoadTriangles(MS3DModel* model, ifstream& file)
	{
		unsigned short numTriangles = 0;
		file.read((char*)&numTriangles, sizeof(unsigned short));
		MS3DTriangle* triangles = new MS3DTriangle[numTriangles];
		for (int i = 0, j = 0; i < numTriangles; i++)
		{
			file.read((char*)&triangles[i], sizeof(MS3DTriangle));
		}
		model->SetTrianglesCount(numTriangles);
		model->SetTriangles(triangles);
	}

	void MS3DImporter::LoadMeshes(MS3DModel* model, ifstream& file)
	{
		unsigned short meshesCount;
		file.read((char*)&meshesCount, sizeof(unsigned short));
		MS3DMesh* meshes = new MS3DMesh[meshesCount];
		for (int i = 0; i < meshesCount; i++)
		{
			file.read((char*)&meshes[i].flags, sizeof(meshes[i].flags));
			file.read((char*)&meshes[i].name, sizeof(meshes[i].name));
			file.read((char*)&meshes[i].numTris, sizeof(meshes[i].numTris));
			meshes[i].indices = new unsigned short[meshes[i].numTris];
			for (int t = 0; t < meshes[i].numTris; t++)
			{
				file.read((char*)&meshes[i].indices[t], sizeof(meshes[i].indices[t]));
			}
			file.read((char*)&meshes[i].material, sizeof(meshes[i].material));
		}
		model->SetMeshesCount(meshesCount);
		model->SetMeshes(meshes);
	}

	void MS3DImporter::LoadMaterials(MS3DModel* model, ifstream& file)
	{
		unsigned short materialsCount;
		file.read((char*)&materialsCount, sizeof(unsigned short));
		MS3DMaterial* materials = new MS3DMaterial[materialsCount];
		for (int i = 0; i < materialsCount; i++)
		{
			file.read((char*)&materials[i], sizeof(MS3DMaterial));
			//if (TextureManager::GetInstance()->Get(materials[i].textureName) == NULL)
			//{
			//	TextureManager::GetInstance()->Load(materials[i].textureName, "Data/Textures/" + string(materials[i].textureName));
			//}
		}
		model->SetMaterialsCount(materialsCount);
		model->SetMaterials(materials);
	}

	void MS3DImporter::LoadAnimationInfo(MS3DModel* model, ifstream& file)
	{
		float fps, curFrame;
		int numFrame;
		file.read((char*)&fps, sizeof(float));
		file.read((char*)&curFrame, sizeof(float));
		file.read((char*)&numFrame, sizeof(int));
		model->SetFps(fps);
		model->SetCurFrame(curFrame);
		model->SetNumFrame(numFrame);
	}

	void MS3DImporter::LoadJoints(MS3DModel* model, ifstream& file)
	{
		unsigned short jointsCount;
		file.read((char*)&jointsCount, sizeof(unsigned short));
		MS3DJoint* joints = new MS3DJoint[jointsCount];
		for (int i = 0; i < jointsCount; i++)
		{
			file.read((char*)&joints[i].flags, sizeof(joints[i].flags));
			file.read((char*)&joints[i].name, sizeof(char) * 32);
			file.read((char*)&joints[i].parent, sizeof(char) * 32);
			file.read((char*)&joints[i].rotation, sizeof(Glml::Vec3));
			file.read((char*)&joints[i].position, sizeof(Glml::Vec3));
			file.read((char*)&joints[i].rotateKeyFramesCount, sizeof(joints[i].rotateKeyFramesCount));
			file.read((char*)&joints[i].translateKeyFramesCount, sizeof(joints[i].translateKeyFramesCount));

			joints[i].rotateKeyFrames = new MS3DKeyFrameRotate[joints[i].rotateKeyFramesCount];
			joints[i].translateKeyFrames = new MS3DKeyFrameTranslate[joints[i].translateKeyFramesCount];

			joints[i].localQuaternion.FromAxisAngle(joints[i].rotation);
			joints[i].localVector = joints[i].position;

			for (int k = 0; k < joints[i].rotateKeyFramesCount; k++)
			{
				Glml::Vec3 vParamTemp;
				float fTimeTemp;
				file.read((char*)&fTimeTemp, sizeof(fTimeTemp));
				file.read((char*)&vParamTemp, sizeof(vParamTemp));

				joints[i].rotateKeyFrames[k].time = fTimeTemp;
				joints[i].rotateKeyFrames[k].param.FromAxisAngle(vParamTemp);
			}
			for (int k = 0; k < joints[i].translateKeyFramesCount; k++)
			{
				file.read((char*)&joints[i].translateKeyFrames[k], sizeof(joints[i].translateKeyFrames[k]));
			}
		}
		model->SetJointsCount(jointsCount);
		model->SetJoints(joints);
	}
}