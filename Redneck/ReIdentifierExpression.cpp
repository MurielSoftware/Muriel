#include "stdafx.h"
#include "ReIdentifierExpression.h"

namespace Redneck
{
	IdentifierExpression::IdentifierExpression()
	{

	}

	IdentifierExpression::IdentifierExpression(const string& value)
		: Expression(value)
	{

	}

	IdentifierExpression::~IdentifierExpression()
	{

	}
}