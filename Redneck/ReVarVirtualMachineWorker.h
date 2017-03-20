#pragma once

#include "ReVirtualMachineWorker.h"

namespace Redneck
{
	class VarVirtualMachineWorker : public VirtualMachineWorker
	{
	public:
		void ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction);
	};
}