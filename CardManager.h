#pragma once
#include"Card.h"
#include"KeyboardInput.h"
#include"DxLib.h"
#include <list>
#include <iostream>
#include "Cost.h"

static const int attackMax = 8;
static const int guardMax = 5;
static const int buffMax = 5;
static const int deBuffMax = 2;

static const int deckMax = attackMax + guardMax + buffMax + deBuffMax;



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

};

