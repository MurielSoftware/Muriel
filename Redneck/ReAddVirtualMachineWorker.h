#pragma once

#include "ReVirtualMachineWorker.h"

namespace Redneck
{
	class AddVirtualMachineWorker : public VirtualMachineWorker
	{
	public:
		void ProcessInstruction(stack<IStackData*>& stack, Instruction* instruction);
	};
}