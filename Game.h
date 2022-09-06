#pragma once
#include "Scene.h"
#include "KeyboardInput.h"

class GameScene :public Iscene
{
private:
	KeyboardInput& key;
	bool isEnd;
	Iscene* nextScene;

public:
	GameScene(KeyboardInput& key);
	void Update() override;
	void Draw() override;
	bool IsEnd() override;
	Iscene* GetNextScene() override;
};
