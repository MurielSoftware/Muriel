#include "stdafx.h"
#include "ReKeywords.h"

namespace Redneck
{
	unordered_map<string, TokenType> Keywords::_keywords = CreateKeywords();

	unordered_map<string, TokenType> Keywords::CreateKeywords()
	{
		unordered_map<string, TokenType> map;
		map.insert(pair<string, TokenType>(VAR, TOKEN_VARIABLE));
		map.insert(pair<string, TokenType>(IF, TOKEN_IF));
		map.insert(pair<string, TokenType>(FUNC, TOKEN_FUNC));
		map.insert(pair<string, TokenType>(WHILE, TOKEN_WHILE));
		return map;
	}

	bool Keywords::IsKeyword(const string& name)
	{
		return _keywords.find(name) != _keywords.end();
	}

	TokenType Keywords::GetKeywordTokenType(const string& name)
	{
		return _keywords[name];
	}
}