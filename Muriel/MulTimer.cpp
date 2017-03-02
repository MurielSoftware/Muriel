#include "stdafx.h"
#include "MuTimer.h"

namespace Muriel
{
	Timer::Timer(float targetFps)
	{
		_frameCount = 0;
		_elapsedGameTime = 0.0f;
		_totalGameTime = 0.0f;
		_frameStarted = false;
		_timeScale = 1.0f;
		_targetFps = targetFps;
		_startFrameTime = high_resolution_clock::now();
		_endFrameTime = high_resolution_clock::now();
	}

	Timer::~Timer()
	{

	}

	void Timer::StartFrame()
	{
		if (!_frameStarted)
		{
			_frameStarted = true;
			_frameCount++;
			_startFrameTime = high_resolution_clock::now();
		}
	}

	void Timer::EndFrame()
	{
		if (_frameStarted)
		{
			_frameStarted = false;
			_endFrameTime = high_resolution_clock::now();
			_elapsedGameTime = duration_cast<duration<float, std::ratio<1, 1>>>(_endFrameTime - _startFrameTime).count();

			if (_elapsedGameTime >= 0.1f)
			{
				_elapsedGameTime = 1.0f / _targetFps;
			}
			_totalGameTime += _elapsedGameTime * _timeScale;
		}
	}
}