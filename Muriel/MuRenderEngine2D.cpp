#include "stdafx.h"
#include "MuRenderEngine2D.h"

namespace Muriel
{
	RenderEngine2D::RenderEngine2D()
	{
		Initialize();
	}

	RenderEngine2D::~RenderEngine2D()
	{
		delete _camera;
		_renderers.clear();
	}

	void RenderEngine2D::Initialize()
	{
	}

	void RenderEngine2D::RegisterRenderer(Renderer* renderer)
	{
		_renderers.push_back(renderer);
	}

	void RenderEngine2D::Render(Timer* timer)
	{

	}
}