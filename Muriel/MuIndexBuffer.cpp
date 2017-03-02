#include "stdafx.h"
#include "MuBuffer.h"
#include "MuIndexBuffer.h"

namespace Muriel
{
	IndexBuffer::IndexBuffer(void* data, unsigned elementSize, unsigned numberOfElements, GraphicsDataType graphicsDataType)
		: Buffer(BufferType::ElementArrayBuffer(), BufferUsage::StaticDraw(), (void*)data, elementSize, numberOfElements)
	{
		_graphicsDataType = graphicsDataType;
	}

	IndexBuffer::~IndexBuffer()
	{
		if (_indices != 0)
		{
			delete[] _indices;
		}
	}
}