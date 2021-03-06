#pragma once

#include "ReToken.h"
#include "ReReader.h"

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
		bool IsWhitespace(string str);
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