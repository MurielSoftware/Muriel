#include "stdafx.h"
#include "ReInstructionGenerator.h"
#include "ReExpression.h"
#include "ReInstruction.h"
#include "ReAritmeticOperationExpression.h"
#include "ReIfExpression.h"
#include "ReDeclarationExpression.h"
#include "ReAssociationExpression.h"
#include "ReWhileExpression.h"

namespace Redneck
{
	InstructionGenerator::InstructionGenerator()
	{

	}

	InstructionGenerator::~InstructionGenerator()
	{

	}

	list<Instruction*> InstructionGenerator::Generate(list<Expression*> expressions)
	{
		list<Instruction*> instructions;
		for (Expression* expression : expressions)
		{
			DoGenerate(instructions, expression);
		}
		return instructions;
	}

	void InstructionGenerator::DoGenerate(list<Instruction*>& instructions, Expression* expression)
	{
		switch (expression->GetExpressionType())
		{
		case ExpressionType::EXPRESSION_DECLARATION:
		{
			DeclarationExpression* declarationExpression = (DeclarationExpression*)expression;
			AddInstruction(instructions, ByteCode::VAR, declarationExpression->GetIdentifier()->GetValue());
			DoGenerate(instructions, declarationExpression->GetDeclaration());
			AddInstruction(instructions, ByteCode::ASN, declarationExpression->GetIdentifier()->GetValue());
		}
		break;
		case ExpressionType::EXPRESSION_ASSOCIATION:
		{
			AssociationExpression* associationExpression = (AssociationExpression*)expression;
			DoGenerate(instructions, associationExpression->GetDeclaration());
			AddInstruction(instructions, ByteCode::ASN, associationExpression->GetIdentifier()->GetValue());
		}
		break;
		case ExpressionType::EXPRESSION_NUMBER:
		{
			Expression* numExpression = (Expression*)expression;
			AddInstruction(instructions, ByteCode::PUSH, numExpression->GetValue());
		}
		break;
		case ExpressionType::EXPRESSION_BIN_OPERATION:
		{
			AritmeticOperationExpression* aritmeticOperationExpression = (AritmeticOperationExpression*)expression;
			DoGenerate(instructions, aritmeticOperationExpression->GetArg0());
			DoGenerate(instructions, aritmeticOperationExpression->GetArg1());

			if (aritmeticOperationExpression->GetOperator() == "+")
			{
				AddInstruction(instructions, ByteCode::ADD, "");
			}
			if (aritmeticOperationExpression->GetOperator() == "-")
			{
				AddInstruction(instructions, ByteCode::SUB, "");
			}
			if (aritmeticOperationExpression->GetOperator() == "*")
			{
				AddInstruction(instructions, ByteCode::MULT, "");
			}
			if (aritmeticOperationExpression->GetOperator() == "/")
			{
				AddInstruction(instructions, ByteCode::DIV, "");
			}
			if (aritmeticOperationExpression->GetOperator() == "==")
			{
				AddInstruction(instructions, ByteCode::CMP, "");
			}
		}
		break;
		case ExpressionType::EXPRESSION_IF:
		{
			IfExpression* ifExpression = (IfExpression*)expression;
			DoGenerate(instructions, ifExpression->GetCondition());
			AddInstruction(instructions, ByteCode::CMP, "");
			DoGenerate(instructions, ifExpression->GetStatement());
			AddInstruction(instructions, ByteCode::END, "");
		}
		break;
		case ExpressionType::EXPRESSION_WHILE:
		{
			WhileExpression* whileExpression = (WhileExpression*)expression;
			AddInstruction(instructions, ByteCode::LOOP, "loop1");
			DoGenerate(instructions, whileExpression->GetCondition());
			AddInstruction(instructions, ByteCode::CMP, "");
			DoGenerate(instructions, whileExpression->GetStatement());
			AddInstruction(instructions, ByteCode::JUMP, "loop1");
		}
		break;
		}
	}

	void InstructionGenerator::AddInstruction(list<Instruction*>& instructions, ByteCode byteCode, const string& value)
	{
		static unsigned short address = 0;
		instructions.push_back(new Instruction(byteCode, value, address++));
	}
}
