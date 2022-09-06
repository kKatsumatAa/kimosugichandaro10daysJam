#include "Enemy.h"

void Enemy::Initialize(const unsigned int textureHandle, Vec2 pos, int hp, int attackCool)
{
	this->pos = pos;

	this->texhandle = textureHandle;

	attribute = ENEMY;

	power = 1;
	HP = hp;
	this->attackCool = attackCool;

}
