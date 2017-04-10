#pragma once

namespace Redneck
{
	enum ByteCode
	{
		VAR, 
		ASN,  
		PUSH,   
		LOAD,

		ADD,    
		SUB,    
		MULT,   
		DIV,    
		
		IF,
		CMP,
		END,
		LOOP,
		JUMP,
		
		EQUALS,
		NEQUALS,
		GRT,
		LS,
		GRTE,
		LSE,

		JZERO,
		SKIP
	};
}
