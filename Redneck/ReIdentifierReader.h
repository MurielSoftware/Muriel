#pragma once

#include "ReReader.h"

namespace Redneck
{
	class IdentifierReader : public Reader
	{
	private:
	public:
		IdentifierReader();
		virtual ~IdentifierReader();

		bool IsReadable(string s);
		Token Read(InputStream& inputStream);
	};
}