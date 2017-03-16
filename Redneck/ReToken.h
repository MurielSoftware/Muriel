#pragma once

#include "ReTokenType.h"

namespace Redneck
{
	class Token
	{
	private:
		TokenType _tokenType;
		int _intValue;
		char _value;
	public:
		Token(TokenType tokenType);
		Token(TokenType tokenType, int intValue);
		Token(TokenType tokenType, char value);
		Token(TokenType tokenType, int intValue, char value);
		virtual ~Token();

		inline TokenType GetTokenType() { return _tokenType; }
		inline int GetIntValue() { return _intValue; }
		inline char GetValue() { return _value; }

		Token& Clone();
	};
}