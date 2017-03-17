#pragma once

#include "stdafx.h"
#include "ReTokenType.h"

#include <string>
#include <vector>
using namespace std;

namespace Redneck
{
	class Parser
	{
	private:
		Lexer* _lexer;

		Expression* Statement();
		Expression* Args();
		Expression* Expr();
		Expression* Term();
		Expression* Factor();

		Expression* DefineVariable();
	public:
		Parser();
		virtual ~Parser();

		Expression* Parse();
	};
}