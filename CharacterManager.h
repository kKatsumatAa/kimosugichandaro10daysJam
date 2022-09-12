#pragma once
#include"Enemy.h"
#include"Particle.h"

class CharacterManager
{
private:
	Player* player = nullptr;
	Enemy* enemy = nullptr;
	Particle* particle = nullptr;

	bool isBattle = false;

	int enemyNum = 0;

	bool isEnd = false;

	const int enemyMax = 4;

public:
	void Initialize(Player* player, Enemy* enemy);

	void Update();
	void Draw();

	Player* GetPlayer() { return player; }
	Enemy* GetEnemy() { return &enemy[enemyNum]; }

	bool GetIsBattle() { return isBattle; }

	bool GetIsEnd() { return isEnd; }
};

