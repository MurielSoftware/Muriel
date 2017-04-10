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

	vector<Instruction*> InstructionGenerator::Generate(list<Expression*> expressions)
	{
		vector<Instruction*> instructions;
		DoGenerateInner(instructions, expressions, 0);
		return instructions;
	}

	void InstructionGenerator::DoGenerateInner(vector<Instruction*>& instructions, list<Expression*> expressions, unsigned depth)
	{
		for (Expression* expression : expressions)
		{
			DoGenerate(instructions, expression, depth);
		}
	}

	void InstructionGenerator::DoGenerate(vector<Instruction*>& instructions, Expression* expression, unsigned depth)
	{
		switch (expression->GetExpressionType())
		{
		case ExpressionType::EXPRESSION_DECLARATION:
			GenerateDeclaration(instructions, expression, depth);
		break;
		case ExpressionType::EXPRESSION_ASSOCIATION:
			GenerateAssociation(instructions, expression, depth);
		break;
		case ExpressionType::EXPRESSION_VALUE:
			GenerateValue(instructions, expression, depth);
		break;
		case ExpressionType::EXPRESSION_IDENTIFIER:
			GenerateIdentifier(instructions, expression, depth);
		break;
		case ExpressionType::EXPRESSION_BIN_OPERATION:
			GenerateBinaryOperation(instructions, expression, depth);
		break;
		case ExpressionType::EXPRESSION_IF:
			GenerateIf(instructions, expression, depth);
		break;
		case ExpressionType::EXPRESSION_WHILE:
			GenerateWhile(instructions, expression, depth);
		break;
		}
	}

	void InstructionGenerator::GenerateDeclaration(vector<Instruction*>& instructions, Expression* expression, unsigned depth)
	{
		DeclarationExpression* declarationExpression = (DeclarationExpression*)expression;
		AddInstruction(instructions, ByteCode::VAR, declarationExpression->GetIdentifier()->GetValue());
		DoGenerate(instructions, declarationExpression->GetDeclaration(), depth);
		AddInstruction(instructions, ByteCode::ASN, declarationExpression->GetIdentifier()->GetValue());
	}

	void InstructionGenerator::GenerateAssociation(vector<Instruction*>& instructions, Expression* expression, unsigned depth)
	{
		AssociationExpression* associationExpression = (AssociationExpression*)expression;
		DoGenerate(instructions, associationExpression->GetDeclaration(), depth);
		AddInstruction(instructions, ByteCode::ASN, associationExpression->GetIdentifier()->GetValue());
	}

	void InstructionGenerator::GenerateValue(vector<Instruction*>& instructions, Expression* expression, unsigned depth)
	{
		ValueExpression* valueExpression = (ValueExpression*)expression;
		AddInstruction(instructions, ByteCode::PUSH, valueExpression->GetValue());
	}

	void InstructionGenerator::GenerateIdentifier(vector<Instruction*>& instructions, Expression* expression, unsigned depth)
	{
		IdentifierExpression* identifierExpression = (IdentifierExpression*)expression;
		AddInstruction(instructions, ByteCode::LOAD, identifierExpression->GetValue());
	}

	void InstructionGenerator::GenerateBinaryOperation(vector<Instruction*>& instructions, Expression* expression, unsigned depth)
	{
		BinaryOperationExpression* binaryOperationExpression = (BinaryOperationExpression*)expression;
		DoGenerate(instructions, binaryOperationExpression->GetArg0(), depth);
		DoGenerate(instructions, binaryOperationExpression->GetArg1(), depth);

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

	void InstructionGenerator::GenerateIf(vector<Instruction*>& instructions, Expression* expression, unsigned depth)
	{
		//IfExpression* ifExpression = (IfExpression*)expression;
		//string jumpAddress = GetJumpAddress("cond", depth++);
		//DoGenerate(instructions, ifExpression->GetCondition(), depth);
		//AddInstruction(instructions, ByteCode::JZERO, jumpAddress);
		//DoGenerateInner(instructions, ifExpression->GetStatements(), depth);
		//AddInstruction(instructions, ByteCode::END, jumpAddress);
	}

	void InstructionGenerator::GenerateWhile(vector<Instruction*>& instructions, Expression* expression, unsigned depth)
	{
		//WhileExpression* whileExpression = (WhileExpression*)expression;
		//string jumpAddress = GetJumpAddress("loop", depth++);
		//AddInstruction(instructions, ByteCode::SKIP, jumpAddress);
		//DoGenerate(instructions, whileExpression->GetCondition(), depth);
		//AddInstruction(instructions, ByteCode::JZERO, EMPTY);
		//DoGenerateInner(instructions, whileExpression->GetStatements(), depth);
		//AddInstruction(instructions, ByteCode::LOOP, jumpAddress);
	}

	void InstructionGenerator::AddInstruction(vector<Instruction*>& instructions, ByteCode byteCode, const string& value)
	{
		instructions.push_back(new Instruction(byteCode, value));
	}

	string InstructionGenerator::GetJumpAddress(const string& name, int depth)
	{
		stringstream sstream;
		sstream << name << depth;
		return sstream.str();
	}
}
