#include "Damage.h"

void Damage::initialize()
{
	LoadDivGraph("resources/UI_number.png", 10, 10, 1, 32, 32, texture_);
}

void Damage::Update()
{
	pos_.y -= 1;
	if (alpha_ <= 0) {
		isDead_ = true;
	}
	else {
		alpha_ -= 3;
	}
}

void Damage::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_);
	if (num_ < 0) {
		DrawGraph(pos_.x, pos_.y, texture_[0], true);
	}
	else if (num_ < 10) {
		DrawGraph(pos_.x, pos_.y, texture_[num_], true);
	}
	else if (num_ < 100) {
		DrawGraph(pos_.x - 10, pos_.y, texture_[num_ / 10], true);
		DrawGraph(pos_.x + 10, pos_.y, texture_[num_ % 10], true);
	}
	else if (num_ < 1000) {
		DrawGraph(pos_.x - 20, pos_.y, texture_[num_ / 100], true);
		DrawGraph(pos_.x, pos_.y, texture_[num_ % 100 / 10], true);
		DrawGraph(pos_.x + 20, pos_.y, texture_[num_ % 10], true);
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}
