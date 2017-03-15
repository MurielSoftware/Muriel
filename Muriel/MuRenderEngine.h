#pragma once

#include <vector>

namespace Muriel
{
	class RenderEngine
	{
	private:
		vector<Renderer*> _renderers;
		AbstractCamera* _camera;
	public:
		RenderEngine();
		virtual ~RenderEngine();

		void Initialize();
		void RegisterRenderer(Renderer* renderer);

		virtual void Update(Timer* timer);
		virtual void Render(Timer* timer);
	};
}