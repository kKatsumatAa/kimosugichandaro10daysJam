#pragma once
#include "Dxlib.h"
#include "Util.h"

class Damage
{
public:
	void initialize();
	void Update();
	void Draw();

	//場所
	Vec2 pos_ = { 100,100 };
	//表示させる数字
	int num_;
	//方向(上下左右)
	int way_;

	//テクスチャ
	int texture_[10];
	//アルファ
	int alpha_ = 255;

	//存在するか
	bool isDead_ = false;
};

