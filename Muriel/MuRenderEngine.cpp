#include "stdafx.h"
#include "MuRenderEngine.h"
#include "MuRenderer.h"
#include "MuAbstractCamera.h"
#include "MuOrbitCamera.h"
#include "MuGL.h"

namespace Muriel
{
	RenderEngine::RenderEngine()
	{
		Initialize();
	}

	RenderEngine::~RenderEngine()
	{
		delete _camera;
		_renderers.clear();
	}

	void RenderEngine::Initialize()
	{
		_camera = new OrbitCamera();
		_camera->Perspective(90.0f, 1.3f, 0.1f, 1000.0f);
	}

	void RenderEngine::RegisterRenderer(Renderer* renderer)
	{
		_renderers.push_back(renderer);
	}

	void RenderEngine::ClearBuffers()
	{
		GL::ClearBuffers(true, true, false);
	}

	void RenderEngine::Update(Timer* timer)
	{
		_camera->UpdateCamera();
	}

	void RenderEngine::Render(Timer* timer)
	{
		for (Renderer* renderer : _renderers)
		{
			renderer->PreRender(_camera);
			renderer->Render();
			renderer->PostRender();
		}
	}
}