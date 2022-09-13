#pragma once
#include "Scene.h"
#include "KeyboardInput.h"
#include "Particle.h"
#include "CharacterManager.h"
#include "CardManager.h"
#include "Tutorial.h"

enum TITLESTATE
{
	TITLE,
	TUTORIAL
};

class TitleScene :public Iscene
{
private:

	Mouse mouse;
	int state = TITLE;

	int skipGauge = 120;

	KeyboardInput& key;
	bool isEnd;

	Player player;

	Enemy enemy;

	CharacterManager charaM;

	CardManager cardM;

	Cost cost;

	Tutorial tutorial;
	//
	unsigned int texhandle[10];
	unsigned int enemy1Texture[6];
	unsigned int playerTexture[9];
	unsigned int background;

public:
	TitleScene(KeyboardInput& key);
	void Update() override;
	void Draw() override;
	bool IsEnd() override;
	Iscene* GetNextScene() override;

	Particle* particle_ = nullptr;
};