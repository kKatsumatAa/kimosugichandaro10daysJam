#include "Game.h"
#include "DxLib.h"
#include "Result.h"
#include "Title.h"

GameScene::GameScene(KeyboardInput& key):
	key(key), isEnd(false),
	nextScene(new ResultScene(key))//Œ³‚ÍƒŠƒUƒ‹ƒg‚ª“ü‚Á‚Ä‚é
{
}

void GameScene::Update()
{
	if (key.GetKeyTrigger(KEY_INPUT_SPACE)) isEnd = true;
	else if (key.GetKeyTrigger(KEY_INPUT_Q))
	{
		isEnd = true;
		delete nextScene;
		nextScene = new TitleScene(key);
	}
}

void GameScene::Draw()
{
	DrawFormatString(0, 0, 0xFFFFFF, "GAME");
}

bool GameScene::IsEnd()
{
	return isEnd;
}

Iscene* GameScene::GetNextScene()
{
	return nextScene;
}
