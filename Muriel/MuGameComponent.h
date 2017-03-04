#pragma once

#include "stdafx.h"
#include "MuGameObject.h"

namespace Muriel
{
	class GameComponent
	{
	private:
		GameObject* _owner;
	public:
		GameComponent(GameObject* owner);
		virtual ~GameComponent();

		inline GameObject* GetOwner() { return _owner; }
		inline Transform& GetTransform() { return _owner->GetTransform(); }
	};
}