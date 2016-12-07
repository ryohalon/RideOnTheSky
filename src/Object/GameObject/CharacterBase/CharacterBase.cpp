#include "CharacterBase.h"

void CharacterBase::UpdateStatus()
{
	Move();
	Roll();
	Dash();
	Clash();
	Interval();
}

void CharacterBase::Move()
{
	if (status != Status::NORMAL)
		return;

	
}

void CharacterBase::Roll()
{
	if (status != Status::ROLL)
		return;

	roll_count += TIME.GetDeltaTime();
	if (roll_count >= 1.0f)
	{
		roll_count = 1.0f;
		status = Status::NORMAL;
	}

	transform.rotate.z = Easing::QuadOut(roll_count, start_roll_angle, end_roll_angle);
}

void CharacterBase::Dash()
{
	if (status != Status::DASH)
		return;

	dash_count += TIME.GetDeltaTime();
	if (dash_count >= 1.0f)
	{
		dash_count = 1.0f;
		status = Status::NORMAL;
	}

	speed = Easing::QuadOut(dash_count, start_speed, end_speed);
}

void CharacterBase::Clash()
{
	if (status != Status::CLASH)
		return;

	clash_count += TIME.GetDeltaTime();
	if (clash_count >= 1.0f)
	{
		clash_count = 1.0f;
		status = Status::NORMAL;
	}

	speed = Easing::QuadOut(clash_count, start_clash_speed, end_clash_speed);
	transform.rotate.z = 
		std::sin(clash_count * clash_take_time * static_cast<float>(M_PI) * 4.0f)
		* static_cast<float>(M_PI) / 4.0f;
}

void CharacterBase::Interval()
{

}

CharacterBase::CharacterBase()
{

}

CharacterBase::~CharacterBase()
{

}

void CharacterBase::Setup()
{

}