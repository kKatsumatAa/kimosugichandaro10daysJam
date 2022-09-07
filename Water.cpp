#include "Water.h"
#include <random>

void Water::Initialize()
{
	//ƒ‰ƒ“ƒ_ƒ€
	std::random_device seed_gen;
	std::mt19937_64 engine(seed_gen());
	std::uniform_real_distribution<float> x(-1.0f, 1.0f);
	move_.x += x(engine);
}

void Water::Update()
{
	move_.y += 0.3f;
	pos_ += move_;
}

void Water::Draw()
{
	for (int i = 0; i < 3; i++) {
		SetDrawBlendMode(DX_BLENDMODE_ADD, 72);
		DrawCircle(pos_.x, pos_.y, r_, GetColor(8, 10, 10), true);
		DrawCircle(pos_.x, pos_.y, r_ - 6, GetColor(20, 24, 24), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
}
