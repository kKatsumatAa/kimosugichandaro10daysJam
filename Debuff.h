#pragma once
#include "Dxlib.h"
#include "Util.h"

class Debuff
{
public:
	void Initialize();

	void Update();

	void Draw();

	//場所
	Vec2 pos_ = { 0,0 };
	//半径
	int r_ = 10;
	//アルファ値
	int alpha_ = 255;

	//存在するか
	bool isDead_;
};

