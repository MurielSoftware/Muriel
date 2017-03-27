#pragma once

#include "ReExpression.h"
#include "ReDataType.h"

namespace Redneck
{
	class ValueExpression : public Expression
	{
	public:
		ValueExpression();
		ValueExpression(const string& value);
		virtual ~ValueExpression();

		inline virtual ExpressionType GetExpressionType() { return ExpressionType::EXPRESSION_VALUE; }
	};
}
