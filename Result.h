#pragma once
#include "Scene.h"
#include "KeyboardInput.h"
#include "Mouse.h"

class ResultScene :public Iscene
{
private:
	KeyboardInput& key;
	bool isEnd;
	Mouse mouse;

public:
	ResultScene(KeyboardInput& key);
	void Update() override;
	void Draw() override;
	bool IsEnd() override;
	Iscene* GetNextScene() override;
};
