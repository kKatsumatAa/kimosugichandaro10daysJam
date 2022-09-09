#include "CardMove.h"

void CardMove::Initialize()
{
	//初期化
	for (int i = 0; i < CARD_CONST; i++) {
		card[i].pos_ = { 1500,800 };
		card[i].move_ = { 0,0 };
		card[i].space_ = 0;
		card[i].isMove_ = 0;
		card[i].isHit_ = 0;
		card[i].chengeSize_ = { 0,0 };
		card[i].alpha_ = 255;
	}
	//画像読み込み
	cardGraph_ = LoadGraph("resources/card_attack_prototype.png");
}

void CardMove::Update()
{
	//マウス座標の取得
	GetMousePoint(&mouseX, &mouseY);

	for (int i = 0; i < 5; i++) {
		//手札にカードがあるか
		isSpace[i] = false;
	}
	for (int i = 0; i < CARD_CONST; i++) {
		//手札にカードがあればtrueに
		if (card[i].space_ - 1 >= 0) {
			isSpace[card[i].space_ - 1] = true;
		}
	}
	//手札にカードが無ければその場所にカードを配布
	for (int i = 0; i < CARD_CONST; i++) {
		//右から1番目
		if (isSpace[0] == false) {
			if (card[i].space_ == CardSpace::Deck) {
				card[i].space_ = CardSpace::Hand1;
				isSpace[0] = true;
			}
		}
		//右から2番目
		else if (isSpace[1] == false) {
			if (card[i].space_ == CardSpace::Deck) {
				card[i].space_ = CardSpace::Hand2;
				isSpace[1] = true;
			}
		}
		//右から3番目
		else if (isSpace[2] == false) {
			if (card[i].space_ == CardSpace::Deck) {
				card[i].space_ = CardSpace::Hand3;
				isSpace[2] = true;
			}
		}
		//右から4番目
		else if (isSpace[3] == false) {
			if (card[i].space_ == CardSpace::Deck) {
				card[i].space_ = CardSpace::Hand4;
				isSpace[3] = true;
			}
		}
		//右から5番目
		else if (isSpace[4] == false) {
			if (card[i].space_ == CardSpace::Deck) {
				card[i].space_ = CardSpace::Hand5;
				isSpace[4] = true;
			}
		}
	}

	//カードが動いているか管理する変数の初期化
	for (int i = 0; i < CARD_CONST; i++) {
		card[i].isMove_ = false;
	}

	//手札を指定の場所まで動かす
	for (int i = 0; i < CARD_CONST; i++) {
		//右から1番目
		if (card[i].space_ == CardSpace::Hand1) {
			if (card[i].pos_.x != handSpace1.x && card[i].isSelect_ == false) {
				card[i].pos_.x -= cardSpeeed_;
				card[i].isMove_ = true;
			}
		}
		//右から2番目
		else if (card[i].space_ == CardSpace::Hand2) {
			if (card[i].pos_.x != handSpace2.x && card[i].isSelect_ == false) {
				card[i].pos_.x -= cardSpeeed_;
				card[i].isMove_ = true;
			}
		}
		//右から3番目
		else if (card[i].space_ == CardSpace::Hand3) {
			if (card[i].pos_.x != handSpace3.x && card[i].isSelect_ == false) {
				card[i].pos_.x -= cardSpeeed_;
				card[i].isMove_ = true;
			}
		}
		//右から4番目
		else if (card[i].space_ == CardSpace::Hand4) {
			if (card[i].pos_.x != handSpace4.x && card[i].isSelect_ == false) {
				card[i].pos_.x -= cardSpeeed_;
				card[i].isMove_ = true;
			}
		}
		//右から5番目
		else if (card[i].space_ == CardSpace::Hand5) {
			if (card[i].pos_.x != handSpace5.x && card[i].isSelect_ == false) {
				card[i].pos_.x -= cardSpeeed_;
				card[i].isMove_ = true;
			}
		}
		//捨て札
		else if (card[i].space_ == CardSpace::Trash) {
			if (card[i].isSelect_ == false) {
				//カードと捨て場の距離
				Vec2 space6Len = handSpace6 - card[i].pos_;
				//使ったカードが捨て場に無ければ移動させる
				if (card[i].pos_.x != handSpace6.x) {
					//距離が20pixel以上離れていたら20pixel動かす
					if (space6Len.GetLength() >= cardSpeeed_) {
						card[i].pos_.x += space6Len.x / space6Len.GetLength() * cardSpeeed_;
					}
					//距離が20pixel以下なら捨て場まで動かす
					else {
						card[i].pos_.x += space6Len.x;
					}
				}
				if (card[i].pos_.y != handSpace6.y) {
					//距離が20pixel以上離れていたら20pixel動かす
					if (space6Len.GetLength() >= cardSpeeed_) {
						card[i].pos_.y += space6Len.y / space6Len.GetLength() * cardSpeeed_;
					}
					//距離が20pixel以下なら捨て場まで動かす
					else {
						card[i].pos_.y += space6Len.y;
					}
				}
				//カードの大きさを小さくする
				if (card[i].chengeSize_.x > -60) {
					card[i].chengeSize_.x -= 2;
					card[i].chengeSize_.y -= 3;
				}

				card[i].isMove_ = true;
			}
		}
		//廃棄した札
		else if (card[i].space_ == CardSpace::Delete) {
			if (card[i].alpha_ > 0) {
				card[i].chengeSize_ += {2, 3};
				card[i].alpha_ -= 10;
			}
			else {
				card[i].chengeSize_ = { 0,0 };
			}
		}
	}

	///手札とマウスの当たり判定
	//すでにマウスでつかんでいたら判定をとらない

	//つかんでいるかの判定用変数と初期化
	bool isCatch = false;

	for (int i = 0; i < CARD_CONST; i++) {
		//既につかんでいる時
		if (card[i].isSelect_ == true) {
			isCatch = true;
		}
	}
	for (int i = 0; i < CARD_CONST; i++) {
		//既に掴んでいたらこの処理をスキップする
		if (isCatch == true) {
			break;
		}

		//初期化
		card[i].isHit_ = false;

		//デッキと捨て札以外の場所にあるカードとマウスの判定を取る
		if (card[i].space_ != CardSpace::Deck && card[i].space_ != CardSpace::Trash && card[i].isMove_ == false) {
			if (card[i].pos_.x - cardSize.x / 2 < mouseX && card[i].pos_.x + cardSize.x / 2 > mouseX) {
				if (card[i].pos_.y - cardSize.y / 2 + card[i].move_.y < mouseY && card[i].pos_.y + cardSize.y / 2 > mouseY) {
					card[i].isHit_ = true;
				}
			}
		}
	}

	//手札とマウスの当たり判定をプレイヤーに分かりやすく
	for (int i = 0; i < CARD_CONST; i++) {
		//当たっていれば少し上に動かす
		if (card[i].isHit_ == true) {
			card[i].move_.y = -50;
		}
		//当たっていない時は戻す
		else {
			card[i].move_.y = 0;
		}
	}

	///カードの選択

	//掴んでいない時右クリックで廃棄
	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0 && isCatch == false) {
		for (int i = 0; i < CARD_CONST; i++) {
			if (card[i].isHit_ == true) {
				card[i].space_ = CardSpace::Delete;
			}
		}
	}
	//左クリックでカードを掴む
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
		for (int i = 0; i < CARD_CONST; i++) {
			if (card[i].isHit_ == true) {
				card[i].isSelect_ = true;
			}
		}
	}
	//左クリックを離した時、掴んでいたカードの場所によって処理を変える
	else {
		for (int i = 0; i < CARD_CONST; i++) {
			//カードを上に持っていったら捨て札に
			if (card[i].pos_.y <= 630) {
				card[i].space_ = CardSpace::Trash;
			}
			else if (card[i].isMove_ == false) {
				//右から1番目のカードを元の場所に戻す
				if (card[i].space_ == CardSpace::Hand1) {
					card[i].pos_ = handSpace1;
				}
				//右から2番目のカードを元の場所に戻す
				else if (card[i].space_ == CardSpace::Hand2) {
					card[i].pos_ = handSpace2;
				}
				//右から3番目のカードを元の場所に戻す
				else if (card[i].space_ == CardSpace::Hand3) {
					card[i].pos_ = handSpace3;
				}
				//右から4番目のカードを元の場所に戻す
				else if (card[i].space_ == CardSpace::Hand4) {
					card[i].pos_ = handSpace4;
				}
				//右から5番目のカードを元の場所に戻す
				else if (card[i].space_ == CardSpace::Hand5) {
					card[i].pos_ = handSpace5;
				}
			}
			//掴んでいるかを管理する変数をfalseに
			card[i].isSelect_ = false;
		}
	}
	for (int i = 0; i < CARD_CONST; i++) {
		//掴んでいるかを管理する変数がtrueならマウスの座標にもっていく
		if (card[i].isSelect_ == true) {
			card[i].pos_.x = mouseX;
			card[i].pos_.y = mouseY;
		}
	}
}

