#pragma once

#include "ReInputStream.h"
#include "ReToken.h"
#include <regex>
#include <string>
using namespace std;

namespace Redneck
{
	class Reader
	{
	protected:
		bool IsDelimiter(string s);
	public:
		virtual bool IsReadable(string s) = 0;
		virtual Token Read(InputStream& inputStream) = 0;
	};
}