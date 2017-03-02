#include "stdafx.h"
#include "MuBuffer.h"

namespace Muriel
{
	Buffer::Buffer(BufferType bufferType, BufferUsage bufferUsage, void* data, unsigned int elementSize, unsigned int numberOfElements)
	{
		_bufferType = bufferType;
		_bufferUsage = bufferUsage;
		_elementSize = elementSize;
		_numberOfElements = numberOfElements;

		glGenBuffers(1, &_bufferId);
		Bind();
		glBufferData(bufferType.GetBufferType(), _elementSize * _numberOfElements, data, bufferUsage.GetBufferUsage());
		Unbind();
	}

	Buffer::~Buffer()
	{
		glDeleteBuffers(1, &_bufferId);
	}

	void Buffer::Bind()
	{
		glBindBuffer(_bufferType.GetBufferType(), _bufferId);
	}

	void Buffer::Unbind()
	{
		glBindBuffer(_bufferType.GetBufferType(), 0);
	}
}