#include "Particle.h"
#include "Particle.h"
#include <random>

void Particle::Initialize() {
	
}

void Particle::BurstGenerate(Vec2 pos,int r, int num, int timer, float angle,float pow, unsigned int color)
{
	for (int i = 0; i < num; i++) {
		std::unique_ptr<Burst> newBurst = std::make_unique<Burst>();
		newBurst->Initialize(angle,pow);
		newBurst->pos_ = pos;
		newBurst->r_ = r;
		newBurst->timer_ = timer;
		newBurst->color_ = color;
		burst_.push_back(std::move(newBurst));
	}
}

void Particle::FireGenerate(Vec2 pos, int r)
{
	for (int i = 0; i < 10; i++) {
		//ランダム
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

void Particle::WaterGenerate(Vec2 pos, int r)
{
	for (int i = 0; i < 5; i++) {
		std::unique_ptr<Water> newWater = std::make_unique<Water>();
		newWater->Initialize();
		newWater->pos_ = pos;
		newWater->r_ = r;
		water_.push_back(std::move(newWater));
	}
}

void Particle::LightningGenerate(Vec2 pos, int length, int num,int time,bool horizontal)
{
	for (int i = 0; i < num; i++) {
		std::unique_ptr<Lightning> newLightning = std::make_unique<Lightning>();
		newLightning->pos_ = pos;
		newLightning->length_ = length;
		newLightning->time_ = time;
		newLightning->horizontal_ = horizontal;
		lightning_.push_back(std::move(newLightning));
	}
}

void Particle::BuffGenerate(Vec2 pos,Vec2 random)
{
	//ランダム
	std::random_device seed_gen;
	std::mt19937_64 engine(seed_gen());
	std::uniform_real_distribution<float> rand(0.0f, 7.0f);

	if (static_cast<int>(rand(engine)) == 0) {
		std::unique_ptr<Buff> newBuff = std::make_unique<Buff>();

		std::uniform_real_distribution<float> x(-random.x, random.x);
		std::uniform_real_distribution<float> y(-random.y, random.y);

		newBuff->pos_.x = pos.x + x(engine);
		newBuff->pos_.y = pos.y + y(engine);
		buff_.push_back(std::move(newBuff));
	}
}

void Particle::Update()
{
	//飛び散る
	burst_.remove_if([](std::unique_ptr<Burst>& burst) {return burst->isDead_; });
	for (std::unique_ptr<Burst>& burst : burst_) {
		burst->Update();
	}
	//火
	fire_.remove_if([](std::unique_ptr<Fire>& fire) {return fire->isDead_; });
	for (std::unique_ptr<Fire>& fire : fire_) {
		fire->Update();
	}
	//水
	water_.remove_if([](std::unique_ptr<Water>& water) {return water->isDead_; });
	for (std::unique_ptr<Water>& water : water_) {
		water->Update();
	}
	//雷
	lightning_.remove_if([](std::unique_ptr<Lightning>& lightning) {return lightning->isDead_; });
	for (std::unique_ptr<Lightning>& lightning : lightning_) {
		lightning->Update();
	}
	//バフ
	buff_.remove_if([](std::unique_ptr<Buff>& buff) {return buff->isDead_; });
	for (std::unique_ptr<Buff>& buff : buff_) {
		buff->Update();
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
	for (std::unique_ptr<Water>& water : water_) {
		water->Draw();
	}
	for (std::unique_ptr<Lightning>& lightning : lightning_) {
		lightning->Draw();
	}
	for (std::unique_ptr<Buff>& buff : buff_) {
		buff->Draw();
	}
}
