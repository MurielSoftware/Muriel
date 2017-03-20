#pragma once

#include "ReTokenType.h"

namespace Redneck
{
	class Token
	{
	private:
		TokenType _tokenType;
		string _value;
	public:
		Token();
		Token(TokenType tokenType);
		Token(TokenType tokenType, const string& value );
		virtual ~Token();

		inline TokenType GetTokenType() { return _tokenType; }
		inline const string& GetValue() const { return _value; }
	};
}