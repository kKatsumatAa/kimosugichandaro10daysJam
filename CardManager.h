#pragma once
#include"Card.h"
#include"KeyboardInput.h"
#include"DxLib.h"
#include <list>
#include <iostream>
#include "Cost.h"
#include "Mouse.h"
#include "Particle.h"
#include "Tutorial.h"

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
	int attackMaxBattle = attackMax;
	int guardMaxBattle = guardMax;
	int buffMaxBattle = buffMax;
	int deBuffMaxBattle = deBuffMax;

	int deckMaxBattle = attackMax + guardMax + buffMax + deBuffMax;

	int handNum = 0;
	int handAllNum = 0;
	const int handNumtmp = 5;
	std::list<std::unique_ptr<Card>> deck;
	std::list<std::unique_ptr<Card>> deck2;

public:
	void Initialize();
	void Update(KeyboardInput* key, Player* player, Enemy* enemy, Cost* cost, bool isBattle, Tutorial* tutorial = nullptr);
	void Draw(unsigned int* texhandle);

	void DeckSet();
	int GetShakeTimer() {
		return shakeTimer;
	}
	void ResetShakeTimer() {
		shakeTimer = 0;
	}

public:
	//手札の場所
	bool isSpace[5];
	static const int CARD_CONST = 20;
	CardInfo card[CARD_CONST];

	Vec2 cardSize = { 160,240 };

	Vec2 deckSpace = { 1720,900 };
	Vec2 handSpace1 = { 460,900 };
	Vec2 handSpace2 = { 710,900 };
	Vec2 handSpace3 = { 960,900 };
	Vec2 handSpace4 = { 1210,900 };
	Vec2 handSpace5 = { 1460,900 };
	Vec2 handSpace6 = { 200,900 };

	Mouse* mouse_ = new Mouse;

	int mouseX, mouseY;
	int mouseClickPosY_;

	int cardGraph_[4][2];
	int deckGraph_;
	int trashGraph_;

	const int cardSpeed_ = 20;
	int handCount = 0;

	//パーティクル関連
	Particle* particle = nullptr;
	int buffTimer = 0;
	int debuffTimer = 0;
	int shakeTimer = 0;
};

