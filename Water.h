#pragma once
#include "Dxlib.h"
#include "Util.h"

class Water
{
public:
	void Initialize();

	void Update();

	void Draw();

	//場所
	Vec2 pos_ = { 0.0f,0.0f };
	//移動
	Vec2 move_ = { 15.0f,-10.0f };
	//半径
	int r_;

	//存在するか
	bool isDead_ = false;
};

