#pragma once

#include <vector>

namespace Muriel
{
	class RenderEngine2D
	{
	private:
		vector<Renderer*> _renderers;
		AbstractCamera* _camera;
	public:
		RenderEngine2D();
		virtual ~RenderEngine2D();

		void Initialize();
		void RegisterRenderer(Renderer* renderer);

		virtual void Render(Timer* timer);
	};
}