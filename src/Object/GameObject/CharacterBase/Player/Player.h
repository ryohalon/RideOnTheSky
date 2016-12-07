#pragma once
#include "../CharacterBase.h"



class Player
{
private:

	bool is_jump;

	void Move();

public:

	Player();
	~Player();

	void Setup();
	void Update();
	void Draw();
};