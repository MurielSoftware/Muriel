#pragma once

#include "ReVirtualMachineWorker.h"

namespace Redneck
{
	class MulVirtualMachineWorker : public VirtualMachineWorker
	{
	public:
		void ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction);
	};
}