#include "Character.h"


//void Character::Initialize(Model* model, const uint32_t textureHandle)
//{
//	//assert(model);
//
//	//model_ = model;
//	//textureHandle_ = textureHandle;
//
//	////�V���O���g���C���X�^���X���擾
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

	attackState->Draw(&texhandle);
}


void Character::Attack(int power)
{
	isAttack = true;

	if (power != 114514) this->power = power;
	else                 this->power = powertmp;
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


//-------------------------------------------------------------------------------
void NormalAttack::Update()
{
	chara->AddAttackTimer();

	//�ʏ킱������
	if (chara->GetAttackTimer() >= chara->GetAttackCool() + (chara->GetAttackCool() * (chara->GetDeBuff() / 3.0f)))
	{
		chara->Attack();
		chara->SetAttackTime(0);
	}

	//�G�ŁAhp�������ȉ��A
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

	//�Q�[�W�����ς��ɂȂ�����ʏ�̍U���͂�2�{�̍U��
	if (specialGauge >= specialGaugeMAX)
	{
		chara->Attack(chara->GetPower() * 2);
		chara->SetAttackTime(0);

		chara->ChangeState(new NormalAttack);

		return;
	}

	//������x�܂ő̗͍��Ύ���
	if (chara->GetHP() < chara->GetHpMAX() / 5 && chara->GetIsSpecial() && chara->GetAttribute() == ENEMY)
	{
		chara->AddHP(-chara->GetHpMAX() / 3);
		chara->ChangeState(new NormalAttack);
	}
}

void SpecialAttack::Draw(unsigned int* texhandle)
{
	DrawBox(chara->GetPos().x - gaugeLength.x / 2, 
		chara->GetPos().y - gaugeLength.y / 2 - 70,
		chara->GetPos().x - gaugeLength.x / 2 + gaugeLength.x * (float)((float)specialGauge / (float)specialGaugeMAX),
		chara->GetPos().y + gaugeLength.y / 2 - 70,
		0xffffff, true);
}
