#include "Player.h"

void Player::Initialize(unsigned int texhandle)
{
	pos = { 780,500 };

	this->texhandle = texhandle;

	attribute = PLAYER;

	power = 1;
	HP = 10;

	attackCool = 100;
}
