#pragma once
#include  "Player.h"


class Enemy : public Character
{
public:
	void Initialize(const unsigned int textureHandle, Vec2 pos, int hp = 5, int attackCool = 240) override;

};

