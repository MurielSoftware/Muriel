#pragma once

#include "stdafx.h"
#include "ReOperatorReader.h"
#include <regex>

namespace Redneck
{
	OperatorReader::OperatorReader()
	{

	}

	OperatorReader::~OperatorReader()
	{

	}

	bool OperatorReader::IsReadable(string s)
	{
		return regex_match(s, regex("( |\\+|\\-|\\*|\\/|\\%|\\^|\\=)"));
	}

	Token OperatorReader::Read(InputStream& inputStream)
	{
		string value = string(1, inputStream.Get());
		if (value == "+")
		{
			return Token(TOKEN_PLUS, value);
		}
		if (value == "-")
		{
			return Token(TOKEN_MINUS, value);
		}
		if (value == "*")
		{
			return Token(TOKEN_MULT, value);
		}
		if (value == "/")
		{
			return Token(TOKEN_DIV, value);
		}
		if (value == "=")
		{
			return Token(TOKEN_EQUAL, value);
		}
	}
}