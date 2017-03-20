#pragma once

#include "ReVirtualMachineWorker.h"

namespace Redneck
{
	class CmpVirtualMachineWorker : public VirtualMachineWorker
	{
	public:
		void ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction);
	};
}