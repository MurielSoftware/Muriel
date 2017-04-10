#include "stdafx.h"
#include "ReLoopVirtualMachineWorker.h"
#include "ReInstruction.h"
#include "ReVirtualMachine.h"
#include "ReBooleanDataType.h"

namespace Redneck
{
	unsigned LoopVirtualMachineWorker::ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction, unsigned instructionIndex)
	{
		//BooleanDataType* condition = (BooleanDataType*)virtualMachine->GetStack().top();

		//if (condition->GetData())
		//{
		//	instructionIndex++;
		//}
		//else
		//{
		//	instructionIndex = JumpToInstruction(virtualMachine, instructionIndex, instruction->GetValue());
		//}
		//return instructionIndex;
		return JumpToInstruction(virtualMachine, instructionIndex, instruction->GetValue());
	}

	unsigned LoopVirtualMachineWorker::JumpToInstruction(VirtualMachine* virtualMachine, unsigned instructionIndex, const string& value)
	{
		while (instructionIndex > 0 && virtualMachine->GetInstructions().at(instructionIndex)->GetValue() != value)
		{
			instructionIndex--;
		}
		return instructionIndex;
	}
}