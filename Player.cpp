#include "Player.h"

void Player::Initialize(const unsigned int textureHandle, Vec2 pos, int hp, int power, int attackCool)
{
	this->pos = pos;

	this->texhandle = textureHandle;

	attribute = PLAYER;

	//0‚ªí“¬‚²‚Æ‚ÌUŒ‚
	this->powertmp[0] = power;
	this->powertmp[1] = power;
	HP = hp;
	hpMAX = hp;
	this->attackCool = attackCool;

	attackState = new NormalAttack;

	attackState->SetChara(this);
}
