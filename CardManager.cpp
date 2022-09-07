#include "CardManager.h"

void CardManager::Initialize()
{
	//�U���J�[�h3���ǉ�
	for (int i = 0; i < 3; i++)
	{
		std::unique_ptr<AttackCard> card = std::make_unique<AttackCard>();
		card->Initialize();
		//�o�^
		deck.push_back(std::move(card));
	}

	//�h��J�[�h3���ǉ�
	for (int i = 0; i < 3; i++)
	{
		std::unique_ptr<GuardCard> card = std::make_unique<GuardCard>();
		card->Initialize();
		//�o�^
		deck.push_back(std::move(card));
	}
	
	//�o�t�J�[�h3���ǉ�
	for (int i = 0; i < 3; i++)
	{
		std::unique_ptr<BuffCard> card = std::make_unique<BuffCard>();
		card->Initialize();
		//�o�^
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
}

void CardManager::Draw(unsigned int* texhandle)
{
	std::list<std::unique_ptr<Card>>::iterator itr = deck.begin();

	//��D�̐�
	if (deck.size() < 5) handAllNum = deck.size();
	else                 handAllNum = handNumtmp;

	//��D�̍ő喇���ɍ��킹�đI�����Ă�J�[�h��ύX
	if (handNum + 1 > handAllNum) handNum = handAllNum - 1;

	for (int i = 0; i < handAllNum; i++)
	{
		double selectPos = 0;
		if (handNum == i) selectPos = -40;

		itr->get()->Draw(texhandle[0], { (double)(400 + i * 300),(double)800 + selectPos });

		itr++;
	}
}