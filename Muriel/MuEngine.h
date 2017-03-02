#pragma once

#include "stdafx.h"

namespace Muriel
{
	class MURIEL_API Engine
	{
	private:
		bool _isRunning;
		Window* _window;
		Game* _game;
		Timer* _timer;
	public:
		Engine();
		virtual ~Engine();

		void Start();
		void Stop();
		void Run();
		void Destroy();
	};
}
