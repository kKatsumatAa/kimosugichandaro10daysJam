#pragma once
class Cost
{
private:
	float costGauge = 0;
	int color[4] = { 0 };


public:
	void Initialize();
	void Update();
	void Draw(unsigned int* texhandle);

	int GetCost() { return (int)costGauge; }
	void UseCost(int cost) { costGauge -= cost; }

};

