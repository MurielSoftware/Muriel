#include "stdafx.h"
#include "ReCmpVirtualMachineWorker.h"
#include "ReInstruction.h"
#include "ReVirtualMachine.h"
#include "ReBooleanDataType.h"

namespace Redneck
{
	unsigned CmpVirtualMachineWorker::ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction, unsigned instructionIndex)
	{
		BooleanDataType* condition = (BooleanDataType*)virtualMachine->GetStack().top();

		if (condition->GetData())
		{
			instructionIndex++;
		}
		else
		{
			instructionIndex = JumpToInstruction(virtualMachine, instructionIndex, instruction->GetValue());
		}
		return instructionIndex;
	}

	unsigned CmpVirtualMachineWorker::JumpToInstruction(VirtualMachine* virtualMachine, unsigned instructionIndex, const string& value)
	{
		while (instructionIndex < virtualMachine->GetInstructions().size() && virtualMachine->GetInstructions().at(instructionIndex)->GetValue() != value)
		{
			instructionIndex++;
		}
		return instructionIndex;
	}
}