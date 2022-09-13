#pragma once
class Cost
{
private:
	float costGauge = 0;
	int color[4] = { 0 };
	const int costMax = 4;
	int selectCost = 0;
	float count = 0;

public:
	void Initialize();
	void Update();
	void Draw(unsigned int* texhandle);

	int GetCost() { return (int)costGauge; }
	void UseCost(int cost) { costGauge -= cost; }
	void AddCost(int cost);
	void SelectCost(int cost) { selectCost = cost; }
};

