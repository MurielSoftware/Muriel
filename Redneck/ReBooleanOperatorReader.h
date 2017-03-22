#pragma once

#include "ReReader.h"

namespace Redneck
{
	class BooleanOperatorReader : public Reader
	{
	private:
	public:
		BooleanOperatorReader();
		virtual ~BooleanOperatorReader();

		bool IsReadable(string s);
		Token Read(InputStream& inputStream);
	};
}