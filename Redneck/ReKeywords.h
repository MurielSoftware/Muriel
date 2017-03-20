#pragma once

#define VAR "var"
#define IF "if"

#include "ReTokenType.h"

#include <string>
#include <unordered_map>

using namespace std;

namespace Redneck
{
	class Keywords
	{
	private:
		static unordered_map<string, TokenType> _keywords;
		static unordered_map<string, TokenType> CreateKeywords();
	public:
		static bool IsKeyword(const string& name);
		static TokenType GetKeywordTokenType(const string& name);
	};
}