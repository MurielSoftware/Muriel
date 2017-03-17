#include "stdafx.h"
#include "ReDeclarationExpression.h"

namespace Redneck
{
	DeclarationExpression::DeclarationExpression()
	{

	}

	DeclarationExpression::DeclarationExpression(Expression* identifier, Expression* declaration)
		: _identifier(identifier), _declaration(declaration)
	{

	}

	DeclarationExpression::~DeclarationExpression()
	{

	}
}