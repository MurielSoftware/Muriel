#include "stdafx.h"
#include "MuBoundingBox.h"

namespace Muriel
{
	BoundingBox::BoundingBox()
	{
		
	}

	BoundingBox::BoundingBox(Vec3 center, Vec3 halfSize)
	{
		_center = center;
		_halfSize = halfSize;
	}

	BoundingBox::~BoundingBox()
	{

	}
}