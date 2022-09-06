#include "Result.h"
#include "DxLib.h"
#include "Title.h"

ResultScene::ResultScene(KeyboardInput& key) :
	key(key), isEnd(false)
{
}

void ResultScene::Update()
{
	if (key.GetKeyTrigger(KEY_INPUT_SPACE)) isEnd = true;
}

void ResultScene::Draw()
{
	DrawFormatString(0, 0, 0xFFFFFF, "RESULT");
}

bool ResultScene::IsEnd()
{
	return isEnd;
}

Iscene* ResultScene::GetNextScene()
{
	return new TitleScene(key);
}
