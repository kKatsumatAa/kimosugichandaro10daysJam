#pragma once

class KeyboardInput
{
private:
	char keys[256] = {0};
	char oldkeys[256] = {0};

public:
	void Update();
	bool GetKey(const int &key);
	bool GetKeyTrigger(const int &key);
	bool GetKeyReleaced(const int &key);
	int GetHorizontal();
	int GetVertical();
};