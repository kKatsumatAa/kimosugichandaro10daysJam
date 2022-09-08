#include "Player.h"

void Player::Initialize(const unsigned int textureHandle, Vec2 pos, int hp, int attackPower, int attackCool)
{
	this->pos = pos;

	this->texhandle = textureHandle;

	attribute = PLAYER;

	power = attackPower;
	HP = hp;
	this->attackCool = attackCool;

}
