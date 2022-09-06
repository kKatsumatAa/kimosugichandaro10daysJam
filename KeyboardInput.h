#pragma once

class KeyboardInput
{
private:
	char keys[256];
	char oldkeys[256];

public:
	void Update();
	bool GetKey(const char &key);
	bool GetKeyTrigger(const char &key);
	bool GetKeyReleaced(const char &key);
	int GetHorizontal();
	int GetVertical();
};