#include "stdafx.h"
#include "ReAssociationExpression.h"

namespace Redneck
{
	AssociationExpression::AssociationExpression()
	{

	}

	AssociationExpression::AssociationExpression(Expression* identifier, Expression* declaration)
		: _identifier(identifier), _declaration(declaration)
	{

	}

	AssociationExpression::~AssociationExpression()
	{
		delete _identifier;
		delete _declaration;
	}
}