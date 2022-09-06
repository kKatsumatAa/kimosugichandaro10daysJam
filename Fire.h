#pragma once
#include "Dxlib.h"
#include "Util.h"

class Fire
{
public:
	void Initialize();

	void Update();

	void Draw();

	//場所
	Vec2 pos_ = { 0,0 };
	//移動
	Vec2 move_ = { 0,-6 };
	//半径
	int r_;
	//アルファ値
	int alpha_ = 255;

	//存在するか
	bool isDead_;
};

