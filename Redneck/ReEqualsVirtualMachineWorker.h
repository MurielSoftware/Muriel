#pragma once

#include "ReVirtualMachineWorker.h"

namespace Redneck
{
	class EqualsVirtualMachineWorker : public VirtualMachineWorker
	{
	public:
		void ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction);
	};
}