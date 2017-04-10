#pragma once

#include "stdafx.h"
#include "ReCompareOperatorReader.h"

namespace Redneck
{
	map<string, TokenType> CompareOperatorReader::_stringToCompareOperatorTokenType = CreateStringToCompareOperatorTokenType();

	map<string, TokenType> CompareOperatorReader::CreateStringToCompareOperatorTokenType()
	{
		map<string, TokenType> map;
		map.insert(pair<string, TokenType>("<", TokenType::TOKEN_LESS));
		map.insert(pair<string, TokenType>(">", TokenType::TOKEN_GREATER));
		map.insert(pair<string, TokenType>("<=", TokenType::TOKEN_LESS_EQUAL));
		map.insert(pair<string, TokenType>(">=", TokenType::TOKEN_GREATER_EQUAL));
		map.insert(pair<string, TokenType>("!=", TokenType::TOKEN_NOT_EQUALS));
		map.insert(pair<string, TokenType>("==", TokenType::TOKEN_EQUALS));
		return map;
	}

	CompareOperatorReader::CompareOperatorReader()
	{

	}

	CompareOperatorReader::~CompareOperatorReader()
	{

	}

	bool CompareOperatorReader::IsReadable(string s)
	{
		return _stringToCompareOperatorTokenType.find(s) != _stringToCompareOperatorTokenType.end();
	}

	Token CompareOperatorReader::Read(InputStream& inputStream)
	{
		string value = inputStream.Get();
		return Token(_stringToCompareOperatorTokenType[value], value);
	}
}