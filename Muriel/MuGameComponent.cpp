#include "stdafx.h"
#include "MuGameComponent.h"

namespace Muriel
{
	GameComponent::GameComponent(GameObject* owner, GameComponentType gameComponentType)
	{
		_owner = owner;
		_gameComponentType = gameComponentType;
	}

	GameComponent::~GameComponent()
	{

	}
}