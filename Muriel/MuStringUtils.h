#pragma once

#include "stdafx.h"
#include <string>

namespace Muriel
{
	class StringUtils
	{
	public:
		static string& Format(const char* message, ...);
	};
}
