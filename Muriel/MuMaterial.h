#pragma once

#include "stdafx.h"

namespace Muriel
{
	class Material
	{
	protected:
		Shader* _shader;
	public:
		Material(Shader* shader);
		virtual ~Material();

		inline Shader* GetShader() { return _shader; }

		void Start();
		void End();

		virtual void SetUniforms(AbstractCamera* camera) = 0;
		virtual void SetUniforms(GameObject* gameObject) = 0;
	};
}
