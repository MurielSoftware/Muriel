#pragma once

#include "ReVirtualMachineWorker.h"

namespace Redneck
{
	class PushVirtualMachineWorker : public VirtualMachineWorker
	{
	public:
		void ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction);
	};
}