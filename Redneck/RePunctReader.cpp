#pragma once

#include "stdafx.h"
#include "RePunctReader.h"

namespace Redneck
{
	PunctReader::PunctReader()
	{

	}

	PunctReader::~PunctReader()
	{

	}

	bool PunctReader::IsReadable(string s)
	{
		return regex_match(s, regex("( |\\,|\\;|\\()|\\)|\\{|\\}"));
	}

	Token PunctReader::Read(InputStream& inputStream)
	{
		string value = string(1, inputStream.Get());

		if (value == ",")
		{
			return Token(TOKEN_COMMA, value);
		}
		if (value == ";")
		{
			return Token(TOKEN_SEMI, value);
		}
		if (value == "(")
		{
			return Token(TOKEN_LPAREN, value);
		}
		if (value == ")")
		{
			return Token(TOKEN_RPAREN, value);
		}
		if (value == "{")
		{
			return Token(TOKEN_LBRACE, value);
		}
		if (value == "}")
		{
			return Token(TOKEN_RBRACE, value);
		}
	}
}