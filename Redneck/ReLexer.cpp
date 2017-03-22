#include "stdafx.h"
#include "ReLexer.h"
#include "ReToken.h"
#include "ReInputStream.h"
#include "ReIdentifierReader.h"
#include "ReNumberReader.h"
#include "ReOperatorReader.h"
#include "RePunctReader.h"
#include "ReStringReader.h"
#include "ReSyntaxException.h"
#include "ReBooleanOperatorReader.h"
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
		readers.push_back(new BooleanOperatorReader());
		return readers;
	}

	Lexer::Lexer(const InputStream& inputStream)
	{
		_inputStream = inputStream;
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
			throw SyntaxException();
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

	bool Lexer::IsWhitespace(string str)
	{
		return regex_match(str, regex("( |\\n|\\r|\\t)"));
	}

	Token Lexer::Step()
	{
		Skip();

		if (_inputStream.Eof())
		{
			return Token(TOKEN_NULL);
		}

		string peek = _inputStream.Peek();

		for (Reader* reader : _readers)
		{
			if (reader->IsReadable(peek))
			{
				return reader->Read(_inputStream);
			}
		}
	}
}