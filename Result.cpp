#include "Result.h"
#include "DxLib.h"
#include "Title.h"

ResultScene::ResultScene(KeyboardInput& key) :
	key(key), isEnd(false)
{
	texhandle[0] = LoadGraph("resources/game_clear.png");
}

void ResultScene::Update()
{
	mouse.Update();
	timer++;

	if (timer >= 180 || (timer > 1 && mouse.GetLeftClickTrriger())) isEnd = true;
}

void ResultScene::Draw()
{
	DrawGraph(0, 0, texhandle[0], true);
}

bool ResultScene::IsEnd()
{
	return isEnd;
}

Iscene* ResultScene::GetNextScene()
{
	return new TitleScene(key);
}
