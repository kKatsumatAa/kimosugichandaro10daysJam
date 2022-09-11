#include "Slash.h"

void Slash::Initialize()
{
}

void Slash::Update()
{
	if (length_ <= 100) {
		length_ += 10;
		if (length_ % 20 == 0) {
			lineThick_++;
		}
	}
	else {
		alpha_ -= 20;
		if (alpha_ <= 0) {
			isDead_ = true;
		}
	}
}

void Slash::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_);
	DrawLine(pos_.x, pos_.y, pos_.x + length_, pos_.y + length_, GetColor(200, 10, 10), lineThick_);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
