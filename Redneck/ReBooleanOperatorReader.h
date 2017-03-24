#pragma once

#include "ReCommon.h"
#include "ReReader.h"

namespace Redneck
{
	class BooleanOperatorReader : public Reader
	{
	private:
		static map<string, TokenType> _stringToTokenBooleanOperatorTokenType;
		static map<string, TokenType> CreateStringToTokenBooleanOperatorTokenType();
	public:
		BooleanOperatorReader();
		virtual ~BooleanOperatorReader();

		bool IsReadable(string s);
		Token Read(InputStream& inputStream);
	};
}