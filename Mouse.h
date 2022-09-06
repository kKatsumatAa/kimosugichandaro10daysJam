#pragma once

class Mouse
{
private:
	int x;
	int y;
	int clickdata;
	int oldclickdata;

public:
	void Update();
	int  GetX();
	int  GetY();
	bool GetLeftClick();
	bool GetLeftClickTrriger();
	bool GetLeftClickRelesed();
};