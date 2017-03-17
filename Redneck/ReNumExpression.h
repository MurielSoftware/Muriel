#pragma once

#include "stdafx.h"
#include "ReExpression.h"

namespace Redneck
{
	class NumExpression : public Expression
	{
	public:
		NumExpression();
		NumExpression(const string& value);
		virtual ~NumExpression();

		inline virtual ExpressionType GetExpressionType() { return ExpressionType::NUMBER; }
	};
}
