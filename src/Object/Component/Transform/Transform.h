#pragma once
#include "cinder/Vector.h"


class Transform
{
public:

	Transform() :
		position(ci::Vec3f::zero()),
		angle(ci::Vec3f::zero()),
		scale(ci::Vec3f::one())
	{

	}
	Transform(const ci::Vec3f &position,
		const ci::Vec3f &angle,
		const ci::Vec3f &scale) :
		position(position),
		angle(angle),
		scale(scale)
	{

	}
	~Transform() {}

	// ç¿ïW
	ci::Vec3f position;
	// âÒì]
	ci::Vec3f angle;
	// ëÂÇ´Ç≥
	ci::Vec3f scale;
};