#pragma once
#include "../GameObject.h"
#include "SignPost/SignPost.h"
#include "../../../Utillity/Collision/Collision.h"


class SignPostManager : public GameObject
{
private:

	std::vector<SignPost> signposts;
	float round_length;
	ci::Vec3f player_posistion;

	void PostLoad();
	void SetDirection();
	void SetRingQuat();
	void SetLength();
	
public:

	ci::Matrix44f GetStageMatrix(const ci::Vec3f &position);
	
	void SetPlayerPosistion(const ci::Vec3f &player_position_) { player_posistion = player_position_; }

public:

	SignPostManager();
	
	void Setup() override;
	void Update() override;
	void Draw() override;
};