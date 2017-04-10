#pragma once

#include "ReCommon.h"
#include "ReReader.h"

namespace Redneck
{
	class CompareOperatorReader : public Reader
	{
	private:
		static map<string, TokenType> _stringToCompareOperatorTokenType;
		static map<string, TokenType> CreateStringToCompareOperatorTokenType();
	public:
		CompareOperatorReader();
		virtual ~CompareOperatorReader();

		bool IsReadable(string s);
		Token Read(InputStream& inputStream);
	};
}