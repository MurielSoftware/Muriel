#pragma once

#include "ReVirtualMachineWorker.h"

namespace Redneck
{
	class ArithmeticOperatorVirtualMachineWorker : public VirtualMachineWorker
	{
	public:
		unsigned ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction, unsigned instructionIndex);
	};
}