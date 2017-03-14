#pragma once

namespace Muriel
{
	class RenderEngine2D
	{
	private:
	public:
		RenderEngine2D();
		virtual ~RenderEngine2D();

		virtual void Render();
	};
}