#pragma once
#include "../GameObject.h"
#include "../../../Utillity/Manager/EasingManager/Easing/Easing.h"
#include "../../../Utillity/Time/Time.h"



class CharacterBase : public GameObject
{
public:

	enum class Status
	{
		NORMAL,
		ROLL,
		DASH,
		CLASH
	};

protected:

	Status status;
	float speed;

	float move_count;
	float move_take_time;
	ci::Vec2f start_move_pos;
	ci::Vec2f end_move_pos;

	float roll_count;
	float roll_take_time;
	float start_roll_angle;
	float end_roll_angle;

	float dash_count;
	float dash_take_time;
	float start_speed;
	float end_speed;

	float clash_count;
	float clash_take_time;
	float start_clash_speed;
	float end_clash_speed;

	float interval_count;
	float interval_take_time;

protected:

	void UpdateStatus();
	void Move();
	void Roll();
	void Dash();
	void Clash();
	void Interval();

public:

	float GetSpeed() const { return speed; }
	Status GetStatus() const { return status; }

	void SetSpeed(const float speed_) { speed = speed_; }
	void SetStatus(const Status status_) { status = status_; }

public:

	CharacterBase();
	~CharacterBase();

	virtual void Setup() override;
	virtual void Update() override = 0;
	virtual void Draw() override = 0;
};