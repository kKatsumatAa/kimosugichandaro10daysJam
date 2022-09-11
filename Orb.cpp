#include "Orb.h"
#include <random>
#include "math.h"

void Orb::Initialize()
{
	//ƒ‰ƒ“ƒ_ƒ€
	std::random_device seed_gen;
	std::mt19937_64 engine(seed_gen());
	std::uniform_real_distribution<float> angle(-360.0f, 360.0f);

	midPos_ = { startPos_.x + cos(angle(engine) * 3.14 / 180) * 100,startPos_.y + sin(angle(engine) * 3.14 / 180) * 100 };
}

void Orb::Update()
{
	if (moveNum == 0) {
		Vec2 len = midPos_ - pos_;
		if (pos_.x == midPos_.x && pos_.y == midPos_.y) {
			moveNum = 1;
		}
		else {
			if (pos_.x != midPos_.x) {
				if (len.GetLength() >= speed) {
					pos_.x += len.x / len.GetLength() * speed;
				}
				else {
					pos_.x = midPos_.x;
				}
			}
			if (pos_.y != midPos_.y) {
				if (len.GetLength() >= speed) {
					pos_.y += len.y / len.GetLength() * speed;
				}
				else {
					pos_.y = midPos_.y;
				}
			}
		}
	}
	else if (moveNum == 1) {
		if (--stopTimer <= 0) {
			moveNum = 2;
		}
	}
	else if (moveNum == 2) {
		Vec2 len = endPos_ - pos_;
		if (pos_.x == endPos_.x && pos_.y == endPos_.y) {
			isDead_ = true;
		}
		else {
			if (pos_.x != endPos_.x) {
				if (len.GetLength() >= speed) {
					pos_.x += len.x / len.GetLength() * speed;
				}
				else {
					pos_.x = endPos_.x;
				}
			}
			if (pos_.y != endPos_.y) {
				if (len.GetLength() >= speed) {
					pos_.y += len.y / len.GetLength() * speed;
				}
				else {
					pos_.y = endPos_.y;
				}
			}
		}
	}
}

void Orb::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,255);
	SetDrawBlendMode(DX_BLENDMODE_ADD, 196);
	DrawCircle(pos_.x, pos_.y, 20, GetColor(100, 240, 90), true);
	DrawCircle(pos_.x, pos_.y, 18, GetColor(100, 60, 40), true);
	DrawCircle(pos_.x, pos_.y, 12, GetColor(160, 80, 140), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
