#pragma once

#include "stdafx.h"
#include "ReBooleanOperatorReader.h"
#include <regex>

namespace Redneck
{
	BooleanOperatorReader::BooleanOperatorReader()
	{

	}

	BooleanOperatorReader::~BooleanOperatorReader()
	{

	}

	bool BooleanOperatorReader::IsReadable(string s)
	{
		return regex_match(s, regex("(\\<|\\>|\\==)"));
	}

	Token BooleanOperatorReader::Read(InputStream& inputStream)
	{
		string value = inputStream.Get();
		if (value == "<")
		{
			return Token(TokenType::TOKEN_LESS, value);
		}
		if (value == ">")
		{
			return Token(TokenType::TOKEN_GREATER, value);
		}
		if (value == "==")
		{
			return Token(TokenType::TOKEN_EQUALS, value);
		}
	}
}