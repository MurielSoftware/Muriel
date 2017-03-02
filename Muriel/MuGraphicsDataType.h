#pragma once

#include "stdafx.h"

namespace Muriel
{
	class GraphicsDataType

	{
	private:
		GLenum _indexDataType;
		explicit GraphicsDataType(GLenum indexDataType) :_indexDataType(indexDataType) {};
	public:
		static GraphicsDataType UnsignedByte() { return GraphicsDataType(GL_UNSIGNED_BYTE); };
		static GraphicsDataType UnsignedInt() { return GraphicsDataType(GL_UNSIGNED_INT); };
		static GraphicsDataType UnsignedShort() { return GraphicsDataType(GL_UNSIGNED_SHORT); };
		static GraphicsDataType UnsignedInt_8_8_8_8() { return GraphicsDataType(GL_UNSIGNED_INT_8_8_8_8); };
		static GraphicsDataType Float() { return GraphicsDataType(GL_FLOAT); };
		
		inline GLenum GetIndexDataType() const { return this->_indexDataType; }

		GraphicsDataType() {}
	};
}