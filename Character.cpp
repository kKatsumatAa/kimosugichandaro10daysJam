#include "Character.h"


//void Character::Initialize(Model* model, const uint32_t textureHandle)
//{
//	//assert(model);
//
//	//model_ = model;
//	//textureHandle_ = textureHandle;
//
//	////シングルトンインスタンスを取得
//	//input_ = Input::GetInstance();
//	//debugText_ = DebugText::GetInstance();
//
//	//worldTransform_.Initialize();
//}

void Character::Update()
{
	attackTime++;

	if (attackTime >= attackCool)
	{
		Attack();
		attackTime = 0;
	}

	if (HP <= 0) isDead = true;
}

void Character::Draw()
{
	if (scale > 1.0f)
	{
		scale -= 0.05f;
		if (scale < 1.0f) scale = 1.0f;
	}

	if (angle > 0.0f)
	{
		angle -= 0.02f;
		if (angle < 0.0f) angle = 0.0f;
	}
	else if (angle < 0.0f)
	{
		angle += 0.02f;
		if (angle > 0.0f) angle = 0.0f;
	}

	DrawRotaGraph2(pos.x, pos.y, 32.0f, 32.0f, scale, angle, texhandle, true);
}


void Character::Attack()
{
	isAttack = true;
}

void Character::Damage(int power)
{
	if (power - guardPower <= 0) return;

	HP -= (power - guardPower);
}
