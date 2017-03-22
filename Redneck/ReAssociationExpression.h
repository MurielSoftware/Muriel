#pragma once

#include "ReExpression.h"

namespace Redneck
{
	class AssociationExpression : public Expression
	{
	private:
		Expression* _identifier;
		Expression* _declaration;
	public:
		AssociationExpression();
		AssociationExpression(Expression* identifier, Expression* declaration);
		virtual ~AssociationExpression();

		inline Expression* GetIdentifier() { return _identifier; }
		inline Expression* GetDeclaration() { return _declaration; }
		inline virtual ExpressionType GetExpressionType() { return ExpressionType::EXPRESSION_ASSOCIATION; }
	};
}
