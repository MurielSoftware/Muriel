#pragma once

#include "ReExpression.h"

namespace Redneck
{
	class IdentifierExpression : public Expression
	{
	public:
		IdentifierExpression();
		IdentifierExpression(const string& value);
		virtual ~IdentifierExpression();

		inline virtual ExpressionType GetExpressionType() { return ExpressionType::EXPRESSION_IDENTIFIER; }
	};
}
