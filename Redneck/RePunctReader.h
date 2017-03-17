#pragma once

#include "ReReader.h"

namespace Redneck
{
	class PunctReader : public Reader
	{
	private:
	public:
		PunctReader();
		virtual ~PunctReader();

		bool IsReadable(string s);
		Token Read(InputStream& inputStream);
	};
}