#include "Particle.h"
#include "Particle.h"
#include <random>

void Particle::Initialize() {
}

void Particle::BurstGenerate(Vec2 pos, int r, int num, int timer, float angle, float pow, unsigned int color)
{
	for (int i = 0; i < num; i++) {
		std::unique_ptr<Burst> newBurst = std::make_unique<Burst>();
		newBurst->Initialize(angle, pow);
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

void Particle::LightningGenerate(Vec2 pos, int length, int num, int time, bool horizontal)
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

void Particle::BuffGenerate(Vec2 pos, Vec2 random, int r)
{
	//ランダム
	std::random_device seed_gen;
	std::mt19937_64 engine(seed_gen());
	std::uniform_real_distribution<float> rand(0.0f, 5.0f);

	if (static_cast<int>(rand(engine)) == 0) {
		std::unique_ptr<Buff> newBuff = std::make_unique<Buff>();

		std::uniform_real_distribution<float> x(-random.x, random.x);
		std::uniform_real_distribution<float> y(-random.y, random.y);

		newBuff->pos_.x = pos.x + x(engine);
		newBuff->pos_.y = pos.y + random.y + y(engine);
		newBuff->r_ = r;
		buff_.push_back(std::move(newBuff));
	}
}

void Particle::DebuffGenerate(Vec2 pos, Vec2 random, int r)
{
	//ランダム
	std::random_device seed_gen;
	std::mt19937_64 engine(seed_gen());
	std::uniform_real_distribution<float> rand(0.0f, 5.0f);

	if (static_cast<int>(rand(engine)) == 0) {
		std::unique_ptr<Debuff> newDebuff = std::make_unique<Debuff>();

		std::uniform_real_distribution<float> x(-random.x, random.x);
		std::uniform_real_distribution<float> y(-random.y, random.y);

		newDebuff->pos_.x = pos.x + x(engine);
		newDebuff->pos_.y = pos.y - random.y + y(engine);
		newDebuff->r_ = r;
		debuff_.push_back(std::move(newDebuff));
	}
}

void Particle::SlashGenerate(Vec2 pos)
{
	std::unique_ptr<Slash> newSlash = std::make_unique<Slash>();
	newSlash->pos_ = pos;
	slash_.push_back(std::move(newSlash));
}

void Particle::OrbGenerate(Vec2 start, Vec2 end)
{
	std::unique_ptr<Orb> newOrb = std::make_unique<Orb>();
	newOrb->startPos_ = start;
	newOrb->pos_ = start;
	newOrb->endPos_ = end;
	newOrb->Initialize();
	orb_.push_back(std::move(newOrb));
}

void Particle::NumberGecerate(Vec2 pos, int way, int num) {
	std::unique_ptr<Number> newNumber = std::make_unique<Number>();
	newNumber->initialize();
	newNumber->pos_ = pos;
	newNumber->way_ = way;
	newNumber->num_ = num;
	number_.push_back(std::move(newNumber));
}

Vec2 Particle::Shake(int& timer)
{
	if (--timer > 0) {
		//ランダム
		std::random_device seed_gen;
		std::mt19937_64 engine(seed_gen());
		std::uniform_real_distribution<float> x(-20.0f, 20.0f);
		std::uniform_real_distribution<float> y(-20.0f, 20.0f);
		return Vec2(x(engine), y(engine));
	}
	else {
		return Vec2(0, 0);
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
	//デバフ
	debuff_.remove_if([](std::unique_ptr<Debuff>& debuff) {return debuff->isDead_; });
	for (std::unique_ptr<Debuff>& debuff : debuff_) {
		debuff->Update();
	}
	//斬撃
	slash_.remove_if([](std::unique_ptr<Slash>& slash) {return slash->isDead_; });
	for (std::unique_ptr<Slash>& slash : slash_) {
		slash->Update();
	}
	//オーブ
	orb_.remove_if([](std::unique_ptr<Orb>& orb) {return orb->isDead_; });
	for (std::unique_ptr<Orb>& orb : orb_) {
		orb->Update();
	}
	//数字
	number_.remove_if([](std::unique_ptr<Number>& number) {return number->isDead_; });
	for (std::unique_ptr<Number>& number : number_) {
		number->Update();
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
	for (std::unique_ptr<Debuff>& debuff : debuff_) {
		debuff->Draw();
	}
	for (std::unique_ptr<Slash>& slash : slash_) {
		slash->Draw();
	}
	for (std::unique_ptr<Orb>& orb : orb_) {
		orb->Draw();
	}
	for (std::unique_ptr<Number>& number : number_) {
		number->Draw();
	}
}
