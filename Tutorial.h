#pragma once
#include"Mouse.h"

static enum TUTORIAL
{
	BATTLE,
	CARD,
	WASTE,
	BREAK,
};

class Tutorial;

class TutorialState
{
protected:
	Tutorial* tutorial;
	float count = 0;

public:
	void SetTutorial(Tutorial* tutorial) { this->tutorial = tutorial; }
	virtual void Update(Mouse* mouse) = 0;
	virtual void Draw(unsigned int* texhandle) = 0;
	
	virtual void AddNum() = 0;
	virtual int GetNum() = 0;
	virtual int GetMaxNum() = 0;
};


class Tutorial
{
private:
	//シンプルなステート（処理用
	TutorialState* state = nullptr;
	//外部から今行ってるチュートリアルが分かるようにした変数
	int state2 = BATTLE;
	bool isEnd = false;
	float count = 0;

public:

	void Initialize();
	void Update(Mouse* mouse);
	void Draw(unsigned int* texhandle);

	int GetState() { return state2; }
	void AddState2() { state2++; }
	void AddState() { state->AddNum(); }

	int GetStateNum() { return state->GetNum(); }
	int GetStateNumMax() { return state->GetMaxNum(); }

	bool GetIsEnd() { return isEnd; }

	void SetIsEnd(bool isEnd) { this->isEnd = isEnd; }

	void ChangeState(TutorialState* state)
	{
		delete this->state;
		this->state = state;
		state->SetTutorial(this);
	}
};


//----------------------------------------------------------
class BattleTutrial :public TutorialState
{
private:
	int num = 0;
	const int numMax = 2;
	int texhandle[4];

public:
	BattleTutrial();


	void AddNum()override { num++; }
	int GetNum()override { return num; }
	int GetMaxNum()override { return numMax; }

	void Update(Mouse* mouse) override;
	void Draw(unsigned int* texhandle) override;
};

class CardTutrial :public TutorialState
{
private:
public:
	int num = 0;
	const int numMax = 3;
	int texhandle[7];

	CardTutrial();

	void AddNum()override { num++; }
	int GetNum()override { return num; }
	int GetMaxNum()override { return numMax; }

	void Update(Mouse* mouse) override;
	void Draw(unsigned int* texhandle) override;
};

class WasteTutrial :public TutorialState
{
private:
public:
	int num = 0;
	const int numMax = 3;
	int texhandle[7];

	WasteTutrial();

	void AddNum()override { num++; }
	int GetNum()override { return num; }
	int GetMaxNum()override { return numMax; }

	void Update(Mouse* mouse) override;
	void Draw(unsigned int* texhandle) override;
};

class BreakTutrial :public TutorialState
{
private:
public:
	int num = 0;
	const int numMax = 3;
	int texhandle[7];


	BreakTutrial();

	void AddNum()override { num++; }
	int GetNum()override { return num; }
	int GetMaxNum()override { return numMax; }

	void Update(Mouse* mouse) override;
	void Draw(unsigned int* texhandle) override;
};

