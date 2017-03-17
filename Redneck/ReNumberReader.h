#pragma once

#include "ReReader.h"

namespace Redneck
{
	class NumberReader : public Reader
	{
	private:
	public:
		NumberReader();
		virtual ~NumberReader();

		bool IsReadable(string s);
		Token Read(InputStream& inputStream);
	};
}