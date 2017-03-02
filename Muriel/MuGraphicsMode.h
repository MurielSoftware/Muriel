#pragma once

#include "stdafx.h"

namespace Muriel
{

	class GraphicsMode
	{
	private:
		explicit GraphicsMode(int mode) :_mode(mode) {};
		int _mode;
	public:
		static GraphicsMode CullFace() { return GraphicsMode(GL_CULL_FACE); };
		static GraphicsMode DepthTest() { return GraphicsMode(GL_DEPTH_TEST); };
		static GraphicsMode Blend() { return GraphicsMode(GL_BLEND); };

		inline int GetMode() const { return _mode; }
	};
}
