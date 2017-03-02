#pragma once

#include "stdafx.h"
#include "MuGraphicsDataType.h"

namespace Muriel
{
	class MURIEL_API VertexAttributeInformation
	{
	private:
		unsigned _index;
		unsigned _size;
		GraphicsDataType _graphicsDataType;
		bool _normalized;
		unsigned _stride;
		unsigned _offset;
	public:
		VertexAttributeInformation(unsigned index, unsigned size, GraphicsDataType graphicsDataType, bool normalized, unsigned stride, unsigned offset);
		virtual ~VertexAttributeInformation();

		inline const unsigned GetIndex() const { return _index; }
		inline const unsigned GetSize() const { return _size; }
		inline const GraphicsDataType GetGraphicsDataType() const { return _graphicsDataType; }
		inline const bool GetNormalized() const { return _normalized; }
		inline const unsigned GetStride() const { return _stride; }
		inline void* GetOffset() const { return (void*)_offset; }
	};
}