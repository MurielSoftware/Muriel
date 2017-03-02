#include "stdafx.h"
#include "MuVertexAttributeInformation.h"

namespace Muriel
{
	VertexAttributeInformation::VertexAttributeInformation(unsigned index, unsigned size, GraphicsDataType graphicsDataType, bool normalized, unsigned stride, unsigned offset)
	{
		_index = index;
		_size = size;
		_graphicsDataType = graphicsDataType;
		_normalized = normalized;
		_stride = stride;
		_offset = offset;
	}

	VertexAttributeInformation::~VertexAttributeInformation()
	{

	}
}