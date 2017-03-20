#pragma once

#include "ReVirtualMachineWorker.h"

namespace Redneck
{
	class AddVirtualMachineWorker : public VirtualMachineWorker
	{
	public:
		void ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction);
	};
}