#pragma once

namespace Redneck
{
	enum ByteCode
	{
	//	NOP,
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
		LSE
	};
}
