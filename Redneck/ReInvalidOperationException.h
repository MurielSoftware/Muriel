#pragma once

#include <exception>

using namespace std;

namespace Redneck
{
	class InvalidOperationException : public exception
	{
		const char* what() const throw()
		{
			return "Invalid operation exception";
		}
	};
}