#pragma once
#include "DxLib.h"
#include "Util.h"

class PadInput
{
private:
	XINPUT_STATE input;
	XINPUT_STATE oldInput;
	int          stickInputX;
	int          stickInputY;

public:
	void   Update();
	void   ResetPad();
	int    GetPadNum();
	int    GetButtonInput(const int& button);
	int    GetButtonTrigger(const int& button);
	int    GetButtonRelease(const int& button);
	Vec2   GetStickInput();
};