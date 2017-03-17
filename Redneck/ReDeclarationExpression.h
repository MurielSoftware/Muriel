#pragma once

#include "stdafx.h"
#include "ReExpression.h"

namespace Redneck
{
	class DeclarationExpression : public Expression
	{
	private:
		Expression* _identifier;
		Expression* _declaration;
	public:
		DeclarationExpression();
		DeclarationExpression(Expression* identifier, Expression* declaration);
		virtual ~DeclarationExpression();

		inline Expression* GetIdentifier() { return _identifier; }
		inline Expression* GetDeclaration() { return _declaration; }
		inline virtual ExpressionType GetExpressionType() { return ExpressionType::DECLARATION; }
	};
}
