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

	//������
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
	LoadDivGraph("resources/card_defense_prototype-Sheet.png", 2, 2, 1, 90, 130, cardGraph_[1]);
	LoadDivGraph("resources/card_buff-Sheet.png", 2, 2, 1, 100, 140, cardGraph_[2]);
	LoadDivGraph("resources/card_debuff-Sheet.png", 2, 2, 1, 100, 140, cardGraph_[3]);


	/*for (int i = 0; i < deck.size(); i++) {
		Card temp = deck[i];
		int randomIndex = Random.Range(i, deck.Count);
		deck[i] = deck[randomIndex];
		deck[randomIndex] = temp;
	}*/
}

void CardManager::Update(KeyboardInput* key, Player* player, Enemy* enemy, Cost* cost, bool isBattle)
{
	{
	//if (key->GetKeyTrigger(KEY_INPUT_RIGHT))
	//{
	//	handNum++;
	//	if (handNum > handAllNum - 1) handNum = 0;
	//}
	//if (key->GetKeyTrigger(KEY_INPUT_LEFT))
	//{
	//	handNum--;
	//	if (handNum < 0) handNum = handNumtmp - 1;
	//}

	//DrawFormatString(0, 0, 0xffffff, "\n\n\n\nhandNum:%d", handNum);

	////�f�b�L�ɃJ�[�h������Ȃ�
	//if (deck.size() > 0)
	//{
	//	std::list<std::unique_ptr<Card>>::iterator itr = deck.begin();

	//	if (key->GetKeyTrigger(KEY_INPUT_RETURN))
	//	{
	//		for (int i = 0; i < handNum; i++)
	//		{
	//			itr++;
	//		}

	//		//�J�[�h�̃R�X�g�ƌ��݂̃R�X�g���r
	//		if (cost->GetCost() >= itr->get()->GetCost() && isBattle)
	//		{
	//			itr->get()->Effect(player, enemy);
	//			cost->UseCost(itr->get()->GetCost());
	//			deck.erase(itr);
	//		}
	//	}
	//}
	////�f�b�L���Z�b�g
	//if (deck.size() <= 0)
	//{
	//	DeckSet();
	//	for (int i = 0; i < CARD_CONST; i++) {
	//		if (card[i].space_ != CardSpace::Delete) {
	//			card[i].space_ = CardSpace::Deck;
	//		}
	//	}
	//}
}

	////////////////////////////////////////////////////////////////////////////////////
	//�}�E�X���W�̎擾
	GetMousePoint(&mouseX, &mouseY);

	for (int i = 0; i < 5; i++) {
		//��D�ɃJ�[�h�����邩
		isSpace[i] = false;
	}

	//�J�[�h�������Ă��邩�Ǘ�����ϐ��̏�����
	for (int i = 0; i < CARD_CONST; i++) {
		card[i].isMove_ = false;
	}

	//��D���w��̏ꏊ�܂œ�����
	for (int i = 0; i < CARD_CONST; i++) {
		Vec2 spaceLen;
		//�R�D
		if (card[i].space_ == CardSpace::Deck) {
			//�J�[�h�Ǝ̂ď�̋���
			spaceLen = deckSpace - card[i].pos_;
			if (card[i].pos_.x != deckSpace.x) {
				//������20pixel�ȏ㗣��Ă�����20pixel������
				if (spaceLen.GetLength() >= cardSpeed_) {
					card[i].pos_.x += spaceLen.x / spaceLen.GetLength() * cardSpeed_;
				}
				//������20pixel�ȉ��Ȃ�̂ď�܂œ�����
				else {
					card[i].pos_.x += spaceLen.x;
				}
				card[i].isMove_ = true;
			}
			if (card[i].pos_.y != deckSpace.y) {
				//������20pixel�ȏ㗣��Ă�����20pixel������
				if (spaceLen.GetLength() >= cardSpeed_) {
					card[i].pos_.y += spaceLen.y / spaceLen.GetLength() * cardSpeed_;
				}
				//������20pixel�ȉ��Ȃ�̂ď�܂œ�����
				else {
					card[i].pos_.y += spaceLen.y;
				}
				card[i].isMove_ = true;
			}
		}
		//�E����1�Ԗ�
		else if (card[i].space_ == CardSpace::Hand1) {
			if (card[i].isSelect_ == false) {
				//�J�[�h�Ǝ̂ď�̋���
				spaceLen = handSpace1 - card[i].pos_;
				if (card[i].pos_.x != handSpace1.x) {
					//������20pixel�ȏ㗣��Ă�����20pixel������
					if (spaceLen.GetLength() >= cardSpeed_) {
						card[i].pos_.x += spaceLen.x / spaceLen.GetLength() * cardSpeed_;
					}
					//������20pixel�ȉ��Ȃ�̂ď�܂œ�����
					else {
						card[i].pos_.x += spaceLen.x;
					}
					card[i].isMove_ = true;
				}
				if (card[i].pos_.y != handSpace1.y) {
					//������20pixel�ȏ㗣��Ă�����20pixel������
					if (spaceLen.GetLength() >= cardSpeed_) {
						card[i].pos_.y += spaceLen.y / spaceLen.GetLength() * cardSpeed_;
					}
					//������20pixel�ȉ��Ȃ�̂ď�܂œ�����
					else {
						card[i].pos_.y += spaceLen.y;
					}
					card[i].isMove_ = true;
				}
			}
		}
		//�E����2�Ԗ�
		else if (card[i].space_ == CardSpace::Hand2) {
			if (card[i].isSelect_ == false) {
				//�J�[�h�Ǝ̂ď�̋���
				spaceLen = handSpace2 - card[i].pos_;
				if (card[i].pos_.x != handSpace2.x) {
					//������20pixel�ȏ㗣��Ă�����20pixel������
					if (spaceLen.GetLength() >= cardSpeed_) {
						card[i].pos_.x += spaceLen.x / spaceLen.GetLength() * cardSpeed_;
					}
					//������20pixel�ȉ��Ȃ�̂ď�܂œ�����
					else {
						card[i].pos_.x += spaceLen.x;
					}
					card[i].isMove_ = true;
				}
				if (card[i].pos_.y != handSpace2.y) {
					//������20pixel�ȏ㗣��Ă�����20pixel������
					if (spaceLen.GetLength() >= cardSpeed_) {
						card[i].pos_.y += spaceLen.y / spaceLen.GetLength() * cardSpeed_;
					}
					//������20pixel�ȉ��Ȃ�̂ď�܂œ�����
					else {
						card[i].pos_.y += spaceLen.y;
					}
					card[i].isMove_ = true;
				}
			}
		}
		//�E����3�Ԗ�
		else if (card[i].space_ == CardSpace::Hand3) {
			if (card[i].isSelect_ == false) {
				//�J�[�h�Ǝ̂ď�̋���
				spaceLen = handSpace3 - card[i].pos_;
				if (card[i].pos_.x != handSpace3.x) {
					//������20pixel�ȏ㗣��Ă�����20pixel������
					if (spaceLen.GetLength() >= cardSpeed_) {
						card[i].pos_.x += spaceLen.x / spaceLen.GetLength() * cardSpeed_;
					}
					//������20pixel�ȉ��Ȃ�̂ď�܂œ�����
					else {
						card[i].pos_.x += spaceLen.x;
					}
					card[i].isMove_ = true;
				}
				if (card[i].pos_.y != handSpace3.y) {
					//������20pixel�ȏ㗣��Ă�����20pixel������
					if (spaceLen.GetLength() >= cardSpeed_) {
						card[i].pos_.y += spaceLen.y / spaceLen.GetLength() * cardSpeed_;
					}
					//������20pixel�ȉ��Ȃ�̂ď�܂œ�����
					else {
						card[i].pos_.y += spaceLen.y;
					}
					card[i].isMove_ = true;
				}
			}
		}
		//�E����4�Ԗ�
		else if (card[i].space_ == CardSpace::Hand4) {
			if (card[i].isSelect_ == false) {
				//�J�[�h�Ǝ̂ď�̋���
				spaceLen = handSpace4 - card[i].pos_;
				if (card[i].pos_.x != handSpace4.x) {
					//������20pixel�ȏ㗣��Ă�����20pixel������
					if (spaceLen.GetLength() >= cardSpeed_) {
						card[i].pos_.x += spaceLen.x / spaceLen.GetLength() * cardSpeed_;
					}
					//������20pixel�ȉ��Ȃ�̂ď�܂œ�����
					else {
						card[i].pos_.x += spaceLen.x;
					}
					card[i].isMove_ = true;
				}
				if (card[i].pos_.y != handSpace4.y) {
					//������20pixel�ȏ㗣��Ă�����20pixel������
					if (spaceLen.GetLength() >= cardSpeed_) {
						card[i].pos_.y += spaceLen.y / spaceLen.GetLength() * cardSpeed_;
					}
					//������20pixel�ȉ��Ȃ�̂ď�܂œ�����
					else {
						card[i].pos_.y += spaceLen.y;
					}
					card[i].isMove_ = true;
				}
			}
		}
		//�E����5�Ԗ�
		else if (card[i].space_ == CardSpace::Hand5) {
			if (card[i].isSelect_ == false) {
				//�J�[�h�Ǝ�D5�̋���
				spaceLen = handSpace5 - card[i].pos_;
				if (card[i].pos_.x != handSpace5.x) {
					//������20pixel�ȏ㗣��Ă�����20pixel������
					if (spaceLen.GetLength() >= cardSpeed_) {
						card[i].pos_.x += spaceLen.x / spaceLen.GetLength() * cardSpeed_;
					}
					//������20pixel�ȉ��Ȃ��D5�܂œ�����
					else {
						card[i].pos_.x += spaceLen.x;
					}
					card[i].isMove_ = true;
				}
				if (card[i].pos_.y != handSpace5.y) {
					//������20pixel�ȏ㗣��Ă�����20pixel������
					if (spaceLen.GetLength() >= cardSpeed_) {
						card[i].pos_.y += spaceLen.y / spaceLen.GetLength() * cardSpeed_;
					}
					//������20pixel�ȉ��Ȃ��D5�܂œ�����
					else {
						card[i].pos_.y += spaceLen.y;
					}
					card[i].isMove_ = true;
				}
			}
		}
		//�̂ĎD
		else if (card[i].space_ == CardSpace::Trash) {
			if (card[i].isSelect_ == false) {
				//�J�[�h�Ǝ̂ď�̋���
				spaceLen = handSpace6 - card[i].pos_;
				//�g�����J�[�h���̂ď�ɖ�����Έړ�������
				if (card[i].pos_.x != handSpace6.x) {
					//������20pixel�ȏ㗣��Ă�����20pixel������
					if (spaceLen.GetLength() >= cardSpeed_) {
						card[i].pos_.x += spaceLen.x / spaceLen.GetLength() * cardSpeed_;
					}
					//������20pixel�ȉ��Ȃ�̂ď�܂œ�����
					else {
						card[i].pos_.x += spaceLen.x;
					}
				}
				if (card[i].pos_.y != handSpace6.y) {
					//������20pixel�ȏ㗣��Ă�����20pixel������
					if (spaceLen.GetLength() >= cardSpeed_) {
						card[i].pos_.y += spaceLen.y / spaceLen.GetLength() * cardSpeed_;
					}
					//������20pixel�ȉ��Ȃ�̂ď�܂œ�����
					else {
						card[i].pos_.y += spaceLen.y;
					}
				}
				//�J�[�h�̑傫��������������
				if (card[i].chengeSize_.x > -60) {
					card[i].chengeSize_.x -= 2;
					card[i].chengeSize_.y -= 3;
				}

				card[i].isMove_ = true;
			}
		}
		//�p�������D
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



	///��D�ƃ}�E�X�̓����蔻��
	//���łɃ}�E�X�ł���ł����画����Ƃ�Ȃ�

	//����ł��邩�̔���p�ϐ��Ə�����
	bool isCatch = false;

	for (int i = 0; i < CARD_CONST; i++) {
		//���ɂ���ł��鎞
		if (card[i].isSelect_ == true) {
			isCatch = true;
		}
	}
	for (int i = 0; i < CARD_CONST; i++) {
		//���ɒ͂�ł����炱�̏������X�L�b�v����
		if (isCatch == true) {
			break;
		}

		//������
		card[i].isHit_ = false;

		//�f�b�L�Ǝ̂ĎD�ȊO�̏ꏊ�ɂ���J�[�h�ƃ}�E�X�̔�������
		if (card[i].space_ != CardSpace::Deck && card[i].space_ != CardSpace::Trash && card[i].isMove_ == false
			&& card[i].space_ != CardSpace::Delete) {
			if (card[i].pos_.x - cardSize.x / 2 < mouseX && card[i].pos_.x + cardSize.x / 2 > mouseX) {
				if (card[i].pos_.y - cardSize.y / 2 + card[i].move_.y < mouseY && card[i].pos_.y + cardSize.y / 2 > mouseY) {
					card[i].isHit_ = true;
				}
			}
		}
	}

	//��D�ƃ}�E�X�̓����蔻����v���C���[�ɕ�����₷��
	for (int i = 0; i < CARD_CONST; i++) {
		//�������Ă���Ώ�����ɓ�����
		if (card[i].isHit_ == true) {
			card[i].move_.y = -50;
		}
		//�������Ă��Ȃ����͖߂�
		else {
			card[i].move_.y = 0;
		}
	}

	///�J�[�h�̑I��
	DrawFormatString(0, 10, 0xffffff, "\n\n\n\n\n\nattacknum:%d", attackMaxBattle);
	DrawFormatString(0, 10, 0xffffff, "\n\n\n\n\n\n\nguardnum:%d", guardMaxBattle);
	DrawFormatString(0, 10, 0xffffff, "\n\n\n\n\n\n\n\nbuffnum:%d", buffMaxBattle);
	DrawFormatString(0, 10, 0xffffff, "\n\n\n\n\n\n\n\n\ndenum:%d", deBuffMaxBattle);

	//�͂�ł��Ȃ����E�N���b�N�Ŕp��
	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0 && isCatch == false && deck.size() > 0) {



		for (int i = 0; i < CARD_CONST; i++) {
			if (card[i].isHit_ == true) {

				int count = 0;
				//���X�g�̕��̔p������
				std::list<std::unique_ptr<Card>>::iterator itr = deck.begin();
				for (int j = 0; j < (card[i].space_ - 1); j++)
				{
					itr++;
					count++;
				}

				switch (itr->get()->GetAttribute())
				{
				case Attibute::ATTACK:
					attackMaxBattle--;
					break;
				case Attibute::GUARD:
					guardMaxBattle--;
					break;
				case Attibute::BUFF:
					buffMaxBattle--;
					break;
				case Attibute::DEBUFF:
					deBuffMaxBattle--;
					break;
				}

				cost->AddCost(itr->get()->GetCost());

				deck.erase(itr);

				//-----------------------------------------------
				for (int j = 0; j < CARD_CONST; j++) {
					if (card[j].space_ >= card[i].space_ + 1 && card[j].space_ <= 5) {
						card[j].space_--;
					}
				}

				isSpace[card[i].space_ - 1] = false;
				card[i].space_ = CardSpace::Delete;
			}
		}

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
	//���N���b�N�ŃJ�[�h��͂�
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
		for (int i = 0; i < CARD_CONST; i++) {
			if (card[i].isHit_ == true) {
				card[i].isSelect_ = true;
			}
		}
	}
	//���N���b�N�𗣂������A�͂�ł����J�[�h�̏ꏊ�ɂ���ď�����ς���
	else {
		for (int i = 0; i < CARD_CONST; i++) {
			//�J�[�h����Ɏ����Ă�������̂ĎD��
			if (card[i].pos_.y <= 630) {

				if (card[i].isSelect_ == true && card[i].space_ != CardSpace::Delete) {
					if (deck.size() > 0) {
						std::list<std::unique_ptr<Card>>::iterator itr = deck.begin();

						for (int j = 0; j < (card[i].space_ - 1); j++)
						{
							itr++;
						}

						//�J�[�h�̃R�X�g�ƌ��݂̃R�X�g���r
						if (cost->GetCost() >= itr->get()->GetCost() && isBattle)
						{
							itr->get()->Effect(player, enemy);
							cost->UseCost(itr->get()->GetCost());
							deck.erase(itr);

							/*if (deck.size() <= 0)DeckSet();*/

							for (int j = 0; j < CARD_CONST; j++) {
								if (card[j].space_ >= card[i].space_ + 1 && card[j].space_ <= 5) {
									card[j].space_--;
								}
							}
							card[i].space_ = CardSpace::Trash;
						}
					}
				}
				else if (card[i].isMove_ == false) {
					//�E����1�Ԗڂ̃J�[�h�����̏ꏊ�ɖ߂�
					if (card[i].space_ == CardSpace::Hand1) {
						card[i].pos_ = handSpace1;
					}
					//�E����2�Ԗڂ̃J�[�h�����̏ꏊ�ɖ߂�
					else if (card[i].space_ == CardSpace::Hand2) {
						card[i].pos_ = handSpace2;
					}
					//�E����3�Ԗڂ̃J�[�h�����̏ꏊ�ɖ߂�
					else if (card[i].space_ == CardSpace::Hand3) {
						card[i].pos_ = handSpace3;
					}
					//�E����4�Ԗڂ̃J�[�h�����̏ꏊ�ɖ߂�
					else if (card[i].space_ == CardSpace::Hand4) {
						card[i].pos_ = handSpace4;
					}
					//�E����5�Ԗڂ̃J�[�h�����̏ꏊ�ɖ߂�
					else if (card[i].space_ == CardSpace::Hand5) {
						card[i].pos_ = handSpace5;
					}
				}
				//�f�b�L���Z�b�g
				if (deck.size() <= 0)
				{
					
					for (int i = 0; i < CARD_CONST; i++) {
						if (card[i].space_ != CardSpace::Delete) {
							card[i].space_ = CardSpace::Deck;
						}
					}
					DeckSet();
				}
			}
			//�͂�ł��邩���Ǘ�����ϐ���false��
			card[i].isSelect_ = false;
		}
	}
	for (int i = 0; i < CARD_CONST; i++) {
		//�͂�ł��邩���Ǘ�����ϐ���true�Ȃ�}�E�X�̍��W�ɂ����Ă���
		if (card[i].isSelect_ == true) {
			card[i].pos_.x = mouseX;
			card[i].pos_.y = mouseY;
		}
	}


	for (int i = 0; i < CARD_CONST; i++) {
		//��D�ɃJ�[�h�������true��
		if (card[i].space_ - 1 >= 0) {
			isSpace[card[i].space_ - 1] = true;
		}
	}
	//��D�ɃJ�[�h��������΂��̏ꏊ�ɃJ�[�h��z�z
	for (int i = 0; i < CARD_CONST; i++) {
		//�E����1�Ԗ�
		if (isSpace[0] == false) {
			if (card[i].space_ == CardSpace::Deck) {
				card[i].space_ = CardSpace::Hand1;
				isSpace[0] = true;
			}
		}
		//�E����2�Ԗ�
		else if (isSpace[1] == false) {
			if (card[i].space_ == CardSpace::Deck) {
				card[i].space_ = CardSpace::Hand2;
				isSpace[1] = true;
			}
		}
		//�E����3�Ԗ�
		else if (isSpace[2] == false) {
			if (card[i].space_ == CardSpace::Deck) {
				card[i].space_ = CardSpace::Hand3;
				isSpace[2] = true;
			}
		}
		//�E����4�Ԗ�
		else if (isSpace[3] == false) {
			if (card[i].space_ == CardSpace::Deck) {
				card[i].space_ = CardSpace::Hand4;
				isSpace[3] = true;
			}
		}
		//�E����5�Ԗ�
		if (isSpace[4] == false) {
			if (card[i].space_ == CardSpace::Deck) {
				card[i].space_ = CardSpace::Hand5;
				isSpace[4] = true;
			}
		}
	}

}

