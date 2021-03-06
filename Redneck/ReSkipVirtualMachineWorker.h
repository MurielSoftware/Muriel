#pragma once

#include "ReVirtualMachineWorker.h"

namespace Redneck
{
	class SkipVirtualMachineWorker : public VirtualMachineWorker
	{
	public:
		unsigned ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction, unsigned instructionIndex);
	};
}