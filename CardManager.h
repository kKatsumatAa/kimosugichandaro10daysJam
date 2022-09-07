#pragma once
#include"Card.h"
#include"KeyboardInput.h"
#include"DxLib.h"
#include <list>
#include <iostream>

class CardManager
{
private:
	int handNum = 0;
	std::list<std::unique_ptr<Card>> deck;

public:
	void Initialize();
	void Update(KeyboardInput* key, Player* player, Enemy* enemy);
	void Draw(unsigned int* texhandle);

};

