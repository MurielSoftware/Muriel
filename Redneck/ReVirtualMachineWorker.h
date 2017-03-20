#pragma once

#include "ReMemory.h"
#include <stack>

using namespace std;

namespace Redneck
{
	class VirtualMachineWorker
	{
	public:
		VirtualMachineWorker()
		{

		}

		virtual void ProcessInstruction(stack<DataType*>& stack, Memory& memory, Instruction* instruction) = 0;
	};
}