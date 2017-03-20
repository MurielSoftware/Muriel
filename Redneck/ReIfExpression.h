#pragma once

#include "stdafx.h"
#include "ReExpression.h"

namespace Redneck
{
	class IfExpression : public Expression
	{
	private:
		Expression* _condition;
		Expression* _statement;
	public:
		IfExpression();
		IfExpression(Expression* condition, Expression* statement);
		virtual ~IfExpression();

		inline Expression* GetCondition() { return _condition; }
		inline Expression* GetStatement() { return _statement; }
		inline virtual ExpressionType GetExpressionType() { return ExpressionType::EXPRESSION_IF; }
	};
}
