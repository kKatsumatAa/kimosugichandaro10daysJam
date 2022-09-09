#include "Player.h"

void Player::Initialize(const unsigned int textureHandle, Vec2 pos, int hp, int power, int attackCool)
{
	this->pos = pos;

	this->texhandle = textureHandle;

	attribute = PLAYER;

	this->power = power;
	HP = hp;
	this->attackCool = attackCool;

}
