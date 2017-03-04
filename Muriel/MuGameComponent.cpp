#include "stdafx.h"
#include "MuGameComponent.h"

namespace Muriel
{
	GameComponent::GameComponent(GameObject* owner)
	{
		_owner = owner;
	}

	GameComponent::~GameComponent()
	{

	}
}