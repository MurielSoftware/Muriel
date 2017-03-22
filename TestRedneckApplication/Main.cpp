#include "ReInterpreter.h"
#include "ReExpression.h"
using namespace Redneck;

int main()
{
	Interpreter interpreter;
	interpreter.Interpret("script.txt");
	return 0;
}