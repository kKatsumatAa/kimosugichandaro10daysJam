#include "KeyboardInput.h"
#include "DxLib.h"

void KeyboardInput::Update()
{
	// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
	for (int i = 0; i < 256; ++i)
	{
		oldkeys[i] = keys[i];
	}

	// 最新のキーボード情報を取得
	GetHitKeyStateAll(keys);
}

bool KeyboardInput::GetKey(const char& key)
{
	return keys[key];
}

bool KeyboardInput::GetKeyTrigger(const char& key)
{
	return (keys[key] && !oldkeys[key]);
}

bool KeyboardInput::GetKeyReleaced(const char& key)
{
	return (!keys[key] && oldkeys[key]);
}

int KeyboardInput::GetHorizontal()
{
	if(keys[KEY_INPUT_RIGHT])return  1;
	if(keys[KEY_INPUT_LEFT]) return -1;
	else                     return  0;
}

int KeyboardInput::GetVertical()
{
	if (keys[KEY_INPUT_DOWN])return  1;
	if (keys[KEY_INPUT_UP])  return -1;
	else                     return  0;
}
