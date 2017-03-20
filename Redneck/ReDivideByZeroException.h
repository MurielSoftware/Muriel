#pragma once

#include <exception>

using namespace std;

namespace Redneck
{
	class DivideByZeroException : public exception
	{
		const char* what() const throw()
		{
			return "Divide by zero exception";
		}
	};
}