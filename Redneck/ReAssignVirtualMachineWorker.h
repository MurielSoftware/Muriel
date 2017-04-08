#pragma once

#include "ReVirtualMachineWorker.h"

namespace Redneck
{
	class AssignVirtualMachineWorker : public VirtualMachineWorker
	{
	public:
		unsigned ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction, unsigned instructionIndex);
	};
}