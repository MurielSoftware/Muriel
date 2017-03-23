#pragma once

#include "ReVirtualMachineWorker.h"

namespace Redneck
{
	class LoadVirtualMachineWorker : public VirtualMachineWorker
	{
	public:
		void ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction);
	};
}