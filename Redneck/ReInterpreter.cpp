#include "stdafx.h"
#include "ReInterpreter.h"
#include "ReInstructionGenerator.h"
#include "ReParser.h"
#include "ReInputStream.h"
#include "ReExpression.h"
#include "ReVirtualMachine.h"

namespace Redneck
{
	Interpreter::Interpreter()
	{
		_instructionGenerator = new InstructionGenerator();
		_virtualMachine = new VirtualMachine();
	}

	Interpreter::~Interpreter()
	{
		delete _instructionGenerator;
		delete _virtualMachine;
	}

	void Interpreter::Interpret(const string& path)
	{
		try
		{
			InputStream* inputStream = new InputStream(path);
			Parser* parser = new Parser(*inputStream);
			list<Expression*> expressions = parser->Parse();
			list<Instruction*> instructions = _instructionGenerator->Generate(expressions);
			_virtualMachine->Execute(instructions);
		}
		catch (exception& ex)
		{
			printf("%s", ex.what());
			return;
		}
	}
}