void CardManager::Draw(unsigned int* texhandle)
{
	std::list<std::unique_ptr<Card>>::iterator itr = deck.begin();

	//��D�̐�
	if (deck.size() < handNumtmp) handAllNum = deck.size();
	else                          handAllNum = handNumtmp;

	//��D�̍ő喇���ɍ��킹�đI�����Ă�J�[�h��ύX
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
		color[i] = itr->get()->GetColorNum();
		itr++;
	}
	itr = deck.begin();
	//�J�[�h�̕`��
	for (int i = 0; i < CARD_CONST; i++) {
		//�J�[�h���f�b�L�ɂ��鎞
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
		//�J�[�h���̂ĎD���p���ɂ��鎞
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
			//�J�[�h���̂ĎD�ɂ��鎞
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
		//�J�[�h����D�ɂ��鎞
		else {
			DrawExtendGraph(
				card[i].pos_.x - (cardSize.x / 2),
				card[i].pos_.y - (cardSize.y / 2) + card[i].move_.y,
				card[i].pos_.x + (cardSize.x / 2),
				card[i].pos_.y + (cardSize.y / 2) + card[i].move_.y,
				cardGraph_[color[card[i].space_ - 1]][card[i].isHit_],
				true
			);
		}
	}
}

std::mt19937 create_rand_engine() {
	std::random_device rnd;
	std::vector<std::uint_least32_t> v(10);// �������p�x�N�^
	std::generate(v.begin(), v.end(), std::ref(rnd));// �x�N�^�̏�����
	std::seed_seq seed(v.begin(), v.end());
	return std::mt19937(seed);// �����G���W��
}

