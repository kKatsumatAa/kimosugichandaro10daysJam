#pragma once
#include"Util.h"
#include "Assert.h"

enum 
{
	PLAYER,
	ENEMY
};

class Character
{
private:

	
protected:
	unsigned int texhandle;

	int attackCool = 240;
	int attackTime = 0;

	bool isAttack = false;

	int power = 1;

	int HP = 10;

	int attribute;

	bool isDead = false;

	float angle = 0;

	float scale = 1.0f;

	int guardPower = 0;

	Vec2 pos = { 0,0 };

	int deBuffPower = 0;


public:
	virtual void Initialize(const unsigned int textureHandle, Vec2 pos, int hp = 5, int power = 1, int attackCool = 240) = 0;
	void Update();
	void Draw();

	void Attack();

	bool GetIsAttack() { return isAttack; }
	void SetIsAttack(bool isAttack) { this->isAttack = isAttack; }

	int GetPower() 
	{ 
		if (power - deBuffPower <= 0) return 0;
		                              return power - deBuffPower;
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

	void AddGuardPower(int guardPower) { this->guardPower = guardPower; }

	void AddPower(int power) { this->power += power; }

	void AddDeBuff(int deBuffPower) { this->deBuffPower += deBuffPower; }

};