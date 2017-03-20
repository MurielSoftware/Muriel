#pragma once

#include "ReVirtualMachineWorker.h"

namespace Redneck
{
	class SubVirtualMachineWorker : public VirtualMachineWorker
	{
	public:
		void ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction);
	};
}