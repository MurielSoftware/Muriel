#include "stdafx.h"
#include "MuObject.h"

namespace Muriel
{
	Object::Object()
	{

	}

	Object::Object(const string& name)
	{
		_name = name;
	}

	Object::~Object()
	{
	}
}