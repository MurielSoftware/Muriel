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
		list<Expression*> _statements;
	public:
		FunctionExpression();
		FunctionExpression(Expression* identifier, list<ArgumentExpression*>& arguments, list<Expression*>& statements);
		virtual ~FunctionExpression();

		inline Expression* GetIdentifier() { return _identifier; }
		inline list<ArgumentExpression*>& GetArguments() { return _arguments; }
		inline list<Expression*>& GetStatements() { return _statements; }
		inline ExpressionType GetExpressionType() { return ExpressionType::EXPRESSION_FUNCTION; }
	};
}