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

	//�e�����(�ʒu,���a,��,�c�鎞��,�ˏo�p�x,��ԋ���,�F)
	void BurstGenerate(Vec2 pos, int r, int num, int time, float angle,float pow, unsigned int color);
	//��(�ʒu,���a)
	void FireGenerate(Vec2 pos, int r);
	//��(�ʒu,���a)
	void WaterGenerate(Vec2 pos, int r);
	//��(�ʒu,����,��,��������,���ɂ��邩(true�ŉ�))
	void LightningGenerate(Vec2 pos,int length,int num,int time,bool horizontal);
	//�o�t(���S�ʒu,�����_���ŏo��ꏊ�͈̔�,���a)
	void BuffGenerate(Vec2 pos, Vec2 random,int r);
	//�f�o�t(���S�ʒu,�����_���ŏo��ꏊ�͈̔�,���a)
	void DebuffGenerate(Vec2 pos, Vec2 random,int r);
	//�a��
	void SlashGenerate(Vec2 pos);
	//�I�[�u
	void OrbGenerate();

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
	//�o�t
	std::list<std::unique_ptr<Buff>> buff_;
	//�f�o�t
	std::list<std::unique_ptr<Debuff>> debuff_;
	//�a��
	std::list<std::unique_ptr<Slash>> slash_;
	//�I�[�u
	std::list<std::unique_ptr<Orb>> orb_;

};

