#pragma once

#include "stdafx.h"
#include "MuBuffer.h"
#include "MuGL.h"

namespace Muriel
{
	class MURIEL_API IndexBuffer : public Buffer
	{
	private:
		unsigned int* _indices;
		GraphicsDataType _graphicsDataType;
	public:
		/*IndexBuffer(unsigned* data, unsigned numberOfElements);*/
		IndexBuffer(void* data, unsigned elementSize, unsigned numberOfElements, GraphicsDataType graphicsDataType);
		virtual ~IndexBuffer();

		inline const GraphicsDataType GetIndexDataType() const { return _graphicsDataType; }
	};
}