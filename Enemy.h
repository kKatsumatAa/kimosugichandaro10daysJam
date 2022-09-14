#pragma once
#include  "Player.h"


class Enemy : public Character
{
public:
	void Initialize(unsigned int* playertexture, unsigned int* textureHandle, Vec2 pos, int hp = 5, int power = 1, int attackCool = 240,bool isBoss = false) override;

};

