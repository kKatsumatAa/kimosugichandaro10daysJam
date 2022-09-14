#include "Buff.h"

void Buff::Initialize()
{
}

void Buff::Update()
{
	pos_.y -= 5;
	alpha_ -= 5;
	if (alpha_ <= 0) {
		isDead_ = true;
	}
}

void Buff::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_);
	//DrawCircle(pos_.x, pos_.y, r_, GetColor(250, 125, 0),false,r_ / 2);
	DrawGraph(pos_.x - 48, pos_.y - 48, texture, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
