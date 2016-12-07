#pragma once
#include "cinder/Vector.h"


class Transform
{
public:

	Transform() :
		translate(ci::Vec3f::zero()),
		rotate(ci::Vec3f::zero()),
		scale(ci::Vec3f::one())
	{

	}
	Transform(const ci::Vec3f &translate,
		const ci::Vec3f &rotate,
		const ci::Vec3f &scale) :
		translate(translate),
		rotate(rotate),
		scale(scale)
	{

	}
	~Transform() {}

	// À•W
	ci::Vec3f translate;
	// ‰ñ“]
	ci::Vec3f rotate;
	// ‘å‚«‚³
	ci::Vec3f scale;
};