#pragma once
#include "Dxlib.h"
#include "Util.h"

class Orb
{
public:
	void Initialize();

	void Update();

	void Draw();

	Vec2 pos_ = {100,100};

	bool isDead_;
};

