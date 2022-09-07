#include "KeyboardInput.h"
#include "DxLib.h"
#include <dinput.h>

void KeyboardInput::Update()
{
	// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
	for (int i = 0; i < 256; ++i)
	{
		oldkeys[i] = keys[i];
	}

	// �ŐV�̃L�[�{�[�h�����擾
	GetHitKeyStateAll(keys);
}

bool KeyboardInput::GetKey(const int& key)
{
	return keys[key];
}

bool KeyboardInput::GetKeyTrigger(const int& key)
{
	return (keys[key] && !oldkeys[key]);
}

bool KeyboardInput::GetKeyReleaced(const int& key)
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
