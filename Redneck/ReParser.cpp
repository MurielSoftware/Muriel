#include "stdafx.h"
#include "ReParser.h"
#include "ReNumExpression.h"
#include "ReAritmeticOperationExpression.h"
#include "ReToken.h"
#include <regex>
#include <sstream>

namespace Redneck
{
	Parser::Parser()
	{

	}

	Parser::~Parser()
	{

	}

	Expression* Parser::CreateExpressions(const string& s)
	{
		vector<string> scanned = Scan(s);
		vector<Token*> tokens = Tokenize(scanned);
		return Parse(tokens);
	}

	bool Parser::IsKeyword(const string& s)
	{
		return false;
	}

	bool Parser::IsIgnored(const string& s)
	{
		return false;
	}

	bool Parser::IsDelimiter(const char c)
	{
		if (IsArithmeticOperator(c) || IsWhitespace(c))
		{
			return true;
		}
		return false;// regex_match(string(1, c), regex("( |\\+|\\-|\\*|||)"));
	}

	bool Parser::IsWhitespace(const char c)
	{
		return regex_match(string(1, c), regex("( |\\n|\\r|\\t)"));
	}

	bool Parser::IsArithmeticOperator(const char c)
	{
		return regex_match(string(1, c), regex("( |\\+|\\-|\\*|\\/|\\%|\\^)"));
	}

	bool Parser::IsGreatLessOperator(const char c)
	{
		return regex_match(string(1, c), regex("( |\\<|\\>)"));
	}

	vector<string> Parser::Scan(const string& s)
	{
		vector<string> out;
		string word;

		for (unsigned i = 0; i < s.length(); i++)
		{
			if (IsDelimiter(s[i]))
			{
				if (word != "")
				{
					out.push_back(word);
				}
				if (!IsWhitespace(s[i]))
				{
					out.push_back(string(1, s[i]));
				}
				word = "";
			}
			else if (i == s.length() - 1)
			{
				word += s[i];
				out.push_back(word);
			}
			else if (s[i])
			{
				word += tolower(s[i]);
			}
		}

		return out;
	}

	vector<Token*> Parser::Tokenize(vector<string>& scanned)
	{
		vector<Token*> tokens;
		int intValue;
		bool boleanValue;

		for (string word : scanned)
		{
			istringstream iss(word);
			if (IsKeyword(word))
			{

			}
			else if (word.length() == 1 && isalpha(word[0]))
			{

			}
			else if (iss >> intValue)
			{
				tokens.push_back(new Token(NUMBER, intValue));
			}
			else if (word.length() == 1 && !isalpha(word[0]))
			{
				if (IsArithmeticOperator(word[0]))
				{
					tokens.push_back(new Token(NUMERIC_OPERATION, word[0]));
				}
				else if (IsGreatLessOperator(word[0]))
				{
					tokens.push_back(new Token(CHECK_GREAT_LESS, word[0]));
				}
			}
		}
		
		for (int i=0; i < tokens.size(); i++)
		{
			if (tokens[i]->GetTokenType() == TokenType::NUMERIC_OPERATION)
			{
				Token* swap = tokens[i];
				tokens[i] = tokens[i - 1];
				tokens[i - 1] = swap;
			}
		}
		return tokens;
	}

	void Parser::EatToken(vector<Token*>& tokens)
	{
		tokens.erase(tokens.begin());
	}

	void Parser::EatToken(vector<Token*>& tokens, TokenType tokenType)
	{
		if (tokens[0]->GetTokenType() != tokenType)
		{
			// throw SyntaxException();
			return;
		}
		EatToken(tokens);
	}

	Expression* Parser::Parse(vector<Token*>& tokens)
	{
		Expression* expression;
		Token currentToken = Token(tokens[0]->GetTokenType(), tokens[0]->GetIntValue(), tokens[0]->GetValue());
		EatToken(tokens);
		switch (currentToken.GetTokenType())
		{
		case NUMBER:
			expression = new NumExpression(currentToken.GetIntValue());
			break;
		case NUMERIC_OPERATION:
			expression = new AritmeticOperationExpression(Parse(tokens), Parse(tokens), currentToken.GetValue());
			break;
		}
		return expression;
	}
}