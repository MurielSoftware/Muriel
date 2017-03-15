#pragma once

#include "stdafx.h"
#include <vector>

namespace Muriel
{
	class MURIEL_API Game
	{
	private:
	//	AbstractCamera* _camera;
		vector<GameObject*> _gameObjects;
		DirectionalLight* _directionalLight;
		RenderEngine* _renderEngine;
		RenderEngine2D* _renderEngine2D;
	protected:
		//virtual void CreateCamera();

		virtual void Input(Timer* timer);
		virtual void Update(Timer* timer);
		virtual void Render(Timer* timer);
	public:
		Game();
		virtual ~Game();

		virtual void Init();
		virtual void AddGameObject(GameObject* gameObject);
		virtual void ProccessFrame(Timer* timer);
	};
}