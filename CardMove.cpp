#include "CardMove.h"

void CardMove::Initialize()
{
	for (int i = 0; i < CARD_CONST; i++) {
		card[i].pos_ = { 1500,800 };
		card[i].move_ = { 0,0 };
		card[i].space_ = 0;
		card[i].isMove_ = 0;
		card[i].isHit_ = 0;
	}
	cardGraph_ = LoadGraph("resources/card_attack_prototype.png");
}

void CardMove::Update()
{
	int mouseX, mouseY;
	GetMousePoint(&mouseX, &mouseY);

	for (int i = 0; i < 5; i++) {
		//手札にカードがあるか
		isSpace[i] = false;
	}
	for (int i = 0; i < CARD_CONST; i++) {
		//手札の場所にカードがあればtrueに
		if (card[i].space_ - 1 >= 0) {
			isSpace[card[i].space_ - 1] = true;
		}
	}
	//手札の配布
	for (int i = 0; i < CARD_CONST; i++) {
		if (isSpace[0] == false) {
			if (card[i].space_ == 0) {
				card[i].space_ = 1;
				isSpace[0] = true;
			}
		}
		else if (isSpace[1] == false) {
			if (card[i].space_ == 0) {
				card[i].space_ = 2;
				isSpace[1] = true;
			}
		}
		else if (isSpace[2] == false) {
			if (card[i].space_ == 0) {
				card[i].space_ = 3;
				isSpace[2] = true;
			}
		}
		else if (isSpace[3] == false) {
			if (card[i].space_ == 0) {
				card[i].space_ = 4;
				isSpace[3] = true;
			}
		}
		else if (isSpace[4] == false) {
			if (card[i].space_ == 0) {
				card[i].space_ = 5;
				isSpace[4] = true;
			}
		}
	}
	for (int i = 0; i < CARD_CONST; i++) {
		card[i].isMove_ = false;
	}

	//手札を指定の場所まで動かす
	for (int i = 0; i < CARD_CONST; i++) {

		if (card[i].space_ == 1) {
			if (card[i].pos_.x != handSpace1.x && card[i].isSelect_ == false) {
				card[i].pos_.x -= 20;
				card[i].isMove_ = true;
			}
		}
		if (card[i].space_ == 2) {
			if (card[i].pos_.x != handSpace2.x && card[i].isSelect_ == false) {
				card[i].pos_.x -= 20;
				card[i].isMove_ = true;
			}
		}
		if (card[i].space_ == 3) {
			if (card[i].pos_.x != handSpace3.x && card[i].isSelect_ == false) {
				card[i].pos_.x -= 20;
				card[i].isMove_ = true;
			}
		}
		if (card[i].space_ == 4) {
			if (card[i].pos_.x != handSpace4.x && card[i].isSelect_ == false) {
				card[i].pos_.x -= 20;
				card[i].isMove_ = true;
			}
		}
		if (card[i].space_ == 5) {
			if (card[i].pos_.x != handSpace5.x && card[i].isSelect_ == false) {
				card[i].pos_.x -= 20;
				card[i].isMove_ = true;
			}
		}
		if (card[i].space_ == 6) {
			if (card[i].pos_.x != handSpace5.x && card[i].isSelect_ == false) {
				card[i].pos_.y -= 20;
				card[i].isMove_ = true;
			}
		}
	}

	///手札とマウスの当たり判定
	//すでにマウスでつかんでいたら判定をとらない
	bool isCatch = false;
	for (int i = 0; i < CARD_CONST; i++) {
		if (card[i].isSelect_ == true) {
			isCatch = true;
		}
	}
	for (int i = 0; i < CARD_CONST; i++) {
		if (isCatch == true) {
			break;
		}

		//初期化
		card[i].isHit_ = false;
		if (card[i].space_ != 0 && card[i].isMove_ == false) {
			if (card[i].pos_.x - cardSize.x / 2 < mouseX && card[i].pos_.x + cardSize.x / 2 > mouseX) {
				if (card[i].pos_.y - cardSize.y / 2 < mouseY && card[i].pos_.y + cardSize.y / 2 > mouseY) {
					card[i].isHit_ = true;
				}
			}
		}
	}

	//手札とマウスの当たり判定をプレイヤーに分かりやすく
	for (int i = 0; i < CARD_CONST; i++) {
		if (card[i].isHit_ == true) {
			card[i].move_.y = -50;
		}
		else {
			card[i].move_.y = 0;
		}
	}

	//カードの選択
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {

		for (int i = 0; i < CARD_CONST; i++) {
			if (card[i].isHit_ == true) {
				card[i].isSelect_ = true;
			}
		}
	}
	else {
		for (int i = 0; i < CARD_CONST; i++) {
			if (card[i].pos_.y <= 500) {
				card[i].space_ = 6;
			}
			else if(card[i].isMove_ == false) {
				if (card[i].space_ == 1) {
					card[i].pos_ = handSpace1;
				}
				if (card[i].space_ == 2) {
					card[i].pos_ = handSpace2;
				}
				if (card[i].space_ == 3) {
					card[i].pos_ = handSpace3;
				}
				if (card[i].space_ == 4) {
					card[i].pos_ = handSpace4;
				}
				if (card[i].space_ == 5) {
					card[i].pos_ = handSpace5;
				}
			}
			card[i].isSelect_ = false;
		}
	}
	for (int i = 0; i < CARD_CONST; i++) {
		if (card[i].isSelect_ == true) {
			card[i].pos_.x = mouseX;
			card[i].pos_.y = mouseY;
		}
	}
}

void CardMove::Draw()
{
	for (int i = 0; i < CARD_CONST; i++) {
		if (card[i].space_ == 0) {
			DrawBox(
				card[i].pos_.x - (cardSize.x / 2),
				card[i].pos_.y - (cardSize.y / 2) + card[i].move_.y,
				card[i].pos_.x + (cardSize.x / 2),
				card[i].pos_.y + (cardSize.y / 2) + card[i].move_.y,
				GetColor(100, 100, 100),
				true
			);
		}
		else {
			DrawExtendGraph(
				card[i].pos_.x - (cardSize.x / 2),
				card[i].pos_.y - (cardSize.y / 2) + card[i].move_.y,
				card[i].pos_.x + (cardSize.x / 2),
				card[i].pos_.y + (cardSize.y / 2) + card[i].move_.y,
				cardGraph_,
				true
			);
		}
	}
}
