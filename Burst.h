#pragma once
#include "Dxlib.h"
#include "Util.h"

class Burst
{
public:
	void Initialize();

	void Update();

	void Draw();

	//�ꏊ
	Vec2 pos_ = { 0,0 };
	//���a
	int r_;
	//��������
	Vec2 move_ = { 0,0 };
	//�F
	unsigned int color_;
	//�p�x
	float angle_;
	//�o�Ă��鎞��
	int timer_;

	//�d��
	const float GRAVITY = 0.3f;

	//���݂��邩
	bool isDead_ = false;
};

//�~�̊֐�
void DrawCirele(Vec2 pos, int r, unsigned int color);

