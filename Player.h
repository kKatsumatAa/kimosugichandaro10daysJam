#pragma once
#include "Character.h"


class Player : public Character
{
public:
	void Initialize(const unsigned int textureHandle, Vec2 pos, int hp = 30, int power = 1, int attackCool = 100) override;
};

