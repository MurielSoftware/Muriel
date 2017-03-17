#include "ReInterpreter.h"
#include "ReExpression.h"
using namespace Redneck;

int main()
{
	Interpreter interpreter;
	interpreter.Interpret("2*3+2*3");
	//interpreter.Interpret(expression);
	return 0;
}