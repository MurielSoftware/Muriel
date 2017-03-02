#pragma once

namespace Muriel
{
	class IRenderer
	{
	public:
		virtual void PreRender(AbstractCamera* camera) = 0;
		virtual void Render() = 0;
		virtual void PostRender() = 0;
	};
}