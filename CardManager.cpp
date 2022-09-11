#include "CardManager.h"
#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<random>
#include<list>



void CardManager::Initialize()
{
	DeckSet();

	//初期化
	for (int i = 0; i < CARD_CONST; i++) {
		card[i].pos_ = deckSpace;
		card[i].move_ = { 0,0 };
		card[i].space_ = 0;
		card[i].isMove_ = 0;
		card[i].isHit_ = 0;
		card[i].chengeSize_ = { 0,0 };
		card[i].alpha_ = 255;
	}
	LoadDivGraph("resources/card_attack-Sheet.png", 2, 2, 1, 100, 140, cardGraph_[0]);
	LoadDivGraph("resources/card_defense_-Sheet.png", 2, 2, 1, 100, 140, cardGraph_[1]);
	LoadDivGraph("resources/card_buff-Sheet.png", 2, 2, 1, 100, 140, cardGraph_[2]);
	LoadDivGraph("resources/card_debuff-Sheet.png", 2, 2, 1, 100, 140, cardGraph_[3]);

	particle = new Particle;
	particle->Initialize();
	/*for (int i = 0; i < deck.size(); i++) {
		Card temp = deck[i];
		int randomIndex = Random.Range(i, deck.Count);
		deck[i] = deck[randomIndex];
		deck[randomIndex] = temp;
	}*/
}

