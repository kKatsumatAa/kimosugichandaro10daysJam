#pragma once
#include"Enemy.h"

#include"Tutorial.h"
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

	int enemyMax = 4;
	int shakeTimer = 0;
	int hitStopTimer = 0;

public:
	void Initialize(Player* player, Enemy* enemy, int enemyMax = 5);

	void Update(Tutorial* tutorial = nullptr);
	void Draw();

	Player* GetPlayer() { return player; }
	Enemy* GetEnemy() { return &enemy[enemyNum]; }

	bool GetIsBattle() { return isBattle; }
	int GetShakeTimer() {
		return shakeTimer;
	}
	void ResetShakeTimer() {
		shakeTimer = 0;
	}
	int GetHitStopTimer() {
		return hitStopTimer;
	}
	void SetHitStopTimer(int time) {
		hitStopTimer = time;
	}
	void ResetHitStopTimer() {
		hitStopTimer = 0;
	}

	bool GetIsEnd() { return isEnd; }
};

