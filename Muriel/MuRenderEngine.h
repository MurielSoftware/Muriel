#pragma once

#include <vector>

namespace Muriel
{
	class RenderEngine
	{
	private:
		vector<Renderer*> _renderers;
		AbstractCamera* _camera;

		void Initialize();
	public:
		RenderEngine();
		virtual ~RenderEngine();

		void RegisterRenderer(Renderer* renderer);
		void ClearBuffers();
		void SwapBuffers();

		virtual void Update(Timer* timer);
		virtual void Render(Timer* timer);
	};
}