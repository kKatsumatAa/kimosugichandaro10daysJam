#include "Enemy.h"

void Enemy::Initialize(const unsigned int textureHandle, Vec2 pos, int hp, int power, int attackCool)
{
	this->pos = pos;

	this->texhandle = textureHandle;

	attribute = ENEMY;

	this->power = power;
	HP = hp;
	this->attackCool = attackCool;

}
