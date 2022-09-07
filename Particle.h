#pragma once
#include "Util.h"
#include "Burst.h"
#include "Fire.h"
#include "Water.h"
#include <list>
#include <memory>

class Particle
{
public:
	void Initialize();

	//’e‚¯”ò‚Ô
	void BurstGenerate(Vec2 pos, int r, int num, int time, float angle, unsigned int color);
	//‰Î
	void FireGenerate(Vec2 pos, int r);
	//…
	void WaterGenerate(Vec2 pos, int r);

	void Update();

	void Draw();


	//’e‚¯”ò‚Ô
	std::list<std::unique_ptr<Burst>> burst_;
	//‰Î
	std::list<std::unique_ptr<Fire>> fire_;
	//…
	std::list<std::unique_ptr<Water>> water_;

};

