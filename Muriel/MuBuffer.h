#pragma once

#include "stdafx.h"
#include "MuGL.h"

namespace Muriel
{
	class MURIEL_API Buffer
	{
	private:
		BufferType _bufferType;
		BufferUsage _bufferUsage;
		unsigned int _bufferId;
		unsigned int _elementSize;
		unsigned int _numberOfElements;
	public:
		Buffer(BufferType bufferType, BufferUsage bufferUsage, void* data, unsigned int elementSize, unsigned int _numberOfElements);
		virtual ~Buffer();

		inline unsigned int GetBufferId() const { return _bufferId; }
		inline unsigned int GetElementSize() const { return _elementSize; }
		inline unsigned int GetNumberOfElements() const { return _numberOfElements; }

		void Bind();
		void Unbind();
	};
}