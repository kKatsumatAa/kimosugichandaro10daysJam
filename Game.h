#pragma once
#include "Scene.h"
#include "KeyboardInput.h"
#include "Particle.h"
#include "CardMove.h"
#include "CharacterManager.h"
#include "CardManager.h"

class GameScene :public Iscene
{
private:
	KeyboardInput& key;
	bool isEnd;
	Iscene* nextScene;

	Player player;
	
	Enemy enemy[3];

	CharacterManager charaM;

	CardManager cardM;
	
	Cost cost;
	//
	unsigned int texhandle = LoadGraph("resources/a.png");
	

public:
	GameScene(KeyboardInput& key);
	~GameScene();
	void Update() override;
	void Draw() override;
	bool IsEnd() override;
	Iscene* GetNextScene() override;

	Particle* particle_ = nullptr;
	CardMove* cardMove_ = nullptr;
};
