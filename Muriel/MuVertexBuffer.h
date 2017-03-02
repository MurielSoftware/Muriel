#pragma once

#include "stdafx.h"
#include "MuBuffer.h"
#include "MuVertexAttributeInformation.h"
#include "MuGL.h"
#include <vector>

namespace Muriel
{
	class MURIEL_API VertexBuffer : public Buffer
	{
	private:
		vector<VertexAttributeInformation> _vertexAttributeInfos;
	public:
		VertexBuffer(BufferType bufferType, BufferUsage bufferUsage, void* data, unsigned int elementSize, unsigned int numberOfElements);
		virtual ~VertexBuffer();

		inline const VertexAttributeInformation& GetVertexAttributeInformation(int index) const { return _vertexAttributeInfos[index]; }

		void AddVertexAttributeInformation(unsigned int index, int size, GraphicsDataType type, bool normalized, unsigned int stride, unsigned int offset);
		unsigned GetVertexAttributeInfosCount();
	};
}