#pragma once

#include "ReVirtualMachineWorker.h"

namespace Redneck
{
	class PushVirtualMachineWorker : public VirtualMachineWorker
	{
	public:
		void ProcessInstruction(stack<DataType*>& stack, Memory& memory, Instruction* instruction);
	};
}