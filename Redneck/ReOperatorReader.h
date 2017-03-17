#pragma once

#include "ReReader.h"

namespace Redneck
{
	class OperatorReader : public Reader
	{
	private:
	public:
		OperatorReader();
		virtual ~OperatorReader();

		bool IsReadable(string s);
		Token Read(InputStream& inputStream);
	};
}