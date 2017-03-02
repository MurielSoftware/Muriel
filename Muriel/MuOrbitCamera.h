#pragma once

#include "MuAbstractCamera.h"

namespace Muriel
{
	class OrbitCamera : public AbstractCamera
	{
	protected:
		void DoRotate(float headingDegrees, float pitchDegrees, float rollDegrees);
		void DoAdditionalEyeUpdateCamera();
	public:
		OrbitCamera() : AbstractCamera()
		{

		}
	};
}