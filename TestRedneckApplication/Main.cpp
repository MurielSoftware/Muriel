#include "ReInterpreter.h"
#include "ReExpression.h"
using namespace Redneck;

int main()
{
	Interpreter interpreter;
	Expression* expression = interpreter.CreateExpressions("2*3+2*3");
	interpreter.Interpret(expression);
	return 0;
}