#pragma once

#include "ReExpression.h"

namespace Redneck
{
	class ArgumentExpression : public Expression
	{
	public:
		ArgumentExpression();
		ArgumentExpression(const string& value);
		virtual ~ArgumentExpression();

		inline virtual ExpressionType GetExpressionType() { return ExpressionType::EXPRESSION_ARGUMENT; }
	};
}