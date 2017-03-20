#pragma once

#include "ReVirtualMachineWorker.h"

namespace Redneck
{
	class DivVirtualMachineWorker : public VirtualMachineWorker
	{
	public:
		void ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction);
	};
}