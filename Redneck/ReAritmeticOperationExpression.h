#pragma once

#include "ReExpression.h"

namespace Redneck
{
	class AritmeticOperationExpression : public Expression
	{
	private:
		Expression* _arg0;
		Expression* _arg1;
		char _operator;
	public:
		AritmeticOperationExpression();
		AritmeticOperationExpression(Expression* arg0, Expression* arg1, char op);
		virtual ~AritmeticOperationExpression();

		inline Expression* GetArg0() { return _arg0; }
		inline Expression* GetArg1() { return _arg1; }
		inline char GetOperator() { return _operator; }
		inline ExpressionType GetExpressionType() { return ExpressionType::EXPRESSION_BIN_OPERATION; }
	};
}