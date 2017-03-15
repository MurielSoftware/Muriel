#pragma once

#include "MuGameComponent.h"

namespace Muriel
{
	class Renderer : public GameComponent
	{
	public:
		Renderer(GameObject* gameObject, GameComponentType gameObjectType)
			: GameComponent(gameObject, gameObjectType)
		{

		}

		virtual void PreRender(AbstractCamera* camera) = 0;
		virtual void Render() = 0;
		virtual void PostRender() = 0;
	};
}