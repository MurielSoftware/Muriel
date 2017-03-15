#pragma once

#include "stdafx.h"
#include "MuRenderer.h"

namespace Muriel
{
	class MeshRenderer : public Renderer
	{
	private:
		GameObject* _gameObject;
		BaseMaterial* _material;
	public:
		MeshRenderer(GameObject* gameObject, BaseMaterial* material);
		virtual ~MeshRenderer();

		void PreRender(AbstractCamera* camera);
		void Render();
		void PostRender();

		void DebugRender();
	};
}