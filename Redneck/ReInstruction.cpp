#include "stdafx.h"
#include "ReInstruction.h"

namespace Redneck
{
	Instruction::Instruction()
	{

	}

	Instruction::Instruction(ByteCode byteCode)
		: _byteCode(byteCode)
	{

	}

	Instruction::Instruction(ByteCode byteCode, const string& value)
		: _byteCode(byteCode), _value(value)
	{

	}

	Instruction::~Instruction()
	{

	}
}