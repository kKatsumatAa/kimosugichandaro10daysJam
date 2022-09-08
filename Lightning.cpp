#include "Lightning.h"
#include <random>

void Lightning::Initialize()
{
}

void Lightning::Update()
{
	if (--time_ <= 0) {
		isDead_ = true;
	}
}

void Lightning::Draw()
{
	//ƒ‰ƒ“ƒ_ƒ€
	std::random_device seed_gen;
	std::mt19937_64 engine(seed_gen());
	std::uniform_real_distribution<float> x(-2.0f, 2.0f);
	posX = x(engine);
	for (int i = 0; i < length_; i++) {
		//ƒ‰ƒ“ƒ_ƒ€
		std::random_device seed_gen;
		std::mt19937_64 engine(seed_gen());
		std::uniform_real_distribution<float> x(-2.0f, 2.0f);
		posX += x(engine);
		if (horizontal_ == 0) {
			DrawPixel(pos_.x + posX, pos_.y + i, GetColor(200, 200, 255));
		}
		else {
			DrawPixel(pos_.x + i, pos_.y + posX, GetColor(200, 200, 255));
		}
	}
}
