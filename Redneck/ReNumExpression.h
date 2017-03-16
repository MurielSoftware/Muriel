#pragma once

#include "ReExpression.h"

namespace Redneck
{
	class NumExpression : public Expression
	{
	private:
		int _value;
	public:
		NumExpression();
		NumExpression(const int value);
		virtual ~NumExpression();

		inline int GetValue() { return _value; }
		inline ByteCodeId GetByteCodeId() { return ByteCodeId::NUMEXP; }
		
		void Accept(StackVisitor& stackVisitor);
	};
}
