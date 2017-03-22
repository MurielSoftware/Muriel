#pragma once

#include "ReExpression.h"
#include "ReCommon.h"
#include "ReArgumentExpression.h"

namespace Redneck
{
	class FunctionExpression : public Expression
	{
	private:
		Expression* _identifier;
		list<ArgumentExpression*> _arguments;
		Expression* _statement;
	public:
		FunctionExpression();
		FunctionExpression(Expression* identifier, list<ArgumentExpression*>& arguments, Expression* statement);
		virtual ~FunctionExpression();

		inline Expression* GetIdentifier() { return _identifier; }
		inline list<ArgumentExpression*>& GetArguments() { return _arguments; }
		inline Expression* GetStatements() { return _statement; }
		inline ExpressionType GetExpressionType() { return ExpressionType::EXPRESSION_FUNCTION; }
	};
}