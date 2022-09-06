#pragma once
#include "Dxlib.h"
#include "Util.h"

class Burst
{
public:
	void Initialize();

	void Update();

	void Draw();

	//êŠ
	Vec2 pos_ = { 0,0 };
	//”¼Œa
	int r_;
	//“®‚­•ûŒü
	Vec2 move_ = { 0,0 };
	//F
	unsigned int color_;
	//Šp“x
	float angle_;
	//o‚Ä‚¢‚éŠÔ
	int timer_;

	//d—Í
	const float GRAVITY = 0.3f;

	//‘¶İ‚·‚é‚©
	bool isDead_ = false;
};

//‰~‚ÌŠÖ”
void DrawCirele(Vec2 pos, int r, unsigned int color);

