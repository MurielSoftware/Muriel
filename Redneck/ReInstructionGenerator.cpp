#include "stdafx.h"
#include "ReInstructionGenerator.h"
#include "ReExpression.h"
#include "ReInstruction.h"
#include "ReAritmeticOperationExpression.h"
#include "ReDeclarationExpression.h"

namespace Redneck
{
	InstructionGenerator::InstructionGenerator()
	{

	}

	InstructionGenerator::~InstructionGenerator()
	{

	}

	list<Instruction*> InstructionGenerator::Generate(Expression* expression)
	{
		list<Instruction*> instructions;
		DoGenerate(instructions, expression);
		return instructions;
	}

	void InstructionGenerator::DoGenerate(list<Instruction*>& instructions, Expression* expression)
	{
		switch (expression->GetExpressionType())
		{
		case ExpressionType::DECLARATION:
		{
			DeclarationExpression* declarationExpression = (DeclarationExpression*)expression;
			instructions.push_back(new Instruction(ByteCode::VAR, declarationExpression->GetIdentifier()->GetValue()));
			DoGenerate(instructions, declarationExpression->GetDeclaration());
			instructions.push_back(new Instruction(ByteCode::ASN, declarationExpression->GetIdentifier()->GetValue()));
		}
			break;
		case ExpressionType::NUMBER:
		{
			Expression* numExpression = (Expression*)expression;
			instructions.push_back(new Instruction(ByteCode::PUSH, numExpression->GetValue()));
		}
			break;
		case ExpressionType::BIN_OPERATION:
			AritmeticOperationExpression* aritmeticOperationExpression = (AritmeticOperationExpression*)expression;
			DoGenerate(instructions, aritmeticOperationExpression->GetArg0());
			DoGenerate(instructions, aritmeticOperationExpression->GetArg1());
			switch (aritmeticOperationExpression->GetOperator())
			{
			case '+':
				instructions.push_back(new Instruction(ByteCode::ADD));
				break;
			case '-':
				instructions.push_back(new Instruction(ByteCode::SUB));
				break;
			case '*':
				instructions.push_back(new Instruction(ByteCode::MULT));
				break;
			case '/':
				instructions.push_back(new Instruction(ByteCode::DIV));
				break;
			}
			break;
		}
	}
}
