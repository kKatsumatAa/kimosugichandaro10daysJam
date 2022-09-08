#include "Burst.h"
#include <random>
#define PI 3.14159265f

void Burst::Initialize(int angle) {
	//ƒ‰ƒ“ƒ_ƒ€
	std::random_device seed_gen;
	std::mt19937_64 engine(seed_gen());
	std::uniform_real_distribution<float> x(-3.0f, 3.0f);
	std::uniform_real_distribution<float> y(-3.0f, 3.0f);

	move_ = { cos(angle * (PI / 180)) * 10 + x(engine),sin(angle * (PI / 180)) * 10 + y(engine)};

}

void Burst::Update()
{
	move_.y += 0.5f;
	pos_ += move_;

	timer_--;
	if (timer_ <= 0) {
		isDead_ = true;
	}
}

void Burst::Draw()
{
	DrawCircle(pos_.x,pos_.y, r_, color_);
}

