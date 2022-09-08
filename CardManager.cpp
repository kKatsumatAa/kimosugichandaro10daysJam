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


	/*for (int i = 0; i < deck.size(); i++) {
		Card temp = deck[i];
		int randomIndex = Random.Range(i, deck.Count);
		deck[i] = deck[randomIndex];
		deck[randomIndex] = temp;
	}*/
}

void CardManager::Update(KeyboardInput* key, Player* player, Enemy* enemy)
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

	if (deck.size() > 0)
	{
		std::list<std::unique_ptr<Card>>::iterator itr = deck.begin();

		if (key->GetKeyTrigger(KEY_INPUT_RETURN))
		{
			for (int i = 0; i < handNum; i++)
			{
				itr++;
			}

			itr->get()->Effect(player, enemy);
			deck.erase(itr);
		}
	}

	//デッキをセット
	if (deck.size() <= 0)
	{
		DeckSet();
	}
}

void CardManager::Draw(unsigned int* texhandle)
{
	std::list<std::unique_ptr<Card>>::iterator itr = deck.begin();

	//手札の数
	if (deck.size() < 5) handAllNum = deck.size();
	else                 handAllNum = handNumtmp;

	//手札の最大枚数に合わせて選択してるカードを変更
	if (handNum + 1 > handAllNum) handNum = handAllNum - 1;

	for (int i = 0; i < handAllNum; i++)
	{
		double selectPos = 0;
		if (handNum == i) selectPos = -40;

		itr->get()->Draw(texhandle[0], { (double)(400 + i * 300),(double)800 + selectPos });

		itr++;
	}
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

	std::unique_ptr<AttackCard> attackC[11];
	std::unique_ptr<GuardCard> guardC[5];
	std::unique_ptr<BuffCard> buffC[5];

	std::vector<int> cardOrder;

	cardOrder = make_rand_array_shuffle(20, 0, 19);

	std::vector<int>::iterator ITR = cardOrder.begin();

	for (int i = 0; i < 10; i++)
	{
		attackC[i] = std::make_unique<AttackCard>();
		attackC[i]->Initialize();
	}
	for (int i = 0; i < 5; i++)
	{
		guardC[i] = std::make_unique<GuardCard>();
		guardC[i]->Initialize();
	}
	for (int i = 0; i < 5; i++)
	{
		buffC[i] = std::make_unique<BuffCard>();
		buffC[i]->Initialize();
	}

	for (int i = 0; i < cardOrder.size(); i++)
	{
		if (i < 10)
		{
			attackC[i]->SetCardOrder(*ITR);
		}
		else if (i < 15)
		{
			guardC[i-10]->SetCardOrder(*ITR);
		}
		else if (i < 20)
		{
			buffC[i-15]->SetCardOrder(*ITR);
		}

		ITR++;
	}

	int count = 0;
	int orderCount = 0;
	std::list<std::unique_ptr<Card>> deck2;

	for (int i = 0; i < 20; i++)
	{
		if (i < 10)
		{
			deck2.push_back(std::move(attackC[i]));
		}
		else if (i < 15)
		{
			deck2.push_back(std::move(guardC[i-10]));
		}
		else if (i < 20)
		{
			deck2.push_back(std::move(buffC[i-15]));
		}
	}

	while (orderCount < 20)
	{
		std::list<std::unique_ptr<Card>>::iterator itr2 = deck2.begin();

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
		if (orderCount >= 20)
		{
			break;
		}
	}

	////攻撃カード3枚追加
	//for (int i = 0; i < 3; i++)
	//{
	//	std::unique_ptr<AttackCard> card = std::make_unique<AttackCard>();
	//	card->Initialize();
	//	//登録
	//	deck.push_back(std::move(card));
	//}

	////防御カード3枚追加
	//for (int i = 0; i < 3; i++)
	//{
	//	std::unique_ptr<GuardCard> card = std::make_unique<GuardCard>();
	//	card->Initialize();
	//	//登録
	//	deck.push_back(std::move(card));
	//}

	////バフカード3枚追加
	//for (int i = 0; i < 3; i++)
	//{
	//	std::unique_ptr<BuffCard> card = std::make_unique<BuffCard>();
	//	card->Initialize();
	//	//登録
	//	deck.push_back(std::move(card));
	//}
}


