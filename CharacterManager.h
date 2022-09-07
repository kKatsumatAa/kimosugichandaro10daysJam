#pragma once
#include"Enemy.h"

class CharacterManager
{
private:
	Player* player = nullptr;
	Enemy* enemy = nullptr;

	bool isBattle = false;

	int enemyNum = 0;

	bool isEnd = false;

public:
	void Initialize(Player* player, Enemy* enemy);

	void Update();
	void Draw();

	Player* GetPlayer() { return player; }
	Enemy* GetEnemy() { return &enemy[enemyNum]; }
};

