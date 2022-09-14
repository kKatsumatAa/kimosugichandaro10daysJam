#include "Enemy.h"

void Enemy::Initialize(unsigned int* playertexture, unsigned int* textureHandle, Vec2 pos, int hp, int power, int attackCool,bool isBoss)
{
	this->pos = pos;

	this->texhandle = textureHandle;
	this->modelTexture = playertexture;

	attribute = ENEMY;

	//0‚ªí“¬‚²‚Æ‚ÌUŒ‚
	this->powertmp[0] = power;
	this->powertmp[1] = power;
	HP = hp;
	hpMAX = hp;
	this->attackCool = attackCool;

	attackState = new NormalAttack;

	attackState->SetChara(this);

	isSpecial = false;
	this->isBoss = isBoss;
}
