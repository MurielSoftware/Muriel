#pragma once

#include "MuBaseMaterial.h"
#include "Color.h"

using namespace Glml;

namespace Muriel
{
	class ColorMaterial : public BaseMaterial
	{
	private:
		Color _color;
	protected:
		unsigned _colorId;
	public:
		ColorMaterial(Shader* shader, const Color& color);
		virtual ~ColorMaterial();

		virtual void SetUniforms(AbstractCamera* camera);
		virtual void SetUniforms(GameObject* gameObject);
	};
}