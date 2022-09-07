#include "CardManager.h"

void CardManager::Initialize()
{
	//UŒ‚ƒJ[ƒh3–‡’Ç‰Á
	for (int i = 0; i < 3; i++)
	{
		std::unique_ptr<AttackCard> card = std::make_unique<AttackCard>();
		card->Initialize();
		//“o˜^
		deck.push_back(std::move(card));
	}

	//–hŒäƒJ[ƒh3–‡’Ç‰Á
	for (int i = 0; i < 3; i++)
	{
		std::unique_ptr<GuardCard> card = std::make_unique<GuardCard>();
		card->Initialize();
		//“o˜^
		deck.push_back(std::move(card));
	}
	
	//ƒoƒtƒJ[ƒh3–‡’Ç‰Á
	for (int i = 0; i < 3; i++)
	{
		std::unique_ptr<BuffCard> card = std::make_unique<BuffCard>();
		card->Initialize();
		//“o˜^
		deck.push_back(std::move(card));
	}


	/*for (int i = 0; i < deck.size(); i++) {
		Card temp = deck[i];
		int randomIndex = Random.Range(i, deck.Count);
		deck[i] = deck[randomIndex];
		deck[randomIndex] = temp;
	}*/
}

void CardManager::Update(KeyboardInput* key, Player* player, Enemy* enemy)
{

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
}

void CardManager::Draw(unsigned int* texhandle)
{
	std::list<std::unique_ptr<Card>>::iterator itr = deck.begin();

	int handNum;

	if (deck.size() < 5) handNum = deck.size();
	else                 handNum = 5;

	for (int i = 0; i < handNum; i++)
	{
		itr->get()->Draw(texhandle[0], { (double)(400 + i * 300),(double)800 });

		itr++;
	}
}
