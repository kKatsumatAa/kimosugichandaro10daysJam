#include "Fire.h"
#include <random>

void Fire::Initialize()
{

}

void Fire::Update()
{
	//ƒ‰ƒ“ƒ_ƒ€
	std::random_device seed_gen;
	std::mt19937_64 engine(seed_gen());
	std::uniform_real_distribution<float> x(-1.0f, 1.0f);
	move_.x += x(engine);

	pos_ += move_;
	if (alpha_ > 0) {
		alpha_ -= 32;
	}
	r_--;

	if (r_ <= 0) {
		isDead_ = true;
	}
}

void Fire::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_);
	SetDrawBlendMode(DX_BLENDMODE_ADD, 196);
	DrawCircle(pos_.x,pos_.y, r_, GetColor(72,8,2),true);
	DrawCircle(pos_.x, pos_.y, r_ - 2, GetColor(0, 32, 12), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
