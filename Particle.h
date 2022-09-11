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

#include <list>
#include <memory>

class Particle
{
public:
	void Initialize();

	//弾け飛ぶ(位置,半径,個数,残る時間,射出角度,飛ぶ強さ,色)
	void BurstGenerate(Vec2 pos, int r, int num, int time, float angle,float pow, unsigned int color);
	//火(位置,半径)
	void FireGenerate(Vec2 pos, int r);
	//水(位置,半径)
	void WaterGenerate(Vec2 pos, int r);
	//雷(位置,長さ,個数,持続時間,横にするか(trueで横))
	void LightningGenerate(Vec2 pos,int length,int num,int time,bool horizontal);
	//バフ(中心位置,ランダムで出る場所の範囲,半径)
	void BuffGenerate(Vec2 pos, Vec2 random,int r);
	//デバフ(中心位置,ランダムで出る場所の範囲,半径)
	void DebuffGenerate(Vec2 pos, Vec2 random,int r);
	//斬撃
	void SlashGenerate(Vec2 pos);
	//オーブ
	void OrbGenerate();

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
	//デバフ
	std::list<std::unique_ptr<Debuff>> debuff_;
	//斬撃
	std::list<std::unique_ptr<Slash>> slash_;
	//オーブ
	std::list<std::unique_ptr<Orb>> orb_;

};

