#pragma once

#include "stdafx.h"
#include "RePunctReader.h"

namespace Redneck
{
	map<string, TokenType> PunctReader::_stringToPunctTokenType = CreateStringToPunctTokenType();

	map<string, TokenType> PunctReader::CreateStringToPunctTokenType()
	{
		map<string, TokenType> map;
		map.insert(pair<string, TokenType>(",", TokenType::TOKEN_COMMA));
		map.insert(pair<string, TokenType>(";", TokenType::TOKEN_SEMI));
		map.insert(pair<string, TokenType>("(", TokenType::TOKEN_LBRACKET));
		map.insert(pair<string, TokenType>(")", TokenType::TOKEN_RBRACKET));
		map.insert(pair<string, TokenType>("{", TokenType::TOKEN_LBRACE));
		map.insert(pair<string, TokenType>("}", TokenType::TOKEN_RBRACE));
		return map;
	}

	PunctReader::PunctReader()
	{

	}

	PunctReader::~PunctReader()
	{

	}

	bool PunctReader::IsReadable(string s)
	{
		return _stringToPunctTokenType.find(s) != _stringToPunctTokenType.end();
	}

	Token PunctReader::Read(InputStream& inputStream)
	{
		string value = inputStream.Get();
		return Token(_stringToPunctTokenType[value], value);
	}
}