#include "stdafx.h"
#include "MuObject.h"
#include "MuGameObject.h"
//#include "MuVertexBuffer.h"
//#include "MuIndexBuffer.h"
//#include "MuGL.h"
//#include "MuMaterial.h"
//#include "MuShader.h"
//#include "MuAbstractCamera.h"

namespace Muriel
{
	GameObject::GameObject(const string& name)
		: Object(name)
	{
	}

	GameObject::~GameObject()
	{
	}

	Transform& GameObject::GetTransform()
	{ 
		return _transform; 
	}

	//void GameObject::PreRender(AbstractCamera* camera)
	//{
	//	_material->Start();
	//	Shader* shader = _material->GetShader();
	//	Mat4x4 m;
	//	shader->UniformMat4x4("projectionViewMatrix", false, camera->GetProjectionViewMatrix());
	//	shader->UniformMat4x4("worldMatrix", false, _transform.GetWorldMatrix());
	//}

	//void GameObject::Render()
	//{		
	//	_vertexBuffer->Bind();
	//	for (int i = 0; i < _vertexBuffer->GetVertexAttributeInfosCount(); i++)
	//	{
	//		const VertexAttributeInformation vertexAttributeInformation = _vertexBuffer->GetVertexAttributeInformation(i);
	//		GL::EnableVertexAttribute(vertexAttributeInformation.GetIndex());
	//		GL::SetVertexAttribute(vertexAttributeInformation.GetIndex(), vertexAttributeInformation.GetSize(), vertexAttributeInformation.GetGraphicsDataType(), vertexAttributeInformation.GetNormalized(), vertexAttributeInformation.GetStride(), vertexAttributeInformation.GetOffset());
	//	}
	//	_indexBuffer->Bind();
	//	GL::DrawElements(GraphicsPrimitiveType::Triangles(), _indexBuffer->GetNumberOfElements(), _indexBuffer->GetIndexDataType(), (void*)0);

	//	for (int i = 0; i < _vertexBuffer->GetVertexAttributeInfosCount(); i++)
	//	{
	//		GL::DisableVertexAttribute(_vertexBuffer->GetVertexAttributeInformation(i).GetIndex());
	//	}
	//	_indexBuffer->Unbind();
	//	_vertexBuffer->Unbind();
	//	_material->End();
	//}
}