#pragma once

#include "stdafx.h"

namespace Muriel
{
	class GraphicsPrimitiveType
	{
	private:
		explicit GraphicsPrimitiveType(int primitiveType) :_primitiveType(primitiveType) {};
		int _primitiveType;
	public:
		static GraphicsPrimitiveType Points() { return GraphicsPrimitiveType(GL_POINTS); };
		static GraphicsPrimitiveType LineStrip() { return GraphicsPrimitiveType(GL_LINE_STRIP); };
		static GraphicsPrimitiveType LineStripAdjacency() { return GraphicsPrimitiveType(GL_LINE_STRIP_ADJACENCY); };
		static GraphicsPrimitiveType LineLoop() { return GraphicsPrimitiveType(GL_LINE_LOOP); };
		static GraphicsPrimitiveType Lines() { return GraphicsPrimitiveType(GL_LINES); };
		static GraphicsPrimitiveType LinesAdjacency() { return GraphicsPrimitiveType(GL_LINES_ADJACENCY); };
		static GraphicsPrimitiveType TriangleStrip() { return GraphicsPrimitiveType(GL_TRIANGLE_STRIP); };
		static GraphicsPrimitiveType TriangleStripAdjacency() { return GraphicsPrimitiveType(GL_TRIANGLE_STRIP_ADJACENCY); };
		static GraphicsPrimitiveType TriangleFan() { return GraphicsPrimitiveType(GL_TRIANGLE_FAN); };
		static GraphicsPrimitiveType Triangles() { return GraphicsPrimitiveType(GL_TRIANGLES); };
		static GraphicsPrimitiveType TrianglesAdjacency() { return GraphicsPrimitiveType(GL_TRIANGLES_ADJACENCY); };
		static GraphicsPrimitiveType Patches() { return GraphicsPrimitiveType(GL_PATCHES); };

		int GetType() const { return this->_primitiveType; }
	};
}