#pragma once
#include "Dxlib.h"
#include "Util.h"

class Lightning
{
public:
	void Initialize();

	void Update();

	void Draw();

	Vec2 pos_;
	int length_;
	int time_;
	bool horizontal_;

	float posX;
	bool isDead_;
};

