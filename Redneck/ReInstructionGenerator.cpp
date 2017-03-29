#include "stdafx.h"
#include "ReInstructionGenerator.h"
#include "ReExpression.h"
#include "ReInstruction.h"
#include "ReBinaryOperationExpression.h"
#include "ReIfExpression.h"
#include "ReDeclarationExpression.h"
#include "ReAssociationExpression.h"
#include "ReValueExpression.h"
#include "ReIdentifierExpression.h"
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
		DoGenerateInner(instructions, expressions);
		return instructions;
	}

	void InstructionGenerator::DoGenerateInner(list<Instruction*>& instructions, list<Expression*> expressions)
	{
		for (Expression* expression : expressions)
		{
			DoGenerate(instructions, expression);
		}
	}

	void InstructionGenerator::DoGenerate(list<Instruction*>& instructions, Expression* expression)
	{
		switch (expression->GetExpressionType())
		{
		case ExpressionType::EXPRESSION_DECLARATION:
			GenerateDeclaration(instructions, expression);
		break;
		case ExpressionType::EXPRESSION_ASSOCIATION:
			GenerateAssociation(instructions, expression);
		break;
		case ExpressionType::EXPRESSION_VALUE:
			GenerateValue(instructions, expression);
		break;
		case ExpressionType::EXPRESSION_IDENTIFIER:
			GenerateIdentifier(instructions, expression);
		break;
		case ExpressionType::EXPRESSION_BIN_OPERATION:
			GenerateBinaryOperation(instructions, expression);
		break;
		case ExpressionType::EXPRESSION_IF:
			GenerateIf(instructions, expression);
		break;
		case ExpressionType::EXPRESSION_WHILE:
			GenerateWhile(instructions, expression);
		break;
		}
	}

	void InstructionGenerator::GenerateDeclaration(list<Instruction*>& instructions, Expression* expression)
	{
		DeclarationExpression* declarationExpression = (DeclarationExpression*)expression;
		AddInstruction(instructions, ByteCode::VAR, declarationExpression->GetIdentifier()->GetValue());
		DoGenerate(instructions, declarationExpression->GetDeclaration());
		AddInstruction(instructions, ByteCode::ASN, declarationExpression->GetIdentifier()->GetValue());
	}

	void InstructionGenerator::GenerateAssociation(list<Instruction*>& instructions, Expression* expression)
	{
		AssociationExpression* associationExpression = (AssociationExpression*)expression;
		DoGenerate(instructions, associationExpression->GetDeclaration());
		AddInstruction(instructions, ByteCode::ASN, associationExpression->GetIdentifier()->GetValue());
	}

	void InstructionGenerator::GenerateValue(list<Instruction*>& instructions, Expression* expression)
	{
		ValueExpression* valueExpression = (ValueExpression*)expression;
		AddInstruction(instructions, ByteCode::PUSH, valueExpression->GetValue());
	}

	void InstructionGenerator::GenerateIdentifier(list<Instruction*>& instructions, Expression* expression)
	{
		IdentifierExpression* identifierExpression = (IdentifierExpression*)expression;
		AddInstruction(instructions, ByteCode::LOAD, identifierExpression->GetValue());
	}

	void InstructionGenerator::GenerateBinaryOperation(list<Instruction*>& instructions, Expression* expression)
	{
		BinaryOperationExpression* binaryOperationExpression = (BinaryOperationExpression*)expression;
		DoGenerate(instructions, binaryOperationExpression->GetArg0());
		DoGenerate(instructions, binaryOperationExpression->GetArg1());

		if (binaryOperationExpression->GetOperator() == "+")
		{
			AddInstruction(instructions, ByteCode::ADD, EMPTY);
		}
		else if (binaryOperationExpression->GetOperator() == "-")
		{
			AddInstruction(instructions, ByteCode::SUB, EMPTY);
		}
		else if (binaryOperationExpression->GetOperator() == "*")
		{
			AddInstruction(instructions, ByteCode::MULT, EMPTY);
		}
		else if (binaryOperationExpression->GetOperator() == "/")
		{
			AddInstruction(instructions, ByteCode::DIV, EMPTY);
		}
		else if (binaryOperationExpression->GetOperator() == "==")
		{
			AddInstruction(instructions, ByteCode::EQUALS, EMPTY);
		}
		else if (binaryOperationExpression->GetOperator() == "!=")
		{
			AddInstruction(instructions, ByteCode::NEQUALS, EMPTY);
		}
		else if (binaryOperationExpression->GetOperator() == ">")
		{
			AddInstruction(instructions, ByteCode::GRT, EMPTY);
		}
		else if (binaryOperationExpression->GetOperator() == "<")
		{
			AddInstruction(instructions, ByteCode::LS, EMPTY);
		}
		else if (binaryOperationExpression->GetOperator() == ">=")
		{
			AddInstruction(instructions, ByteCode::GRTE, EMPTY);
		}
		else if (binaryOperationExpression->GetOperator() == "<=")
		{
			AddInstruction(instructions, ByteCode::LSE, EMPTY);
		}
	}

	void InstructionGenerator::GenerateIf(list<Instruction*>& instructions, Expression* expression)
	{
		IfExpression* ifExpression = (IfExpression*)expression;
		DoGenerate(instructions, ifExpression->GetCondition());
		AddInstruction(instructions, ByteCode::CMP, EMPTY);
		DoGenerateInner(instructions, ifExpression->GetStatements());
		AddInstruction(instructions, ByteCode::END, EMPTY);
	}

	void InstructionGenerator::GenerateWhile(list<Instruction*>& instructions, Expression* expression)
	{
		WhileExpression* whileExpression = (WhileExpression*)expression;
		AddInstruction(instructions, ByteCode::LOOP, "loop1");
		DoGenerate(instructions, whileExpression->GetCondition());
		AddInstruction(instructions, ByteCode::CMP, EMPTY);
		DoGenerateInner(instructions, whileExpression->GetStatements());
		AddInstruction(instructions, ByteCode::JUMP, "loop1");
	}

	void InstructionGenerator::AddInstruction(list<Instruction*>& instructions, ByteCode byteCode, const string& value, unsigned short address)
	{
		instructions.push_back(new Instruction(byteCode, value, address));
	}
}
