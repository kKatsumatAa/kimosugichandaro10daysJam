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


	Vec2 pos = { 0,0 };


public:
	virtual void Initialize(const unsigned int textureHandle) = 0;
	void Update();
	void Draw();

	void Attack();

	bool GetIsAttack() { return isAttack; }
	void SetIsAttack(bool isAttack) { this->isAttack = isAttack; }

	int GetPower() { return power; }

	void Damage(int power) { HP -= power; }

	int GetAttribute() { return attribute; }

	bool GetIsDead() { return isDead; }

	void AddScale(const float& scale) { this->scale += scale; }

	void AddAngle(const float& angle){ this->angle += angle; }

};