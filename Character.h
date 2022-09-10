#pragma once
#include"Util.h"
#include "Assert.h"

enum 
{
	PLAYER,
	ENEMY
};


class Character;


class AttackState
{
protected:
	Character* chara = nullptr;

public:
	void SetChara(Character* chara) { this->chara = chara; }
	virtual void Update() = 0;
	virtual void Draw(unsigned int* texhandle) = 0;
};


class Character
{
private:

	
protected:
	unsigned int texhandle;

	int attackCool = 240;
	int attackTime = 0;

	bool isAttack = false;

	//UŒ‚—Íƒoƒt
	int power = 0;
	//UŒ‚—Í(0‚Íí“¬‚²‚ÆA1‚ÍŒ³‚Ìí“¬—Í)
	int powertmp[2] = {0};

	int HP = 10;

	int attribute;

	bool isDead = false;

	float angle = 0;

	float scale = 1.0f;

	int guardPower = 0;

	Vec2 pos = { 0,0 };

	int deBuffPower = 0;

	AttackState* attackState = nullptr;

	bool isSpecial = false;

	int hpMAX = 0;

public:
	virtual void Initialize(const unsigned int textureHandle, Vec2 pos, int hp = 5, int power = 1, int attackCool = 240) = 0;
	void Update();
	void Draw();

	void Attack(int power = 114514);

	bool GetIsAttack() { return isAttack; }
	void SetIsAttack(bool isAttack) { this->isAttack = isAttack; }

	int GetPower() 
	{ 
		if (powertmp[0] + power - deBuffPower <= 0) return 0;
		                                            return powertmp[0] + power - deBuffPower;
	}

	void Damage(int power);

	int GetAttribute() { return attribute; }

	bool GetIsDead() { return isDead; }

	void AddScale(const float& scale) { this->scale += scale; }

	void AddAngle(const float& angle){ this->angle += angle; }

	void AddPos(const Vec2& vec2) { this->pos += vec2; }

	Vec2 GetPos() { return pos; }

	int GetHP() { return HP; }

	float GetAttackGauge() { return (float)attackTime / (float)(attackCool + (attackCool * (deBuffPower / 3.0f))); }

	unsigned int GetTexHandle() { return texhandle; }

	void AddGuardPower(int guardPower) { this->guardPower += guardPower; }

	void AddPower(int power) { this->power += power; }

	void AddDeBuff(int deBuffPower) { this->deBuffPower += deBuffPower; }

	int GetDeBuff() { return deBuffPower; }

	void AddAttackTimer() { attackTime++; }

	int GetAttackTimer() { return attackTime; }

	int GetAttackCool() { return attackCool; }

	void SetAttackTime(int time) { attackTime = time; }

	void ChangeState(AttackState* state);

	int GetHpMAX() { return hpMAX; }

	void SetIsSpecial(bool isSpecial) { this->isSpecial = isSpecial; }

	int GetIsSpecial() { return isSpecial; }

	void AddHP(int hp) { HP += hp; }

	void InitializeBattle();
};


//
class NormalAttack :public AttackState
{
private:


public:
	void Update() override;
	void Draw(unsigned int* texhandle) override;
};

//
class SpecialAttack :public AttackState
{
private:
	const int specialGaugeMAX = 300;
	int specialGauge = 0;

	const Vec2 gaugeLength = { 100.0f,10.0f };

	int count = 0;

public:
	void Update() override;
	void Draw(unsigned int* texhandle) override;
};