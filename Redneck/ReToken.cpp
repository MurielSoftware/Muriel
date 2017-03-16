#include "stdafx.h"
#include "ReToken.h"

namespace Redneck
{
	Token::Token(TokenType tokenType)
	{
		_tokenType = tokenType;
	}

	Token::Token(TokenType tokenType, int intValue)
		: Token(tokenType)
	{
		_intValue = intValue;
	}

	Token::Token(TokenType tokenType, char value)
		: Token(tokenType)
	{
		_value = value;
	}

	Token::Token(TokenType tokenType, int intValue, char value)
		: Token(tokenType)
	{
		_intValue = intValue;
		_value = value;
	}

	Token::~Token()
	{

	}

	Token& Token::Clone()
	{
		return Token(_tokenType, _intValue, _value);
	}
}