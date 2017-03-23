#include "stdafx.h"
#include "ReCmpVirtualMachineWorker.h"
#include "ReInstruction.h"
#include "ReVirtualMachine.h"
#include "ReBooleanDataType.h"

namespace Redneck
{
	void CmpVirtualMachineWorker::ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction)
	{
		BooleanDataType* condition = (BooleanDataType*)virtualMachine->GetStack().top();
		virtualMachine->GetStack().pop();

		if (condition->GetData())
		{

		}
	}
}