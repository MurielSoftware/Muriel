#pragma once

#include "ReExpression.h"

namespace Redneck
{
	class BinaryOperationExpression : public Expression
	{
	private:
		Expression* _arg0;
		Expression* _arg1;
		string _operator;
	public:
		BinaryOperationExpression();
		BinaryOperationExpression(Expression* arg0, Expression* arg1, const string& op);
		virtual ~BinaryOperationExpression();

		inline Expression* GetArg0() { return _arg0; }
		inline Expression* GetArg1() { return _arg1; }
		inline const string& GetOperator() const { return _operator; }
		inline ExpressionType GetExpressionType() { return ExpressionType::EXPRESSION_BIN_OPERATION; }
	};
}