#include "stdafx.h"
#include "ReToken.h"

namespace Redneck
{
	Token::Token()
	{

	}

	Token::Token(TokenType tokenType)
	{
		_tokenType = tokenType;
	}

	Token::Token(TokenType tokenType, const string& value)
		: Token(tokenType)
	{
		_value = value;
	}

	Token::~Token()
	{

	}
}