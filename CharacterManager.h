#pragma once
#include"Enemy.h"

#include"Tutorial.h"

class CharacterManager
{
private:
	Player* player = nullptr;
	Enemy* enemy = nullptr;
	Particle* particle = nullptr;

	bool isBattle = false;

	int enemyNum = 0;

	bool isEnd = false;

	int enemyMax = 4;

public:
	void Initialize(Player* player, Enemy* enemy, int enemyMax = 5);

	void Update(Tutorial* tutorial = nullptr);
	void Draw();

	Player* GetPlayer() { return player; }
	Enemy* GetEnemy() { return &enemy[enemyNum]; }

	bool GetIsBattle() { return isBattle; }

	bool GetIsEnd() { return isEnd; }
};

