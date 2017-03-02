#pragma once

#include "stdafx.h"

namespace Muriel
{
	class CullMode
	{
	private:
		explicit CullMode(int mode) :_mode(mode) {};
		int _mode;
	public:
		static CullMode Front() { return CullMode(GL_FRONT); };
		static CullMode Back() { return CullMode(GL_BACK); };
		static CullMode FrontAndBack() { return CullMode(GL_FRONT_AND_BACK); };

		inline int GetMode() { return _mode; }
	};
}
