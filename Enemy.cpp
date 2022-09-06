#include "Enemy.h"

void Enemy::Initialize(unsigned int texhandle)
{
	pos = { 1180,500 };

	this->texhandle = texhandle;

	attribute = ENEMY;

	power = 1;
	HP = 5;


}
