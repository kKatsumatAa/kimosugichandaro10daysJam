#include "Orb.h"

void Orb::Initialize()
{
}

void Orb::Update()
{

}

void Orb::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,255);
	SetDrawBlendMode(DX_BLENDMODE_ADD, 196);
	DrawCircle(pos_.x, pos_.y, 20, GetColor(8, 72, 2), true);
	DrawCircle(pos_.x, pos_.y, 15, GetColor(32, 0, 12), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
