#include "stdafx.h"
#include "MuBoundingBox.h"
#include "MuVertexBuffer.h"
#include "MuIndexBuffer.h"

namespace Muriel
{
	VertexPos* BoundingBox::_vertices = CreateVertices();
	unsigned short* BoundingBox::_indices = CreateIndices();

	BoundingBox::BoundingBox()
	{
		
	}

	BoundingBox::BoundingBox(Vec3 center, Vec3 halfSize)
	{
		_center = center;
		_halfSize = halfSize;
	}

	BoundingBox::~BoundingBox()
	{
		//delete _vertices;
		//delete _indices;
	}

	VertexPos* BoundingBox::CreateVertices()
	{
		VertexPos* vertices = new VertexPos[8];
		vertices[0] = Vec3(-0.5f, -0.5f, -0.5f);
		vertices[0] = Vec3(0.5f, -0.5f, -0.5f);
		vertices[0] = Vec3(0.5f, 0.5f, -0.5f);
		vertices[0] = Vec3(-0.5f, 0.5f, -0.5f);
		vertices[0] = Vec3(-0.5f, -0.5f, 0.5f);
		vertices[0] = Vec3(0.5f, -0.5f, 0.5f);
		vertices[0] = Vec3(0.5f, 0.5f, 0.5f);
		vertices[0] = Vec3(-0.5f, 0.5f, 0.5f);
		return vertices;
	}

	unsigned short* BoundingBox::CreateIndices()
	{
		unsigned short* indices = new unsigned short[16];
		indices[0] = 0;
		indices[1] = 1;
		indices[2] = 2;
		indices[3] = 3;

		indices[4] = 4;
		indices[5] = 5;
		indices[6] = 6;
		indices[7] = 7;

		indices[8] = 0;
		indices[9] = 4;
		indices[10] = 1;
		indices[11] = 5;
		indices[12] = 2;
		indices[13] = 6;
		indices[14] = 3;
		indices[15] = 7;

		//_indexBuffer = new IndexBuffer(_indices, sizeof(unsigned short), 16, GraphicsDataType::UnsignedShort());
		return indices;
	}

	VertexBuffer* BoundingBox::CreateVertexBuffer()
	{
		VertexBuffer* vertexBuffer = new VertexBuffer(BufferType::ArrayBuffer(), BufferUsage::StaticDraw(), (void*)_vertices, sizeof(VertexPos), 8);
		vertexBuffer->AddVertexAttributeInformation(0, 3, GraphicsDataType::Float(), false, sizeof(VertexPos), 0);
		return vertexBuffer;
	}

	IndexBuffer* BoundingBox::CreateIndexBuffer()
	{
		return new IndexBuffer(_indices, sizeof(unsigned short), 16, GraphicsDataType::UnsignedShort());
	}

	void BoundingBox::Render()
	{
		GL::DrawElements(GraphicsPrimitiveType::LineLoop(), 4, GraphicsDataType::UnsignedShort(), 0);
		GL::DrawElements(GraphicsPrimitiveType::LineLoop(), 4, GraphicsDataType::UnsignedShort(), (void*)(4 * sizeof(unsigned short)));
		GL::DrawElements(GraphicsPrimitiveType::Lines(), 8, GraphicsDataType::UnsignedShort(), (void*)(8 * sizeof(unsigned short)));
	}
}