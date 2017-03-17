#pragma once

#include "ReVirtualMachineWorker.h"

namespace Redneck
{
	class SubVirtualMachineWorker : public VirtualMachineWorker
	{
	public:
		void ProcessInstruction(stack<IStackData*>& stack, Instruction* instruction);
	};
}