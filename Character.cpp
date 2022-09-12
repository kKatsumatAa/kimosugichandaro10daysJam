#include "Character.h"
#include <math.h>


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
	attackState->Update();

	if (HP <= 0) isDead = true;
}

void Character::Draw()
{
	if (scale > 1.0f)
	{
		scale -= 0.05f;
		if (scale < 1.0f) scale = 1.0f;
	}
	if (scale < 1.0f)
	{
		scale += 0.05f;
		if (scale > 1.0f) scale = 1.0f;
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
	if (animeTimer >= 8.8f) {
		animeTimer = 0;
	}
	else {
		animeTimer += 0.2f;
	}

	if (attribute == PLAYER) {
		DrawRotaGraph2(pos.x - 80, pos.y, 32.0f, 32.0f, scale * 1.7f, angle, modelTexture[static_cast<int>(animeTimer)], true);
	}
	

	//数値描画
	DrawFormatString(pos.x + 50, pos.y - 20, 0xffffff, "power:%d", GetPower());
	DrawFormatString(pos.x + 50, pos.y - 20, 0xffff00, "\nguard:%d", guardPower);

	//hp,攻撃ゲージ
	DrawRotaGraph(pos.x , pos.y - 100, 1.5f, 0.0f, texhandle[1], true);

	SetDrawBright(255, 255, 255);
	DrawBox(pos.x - 77 * 1.5f, pos.y - 93,
		pos.x - 77 * 1.5f + ((float)168 * 1.5f * GetAttackGauge()), pos.y - 76, 
		0x00ffff, true);
	DrawBox(pos.x - 78 * 1.5f, pos.y - 123,
		pos.x - 78 * 1.5f + ((float)168 * 1.5f * ((float)HP / (float)hpMAX)), pos.y - 95,
		0xff0000, true);

	attackState->Draw(texhandle);
}


void Character::Attack(int power)
{
	isAttack = true;

	if (power != 114514) this->powertmp[0] = power;
	else                 this->powertmp[0] = powertmp[1];
}

void Character::Damage(int power)
{
	if (power - guardPower <= 0) return;

	HP -= (power - guardPower);
}


//---------------------------------------------------------------------------
void Character::ChangeState(AttackState* state)
{
	delete this->attackState;
	this->attackState = state;
	state->SetChara(this);
}

void Character::InitializeBattle()
{
	attackTime = 0;

	isAttack = false;

	//攻撃力バフ
	power = 0;
	//攻撃力(0は戦闘ごと、1は元の戦闘力)
	powertmp[0] = powertmp[1];

	//上限じゃない限り回復
	for (int i = 0; i < 5; i++)
	{
		if (HP >= hpMAX)break;
		HP++;
	}

	guardPower = 0;

	deBuffPower = 0;
}


//-------------------------------------------------------------------------------
void NormalAttack::Update()
{
	chara->AddAttackTimer();

	//通常こうげき　　　　　　　　　　　　　　　　　　　　　//デバフがかかっていたら攻撃が発動長くなる
	if (chara->GetAttackTimer() >= chara->GetAttackCool() + (chara->GetAttackCool() * (chara->GetDeBuff() / 3.0f)))
	{
		chara->Attack();
		chara->SetAttackTime(0);
	}

	//敵で、hpが半分以下、まだ強こうげき発動していない
	if (chara->GetHP() <= chara->GetHpMAX() / 2 && !chara->GetIsSpecial() && chara->GetAttribute() == ENEMY)
	{
		chara->SetIsSpecial(true);
		chara->ChangeState(new SpecialAttack);
		
	}
}

void NormalAttack::Draw(unsigned int* texhandle)
{
	
}

//-------------------------------------------------------------------------------
void SpecialAttack::Update()
{
	specialGauge++;

	DrawFormatString(0, 0, 0xffffff, "\n\n\n\n\n\ngauge%d", specialGauge);

	//ゲージいっぱいになったら通常の攻撃力の2倍の攻撃
	if (specialGauge >= specialGaugeMAX)
	{
		chara->Attack(chara->GetPower() * 2);
		chara->SetAttackTime(0);

		chara->ChangeState(new NormalAttack);

		return;
	}

	//ある程度まで体力削ればデバフを２与える
	if ((float)chara->GetHP() <= (float)chara->GetHpMAX() / 5.0f && chara->GetIsSpecial() && chara->GetAttribute() == ENEMY)
	{
		chara->AddDeBuff(2);
		chara->ChangeState(new NormalAttack);
	}
}

void SpecialAttack::Draw(unsigned int* texhandle)
{
	//強攻撃時、スケール変える
	count ++;

	if (count % 5 == 0)
	{
		chara->AddScale((float)(GetRand(2) + 1) * 0.1f);
	}

	DrawBox(chara->GetPos().x - gaugeLength.x / 2, 
		chara->GetPos().y - gaugeLength.y / 2 + 70,
		chara->GetPos().x - gaugeLength.x / 2 + gaugeLength.x * (float)((float)specialGauge / (float)specialGaugeMAX),
		chara->GetPos().y + gaugeLength.y / 2 + 70,
		0xffffff, true);

	//ブレークするhp
	DrawLine(chara->GetPos().x - 77 * 1.5f + ((float)168 * 1.5f / 5.0f), chara->GetPos().y - 123,
		chara->GetPos().x - 77 * 1.5f + ((float)168 * 1.5f / 5.0f), chara->GetPos().y - 95, 0xffffff, 3);
}
