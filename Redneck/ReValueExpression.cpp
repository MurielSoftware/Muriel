#include "stdafx.h"
#include "ReValueExpression.h"
#include "ReKeywords.h"
#include "ReDataType.h"

namespace Redneck
{
	ValueExpression::ValueExpression()
	{

	}

	ValueExpression::ValueExpression(const string& value)
		: Expression(value)
	{
	}

	ValueExpression::~ValueExpression()
	{

	}
}