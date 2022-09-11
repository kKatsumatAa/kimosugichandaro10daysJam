#pragma once
#include"Card.h"
#include"KeyboardInput.h"
#include"DxLib.h"
#include <list>
#include <iostream>
#include "Cost.h"
#include "Mouse.h"
#include "Particle.h"

static const int attackMax = 8;
static const int guardMax = 5;
static const int buffMax = 5;
static const int deBuffMax = 2;

static const int deckMax = attackMax + guardMax + buffMax + deBuffMax;

struct CardInfo
{
	Vec2 pos_;
	Vec2 move_;
	int space_;
	bool isMove_;
	bool isHit_;
	bool isSelect_;
	Vec2 chengeSize_;
	int alpha_;
	int type_;
};

enum CardSpace {
	Deck,
	Hand1,
	Hand2,
	Hand3,
	Hand4,
	Hand5,
	Trash,
	Delete
};

class CardManager
{
private:
	int handNum = 0;
	int handAllNum = 0;
	const int handNumtmp = 5;
	std::list<std::unique_ptr<Card>> deck;

public:
	void Initialize();
	void Update(KeyboardInput* key, Player* player, Enemy* enemy, Cost* cost, bool isBattle);
	void Draw(unsigned int* texhandle);

	void DeckSet();

public:
	//手札の場所
	bool isSpace[5];
	static const int CARD_CONST = 20;
	CardInfo card[CARD_CONST];

	Vec2 cardSize = { 160,240 };

	Vec2 deckSpace = { 1500,800 };
	Vec2 handSpace1 = { 400,800 };
	Vec2 handSpace2 = { 600,800 };
	Vec2 handSpace3 = { 800,800 };
	Vec2 handSpace4 = { 1000,800 };
	Vec2 handSpace5 = { 1200,800 };
	Vec2 handSpace6 = { 200,800 };

	Mouse* mouse_ = new Mouse;

	int mouseX, mouseY;
	int mouseClickPosY_;
	int cardGraph_[4][2];
	const int cardSpeed_ = 20;
	int handCount = 0;

	//パーティクル関連
	Particle* particle = nullptr;
	int buffTimer = 0;
	int debuffTimer = 0;
};

