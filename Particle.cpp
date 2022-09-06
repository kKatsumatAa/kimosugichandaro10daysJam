#include "Particle.h"

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

void Particle::Update()
{
	burst_.remove_if([](std::unique_ptr<Burst>& burst) {return burst->isDead_; });
	for (std::unique_ptr<Burst>& burst : burst_) {
		burst->Update();
	}
}

void Particle::Draw()
{
	for (std::unique_ptr<Burst>& burst : burst_) {
		burst->Draw();
	}
}
