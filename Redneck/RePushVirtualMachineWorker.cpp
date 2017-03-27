#include "stdafx.h"
#include "RePushVirtualMachineWorker.h"
#include "ReInstruction.h"
#include "ReIntDataType.h"
#include "ReFloatDataType.h"
#include "ReBooleanDataType.h"
#include "ReStringDataType.h"
#include "ReVirtualMachine.h"

#include <regex>

namespace Redneck
{
	void PushVirtualMachineWorker::ProcessInstruction(VirtualMachine* virtualMachine, Instruction* instruction)
	{
		virtualMachine->GetStack().push(GetDataTypeValue(instruction->GetValue()));
	}

	DataType* PushVirtualMachineWorker::GetDataTypeValue(const string& value)
	{
		if (IsInteger(value))
		{
			return new IntDataType(stoi(value));
		}
		else if (IsFloat(value))
		{
			return new FloatDataType(stof(value));
		}
		else if (IsBoolean(value))
		{
			bool booleanValue = value == "false" ? false : true;
			return new BooleanDataType(booleanValue);
		}
		return new StringDataType(value);
	}

	bool PushVirtualMachineWorker::IsInteger(const string& value)
	{
		return regex_match(value, regex("^(0|[1-9][0-9]*)$"));
	}

	bool PushVirtualMachineWorker::IsFloat(const string& value)
	{
		return regex_match(value, regex("^([0-9][0-9]*.[0-9][0-9]*)$"));
	}

	bool PushVirtualMachineWorker::IsBoolean(const string& value)
	{
		return regex_match(value, regex("(true|false)"));
	}
}