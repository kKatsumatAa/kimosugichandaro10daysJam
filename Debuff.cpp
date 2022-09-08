#include "Debuff.h"

void Debuff::Initialize()
{
}

void Debuff::Update()
{
	pos_.y += 5;
	alpha_ -= 5;
	if (alpha_ <= 0) {
		isDead_ = true;
	}
}

void Debuff::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_);
	DrawCircle(pos_.x, pos_.y, r_, GetColor(0, 125, 250), false, r_ / 2);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}