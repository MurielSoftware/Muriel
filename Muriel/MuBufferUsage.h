#pragma once

#include "stdafx.h"

namespace Muriel
{
	class BufferUsage
	{
	private:
		GLenum _bufferUsage;
		explicit BufferUsage(GLenum bufferUsage) :_bufferUsage(bufferUsage) {};
	public:
		static BufferUsage StreamDraw() { return BufferUsage(GL_STREAM_DRAW); };
		static BufferUsage StreamRead() { return BufferUsage(GL_STREAM_READ); };
		static BufferUsage StreamCopy() { return BufferUsage(GL_STREAM_COPY); };
		static BufferUsage StaticDraw() { return BufferUsage(GL_STATIC_DRAW); };
		static BufferUsage StaticRead() { return BufferUsage(GL_STATIC_READ); };
		static BufferUsage StaticCopy() { return BufferUsage(GL_STATIC_COPY); };
		static BufferUsage DynamicDraw() { return BufferUsage(GL_DYNAMIC_DRAW); };
		static BufferUsage DynamicRead() { return BufferUsage(GL_DYNAMIC_READ); };
		static BufferUsage DynamicCopy() { return BufferUsage(GL_DYNAMIC_COPY); };

		inline GLenum GetBufferUsage() const { return _bufferUsage; }

		BufferUsage() {}
	};
}