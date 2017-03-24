#pragma once

#include "ReCommon.h"
#include "ReReader.h"

namespace Redneck
{
	class OperatorReader : public Reader
	{
	private:
		static map<string, TokenType> _stringToOperatorTokenType;
		static map<string, TokenType> CreateStringToOperatorTokenType();
	public:
		OperatorReader();
		virtual ~OperatorReader();

		bool IsReadable(string s);
		Token Read(InputStream& inputStream);
	};
}