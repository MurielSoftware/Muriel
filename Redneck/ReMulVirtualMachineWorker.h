#pragma once

#include "ReVirtualMachineWorker.h"

namespace Redneck
{
	class MulVirtualMachineWorker : public VirtualMachineWorker
	{
	public:
		void ProcessInstruction(stack<DataType*>& stack, Memory& memory, Instruction* instruction);
	};
}