#pragma once

#include "stdafx.h"

namespace Muriel
{
	class Exception
	{
	private:
		string _message;
	public:
		Exception(const char* message, ...);

		inline const string& What() const { return _message; }
	};
}
