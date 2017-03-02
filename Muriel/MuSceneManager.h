#pragma once

#include "MuSingleton.h"

namespace Muriel
{
	class SceneManager : public Singleton<SceneManager>
	{
	public:
		void Render();
	};
}