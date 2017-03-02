#pragma once

#include "stdafx.h"

namespace Muriel
{
	class MURIEL_API Object
	{
	private:
		string _name;
	public:
		Object(const string& name);
		virtual ~Object();

		inline string GetName() const { return _name; }
		inline void SetName(const string& name) { _name = name; }
	};
}