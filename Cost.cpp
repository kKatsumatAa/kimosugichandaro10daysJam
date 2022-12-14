#include "Cost.h"
#include "DxLib.h"
#include <math.h>

void Cost::Initialize()
{
	costGauge = 0;
}

void Cost::Update()
{
	if (costGauge < costMax)
	{
		costGauge += 0.01f;
	}
}

void Cost::Draw(unsigned int* texhandle)
{
	/*DrawBox(1920 / 2 - 300, 100, 1920 / 2 - 300 + (600 / 4 * costGauge), 130, 0xaaaa00, true);

	DrawLine(1920 / 2 - 300 + 600 / 4, 100, 1920 / 2 - 300 + 600 / 4, 130, 0xffffff);
	DrawLine(1920 / 2 - 300 + 600 / 4 * 2, 100, 1920 / 2 - 300 + 600 / 4 * 2, 130, 0xffffff);
	DrawLine(1920 / 2 - 300 + 600 / 4 * 3, 100, 1920 / 2 - 300 + 600 / 4 * 3, 130, 0xffffff);*/

	DrawRotaGraph(1920 / 2, 130, 2.5f, 0.0f, texhandle[2], true);

	//エナジーの玉
	if (costGauge >= 1.0f) color[0] = 0xffff00;
	else                   color[0] = 0x999900;
	if (costGauge >= 2.0f) color[1] = 0xffff00;
	else                   color[1] = 0x999900;
	if (costGauge >= 3.0f) color[2] = 0xffff00;
	else                   color[2] = 0x999900;
	if (costGauge >= 4.0f) color[3] = 0xffff00;
	else                   color[3] = 0x999900;

	DrawCircle(1920 / 2 - 36.0f * 2.5f, 130,  17.0f * min(costGauge, 1.0f), color[0]);
	DrawCircle(1920 / 2 - 5.0f * 2.5f, 130, 17.0f * min(costGauge - 1.0f, 1.0f), color[1]);
	DrawCircle(1920 / 2 + 27.0f * 2.5f, 130, 17.0f * min(costGauge - 2.0f, 1.0f), color[2]);
	DrawCircle(1920 / 2 + 58.0f * 2.5f, 130, 17.0f * min(costGauge - 3.0f, 1.0f), color[3]);

	count += 0.2f;

	float  R = 30.0f + sinf(count);

	for (int i = 1; i <= selectCost; i++)
	{
		switch (i)
		{
		case 1:
			DrawCircle(1920 / 2 - 36.0f * 2.5f, 130, R, 0xffff00, false, 3);
			break;
		case 2:
			DrawCircle(1920 / 2 - 5.0f * 2.5f, 130, R, 0xffff00, false, 3);
			break;
		case 3:
			DrawCircle(1920 / 2 + 27.0f * 2.5f, 130, R, 0xffff00, false, 3);
			break;
		}
	}
}

void Cost::AddCost(int cost)
{
	if (costGauge + cost >= costMax) costGauge = costMax;
	else                             costGauge += cost;
}
