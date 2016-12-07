#pragma once
#include <iostream>
#include <chrono>


#define TIME Time::Get()

class Time
{
private:

	float delta_time;
	float prev_second;
	float now_second;

	int frame_num;

public:

	Time() :
		delta_time(0.0f),
		prev_second(0.0f),
		now_second(0.0f)
	{}
	~Time() {}

	static Time& Get()
	{
		static Time time;

		return time;
	}

	const float& GetDeltaTime() const { return delta_time; }

	const int& GetFrameNum() const { return frame_num; }

	const bool& IsIntervalTime(const int &interval_time) { return (frame_num % interval_time) == 0; }

	void Update(const float &now_second, const int &now_frame_num)
	{
		prev_second = this->now_second;
		this->now_second = now_second;
		delta_time = this->now_second - prev_second;

		frame_num = now_frame_num;
	}
};