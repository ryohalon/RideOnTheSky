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

	// 座標
	ci::Vec3f translate;
	// 回転
	ci::Vec3f rotate;
	// 大きさ
	ci::Vec3f scale;
};