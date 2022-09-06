#include "Title.h"
#include "DxLib.h"
#include "Game.h"

TitleScene::TitleScene(KeyboardInput& key):
	key(key), isEnd(false)
{
}

void TitleScene::Update()
{
	if (key.GetKeyTrigger(KEY_INPUT_SPACE)) isEnd = true;
}

void TitleScene::Draw()
{
	DrawFormatString(0, 0, 0xFFFFFF, "TITLE");
}

bool TitleScene::IsEnd()
{
	return isEnd;
}

Iscene* TitleScene::GetNextScene()
{
	return new GameScene(key);
}
