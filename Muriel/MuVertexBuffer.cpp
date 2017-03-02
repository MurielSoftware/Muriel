#include "stdafx.h"
#include "MuVertexAttributeInformation.h"
#include "MuBuffer.h"
#include "MuVertexBuffer.h"

namespace Muriel
{
	VertexBuffer::VertexBuffer(BufferType bufferType, BufferUsage bufferUsage, void* data, unsigned elementSize, unsigned numberOfElements)
		: Buffer(bufferType, bufferUsage, data, elementSize, numberOfElements)
	{

	}

	VertexBuffer::~VertexBuffer()
	{
	}

	void VertexBuffer::AddVertexAttributeInformation(unsigned index, int size, GraphicsDataType graphicsDataType, bool normalized, unsigned stride, unsigned offset)
	{
		_vertexAttributeInfos.push_back(VertexAttributeInformation(index, size, graphicsDataType, normalized, stride, offset));
	}

	unsigned VertexBuffer::GetVertexAttributeInfosCount()
	{
		return _vertexAttributeInfos.size();
	}
}