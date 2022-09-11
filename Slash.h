#pragma once
#include "Dxlib.h"
#include "Util.h"

class Slash
{
public:
	void Initialize();

	void Update();

	void Draw();

	Vec2 pos_;
	int length_ = 0;
	int alpha_ = 255;
	int lineThick_ = 0;

	bool isDead_;
};

