#include "Cost.h"
#include "DxLib.h"

void Cost::Initialize()
{
	costGauge = 0;
}

void Cost::Update()
{
	if (costGauge < 3.0f)
	{
		costGauge += 0.01f;
	}
}

void Cost::Draw(unsigned int* texhandle)
{
	DrawBox(1920 / 2 - 300, 100, 1920 / 2 - 300 + (200 * costGauge), 130, 0xaaaa00, true);

	DrawLine(1920 / 2 - 300 + 600 / 3, 100, 1920 / 2 - 300 + 600 / 3, 130, 0xffffff);
	DrawLine(1920 / 2 - 300 + 600 / 3 * 2, 100, 1920 / 2 - 300 + 600 / 3 * 2, 130, 0xffffff);
}
