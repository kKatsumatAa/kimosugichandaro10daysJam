#pragma once
#include "Util.h"
#include "Burst.h"
#include "Fire.h"
#include "Water.h"
#include "Lightning.h"
#include "Buff.h"

#include <list>
#include <memory>

class Particle
{
public:
	void Initialize();

	//弾け飛ぶ
	void BurstGenerate(Vec2 pos, int r, int num, int time, float angle,float pow, unsigned int color);
	//火
	void FireGenerate(Vec2 pos, int r);
	//水
	void WaterGenerate(Vec2 pos, int r);
	//雷
	void LightningGenerate(Vec2 pos,int length,int num,int time,bool horizontal);
	//バフ
	void BuffGenerate(Vec2 pos, Vec2 random);

	void Update();

	void Draw();


	//弾け飛ぶ
	std::list<std::unique_ptr<Burst>> burst_;
	//火
	std::list<std::unique_ptr<Fire>> fire_;
	//水
	std::list<std::unique_ptr<Water>> water_;
	//雷
	std::list<std::unique_ptr<Lightning>> lightning_;
	//バフ
	std::list<std::unique_ptr<Buff>> buff_;

};

