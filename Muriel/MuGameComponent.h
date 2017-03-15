#pragma once

#include "stdafx.h"
#include "MuGameObject.h"

namespace Muriel
{
	enum GameComponentType
	{
		RENDER,
		RENDER_2D
	};

	class GameComponent
	{
	private:
		GameObject* _owner;
		GameComponentType _gameComponentType;
	public:
		GameComponent(GameObject* owner, GameComponentType gameComponentType);
		virtual ~GameComponent();

		inline GameObject* GetOwner() { return _owner; }
		inline Transform& GetTransform() { return _owner->GetTransform(); }
		inline GameComponentType& GetGameComponentType() { return _gameComponentType; }
	};
}