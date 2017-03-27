#pragma once

#include "ReVirtualMachineWorker.h"

namespace Redneck
{
	class SkipVirtualMachineWorker : public VirtualMachineWorker
	{
	public:
		void ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction);
	};
}