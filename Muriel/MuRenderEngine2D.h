#pragma once

#include <vector>

namespace Muriel
{
	class RenderEngine2D
	{
	private:
		vector<Renderer*> _renderers;
		AbstractCamera* _camera;

		void Initialize();
	public:
		RenderEngine2D();
		virtual ~RenderEngine2D();

		void RegisterRenderer(Renderer* renderer);

		virtual void Render(Timer* timer);
	};
}