void CardManager::Update(KeyboardInput* key, Player* player, Enemy* enemy, Cost* cost, bool isBattle)
{

	if (key->GetKeyTrigger(KEY_INPUT_RIGHT))
	{
		handNum++;
		if (handNum > handAllNum - 1) handNum = 0;
	}
	if (key->GetKeyTrigger(KEY_INPUT_LEFT))
	{
		handNum--;
		if (handNum < 0) handNum = handNumtmp - 1;
	}

	DrawFormatString(0, 0, 0xffffff, "\n\n\n\nhandNum:%d", handNum);

	//デッキにカードがあるなら
	if (deck.size() > 0)
	{
		std::list<std::unique_ptr<Card>>::iterator itr = deck.begin();

		if (key->GetKeyTrigger(KEY_INPUT_RETURN))
		{
			for (int i = 0; i < handNum; i++)
			{
				itr++;
			}

			//カードのコストと現在のコストを比較
			if (cost->GetCost() >= itr->get()->GetCost() && isBattle)
			{
				itr->get()->Effect(player, enemy);
				cost->UseCost(itr->get()->GetCost());
				deck.erase(itr);
			}
		}
	}
	//デッキをセット
	if (deck.size() <= 0)
	{
		DeckSet();
	}

	////////////////////////////////////////////////////////////////////////////////////
	//マウス座標の取得
	GetMousePoint(&mouseX, &mouseY);

	for (int i = 0; i < 5; i++) {
		//手札にカードがあるか
		isSpace[i] = false;
	}

	//カードが動いているか管理する変数の初期化
	for (int i = 0; i < CARD_CONST; i++) {
		card[i].isMove_ = false;
	}

	//手札を指定の場所まで動かす
	for (int i = 0; i < CARD_CONST; i++) {
		Vec2 spaceLen;
		//山札
		if (card[i].space_ == CardSpace::Deck) {
			//カードと捨て場の距離
			spaceLen = deckSpace - card[i].pos_;
			if (card[i].pos_.x != deckSpace.x) {
				//距離が20pixel以上離れていたら20pixel動かす
				if (spaceLen.GetLength() >= cardSpeed_) {
					card[i].pos_.x += spaceLen.x / spaceLen.GetLength() * cardSpeed_;
				}
				//距離が20pixel以下なら捨て場まで動かす
				else {
					card[i].pos_.x += spaceLen.x;
				}
				card[i].isMove_ = true;
			}
			if (card[i].pos_.y != deckSpace.y) {
				//距離が20pixel以上離れていたら20pixel動かす
				if (spaceLen.GetLength() >= cardSpeed_) {
					card[i].pos_.y += spaceLen.y / spaceLen.GetLength() * cardSpeed_;
				}
				//距離が20pixel以下なら捨て場まで動かす
				else {
					card[i].pos_.y += spaceLen.y;
				}
				card[i].isMove_ = true;
			}
		}
		//右から1番目
		else if (card[i].space_ == CardSpace::Hand1) {
			if (card[i].isSelect_ == false) {
				//カードと捨て場の距離
				spaceLen = handSpace1 - card[i].pos_;
				if (card[i].pos_.x != handSpace1.x) {
					//距離が20pixel以上離れていたら20pixel動かす
					if (spaceLen.GetLength() >= cardSpeed_) {
						card[i].pos_.x += spaceLen.x / spaceLen.GetLength() * cardSpeed_;
					}
					//距離が20pixel以下なら捨て場まで動かす
					else {
						card[i].pos_.x += spaceLen.x;
					}
					card[i].isMove_ = true;
				}
				if (card[i].pos_.y != handSpace1.y) {
					//距離が20pixel以上離れていたら20pixel動かす
					if (spaceLen.GetLength() >= cardSpeed_) {
						card[i].pos_.y += spaceLen.y / spaceLen.GetLength() * cardSpeed_;
					}
					//距離が20pixel以下なら捨て場まで動かす
					else {
						card[i].pos_.y += spaceLen.y;
					}
					card[i].isMove_ = true;
				}
			}
		}
		//右から2番目
		else if (card[i].space_ == CardSpace::Hand2) {
			if (card[i].isSelect_ == false) {
				//カードと捨て場の距離
				spaceLen = handSpace2 - card[i].pos_;
				if (card[i].pos_.x != handSpace2.x) {
					//距離が20pixel以上離れていたら20pixel動かす
					if (spaceLen.GetLength() >= cardSpeed_) {
						card[i].pos_.x += spaceLen.x / spaceLen.GetLength() * cardSpeed_;
					}
					//距離が20pixel以下なら捨て場まで動かす
					else {
						card[i].pos_.x += spaceLen.x;
					}
					card[i].isMove_ = true;
				}
				if (card[i].pos_.y != handSpace2.y) {
					//距離が20pixel以上離れていたら20pixel動かす
					if (spaceLen.GetLength() >= cardSpeed_) {
						card[i].pos_.y += spaceLen.y / spaceLen.GetLength() * cardSpeed_;
					}
					//距離が20pixel以下なら捨て場まで動かす
					else {
						card[i].pos_.y += spaceLen.y;
					}
					card[i].isMove_ = true;
				}
			}
		}
		//右から3番目
		else if (card[i].space_ == CardSpace::Hand3) {
			if (card[i].isSelect_ == false) {
				//カードと捨て場の距離
				spaceLen = handSpace3 - card[i].pos_;
				if (card[i].pos_.x != handSpace3.x) {
					//距離が20pixel以上離れていたら20pixel動かす
					if (spaceLen.GetLength() >= cardSpeed_) {
						card[i].pos_.x += spaceLen.x / spaceLen.GetLength() * cardSpeed_;
					}
					//距離が20pixel以下なら捨て場まで動かす
					else {
						card[i].pos_.x += spaceLen.x;
					}
					card[i].isMove_ = true;
				}
				if (card[i].pos_.y != handSpace3.y) {
					//距離が20pixel以上離れていたら20pixel動かす
					if (spaceLen.GetLength() >= cardSpeed_) {
						card[i].pos_.y += spaceLen.y / spaceLen.GetLength() * cardSpeed_;
					}
					//距離が20pixel以下なら捨て場まで動かす
					else {
						card[i].pos_.y += spaceLen.y;
					}
					card[i].isMove_ = true;
				}
			}
		}
		//右から4番目
		else if (card[i].space_ == CardSpace::Hand4) {
			if (card[i].isSelect_ == false) {
				//カードと捨て場の距離
				spaceLen = handSpace4 - card[i].pos_;
				if (card[i].pos_.x != handSpace4.x) {
					//距離が20pixel以上離れていたら20pixel動かす
					if (spaceLen.GetLength() >= cardSpeed_) {
						card[i].pos_.x += spaceLen.x / spaceLen.GetLength() * cardSpeed_;
					}
					//距離が20pixel以下なら捨て場まで動かす
					else {
						card[i].pos_.x += spaceLen.x;
					}
					card[i].isMove_ = true;
				}
				if (card[i].pos_.y != handSpace4.y) {
					//距離が20pixel以上離れていたら20pixel動かす
					if (spaceLen.GetLength() >= cardSpeed_) {
						card[i].pos_.y += spaceLen.y / spaceLen.GetLength() * cardSpeed_;
					}
					//距離が20pixel以下なら捨て場まで動かす
					else {
						card[i].pos_.y += spaceLen.y;
					}
					card[i].isMove_ = true;
				}
			}
		}
		//右から5番目
		else if (card[i].space_ == CardSpace::Hand5) {
			if (card[i].isSelect_ == false) {
				//カードと手札5の距離
				spaceLen = handSpace5 - card[i].pos_;
				if (card[i].pos_.x != handSpace5.x) {
					//距離が20pixel以上離れていたら20pixel動かす
					if (spaceLen.GetLength() >= cardSpeed_) {
						card[i].pos_.x += spaceLen.x / spaceLen.GetLength() * cardSpeed_;
					}
					//距離が20pixel以下なら手札5まで動かす
					else {
						card[i].pos_.x += spaceLen.x;
					}
					card[i].isMove_ = true;
				}
				if (card[i].pos_.y != handSpace5.y) {
					//距離が20pixel以上離れていたら20pixel動かす
					if (spaceLen.GetLength() >= cardSpeed_) {
						card[i].pos_.y += spaceLen.y / spaceLen.GetLength() * cardSpeed_;
					}
					//距離が20pixel以下なら手札5まで動かす
					else {
						card[i].pos_.y += spaceLen.y;
					}
					card[i].isMove_ = true;
				}
			}
		}
		//捨て札
		else if (card[i].space_ == CardSpace::Trash) {
			if (card[i].isSelect_ == false) {
				//カードと捨て場の距離
				spaceLen = handSpace6 - card[i].pos_;
				//使ったカードが捨て場に無ければ移動させる
				if (card[i].pos_.x != handSpace6.x) {
					//距離が20pixel以上離れていたら20pixel動かす
					if (spaceLen.GetLength() >= cardSpeed_) {
						card[i].pos_.x += spaceLen.x / spaceLen.GetLength() * cardSpeed_;
					}
					//距離が20pixel以下なら捨て場まで動かす
					else {
						card[i].pos_.x += spaceLen.x;
					}
				}
				if (card[i].pos_.y != handSpace6.y) {
					//距離が20pixel以上離れていたら20pixel動かす
					if (spaceLen.GetLength() >= cardSpeed_) {
						card[i].pos_.y += spaceLen.y / spaceLen.GetLength() * cardSpeed_;
					}
					//距離が20pixel以下なら捨て場まで動かす
					else {
						card[i].pos_.y += spaceLen.y;
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
				for (int j = 0; j < CARD_CONST; j++) {
					if (card[j].space_ >= card[i].space_ + 1 && card[j].space_ <= 5) {
						card[j].space_--;
					}
				}
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

				if (card[i].isSelect_ == true) {
					if (deck.size() > 0) {
						std::list<std::unique_ptr<Card>>::iterator itr = deck.begin();

						for (int j = 0; j < (card[i].space_ - 1); j++)
						{
							itr++;
						}

						//カードのコストと現在のコストを比較
						if (cost->GetCost() >= itr->get()->GetCost() && isBattle)
						{
							itr->get()->Effect(player, enemy);
							cost->UseCost(itr->get()->GetCost());
							deck.erase(itr);

							for (int j = 0; j < CARD_CONST; j++) {
								if (card[j].space_ >= card[i].space_ + 1 && card[j].space_ <= 5) {
									card[j].space_--;
								}
							}
							if (card[i].type_ == 0) {
								particle->BurstGenerate(Vec2(1175, 390), 5, 50, 60, -45, 15.0f, GetColor(200, 0, 0));
								particle->SlashGenerate(Vec2(1125, 340));
							}
							else if (card[i].type_ == 1) {

							}
							else if (card[i].type_ == 2) {
								buffTimer = 50;
							}
							else if (card[i].type_ == 3) {
								debuffTimer = 50;
							}
							card[i].space_ = CardSpace::Trash;
						}
					}
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
				//デッキをセット
				if (deck.size() <= 0)
				{
					DeckSet();
					for (int i = 0; i < CARD_CONST; i++) {
						if (card[i].space_ != CardSpace::Delete) {
							card[i].space_ = CardSpace::Deck;
						}
					}
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
			if (card[0].space_ == CardSpace::Deck) {
				card[0].space_ = CardSpace::Hand1;
				isSpace[0] = true;
			}
		}
		//右から2番目
		else if (isSpace[1] == false) {
			if (card[1].space_ == CardSpace::Deck) {
				card[1].space_ = CardSpace::Hand2;
				isSpace[1] = true;
			}
		}
		//右から3番目
		else if (isSpace[2] == false) {
			if (card[2].space_ == CardSpace::Deck) {
				card[2].space_ = CardSpace::Hand3;
				isSpace[2] = true;
			}
		}
		//右から4番目
		else if (isSpace[3] == false) {
			if (card[3].space_ == CardSpace::Deck) {
				card[3].space_ = CardSpace::Hand4;
				isSpace[3] = true;
			}
		}
		//右から5番目
		if (isSpace[4] == false) {
			if (card[i].space_ == CardSpace::Deck) {
				card[i].space_ = CardSpace::Hand5;
				isSpace[4] = true;
			}
		}
	}
	//パーティクル関連
	if (--buffTimer >= 0) {
		particle->BuffGenerate(Vec2(775, 390), Vec2(100, 50), 15);
	}
	if (--debuffTimer >= 0) {
		particle->DebuffGenerate(Vec2(1175, 390), Vec2(100, 50), 15);
	}

	particle->Update();
}

void CardManager::Draw(unsigned int* texhandle)
{
	std::list<std::unique_ptr<Card>>::iterator itr = deck.begin();

	//手札の数
	if (deck.size() < handNumtmp) handAllNum = deck.size();
	else                          handAllNum = handNumtmp;

	//手札の最大枚数に合わせて選択してるカードを変更
	if (handNum + 1 > handAllNum) handNum = handAllNum - 1;
	for (int i = 0; i < handAllNum; i++)
	{
		double selectPos = 0;
		if (handNum == i) selectPos = -40;

		itr->get()->Draw(texhandle[0], { (double)(400 + i * 300),(double)800 + selectPos });

		itr++;
	}
	itr = deck.begin();
	for (int i = 0; i < deck.size(); i++) {
		for (int j = 0; j < CARD_CONST; j++) {
			if (card[j].space_ == i + 1 && card[j].space_ <= 5) {
				card[j].type_ = itr->get()->GetColorNum();
				itr++;
				break;
			}
		}
	}
	itr = deck.begin();
	//カードの描画
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
				cardGraph_[1][card[i].isHit_],
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
				cardGraph_[card[i].type_][card[i].isHit_],
				true
			);
		}
	}


	particle->Draw();
}

std::mt19937 create_rand_engine() {
	std::random_device rnd;
	std::vector<std::uint_least32_t> v(10);// 初期化用ベクタ
	std::generate(v.begin(), v.end(), std::ref(rnd));// ベクタの初期化
	std::seed_seq seed(v.begin(), v.end());
	return std::mt19937(seed);// 乱数エンジン
}

std::vector<int> make_rand_array_shuffle(const size_t size, int rand_min, int rand_max) {
	if (rand_min > rand_max) std::swap(rand_min, rand_max);
	const size_t max_min_diff = static_cast<size_t>(rand_max - rand_min + 1);
	if (max_min_diff < size) throw std::runtime_error("引数が異常です");

	std::vector<int> tmp;
	tmp.reserve(max_min_diff);

	for (int i = rand_min; i <= rand_max; ++i)tmp.push_back(i);

	auto engine = create_rand_engine();
	std::shuffle(tmp.begin(), tmp.end(), engine);

	tmp.erase(std::next(tmp.begin(), size), tmp.end());

	return std::move(tmp);
}


void CardManager::DeckSet()
{
	deck.clear();

	//使うカードを生成
	std::unique_ptr<AttackCard> attackC[attackMax];
	std::unique_ptr<GuardCard> guardC[guardMax];
	std::unique_ptr<BuffCard> buffC[buffMax];
	std::unique_ptr<DeBuffCard> deBuffC[deBuffMax];

	for (int i = 0; i < attackMax; i++)
	{
		attackC[i] = std::make_unique<AttackCard>();
		attackC[i]->Initialize(1, 3);
	}
	for (int i = 0; i < guardMax; i++)
	{
		guardC[i] = std::make_unique<GuardCard>();
		guardC[i]->Initialize();
	}
	for (int i = 0; i < buffMax; i++)
	{
		buffC[i] = std::make_unique<BuffCard>();
		buffC[i]->Initialize(2);
	}
	for (int i = 0; i < deBuffMax; i++)
	{
		deBuffC[i] = std::make_unique<DeBuffCard>();
		deBuffC[i]->Initialize(2);
	}

	//重複なしランダムな数字の配列
	std::vector<int> cardOrder;

	cardOrder = make_rand_array_shuffle(deckMax, 0, deckMax - 1);
	std::vector<int>::iterator ITR = cardOrder.begin();


	//デッキ上でのカードの順番をここで入れてあげる
	for (int i = 0; i < cardOrder.size(); i++)
	{
		if (i < attackMax)
		{
			attackC[i]->SetCardOrder(*ITR);
		}
		else if (i < attackMax + guardMax)
		{
			guardC[i - attackMax]->SetCardOrder(*ITR);
		}
		else if (i < attackMax + guardMax + buffMax)
		{
			buffC[i - (attackMax + guardMax)]->SetCardOrder(*ITR);
		}
		else if (i < attackMax + guardMax + buffMax + deBuffMax)
		{
			deBuffC[i - (attackMax + guardMax + buffMax)]->SetCardOrder(*ITR);
		}

		ITR++;
	}


	//仮のリスト（デッキ）に順番関係なくとりあえず入れる
	std::list<std::unique_ptr<Card>> deck2;

	for (int i = 0; i < deckMax; i++)
	{
		if (i < attackMax)
		{
			deck2.push_back(std::move(attackC[i]));
		}
		else if (i < attackMax + guardMax)
		{
			deck2.push_back(std::move(guardC[i - attackMax]));
		}
		else if (i < attackMax + guardMax + buffMax)
		{
			deck2.push_back(std::move(buffC[i - (attackMax + guardMax)]));
		}
		else if (i < attackMax + guardMax + buffMax + deBuffMax)
		{
			deck2.push_back(std::move(deBuffC[i - (attackMax + guardMax + buffMax)]));
		}
	}

	//仮のリストの中のカードを調べて、デッキ上での順にデッキのリストに入れてあげる
	int orderCount = 0;
	while (orderCount < deckMax)
	{
		//std::list<std::unique_ptr<Card>>::iterator itr2 = deck2.begin();

		for (int i = 0; i < deck2.size(); i++)
		{
			std::list<std::unique_ptr<Card>>::iterator itr2 = deck2.begin();

			std::advance(itr2, i);
			if (itr2->get()->GetCardOrder() == orderCount)
			{

				deck.push_back(std::move(*itr2));
				deck2.erase(itr2);

				orderCount++;
			}
		}
		if (orderCount >= deckMax)
		{
			break;
		}
	}
}


