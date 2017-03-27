#pragma once

#include "ReExpression.h"

namespace Redneck
{
	class WhileExpression : public Expression
	{
	private:
		Expression* _condition;
		list<Expression*> _statements;
	public:
		WhileExpression();
		WhileExpression(Expression* condition, list<Expression*>& statements);
		virtual ~WhileExpression();

		inline Expression* GetCondition() { return _condition; }
		inline list<Expression*>& GetStatements() { return _statements; }
		inline virtual ExpressionType GetExpressionType() { return ExpressionType::EXPRESSION_WHILE; }
	};
}