void CardMove::Draw()
{
	for (int i = 0; i < CARD_CONST; i++) {
		//カードがデッキにある時
		if (card[i].space_ == CardSpace::Deck) {
			DrawBox(
				card[i].pos_.x - (cardSize.x / 2),
				card[i].pos_.y - (cardSize.y / 2) + card[i].move_.y,
				card[i].pos_.x + (cardSize.x / 2),
				card[i].pos_.y + (cardSize.y / 2) + card[i].move_.y,
				GetColor(100, 100, 100),
				true
			);
		}
		//カードが捨て札か廃棄にある時
		else if (card[i].space_ == CardSpace::Trash || card[i].space_ == CardSpace::Delete) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, card[i].alpha_);
			DrawExtendGraph(
				card[i].pos_.x - (cardSize.x / 2) - card[i].chengeSize_.x,
				card[i].pos_.y - (cardSize.y / 2) + card[i].move_.y - card[i].chengeSize_.y,
				card[i].pos_.x + (cardSize.x / 2) + card[i].chengeSize_.x,
				card[i].pos_.y + (cardSize.y / 2) + card[i].move_.y + card[i].chengeSize_.y,
				cardGraph_,
				true
			);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			//カードが捨て札にある時
			if (card[i].space_ == CardSpace::Trash) {
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
				DrawBox(
					card[i].pos_.x - (cardSize.x / 2) - card[i].chengeSize_.x,
					card[i].pos_.y - (cardSize.y / 2) + card[i].move_.y - card[i].chengeSize_.y,
					card[i].pos_.x + (cardSize.x / 2) + card[i].chengeSize_.x,
					card[i].pos_.y + (cardSize.y / 2) + card[i].move_.y + card[i].chengeSize_.y,
					GetColor(100, 100, 100),
					true
				);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			}
		}
		//カードが手札にある時
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
