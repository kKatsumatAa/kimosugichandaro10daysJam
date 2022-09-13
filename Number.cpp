#include "Number.h"

void Number::initialize()
{
	LoadDivGraph("resources/UI_number.png", 10, 10, 1, 32, 32, texture_);
	isDead_ = false;
}

void Number::Update()
{
	switch (way_)
	{
	case 0:
		if (timer <= 0) {
			isDead_ = true;
		}
		timer--;
	case 1:
		pos_.y -= 1;
		if (alpha_ <= 0) {
			isDead_ = true;
		}
		else {
			alpha_ -= 3;
		}
	}
}

void Number::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_);
	if (num_ < 0) {
		DrawRotaGraph(pos_.x, pos_.y, 2.0, 0.0, texture_[0], true);
	}
	else if (num_ < 10) {
		DrawRotaGraph(pos_.x, pos_.y, 2.0, 0.0, texture_[num_], true);
	}
	else if (num_ < 100) {
		DrawRotaGraph(pos_.x - 20, pos_.y, 2.0, 0.0, texture_[num_ / 10], true);
		DrawRotaGraph(pos_.x + 20, pos_.y, 2.0, 0.0, texture_[num_ % 10], true);
	}
	else if (num_ < 1000) {
		DrawRotaGraph(pos_.x - 40, pos_.y, 2.0, 0.0, texture_[num_ / 100], true);
		DrawRotaGraph(pos_.x, pos_.y, 2.0, 0.0, texture_[num_ % 100 / 10], true);
		DrawRotaGraph(pos_.x + 40, pos_.y, 2.0, 0.0, texture_[num_ % 10], true);
	}
	DrawFormatString(200, 0, GetColor(255, 255, 255), "num = %d", num_);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}
