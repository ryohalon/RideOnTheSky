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

	// ���W
	ci::Vec3f position;
	// ��]
	ci::Vec3f angle;
	// �傫��
	ci::Vec3f scale;
};