#pragma once

#include "stdafx.h"
#include "ReIdentifierReader.h"
#include "ReKeywords.h"

namespace Redneck
{
	IdentifierReader::IdentifierReader()
	{

	}

	IdentifierReader::~IdentifierReader()
	{

	}

	bool IdentifierReader::IsReadable(string s)
	{
		return isalpha(s[0]) == 0 ? false : true;
	}

	Token IdentifierReader::Read(InputStream& inputStream)
	{
		string value;
		while (!inputStream.Eof() && !IsDelimiter(inputStream.Peek()))
		{
			value += inputStream.Get();
		}
		if (Keywords::IsKeyword(value))
		{
			return Token(Keywords::GetKeywordTokenType(value), value);
		}
		return Token(TOKEN_IDENTIFIER, value);
	}
}