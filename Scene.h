#pragma once
#include"CharacterManager.h"


class Iscene
{
private:
	CharacterManager charaManager;

public:
	virtual ~Iscene() {};
	virtual void Update() =0;
	virtual void Draw() =0;
	virtual bool IsEnd() =0;
	virtual Iscene* GetNextScene() =0;
};

class NullScene//nullを入れたいときに使う
{
public:
	virtual ~NullScene() {};
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual bool IsEnd() = 0;
	virtual Iscene* GetNextScene() = 0;
};
