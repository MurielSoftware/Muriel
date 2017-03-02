#pragma once

#include "stdafx.h"

namespace Muriel
{
	class BaseMaterial
	{
	protected:
		Shader* _shader;
	public:
		BaseMaterial(Shader* shader);
		virtual ~BaseMaterial();

		inline Shader* GetShader() { return _shader; }

		void Start();
		void End();

		virtual void SetUniforms(AbstractCamera* camera) = 0;
		virtual void SetUniforms(GameObject* gameObject) = 0;
	};
}
