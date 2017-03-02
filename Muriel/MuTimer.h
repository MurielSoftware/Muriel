#pragma once

#include <chrono>

using namespace std::chrono;

namespace Muriel
{
	class Timer
	{
	private:
		int _frameCount;
		float _elapsedGameTime;
		float _totalGameTime;
		float _timeScale;
		float _targetFps;
		bool _frameStarted;
		high_resolution_clock::time_point _startFrameTime;
		high_resolution_clock::time_point _endFrameTime;
	public:
		Timer(float targetFps = 60.0f);
		virtual ~Timer();

		inline float GetFps() const { return 1.0f / _elapsedGameTime; }
		inline float GetAverageFps() const { return _frameCount / _totalGameTime; }
		inline int GetFrameCount() const { return _frameCount; }
		float GetElapsedTime() const { return _elapsedGameTime * _timeScale; }
		float GetTimeScale() const { return _timeScale; }
		void SetTimeScale(const float timeScale) { _timeScale = timeScale; }

		void StartFrame();
		void EndFrame();
	};
}