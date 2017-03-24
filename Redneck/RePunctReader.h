#pragma once

#include "ReCommon.h"
#include "ReReader.h"

namespace Redneck
{
	class PunctReader : public Reader
	{
	private:
		static map<string, TokenType> _stringToPunctTokenType;
		static map<string, TokenType> CreateStringToPunctTokenType();
	public:
		PunctReader();
		virtual ~PunctReader();

		bool IsReadable(string s);
		Token Read(InputStream& inputStream);
	};
}