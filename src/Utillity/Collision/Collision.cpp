#include "Collision.h"

using namespace ci;


namespace Collision
{
	bool IsHitBlockToBlock(const ci::Vec3f & pos1, const ci::Vec3f & size1, const ci::Vec3f & pos2, const ci::Vec3f & size2)
	{
		return ((pos1.x + size1.x / 2 >= pos2.x - size2.x / 2) &&
			(pos1.x - size1.x / 2 <= pos2.x + size2.x / 2) &&
			(pos1.y + size1.y / 2 >= pos2.y - size2.y / 2) &&
			(pos1.y - size1.y / 2 <= pos2.y + size2.y / 2) &&
			(pos1.z + size1.z / 2 >= pos2.z - size2.z / 2) &&
			(pos1.z - size1.z / 2 <= pos2.z + size2.z / 2));
	}

	bool IsHitTopBlockToBlock(const Vec3f& pos1,
		const Vec3f& size1,
		const Vec3f& pos2,
		const Vec3f& size2)
	{
		return ((pos1.x + size1.x / 2 > pos2.x - size2.x / 2) &&
			(pos1.x - size1.x / 2 < pos2.x + size2.x / 2) &&
			(pos1.y - size1.y / 2 > pos2.y) &&
			(pos1.y - size1.y / 2 < pos2.y + size2.y / 2) &&
			(pos1.z + size1.z / 2 > pos2.z - size2.z / 2) &&
			(pos1.z - size1.z / 2 < pos2.z + size2.z / 2));
	}

	bool IsHitDownBlockToBlock(const ci::Vec3f & pos1,
		const ci::Vec3f& size1,
		const ci::Vec3f& pos2,
		const ci::Vec3f & size2)
	{
		return ((pos1.x + size1.x / 2 > pos2.x - size2.x / 2) &&
			(pos1.x - size1.x / 2 < pos2.x + size2.x / 2) &&
			(pos1.y + size1.y / 2 > pos2.y - size2.y / 2) &&
			(pos1.y + size1.y / 2 < pos2.y) &&
			(pos1.z + size1.z / 2 > pos2.z - size2.z / 2) &&
			(pos1.z - size1.z / 2 < pos2.z + size2.z / 2));
	}

	bool IsHitLeftBlockToBlock(const ci::Vec3f& pos1,
		const ci::Vec3f& size1,
		const ci::Vec3f& pos2,
		const ci::Vec3f & size2)
	{
		return ((pos1.x - size1.x / 2 > pos2.x + size2.x / 4) &&
			(pos1.x - size1.x / 2 < pos2.x + size2.x / 2) &&
			(pos1.y + size1.y / 2 > pos2.y - size2.y / 2) &&
			(pos1.y - size1.y / 2 < pos2.y + size2.y / 2) &&
			(pos1.z + size1.z / 2 > pos2.z - size2.z / 2) &&
			(pos1.z - size1.z / 2 < pos2.z + size2.z / 2));
	}

	bool IsHitRightBlockToBlock(const ci::Vec3f& pos1,
		const ci::Vec3f& size1,
		const ci::Vec3f& pos2,
		const ci::Vec3f & size2)
	{
		return ((pos1.x + size1.x / 2 > pos2.x - size2.x / 2) &&
			(pos1.x + size1.x / 2 < pos2.x - size2.x / 4) &&
			(pos1.y + size1.y / 2 > pos2.y - size2.y / 2) &&
			(pos1.y - size1.y / 2 < pos2.y + size2.y / 2) &&
			(pos1.z + size1.z / 2 > pos2.z - size2.z / 2) &&
			(pos1.z - size1.z / 2 < pos2.z + size2.z / 2));
	}

	bool IsHitFrontBlockToBlock(const ci::Vec3f
		& pos1,
		const ci::Vec3f& size1,
		const ci::Vec3f& pos2,
		const ci::Vec3f & size2)
	{
		return ((pos1.x + size1.x / 2 > pos2.x - size2.x / 2) &&
			(pos1.x - size1.x / 2 < pos2.x + size2.x / 2) &&
			(pos1.y + size1.y / 2 > pos2.y - size2.y / 2) &&
			(pos1.y - size1.y / 2 < pos2.y + size2.y / 2) &&
			(pos1.z - size1.z / 2 > pos2.z + size2.z / 4) &&
			(pos1.z - size1.z / 2 < pos2.z + size2.z / 2));
	}

	bool IsHitBackBlockToBlock(const ci::Vec3f& pos1,
		const ci::Vec3f& size1,
		const ci::Vec3f& pos2,
		const ci::Vec3f& size2)
	{
		return ((pos1.x + size1.x / 2 > pos2.x - size2.x / 2) &&
			(pos1.x - size1.x / 2 < pos2.x + size2.x / 2) &&
			(pos1.y + size1.y / 2 > pos2.y - size2.y / 2) &&
			(pos1.y - size1.y / 2 < pos2.y + size2.y / 2) &&
			(pos1.z + size1.z / 2 > pos2.z - size2.z / 2) &&
			(pos1.z + size1.z / 2 < pos2.z - size2.z / 4));
	}

	float SinkingTopValue(const float& pos1_y,
		const float& size1_y,
		const float& pos2_y,
		const float& size2_y)
	{
		return ((pos2_y + size2_y / 2) - (pos1_y - size1_y / 2));
	}

	float SinkingDownValue(const float& pos1_y,
		const float& size1_y,
		const float& pos2_y,
		const float& size2_y)
	{
		return ((pos2_y - size2_y / 2) - (pos1_y + size1_y / 2));
	}

	float SinkingLeftValue(const float& pos1_x,
		const float& size1_x,
		const float& pos2_x,
		const float& size2_x)
	{
		return ((pos2_x + size2_x / 2) - (pos1_x - size1_x / 2));
	}

	float SinkingRightValue(const float& pos1_x,
		const float& size1_x,const float& pos2_x,
		const float& size2_x)
	{
		return ((pos2_x - size2_x / 2) - (pos1_x + size1_x / 2));
	}

	float SinkingFrontValue(const float& pos1_z,
		const float& size1_z,
		const float& pos2_z,
		const float & size2_z)
	{
		return ((pos2_z + size2_z / 2) - (pos1_z - size1_z / 2));
	}

	float SinkingBackValue(const float& pos1_z,
		const float& size1_z,
		const float& pos2_z,
		const float& size2_z)
	{
		return ((pos2_z - size2_z / 2) - (pos1_z + size1_z / 2));
	}
}
