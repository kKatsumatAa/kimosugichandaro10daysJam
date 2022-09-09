#include "Enemy.h"

void Enemy::Initialize(const unsigned int textureHandle, Vec2 pos, int hp, int power, int attackCool)
{
	this->pos = pos;

	this->texhandle = textureHandle;

	attribute = ENEMY;

	this->powertmp = power;
	HP = hp;
	hpMAX = hp;
	this->attackCool = attackCool;

	attackState = new NormalAttack;

	attackState->SetChara(this);

	isSpecial = false;
}