std::vector<int> make_rand_array_shuffle(const size_t size, int rand_min, int rand_max) {
	if (rand_min > rand_max) std::swap(rand_min, rand_max);
	const size_t max_min_diff = static_cast<size_t>(rand_max - rand_min + 1);
	if (max_min_diff < size) throw std::runtime_error("�������ُ�ł�");

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
	if (deckMaxBattle > 0)
	{
		deck.clear();
		deck2.clear();

		//�d���Ȃ������_���Ȑ����̔z��
		std::vector<int> cardOrder;

		//�p�����������ł̃f�b�L�̍ő喇��
		deckMaxBattle = attackMaxBattle + guardMaxBattle + buffMaxBattle + deBuffMaxBattle;

		cardOrder = make_rand_array_shuffle(deckMaxBattle, 0, deckMaxBattle - 1);
		std::vector<int>::iterator ITR = cardOrder.begin();


		//�g���J�[�h�𐶐�
		//std::unique_ptr<AttackCard> attackC[attackMax];
		//std::unique_ptr<GuardCard> guardC[guardMax];
		//std::unique_ptr<BuffCard> buffC[buffMax];
		//std::unique_ptr<DeBuffCard> deBuffC[deBuffMax];

		//�����A�f�b�L��ł̃J�[�h�̏��Ԃ������œ���Ă����āA���̃��X�g�i�f�b�L�j�ɏ��Ԋ֌W�Ȃ��Ƃ肠���������

		for (int i = 0; i < attackMaxBattle; i++)
		{
			std::unique_ptr<AttackCard> attackC = std::make_unique<AttackCard>();
			attackC->Initialize(1, 3);
			attackC->SetCardOrder(*ITR);
			deck2.push_back(std::move(attackC));

			ITR++;
		}
		for (int i = 0; i < guardMaxBattle; i++)
		{
			std::unique_ptr<GuardCard> guardC = std::make_unique<GuardCard>();
			guardC->Initialize();
			guardC->SetCardOrder(*ITR);
			deck2.push_back(std::move(guardC));

			ITR++;
		}
		for (int i = 0; i < buffMaxBattle; i++)
		{
			std::unique_ptr<BuffCard> buffC = std::make_unique<BuffCard>();
			buffC->Initialize(2);
			buffC->SetCardOrder(*ITR);
			deck2.push_back(std::move(buffC));

			ITR++;
		}
		for (int i = 0; i < deBuffMaxBattle; i++)
		{
			std::unique_ptr<DeBuffCard> deBuffC = std::make_unique<DeBuffCard>();
			deBuffC->Initialize(2);
			deBuffC->SetCardOrder(*ITR);
			deck2.push_back(std::move(deBuffC));

			ITR++;
		}




		////�f�b�L��ł̃J�[�h�̏��Ԃ������œ���Ă�����
		//for (int i = 0; i < cardOrder.size(); i++)
		//{
		//	if (i < attackMax)
		//	{
		//		attackC[i]->SetCardOrder(*ITR);
		//	}
		//	else if (i < attackMax + guardMax)
		//	{
		//		guardC[i - attackMax]->SetCardOrder(*ITR);
		//	}
		//	else if (i < attackMax + guardMax + buffMax)
		//	{
		//		buffC[i - (attackMax + guardMax)]->SetCardOrder(*ITR);
		//	}
		//	else if (i < attackMax + guardMax + buffMax + deBuffMax)
		//	{
		//		deBuffC[i - (attackMax + guardMax + buffMax)]->SetCardOrder(*ITR);
		//	}

		//	ITR++;
		//}


		//
		//for (int i = 0; i < deckMax; i++)
		//{
		//	if (i < attackMax)
		//	{
		//		deck2.push_back(std::move(attackC[i]));
		//	}
		//	else if (i < attackMax + guardMax)
		//	{
		//		deck2.push_back(std::move(guardC[i - attackMax]));
		//	}
		//	else if (i < attackMax + guardMax + buffMax)
		//	{
		//		deck2.push_back(std::move(buffC[i - (attackMax + guardMax)]));
		//	}
		//	else if (i < attackMax + guardMax + buffMax + deBuffMax)
		//	{
		//		deck2.push_back(std::move(deBuffC[i - (attackMax + guardMax + buffMax)]));
		//	}
		//}

		//���̃��X�g�̒��̃J�[�h�𒲂ׂāA�f�b�L��ł̏��Ƀf�b�L�̃��X�g�ɓ���Ă�����
		int orderCount = 0;
		while (orderCount < deckMaxBattle)
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
			if (orderCount >= deckMaxBattle)
			{
				break;
			}
		}
	}
}


