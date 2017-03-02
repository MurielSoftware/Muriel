#include "stdafx.h"
#include "MuStringUtils.h"

namespace Muriel
{
	string& StringUtils::Format(const char* message, ...)
	{
		char buffer[256];
		va_list args;
		va_start(args, message);
		vsnprintf(buffer, 255, message, args);

		return string(&buffer[0]);
	}
}