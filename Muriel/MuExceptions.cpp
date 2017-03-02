#include "stdafx.h"
#include "MuException.h"

namespace Muriel
{
	Exception::Exception(const char* message, ...)
	{
		va_list args;
		va_start(args, message);
		size_t length = _vscprintf(message, args);
		vsnprintf(const_cast<char*>(_message.data()), length, message, args);
		va_end(args);
	}
}