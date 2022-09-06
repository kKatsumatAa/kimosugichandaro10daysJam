#pragma once
#include "Dxlib.h"
#include "Util.h"

class Burst
{
public:
	void Initialize();

	void Update();

	void Draw();

	//場所
	Vec2 pos_ = { 0,0 };
	//半径
	int r_;
	//動く方向
	Vec2 move_ = { 0,0 };
	//色
	unsigned int color_;
	//角度
	float angle_;
	//出ている時間
	int timer_;

	//重力
	const float GRAVITY = 0.3f;

	//存在するか
	bool isDead_ = false;
};
