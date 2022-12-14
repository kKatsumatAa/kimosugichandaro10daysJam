#pragma once
#include "Util.h"
#include "Burst.h"
#include "Fire.h"
#include "Water.h"
#include "Lightning.h"
#include "Buff.h"
#include "Debuff.h"
#include "Slash.h"
#include "Orb.h"
#include "Number.h"

#include <list>
#include <memory>

class Particle
{
public:
	void Initialize();

	//e¯òÔ(Êu,¼a,Â,céÔ,Ëopx,òÔ­³,F)
	void BurstGenerate(Vec2 pos, int r, int num, int time, float angle,float pow, unsigned int color);
	//Î(Êu,¼a)
	void FireGenerate(Vec2 pos, int r);
	//(Êu,¼a)
	void WaterGenerate(Vec2 pos, int r);
	//(Êu,·³,Â,±Ô,¡É·é©(trueÅ¡))
	void LightningGenerate(Vec2 pos,int length,int num,int time,bool horizontal);
	//ot(SÊu,_ÅoéêÌÍÍ,¼a)
	void BuffGenerate(Vec2 pos, Vec2 random,int r);
	//fot(SÊu,_ÅoéêÌÍÍ,¼a)
	void DebuffGenerate(Vec2 pos, Vec2 random,int r);
	//a
	void SlashGenerate(Vec2 pos);
	//I[u
	void OrbGenerate(Vec2 start, Vec2 end);
	//
	void NumberGecerate(Vec2 pos, int way,int num);
	//VFCN
	Vec2 Shake(int &timer);

	void Update();

	void Draw();

	int buffTexture;
	int debuffTexture;


	//e¯òÔ
	std::list<std::unique_ptr<Burst>> burst_;
	//Î
	std::list<std::unique_ptr<Fire>> fire_;
	//
	std::list<std::unique_ptr<Water>> water_;
	//
	std::list<std::unique_ptr<Lightning>> lightning_;
	//ot
	std::list<std::unique_ptr<Buff>> buff_;
	//fot
	std::list<std::unique_ptr<Debuff>> debuff_;
	//a
	std::list<std::unique_ptr<Slash>> slash_;
	//I[u
	std::list<std::unique_ptr<Orb>> orb_;
	//
	std::list<std::unique_ptr<Number>> number_;
};

