#pragma once

#include "stdafx.h"

namespace Muriel
{
	class BufferType
	{
	private:
		GLenum _bufferType;
		explicit BufferType(GLenum bufferType) :_bufferType(bufferType) {};
	public:
		static BufferType ArrayBuffer() { return BufferType(GL_ARRAY_BUFFER); };
		static BufferType AtomicCounterBuffer() { return BufferType(GL_ATOMIC_COUNTER_BUFFER); };
		static BufferType CopyReadBuffer() { return BufferType(GL_COPY_READ_BUFFER); };
		static BufferType CopyWriteBuffer() { return BufferType(GL_COPY_WRITE_BUFFER); };
		static BufferType DrawIndirectBuffer() { return BufferType(GL_DRAW_INDIRECT_BUFFER); };
		static BufferType DispatchIndirectBuffer() { return BufferType(GL_DISPATCH_INDIRECT_BUFFER); };
		static BufferType ElementArrayBuffer() { return BufferType(GL_ELEMENT_ARRAY_BUFFER); };
		static BufferType PixelPackBuffer() { return BufferType(GL_PIXEL_PACK_BUFFER); };
		static BufferType PixelUnpackBuffer() { return BufferType(GL_PIXEL_UNPACK_BUFFER); };
		static BufferType ShaderStorageBuffer() { return BufferType(GL_SHADER_STORAGE_BUFFER); };
		static BufferType TextureBuffer() { return BufferType(GL_TEXTURE_BUFFER); };
		static BufferType TransformFeedbackBuffer() { return BufferType(GL_TRANSFORM_FEEDBACK_BUFFER); };
		static BufferType UniformBuffer() { return BufferType(GL_UNIFORM_BUFFER); };

		inline GLenum GetBufferType() const { return this->_bufferType; }

		BufferType() {}
	};
}