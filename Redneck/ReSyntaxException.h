#pragma once

#include <exception>
#include "ReCommon.h"

namespace Redneck
{
	class SyntaxException : public exception
	{
	public:
		SyntaxException()
		{
		}

		const char* what() const throw()
		{
			return "Syntax exception";
		}
	};
}