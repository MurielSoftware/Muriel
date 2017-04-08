#include "stdafx.h"
#include "ReVirtualMachine.h"
#include "ReInstruction.h"
#include "RePushVirtualMachineWorker.h"
#include "ReArithmeticOperatorVirtualMachineWorker.h"
#include "ReVarVirtualMachineWorker.h"
#include "ReAssignVirtualMachineWorker.h"
#include "ReCmpVirtualMachineWorker.h"
#include "ReBooleanOperatorVirtualMachineWorker.h"
#include "ReLoadVirtualMachineWorker.h"
#include "ReSkipVirtualMachineWorker.h"

namespace Redneck
{
	map<ByteCode, VirtualMachineWorker*> VirtualMachine::_virtualMachineWorkers = CreateVirtualMachineWorkers();

	map<ByteCode, VirtualMachineWorker*> VirtualMachine::CreateVirtualMachineWorkers()
	{
		map<ByteCode, VirtualMachineWorker*> map;
		
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::ADD, new ArithmeticOperatorVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::SUB, new ArithmeticOperatorVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::MULT, new ArithmeticOperatorVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::DIV, new ArithmeticOperatorVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::EQUALS, new BooleanOperatorVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::NEQUALS, new BooleanOperatorVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::GRT, new BooleanOperatorVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::GRTE, new BooleanOperatorVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::LS, new BooleanOperatorVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::LSE, new BooleanOperatorVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::PUSH, new PushVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::LOAD, new LoadVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::VAR, new VarVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::ASN, new AssignVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::JZERO, new CmpVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::END, new SkipVirtualMachineWorker()));
		return map;
	}

	VirtualMachine::VirtualMachine()
	{

	}

	VirtualMachine::~VirtualMachine()
	{

	}

	void VirtualMachine::Execute(vector<Instruction*> instructions)
	{
		_instructions = instructions;
		unsigned instructionIndex = 0;

		while (instructionIndex < _instructions.size())
		{
			Instruction* instruction = _instructions[instructionIndex];
			instructionIndex = _virtualMachineWorkers[instruction->GetByteCode()]->ProcessInstruction(this, instruction, instructionIndex);
		}
		_memory.Clear();
	}
}