#pragma once
#include "Dxlib.h"
#include "Util.h"

class Number
{
public:
	void initialize();
	void Update();
	void Draw();

	//�ꏊ
	Vec2 pos_ = { 100,100 };
	//�\�������鐔��
	int num_;
	//����(�㉺���E)
	int way_;

	//�e�N�X�`��
	int texture_[10];
	//�A���t�@
	int alpha_ = 255;

	//����
	int timer = 1;
	//���݂��邩
	bool isDead_ = false;
};
