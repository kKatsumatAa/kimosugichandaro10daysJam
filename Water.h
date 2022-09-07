#pragma once
#include "Dxlib.h"
#include "Util.h"

class Water
{
public:
	void Initialize();

	void Update();

	void Draw();

	//êŠ
	Vec2 pos_ = { 0.0f,0.0f };
	//ˆÚ“®
	Vec2 move_ = { 15.0f,-10.0f };
	//”¼Œa
	int r_;

	//‘¶İ‚·‚é‚©
	bool isDead_ = false;
};

