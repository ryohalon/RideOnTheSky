#pragma once
#include "../Cinder-LeapMotion.h"



class LeapController
{
private:

	LeapMotion::DeviceRef device;
	Leap::Frame frame;

	ci::Vec2f range_center_pos = ci::Vec2f(0.0f, 320.0f);
	ci::Vec2f range = ci::Vec2f(460.0f, 480.0f);

public:

	ci::Vec2f GetRange() const { return range; }
	ci::Vec2f GetRangeCenterPos() const { return range_center_pos; }
	void SetRange(const ci::Vec2f &range_)
	{
		if (range_.x <= 0.0f || range_.y <= 0.0f)
			return;

		range = range_;
	}
	void SetRangeCenterPos(const ci::Vec2f &range_center_pos_) { range_center_pos = range_center_pos_; }

	Leap::HandList& GetHandList() const;
	//���̒��S���W��Ԃ�
	//����͎g��Ȃ�
	ci::Vec3f GetHandCenterPos() const;
	//���z�ŉ�ʂ���菶�̒��S���W���ŕԂ�
	//-1.0f ~ 1.0f
	ci::Vec2f GetHandCenterPosByRatio() const;
	// ���㌴�_
	ci::Vec2f GetHandCenterPosToRatioLeftUp() const;
	//���̖@����Ԃ�
	ci::Vec3f GetHandNormal() const;
	//�����ݎ肪���邩�Ȃ�����Ԃ�
	bool IsHandExist() const;

public:

	LeapController();
	~LeapController();

	static LeapController& Get()
	{
		static LeapController leap_hands;

		return leap_hands;
	}

	void Setup();
	void Draw();
};