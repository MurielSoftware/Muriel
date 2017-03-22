#pragma once

#include "ReExpression.h"

namespace Redneck
{
	class WhileExpression : public Expression
	{
	private:
		Expression* _condition;
		Expression* _statement;
	public:
		WhileExpression();
		WhileExpression(Expression* condition, Expression* statement);
		virtual ~WhileExpression();

		inline Expression* GetCondition() { return _condition; }
		inline Expression* GetStatement() { return _statement; }
		inline virtual ExpressionType GetExpressionType() { return ExpressionType::EXPRESSION_WHILE; }
	};
}
