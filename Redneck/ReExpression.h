#pragma once

#include "ReExpressionType.h"

namespace Redneck
{
	class Expression
	{
	private:
		string _value;
	public:
		Expression();
		Expression(const string& value);
		virtual ~Expression();

		inline virtual const string& GetValue() const { return _value; }

		inline virtual ExpressionType GetExpressionType() = 0;
	};
}
