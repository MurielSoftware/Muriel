#pragma once

#include "stdafx.h"
#include "MuIRenderer.h"

namespace Muriel
{
	class MeshRenderer : public IRenderer
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