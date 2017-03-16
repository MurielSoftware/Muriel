#include "stdafx.h"
#include "ReNumExpression.h"
#include "ReStackVisitor.h"

namespace Redneck
{
	NumExpression::NumExpression()
	{
	}

	NumExpression::NumExpression(const int value)
	{
		_value = value;
	}

	NumExpression::~NumExpression()
	{
	}

	void NumExpression::Accept(StackVisitor& stackVisitor)
	{
		stackVisitor.Visit(*this);
	}
}
