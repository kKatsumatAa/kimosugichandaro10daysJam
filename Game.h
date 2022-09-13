#pragma once
#include "Scene.h"
#include "KeyboardInput.h"
#include "Particle.h"
#include "CharacterManager.h"
#include "CardManager.h"

class GameScene :public Iscene
{
private:
	KeyboardInput& key;
	bool isEnd;
	Iscene* nextScene;

	Player player;
	
	Enemy enemy[5];

	CharacterManager charaM;

	CardManager cardM;
	
	Cost cost;
	//
	unsigned int texhandle[10];
	unsigned int playerTexture[9];
	unsigned int enemy1Texture[6];
	unsigned int enemy2Texture[6];
	unsigned int enemy3Texture[6];
	unsigned int enemy4Texture[6];
	unsigned int enemy5Texture[6];
	unsigned int enemy6Texture[6];
	unsigned int background;
	int shakeTimer = 0;
	int hitStopTimer = 0;
	int numText[10];
public:
	GameScene(KeyboardInput& key);
	~GameScene();
	void Update() override;
	void Draw() override;
	bool IsEnd() override;
	Iscene* GetNextScene() override;

	Particle* particle_ = nullptr;
};
