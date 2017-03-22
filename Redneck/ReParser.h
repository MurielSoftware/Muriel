#pragma once

#include "ReCommon.h"
#include "ReArgumentExpression.h"
#include "ReInputStream.h"

namespace Redneck
{
	class Parser
	{
	private:
		Lexer* _lexer;

		Expression* Statement();
		Expression* Expr();
		Expression* Term();
		Expression* Bool();
		Expression* Assignment();
		Expression* Factor();

		Expression* DefineVariable();
		Expression* DefineIf();
		Expression* DefineWhile();
		Expression* DefineAssociation();
		Expression* DefineFunction();
		list<ArgumentExpression*> DefineArgs();
	public:
		Parser(const InputStream& inputStream);
		virtual ~Parser();

		list<Expression*> Parse();
	};
}