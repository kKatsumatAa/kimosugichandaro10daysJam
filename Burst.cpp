#include "Burst.h"
#include <random>

void Burst::Initialize() {
	//ƒ‰ƒ“ƒ_ƒ€
	std::random_device seed_gen;
	std::mt19937_64 engine(seed_gen());
	std::uniform_real_distribution<float> x(5.0f, 10.0f);
	std::uniform_real_distribution<float> y(-10.0f, -5.0f);

	move_ = { x(engine),y(engine) };

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

