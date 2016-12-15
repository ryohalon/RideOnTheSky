#pragma once
#include "cinder/app/AppNative.h"
#include "cinder/gl/Material.h"
#include "../../GameObject.h"



class SignPost : public GameObject
{
private:

	ci::Quatf ring_quatf;
	ci::Vec3f direction;
	float length;
	
public:

	SignPost(const ci::Vec3f &position_)
	{
		transform.position = position_;
	}
	~SignPost()
	{
	}

	float GetLength() const;
	ci::Vec3f GetDirection() const;
	
	void SetDirection(const ci::Vec3f &next_position);
	void SetRingQuat(const ci::Vec3f &prev_position);
	void SetLength(const float &length_);
	
	void Setup() override;
	void Update() override;
	void Draw() override;

};