#include "SignPost.h"

float SignPost::GetLength() const
{
	return length;
}

ci::Vec3f SignPost::GetDirection() const
{
	return direction;
}

void SignPost::SetDirection(const ci::Vec3f &next_position)
{
	direction = next_position - transform.position;
	ci::Vec2f rotate;
	rotate.y = atan2(direction.x, direction.z);
	rotate.x = atan2(ci::Vec2f(direction.x, direction.z).length(), direction.y) - M_PI / 2;

	matrix *= ci::Matrix44f::createRotation(ci::Vec3f(0, rotate.y, 0.f));
	matrix *= ci::Matrix44f::createRotation(ci::Vec3f(rotate.x, 0, 0.f));

}

void SignPost::SetRingQuat(const ci::Vec3f &prev_position)
{
	ring_quatf = ci::Quatf(ci::Vec3f::zAxis(),
		((transform.position - prev_position).normalized() + direction.normalized()).normalized());

}

void SignPost::SetLength(const float &length_)
{
	length = length_;
}

void SignPost::Setup()
{
}

void SignPost::Update()
{
}

void SignPost::Draw()
{
	ci::gl::pushModelView();
	ci::gl::translate(transform.position);
	ci::gl::multModelView(ring_quatf.toMatrix44());
	material.apply();
	ci::gl::drawTorus(7.0f, 0.3f, 1, 1);
	ci::gl::popModelView();

}
