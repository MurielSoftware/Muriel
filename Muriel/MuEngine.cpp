#include "stdafx.h"
#include "MuEngine.h"
#include "MuWindow.h"
#include "MuGame.h"
#include "MuTimer.h"
#include <iostream>

namespace Muriel
{
	Engine::Engine()
	{
		_isRunning = false;
	}

	Engine::~Engine()
	{

	}

	void Engine::Start()
	{
		if (_isRunning)
		{
			return;
		}
		_timer = GetTimer();
		_window = GetWindow();
		_game = GetGame();
		
		Run();
	}

	Game* Engine::GetGame()
	{
		return new Game();
	}

	Window* Engine::GetWindow()
	{
		return new Window("test");
	}

	Timer* Engine::GetTimer()
	{
		return new Timer();
	}

	void Engine::Stop()
	{
		if (!_isRunning)
		{
			return;
		}
		_isRunning = false;
	}

	void Engine::Run()
	{
		_isRunning = true;

		while (_isRunning)
		{
			if (_window->IsCloseRequested())
			{
				Stop();
			}
			else
			{
				_timer->StartFrame();
				_game->ProccessFrame(_timer);
				_timer->EndFrame();
			}
		}
		Destroy();
	}

	void Engine::Destroy()
	{
		delete _window;
		delete _game;
		delete _timer;
	}
}