#pragma once

#include "ReVirtualMachineWorker.h"

namespace Redneck
{
	class DivVirtualMachineWorker : public VirtualMachineWorker
	{
	public:
		void ProcessInstruction(stack<IStackData*>& stack, Instruction* instruction);
	};
}