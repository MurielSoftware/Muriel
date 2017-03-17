#pragma once

#include "ReReader.h"

namespace Redneck
{
	class StringReader : public Reader
	{
	private:
	public:
		StringReader();
		virtual ~StringReader();

		bool IsReadable(string s);
		Token Read(InputStream& inputStream);
	};
}