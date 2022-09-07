#pragma once
#include "Dxlib.h"
#include "Util.h"

class Water
{
public:
	void Initialize();

	void Update();

	void Draw();

	//�ꏊ
	Vec2 pos_ = { 0.0f,0.0f };
	//�ړ�
	Vec2 move_ = { 10.0f,-7.0f };
	//���a
	int r_;

	//���݂��邩
	bool isDead_ = false;
};

