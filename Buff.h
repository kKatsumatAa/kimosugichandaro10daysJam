#pragma once
#include "Dxlib.h"
#include "Util.h"

class Buff
{
public:
	void Initialize();

	void Update();

	void Draw();

	//�ꏊ
	Vec2 pos_ = { 0,0 };
	//���a
	int r_ = 10;
	//�A���t�@�l
	int alpha_ = 255;

	int texture;

	//���݂��邩
	bool isDead_;
};

