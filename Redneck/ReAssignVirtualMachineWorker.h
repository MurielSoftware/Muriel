#pragma once

#include "ReVirtualMachineWorker.h"

namespace Redneck
{
	class AssignVirtualMachineWorker : public VirtualMachineWorker
	{
	public:
		void ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction);
	};
}