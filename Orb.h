#pragma once
#include "Dxlib.h"
#include "Util.h"

class Orb
{
public:
	void Initialize();

	void Update();

	void Draw();

	Vec2 startPos_;
	Vec2 midPos_;
	Vec2 endPos_;
	Vec2 pos_ = startPos_;

	int moveNum = 0;
	int speed = 20;
	int stopTimer = 0;

	bool isDead_;
};

