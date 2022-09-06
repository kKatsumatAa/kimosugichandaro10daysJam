#include "Player.h"

void Player::Initialize(const unsigned int textureHandle, Vec2 pos, int hp, int attackCool)
{
	this->pos = pos;

	this->texhandle = textureHandle;

	attribute = PLAYER;

	power = 1;
	HP = hp;
	this->attackCool = attackCool;

}
