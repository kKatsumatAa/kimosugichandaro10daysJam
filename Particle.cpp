#include "Particle.h"
#include <random>

void Particle::Initialize() {
	
}

void Particle::BurstGenerate(Vec2 pos,int r, int num, int timer, float angle, unsigned int color)
{
	for (int i = 0; i < num; i++) {
		std::unique_ptr<Burst> newBurst = std::make_unique<Burst>();
		newBurst->Initialize();
		newBurst->pos_ = pos;
		newBurst->r_ = r;
		newBurst->timer_ = timer;
		newBurst->angle_ = angle;
		newBurst->color_ = color;
		burst_.push_back(std::move(newBurst));
	}
}

void Particle::FireGenerate(Vec2 pos, int r)
{
	for (int i = 0; i < 10; i++) {
		//ƒ‰ƒ“ƒ_ƒ€
		std::random_device seed_gen;
		std::mt19937_64 engine(seed_gen());
		std::uniform_real_distribution<float> x(-15.0f, 15.0f);
		std::uniform_real_distribution<float> y(-10.0f, 10.0f);

		std::unique_ptr<Fire> newFire = std::make_unique<Fire>();
		newFire->Initialize();
		newFire->pos_.x = pos.x + x(engine);
		newFire->pos_.y = pos.y + y(engine);
		newFire->r_ = r;
		fire_.push_back(std::move(newFire));
	}
}

void Particle::Update()
{
	//”ò‚ÑŽU‚é
	burst_.remove_if([](std::unique_ptr<Burst>& burst) {return burst->isDead_; });
	for (std::unique_ptr<Burst>& burst : burst_) {
		burst->Update();
	}
	//‰Î
	fire_.remove_if([](std::unique_ptr<Fire>& fire) {return fire->isDead_; });
	for (std::unique_ptr<Fire>& fire : fire_) {
		fire->Update();
	}
}

void Particle::Draw()
{
	for (std::unique_ptr<Burst>& burst : burst_) {
		burst->Draw();
	}
	for (std::unique_ptr<Fire>& fire : fire_) {
		fire->Draw();
	}
}
