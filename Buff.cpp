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
	DrawCircle(pos_.x, pos_.y, 20, GetColor(250, 125, 0));
	SetDrawBlendMode(DX_BLENDMODE_SUB, 255);
	DrawCircle(pos_.x, pos_.y,10, GetColor(250, 125, 0));
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
