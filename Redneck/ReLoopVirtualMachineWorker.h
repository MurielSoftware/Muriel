#pragma once

#include "ReVirtualMachineWorker.h"
#include "ReByteCode.h"

namespace Redneck
{
	class LoopVirtualMachineWorker : public VirtualMachineWorker
	{
	protected:
		unsigned JumpToInstruction(VirtualMachine* virtualMachine, unsigned instructionIndex, const string& value);
	public:
		unsigned ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction, unsigned instructionIndex);
	};
}