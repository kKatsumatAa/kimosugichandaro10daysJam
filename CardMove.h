#pragma once
#include "Dxlib.h"
#include "Util.h"
#include "Mouse.h"

struct CardInfo
{
	Vec2 pos_;
	Vec2 move_;
	int space_;
	bool isMove_;
	bool isHit_;
	bool isSelect_;
};

class CardMove
{
public:
	void Initialize();

	void Update();

	void Draw();

	//éËéDÇÃèÍèä
	bool isSpace[5];
	static const int CARD_CONST = 20;
	CardInfo card[CARD_CONST];

	Vec2 cardSize = { 160,280 };
	Vec2 handSpace1 = { 400,800 };
	Vec2 handSpace2 = { 600,800 };
	Vec2 handSpace3 = { 800,800 };
	Vec2 handSpace4 = { 1000,800 };
	Vec2 handSpace5 = { 1200,800 };

	Mouse* mouse_ = new Mouse;
};

