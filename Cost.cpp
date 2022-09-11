#include "Cost.h"
#include "DxLib.h"

void Cost::Initialize()
{
	costGauge = 0;
}

void Cost::Update()
{
	if (costGauge < 4.0f)
	{
		costGauge += 0.01f;
	}
}

void Cost::Draw(unsigned int* texhandle)
{
	DrawBox(1920 / 2 - 300, 100, 1920 / 2 - 300 + (600 / 4 * costGauge), 130, 0xaaaa00, true);

	DrawLine(1920 / 2 - 300 + 600 / 4, 100, 1920 / 2 - 300 + 600 / 4, 130, 0xffffff);
	DrawLine(1920 / 2 - 300 + 600 / 4 * 2, 100, 1920 / 2 - 300 + 600 / 4 * 2, 130, 0xffffff);
	DrawLine(1920 / 2 - 300 + 600 / 4 * 3, 100, 1920 / 2 - 300 + 600 / 4 * 3, 130, 0xffffff);
}
