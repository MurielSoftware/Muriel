#pragma once

#include "ReVirtualMachineWorker.h"

namespace Redneck
{
	class MulVirtualMachineWorker : public VirtualMachineWorker
	{
	public:
		void ProcessInstruction(stack<IStackData*>& stack, Instruction* instruction);
	};
}