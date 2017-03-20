#include "ReInterpreter.h"
#include "ReExpression.h"
using namespace Redneck;

int main()
{
	Interpreter interpreter;
	interpreter.Interpret("scripts/script.txt");
	//interpreter.Interpret(expression);
	return 0;
}