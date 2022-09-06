#pragma once
#include "Scene.h"
#include "KeyboardInput.h"

class TitleScene :public Iscene
{
private:
	KeyboardInput& key;
	bool isEnd;

public:
	TitleScene(KeyboardInput& key);
	void Update() override;
	void Draw() override;
	bool IsEnd() override;
	Iscene* GetNextScene() override;
};