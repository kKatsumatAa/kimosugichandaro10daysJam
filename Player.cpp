#include "Player.h"

void Player::Initialize(unsigned int texhandle)
{
	pos = { -100,0 };

	this->texhandle = texhandle;

	attribute = PLAYER;

	power = 1;
	HP = 10;

	attackCool = 100;
}
