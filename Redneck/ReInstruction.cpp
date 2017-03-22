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

	Instruction::Instruction(ByteCode byteCode, const string& value, unsigned short address)
		: _byteCode(byteCode), _value(value), _address(address)
	{

	}


	Instruction::~Instruction()
	{

	}
}