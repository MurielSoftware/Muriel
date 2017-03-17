#include "stdafx.h"
#include "ReLexer.h"
#include "ReToken.h"
#include "ReInputStream.h"
#include "ReIdentifierReader.h"
#include "ReNumberReader.h"
#include "ReOperatorReader.h"
#include "RePunctReader.h"
#include "ReStringReader.h"
#include <regex>

namespace Redneck
{
	list<Reader*> Lexer::_readers = CreateReaders();

	list<Reader*> Lexer::CreateReaders()
	{
		list<Reader*> readers;
		readers.push_back(new IdentifierReader());
		readers.push_back(new NumberReader());
		readers.push_back(new OperatorReader());
		readers.push_back(new PunctReader());
		readers.push_back(new StringReader());
		return readers;
	}

	Lexer::Lexer(const string& path)
	{
		_inputStream = InputStream(path);
		_currentToken = Step();
	}

	Lexer::~Lexer()
	{
	}

	Token Lexer::Peek()
	{
		return _currentToken;
	}

	Token Lexer::Next()
	{
		Token token = Token(_currentToken.GetTokenType(), _currentToken.GetValue());
		_currentToken = Step();
		return token;
	}

	void Lexer::Consume(TokenType tokenType)
	{
		if (_currentToken.GetTokenType() != tokenType)
		{

		}
		_currentToken = Step();
	}

	bool Lexer::Eof()
	{
		Token token = Peek();
		return token.GetTokenType() == TokenType::TOKEN_NULL;
	}

	void Lexer::Skip()
	{
		while (!_inputStream.Eof() && IsWhitespace(_inputStream.Peek()))
		{
			_inputStream.Ignore();
		}
	}

	//Token Lexer::ReadNumber()
	//{
	//	string value;
	//	while (!_inputStream->Eof() && !IsDelimiter(_inputStream->Peek()))
	//	{
	//		value += _inputStream->Get();
	//	}
	//	return Token(TOKEN_INT, value);
	//}

	//Token Lexer::ReadString()
	//{
	//	string value;
	//	_inputStream->Ignore();
	//	while (!_inputStream->Eof() && _inputStream->Peek() != '"')
	//	{
	//		value += _inputStream->Get();
	//	}
	//	_inputStream->Ignore();
	//	return Token(TOKEN_STRING, value);
	//}

	//Token Lexer::ReadIdentifier()
	//{
	//	string value;
	//	while (!_inputStream->Eof() && !IsDelimiter(_inputStream->Peek()))
	//	{
	//		value += _inputStream->Get();
	//	}
	//	return Token(TOKEN_IDENTIFIER, value);
	//}

	//Token Lexer::ReadPunct()
	//{
	//	string value = string(1, _inputStream->Get());

	//	if (value == ",")
	//	{
	//		return Token(TOKEN_COMMA, value);
	//	}
	//	if (value == ";")
	//	{
	//		return Token(TOKEN_SEMI, value);
	//	}
	//	if (value == "(")
	//	{
	//		return Token(TOKEN_LPAREN, value);
	//	}
	//	if (value == ")")
	//	{
	//		return Token(TOKEN_RPAREN, value);
	//	}
	//	if (value == "{")
	//	{
	//		return Token(TOKEN_LBRACE, value);
	//	}
	//	if (value == "}")
	//	{
	//		return Token(TOKEN_RBRACE, value);
	//	}
	//}

	//Token Lexer::ReadOperators()
	//{
	//	string value = string(1, _inputStream->Get());
	//	if (value == "+")
	//	{
	//		return Token(TOKEN_PLUS, value);
	//	}
	//	if (value == "-")
	//	{
	//		return Token(TOKEN_MINUS, value);
	//	}
	//	if (value == "*")
	//	{
	//		return Token(TOKEN_MULT, value);
	//	}
	//	if (value == "/")
	//	{
	//		return Token(TOKEN_DIV, value);
	//	}
	//	if (value == "=")
	//	{
	//		return Token(TOKEN_EQUAL, value);
	//	}
	//}

	//bool Lexer::IsDelimiter(char c)
	//{
	//	if (IsOperator(c) || IsWhitespace(c))
	//	{
	//		return true;
	//	}
	//	return false;
	//}

	//bool Lexer::IsPunct(char c)
	//{
	//	return regex_match(string(1, c), regex("( |\\,|\\;|\\()|\\)|\\{|\\}"));
	//}

	bool Lexer::IsWhitespace(char c)
	{
		return regex_match(string(1, c), regex("( |\\n|\\r|\\t)"));
	}

	//bool Lexer::IsOperator(char c)
	//{
	//	return regex_match(string(1, c), regex("( |\\+|\\-|\\*|\\/|\\%|\\^)"));
	//}

	Token Lexer::Step()
	{
		Skip();

		if (_inputStream.Eof())
		{
			return Token(TOKEN_NULL);
		}

		char peek = _inputStream.Peek();

		for (Reader* reader : _readers)
		{
			if (reader->IsReadable(string(1, peek)))
			{
				return reader->Read(_inputStream);
			}
		}
		//if (peek == '"')
		//{
		//	return ReadString();
		//}
		//if (isdigit(peek))
		//{
		//	return ReadNumber();
		//}
		//if (isalpha(peek))
		//{
		//	return ReadIdentifier();
		//}
		//if (IsPunct(peek))
		//{
		//	return ReadPunct();
		//}
		//if (IsOperator(peek))
		//{
		//	return ReadOperators();
		//}
	}
}