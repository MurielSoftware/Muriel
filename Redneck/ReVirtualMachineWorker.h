#pragma once

#include "ReStackData.h"
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

		virtual void ProcessInstruction(stack<IStackData*>& stack, Instruction* instruction) = 0;
	};
}