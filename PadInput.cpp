#include "PadInput.h"
#include "DxLib.h"

void PadInput::Update()
{
	//ReSetupJoypad();

	oldInput = input;
	GetJoypadXInputState(DX_INPUT_PAD1, &input);

	GetJoypadAnalogInput(&stickInputX, &stickInputY, DX_INPUT_PAD1);
}

void PadInput::ResetPad()
{
	ReSetupJoypad();//‚¤‚ñ‚±
}

int PadInput::GetPadNum()
{
	return GetJoypadNum();
}

int PadInput::GetButtonInput(const int& button)
{
	if (input.Buttons[button]) return 1;
	return 0;
}

int PadInput::GetButtonTrigger(const int& button)
{
	if (input.Buttons[button] && !oldInput.Buttons[button]) return 1;
	return 0;
}

int PadInput::GetButtonRelease(const int& button)
{
	if (!input.Buttons[button] && oldInput.Buttons[button]) return 1;
	return 0;
}

Vec2 PadInput::GetStickInput()
{
	Vec2 vec;

	if (stickInputX > 0)      stickInputX = 1;
	else if (stickInputX < 0) stickInputX = -1;
	else                      stickInputX = 0;

	if (stickInputY > 0)      stickInputY = 1;
	else if (stickInputY < 0) stickInputY = -1;
	else                      stickInputY = 0;

	vec = { (double)stickInputX,(double)stickInputY };

	return vec;
}
