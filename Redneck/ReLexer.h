#pragma once

#include "stdafx.h"
#include "ReToken.h"
#include <string>
#include <list>
#include "ReReader.h"
using namespace std;

namespace Redneck
{
	class Lexer
	{
	private:
		static list<Reader*> _readers;

		InputStream _inputStream;
		Token _currentToken;

		static list<Reader*> CreateReaders();

		void Skip();

		//bool IsDelimiter(char c);
		//bool IsPunct(char c);
		bool IsWhitespace(char c);
		//bool IsOperator(char c);

		Token Step();
	public:
		Lexer(const InputStream& inputStream);
		virtual ~Lexer();

		Token Peek();
		Token Next();
		void Consume(TokenType tokenType);
		bool Eof();
	};
}