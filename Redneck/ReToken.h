#pragma once

#include "ReTokenType.h"
#include <string>
#include <sstream>

using namespace std;

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