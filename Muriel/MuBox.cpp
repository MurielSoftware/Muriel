#include "stdafx.h"
#include "MuBox.h"
#include "MuVertexBuffer.h"
#include "MuIndexBuffer.h"
#include "MuVertexPosNormTex.h"

namespace Muriel
{
	const unsigned short indices[] =
	{
		0,1,2, 
		1,3,2,
		6,7,5, 
		6,5,4,
		8,9,10, 
		9,10,11,
		12,13,14, 
		13,14,15,
		17,16,18, 
		17,18,19,
		20,21,22, 
		21,22,23
	};

	const VertexPosNormTex vertices[] =
	{
		VertexPosNormTex(Vec3(-1.0f, -1.0f, 1.0f), Vec3(0.0f, 0.0f, 1.0f), Vec2(0.0f, 1.0f)),
		VertexPosNormTex(Vec3(1.0f, -1.0f, 1.0f), Vec3(0.0f, 0.0f, 1.0f), Vec2(1.0f, 1.0f)),
		VertexPosNormTex(Vec3(-1.0f, 1.0f, 1.0f), Vec3(0.0f, 0.0f, 1.0f), Vec2(0.0f, 0.0f)),
		VertexPosNormTex(Vec3(1.0f, 1.0f, 1.0f), Vec3(0.0f, 0.0f, 1.0f), Vec2(1.0f, 0.0f)),

		VertexPosNormTex(Vec3(-1.0f, -1.0f, -1.0f), Vec3(0.0f, 0.0f, -1.0f), Vec2(0.0f, 1.0f)),
		VertexPosNormTex(Vec3(1.0f, -1.0f, -1.0f), Vec3(0.0f, 0.0f, -1.0f), Vec2(1.0f, 1.0f)),
		VertexPosNormTex(Vec3(-1.0f, 1.0f, -1.0f), Vec3(0.0f, 0.0f, -1.0f), Vec2(0.0f, 0.0f)),
		VertexPosNormTex(Vec3(1.0f, 1.0f, -1.0f), Vec3(0.0f, 0.0f, -1.0f), Vec2(1.0f, 0.0f)),

		VertexPosNormTex(Vec3(-1.0f, 1.0f, 1.0f), Vec3(0.0f, 1.0f, 0.0f), Vec2(0.0f, 1.0f)),
		VertexPosNormTex(Vec3(1.0f, 1.0f, 1.0f), Vec3(0.0f, 1.0f, 0.0f), Vec2(1.0f, 1.0f)),
		VertexPosNormTex(Vec3(-1.0f, 1.0f, -1.0f), Vec3(0.0f, 1.0f, 0.0f), Vec2(0.0f, 0.0f)),
		VertexPosNormTex(Vec3(1.0f, 1.0f, -1.0f), Vec3(0.0f, 1.0f, 0.0f), Vec2(1.0f, 0.0f)),

		VertexPosNormTex(Vec3(-1.0f, -1.0f, 1.0f), Vec3(0.0f, -1.0f, 0.0f), Vec2(0.0f, 1.0f)),
		VertexPosNormTex(Vec3(1.0f, -1.0f, 1.0f), Vec3(0.0f, -1.0f, 0.0f), Vec2(1.0f, 1.0f)),
		VertexPosNormTex(Vec3(-1.0f, -1.0f, -1.0f), Vec3(0.0f, -1.0f, 0.0f), Vec2(0.0f, 0.0f)),
		VertexPosNormTex(Vec3(1.0f, -1.0f, -1.0f), Vec3(0.0f, -1.0f, 0.0f), Vec2(1.0f, 0.0f)),

		VertexPosNormTex(Vec3(-1.0f, -1.0f, 1.0f), Vec3(-1.0f, 0.0f, 0.0f), Vec2(0.0f, 1.0f)),
		VertexPosNormTex(Vec3(-1.0f, 1.0f, 1.0f), Vec3(-1.0f, 0.0f, 0.0f), Vec2(1.0f, 1.0f)),
		VertexPosNormTex(Vec3(-1.0f, -1.0f, -1.0f), Vec3(-1.0f, 0.0f, 0.0f), Vec2(0.0f, 0.0f)),
		VertexPosNormTex(Vec3(-1.0f, 1.0f, -1.0f), Vec3(-1.0f, 0.0f, 0.0f), Vec2(1.0f, 0.0f)),

		VertexPosNormTex(Vec3(1.0f, -1.0f, 1.0f), Vec3(1.0f, 0.0f, 0.0f), Vec2(0.0f, 1.0f)),
		VertexPosNormTex(Vec3(1.0f, 1.0f, 1.0f), Vec3(1.0f, 0.0f, 0.0f), Vec2(1.0f, 1.0f)),
		VertexPosNormTex(Vec3(1.0f, -1.0f, -1.0f), Vec3(1.0f, 0.0f, 0.0f), Vec2(0.0f, 0.0f)),
		VertexPosNormTex(Vec3(1.0f, 1.0f, -1.0f), Vec3(1.0f, 0.0f, 0.0f), Vec2(1.0f, 0.0f)),
	};

	Box::Box(const string& name)
		: GameObject(name)
	{
		Init();
	}

	Box::~Box()
	{
	}

	void Box::Init()
	{
		_vertexBuffer = new VertexBuffer(BufferType::ArrayBuffer(), BufferUsage::StaticDraw(), (void*)vertices, sizeof(VertexPosNormTex), 24);
		_vertexBuffer->AddVertexAttributeInformation(0, 3, GraphicsDataType::Float(), false, sizeof(VertexPosNormTex), 0);
		_vertexBuffer->AddVertexAttributeInformation(1, 3, GraphicsDataType::Float(), false, sizeof(VertexPosNormTex), sizeof(Vec3));
		_vertexBuffer->AddVertexAttributeInformation(2, 2, GraphicsDataType::Float(), false, sizeof(VertexPosNormTex), sizeof(Vec3) * 2);
		_indexBuffer = new IndexBuffer((void*)indices, sizeof(unsigned short), 36, GraphicsDataType::UnsignedShort());
	}
}