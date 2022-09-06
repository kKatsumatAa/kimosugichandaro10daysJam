#pragma once
#include "Util.h"
#include "Burst.h"
#include <list>
#include <memory>

class Particle
{
public:
	void Initialize();

	//’e‚¯”ò‚Ô
	void BurstGenerate(Vec2 pos, int r, int num, int time, float angle, unsigned int color);
	void Update();

	void Draw();


	//’e‚¯”ò‚Ô
	std::list<std::unique_ptr<Burst>> burst_;
};

