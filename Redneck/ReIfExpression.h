#pragma once

#include "ReExpression.h"

namespace Redneck
{
	class IfExpression : public Expression
	{
	private:
		Expression* _condition;
		list<Expression*> _statements;
	public:
		IfExpression();
		IfExpression(Expression* condition, list<Expression*>& statements);
		virtual ~IfExpression();

		inline Expression* GetCondition() { return _condition; }
		inline list<Expression*>& GetStatements() { return _statements; }
		inline virtual ExpressionType GetExpressionType() { return ExpressionType::EXPRESSION_IF; }
	};
}
