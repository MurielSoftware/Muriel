#pragma once

#include "ReInputStream.h"

namespace Redneck
{
	class Parser
	{
	private:
		Lexer* _lexer;

		Expression* Statement();
		Expression* Args();
		Expression* Expr();
		Expression* Term();
		Expression* Factor();

		Expression* DefineVariable();
		Expression* DefineIf();
	public:
		Parser(const InputStream& inputStream);
		virtual ~Parser();

		list<Expression*>& Parse();
	};
}