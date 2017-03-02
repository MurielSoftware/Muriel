#pragma once

#include "MuAbstractCamera.h"

namespace Muriel
{
	class FirstPersonCamera : public AbstractCamera
	{
	protected:
		void DoRotate(float headingDegrees, float pitchDegrees, float rollDegrees);
		void DoAdditionalEyeUpdateCamera();
	};
}