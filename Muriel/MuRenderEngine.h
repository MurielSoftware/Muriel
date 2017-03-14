#pragma once

namespace Muriel
{
	class RenderEngine
	{
	private:
	public:
		RenderEngine();
		virtual ~RenderEngine();

		virtual void Render();
	};
}