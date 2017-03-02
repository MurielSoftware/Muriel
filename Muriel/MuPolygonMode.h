#pragma once

#include "stdafx.h"

namespace Muriel
{
	class PolygonMode
	{
	private:
		explicit PolygonMode(GLenum mode) :_mode(mode) {};
		GLenum _mode;
	public:
		static PolygonMode Point() { return PolygonMode(GL_POINT); };
		static PolygonMode Line() { return PolygonMode(GL_LINE); };
		static PolygonMode Fill() { return PolygonMode(GL_FILL); };

		inline GLenum GetMode() const { return _mode; }
	};
}