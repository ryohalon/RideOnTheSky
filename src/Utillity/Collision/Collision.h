#pragma once
#include "cinder/Vector.h"


namespace Collision
{
	bool IsHitBlockToBlock(const ci::Vec3f& pos1,
		const ci::Vec3f& size1,
		const ci::Vec3f& pos2,
		const ci::Vec3f& size2);




	bool IsHitTopBlockToBlock(const ci::Vec3f& pos1,
		const ci::Vec3f& size1,
		const ci::Vec3f& pos2,
		const ci::Vec3f& size2);

	bool IsHitDownBlockToBlock(const ci::Vec3f& pos1,
		const ci::Vec3f& size1,
		const ci::Vec3f& pos2,
		const ci::Vec3f& size2);

	bool IsHitLeftBlockToBlock(const ci::Vec3f& pos1,
		const ci::Vec3f& size1,
		const ci::Vec3f& pos2,
		const ci::Vec3f& size2);

	bool IsHitRightBlockToBlock(const ci::Vec3f& pos1,
		const ci::Vec3f& size1,
		const ci::Vec3f& pos2,
		const ci::Vec3f& size2);

	bool IsHitFrontBlockToBlock(const ci::Vec3f& pos1,
		const ci::Vec3f& size1,
		const ci::Vec3f& pos2,
		const ci::Vec3f& size2);

	bool IsHitBackBlockToBlock(const ci::Vec3f& pos1,
		const ci::Vec3f& size1,
		const ci::Vec3f& pos2,
		const ci::Vec3f& size2);

	float SinkingTopValue(const float& pos1_y,
		const float& size1_y,
		const float& pos2_y,
		const float& size2_y);

	float SinkingDownValue(const float& pos1_y,
		const float& size1_y,
		const float& pos2_y,
		const float& size2_y);

	float SinkingLeftValue(const float& pos1_x,
		const float& size1_x,
		const float& pos2_x,
		const float& size2_x);

	float SinkingRightValue(const float& pos1_x,
		const float& size1_x,
		const float& pos2_x,
		const float& size2_x);

	float SinkingFrontValue(const float& pos1_z,
		const float& size1_z,
		const float& pos2_z,
		const float& size2_z);

	float SinkingBackValue(const float& pos1_z,
		const float& size1_z,
		const float& pos2_z,
		const float& size2_z);
}