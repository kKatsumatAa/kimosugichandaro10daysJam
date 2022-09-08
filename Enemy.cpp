#include "Enemy.h"

void Enemy::Initialize(const unsigned int textureHandle, Vec2 pos, int hp, int attackPower, int attackCool)
{
	this->pos = pos;

	this->texhandle = textureHandle;

	attribute = ENEMY;

	power = attackPower;
	HP = hp;
	this->attackCool = attackCool;

}
