#pragma once
#include "Util.h"
#include "Burst.h"
#include "Fire.h"
#include "Water.h"
#include "Lightning.h"
#include <list>
#include <memory>

class Particle
{
public:
	void Initialize();

	//�e�����
	void BurstGenerate(Vec2 pos, int r, int num, int time, float angle,float pow, unsigned int color);
	//��
	void FireGenerate(Vec2 pos, int r);
	//��
	void WaterGenerate(Vec2 pos, int r);
	//��
	void LightningGenerate(Vec2 pos,int length,int num,int time,bool horizontal);

	void Update();

	void Draw();


	//�e�����
	std::list<std::unique_ptr<Burst>> burst_;
	//��
	std::list<std::unique_ptr<Fire>> fire_;
	//��
	std::list<std::unique_ptr<Water>> water_;
	//��
	std::list<std::unique_ptr<Lightning>> lightning_;

};

