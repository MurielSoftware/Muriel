#include "stdafx.h"
#include "ReVirtualMachine.h"
#include "ReInstruction.h"
#include "RePushVirtualMachineWorker.h"
#include "ReArithmeticOperatorVirtualMachineWorker.h"
#include "ReVarVirtualMachineWorker.h"
#include "ReAssignVirtualMachineWorker.h"
#include "ReCompareVirtualMachineWorker.h"
#include "ReJumpVirtualMachineWorker.h"
#include "ReLoadVirtualMachineWorker.h"
#include "ReSkipVirtualMachineWorker.h"
#include "ReLoopVirtualMachineWorker.h"

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
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::EQUALS, new CompareVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::NEQUALS, new CompareVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::GRT, new CompareVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::GRTE, new CompareVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::LS, new CompareVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::LSE, new CompareVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::PUSH, new PushVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::LOAD, new LoadVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::VAR, new VarVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::ASN, new AssignVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::JZERO, new JumpVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::LOOP, new LoopVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::END, new SkipVirtualMachineWorker()));
		map.insert(pair<ByteCode, VirtualMachineWorker*>(ByteCode::SKIP, new SkipVirtualMachineWorker()));
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

		//for (unsigned i = 0; i < _instructions.size(); i++)
		//{
		//	i = _virtualMachineWorkers[_instructions[i]->GetByteCode()]->ProcessInstruction(this, _instructions[i], i);
		//}

		_memory.Clear();
	}
}