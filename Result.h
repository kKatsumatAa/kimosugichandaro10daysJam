#pragma once
#include "Scene.h"
#include "KeyboardInput.h"

class ResultScene :public Iscene
{
private:
	KeyboardInput& key;
	bool isEnd;

public:
	ResultScene(KeyboardInput& key);
	void Update() override;
	void Draw() override;
	bool IsEnd() override;
	Iscene* GetNextScene() override;
};
