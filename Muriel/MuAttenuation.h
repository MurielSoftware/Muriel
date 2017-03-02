#pragma once

namespace Muriel
{
	class Attenuation
	{
	private:
		float _constant;
		float _linear;
		float _exponent;
	public: 
		Attenuation();
		Attenuation(float constant, float linear, float exponent);
		virtual ~Attenuation();

		inline float GetConstant() { return _constant; }
		inline float GetLinear() { return _linear; }
		inline float GetExponent() { return _exponent; }
	};
}
