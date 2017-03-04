#include "stdafx.h"
#include "MuMeshRenderer.h"
#include "MuBaseMaterial.h"
#include "MuGameObject.h"
#include "MuVertexBuffer.h"
#include "MuIndexBuffer.h"

namespace Muriel
{
	MeshRenderer::MeshRenderer(GameObject* gameObject, BaseMaterial* material)
	{
		_gameObject = gameObject;
		_material = material;
	}

	MeshRenderer::~MeshRenderer()
	{

	}

	void MeshRenderer::PreRender(AbstractCamera* camera)
	{
//		_material->Start();
	//	_material->SetUniforms(camera);
	}

	void MeshRenderer::Render()
	{
		VertexBuffer* vertexBuffer = _gameObject->GetVertexBuffer();
		IndexBuffer* indexBuffer = _gameObject->GetIndexBuffer();
		_material->SetUniforms(_gameObject);
		vertexBuffer->Bind();
		for (int i = 0; i < vertexBuffer->GetVertexAttributeInfosCount(); i++)
		{
			const VertexAttributeInformation vertexAttributeInformation = vertexBuffer->GetVertexAttributeInformation(i);
			GL::EnableVertexAttribute(vertexAttributeInformation.GetIndex());
			GL::SetVertexAttribute(vertexAttributeInformation.GetIndex(), vertexAttributeInformation.GetSize(), vertexAttributeInformation.GetGraphicsDataType(), vertexAttributeInformation.GetNormalized(), vertexAttributeInformation.GetStride(), vertexAttributeInformation.GetOffset());
		}
		indexBuffer->Bind();
		GL::DrawElements(GraphicsPrimitiveType::Triangles(), indexBuffer->GetNumberOfElements(), indexBuffer->GetIndexDataType(), (void*)0);

		for (int i = 0; i < vertexBuffer->GetVertexAttributeInfosCount(); i++)
		{
			GL::DisableVertexAttribute(vertexBuffer->GetVertexAttributeInformation(i).GetIndex());
		}
		indexBuffer->Unbind();
		vertexBuffer->Unbind();
	}

	void MeshRenderer::PostRender()
	{
	//	_material->End();
	}
}