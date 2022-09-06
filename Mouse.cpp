#include "Mouse.h"
#include "DxLib.h"

void Mouse::Update()
{
	oldclickdata = clickdata;
	GetMousePoint(&x, &y);
	clickdata = GetMouseInput();
}

int Mouse::GetX()
{
	return x;
}

int Mouse::GetY()
{
	return y;
}

bool Mouse::GetLeftClick()
{
	return clickdata & MOUSE_INPUT_LEFT;
}

bool Mouse::GetLeftClickTrriger()
{
	return (clickdata & MOUSE_INPUT_LEFT && !(oldclickdata & MOUSE_INPUT_LEFT));
}

bool Mouse::GetLeftClickRelesed()
{
	return (!(clickdata & MOUSE_INPUT_LEFT) && (oldclickdata & MOUSE_INPUT_LEFT));
}
