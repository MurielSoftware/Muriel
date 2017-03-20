#pragma once

#include <exception>

using namespace std;

namespace Redneck
{
	class NullPointerException : public exception
	{
		const char* what() const throw()
		{
			return "Nullpointer exception";
		}
	};
}