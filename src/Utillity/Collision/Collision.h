#pragma once
#include "cinder/Vector.h"


namespace Collision
{
	// Cube��Cube�̓����蔻��
	bool IsHitCubeToCube(const ci::Vec3f& pos1,
		const ci::Vec3f& size1,
		const ci::Vec3f& pos2,
		const ci::Vec3f& size2);

	bool IsHitSphereToSphere(const ci::Vec3f &pos1,
		const float &radius1,
		const ci::Vec3f &pos2,
		const float &radius2);
}