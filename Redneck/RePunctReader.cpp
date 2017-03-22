#pragma once

#include "stdafx.h"
#include "RePunctReader.h"
#include <regex>

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
		return regex_match(s, regex("( |\\,|\\;|\\(|\\)|\\{|\\})"));
	}

	Token PunctReader::Read(InputStream& inputStream)
	{
		string value = inputStream.Get();

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
			return Token(TOKEN_LBRACKET, value);
		}
		if (value == ")")
		{
			return Token(TOKEN_RBRACKET, value);
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