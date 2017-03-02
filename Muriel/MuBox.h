#pragma once

#include "stdafx.h"
#include "MuGameObject.h"

namespace Muriel
{
	class Box : public GameObject
	{
	private:
		void Init();
	public:
		Box(const string& name);
		~Box();
	};
}