#pragma once

#include "stdafx.h"
#include "ByteCodeId.h"

namespace Redneck
{
	class Expression
	{
	private:
	public:
		Expression();
		virtual ~Expression();

		virtual void Accept(StackVisitor& stackVisitor) = 0;
		virtual ByteCodeId GetByteCodeId() = 0;
	};
}
