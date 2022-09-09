#include "CardMove.h"

void CardMove::Initialize()
{
	//������
	for (int i = 0; i < CARD_CONST; i++) {
		card[i].pos_ = { 1500,800 };
		card[i].move_ = { 0,0 };
		card[i].space_ = 0;
		card[i].isMove_ = 0;
		card[i].isHit_ = 0;
		card[i].chengeSize_ = { 0,0 };
		card[i].alpha_ = 255;
	}
	//�摜�ǂݍ���
	cardGraph_ = LoadGraph("resources/card_attack_prototype.png");
}

void CardMove::Update()
{
	//�}�E�X���W�̎擾
	GetMousePoint(&mouseX, &mouseY);

	for (int i = 0; i < 5; i++) {
		//��D�ɃJ�[�h�����邩
		isSpace[i] = false;
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
		else if (isSpace[4] == false) {
			if (card[i].space_ == CardSpace::Deck) {
				card[i].space_ = CardSpace::Hand5;
				isSpace[4] = true;
			}
		}
	}

	//�J�[�h�������Ă��邩�Ǘ�����ϐ��̏�����
	for (int i = 0; i < CARD_CONST; i++) {
		card[i].isMove_ = false;
	}

	//��D���w��̏ꏊ�܂œ�����
	for (int i = 0; i < CARD_CONST; i++) {
		//�E����1�Ԗ�
		if (card[i].space_ == CardSpace::Hand1) {
			if (card[i].pos_.x != handSpace1.x && card[i].isSelect_ == false) {
				card[i].pos_.x -= cardSpeeed_;
				card[i].isMove_ = true;
			}
		}
		//�E����2�Ԗ�
		else if (card[i].space_ == CardSpace::Hand2) {
			if (card[i].pos_.x != handSpace2.x && card[i].isSelect_ == false) {
				card[i].pos_.x -= cardSpeeed_;
				card[i].isMove_ = true;
			}
		}
		//�E����3�Ԗ�
		else if (card[i].space_ == CardSpace::Hand3) {
			if (card[i].pos_.x != handSpace3.x && card[i].isSelect_ == false) {
				card[i].pos_.x -= cardSpeeed_;
				card[i].isMove_ = true;
			}
		}
		//�E����4�Ԗ�
		else if (card[i].space_ == CardSpace::Hand4) {
			if (card[i].pos_.x != handSpace4.x && card[i].isSelect_ == false) {
				card[i].pos_.x -= cardSpeeed_;
				card[i].isMove_ = true;
			}
		}
		//�E����5�Ԗ�
		else if (card[i].space_ == CardSpace::Hand5) {
			if (card[i].pos_.x != handSpace5.x && card[i].isSelect_ == false) {
				card[i].pos_.x -= cardSpeeed_;
				card[i].isMove_ = true;
			}
		}
		//�̂ĎD
		else if (card[i].space_ == CardSpace::Trash) {
			if (card[i].isSelect_ == false) {
				//�J�[�h�Ǝ̂ď�̋���
				Vec2 space6Len = handSpace6 - card[i].pos_;
				//�g�����J�[�h���̂ď�ɖ�����Έړ�������
				if (card[i].pos_.x != handSpace6.x) {
					//������20pixel�ȏ㗣��Ă�����20pixel������
					if (space6Len.GetLength() >= cardSpeeed_) {
						card[i].pos_.x += space6Len.x / space6Len.GetLength() * cardSpeeed_;
					}
					//������20pixel�ȉ��Ȃ�̂ď�܂œ�����
					else {
						card[i].pos_.x += space6Len.x;
					}
				}
				if (card[i].pos_.y != handSpace6.y) {
					//������20pixel�ȏ㗣��Ă�����20pixel������
					if (space6Len.GetLength() >= cardSpeeed_) {
						card[i].pos_.y += space6Len.y / space6Len.GetLength() * cardSpeeed_;
					}
					//������20pixel�ȉ��Ȃ�̂ď�܂œ�����
					else {
						card[i].pos_.y += space6Len.y;
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
		if (card[i].space_ != CardSpace::Deck && card[i].space_ != CardSpace::Trash && card[i].isMove_ == false) {
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

	//�͂�ł��Ȃ����E�N���b�N�Ŕp��
	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0 && isCatch == false) {
		for (int i = 0; i < CARD_CONST; i++) {
			if (card[i].isHit_ == true) {
				card[i].space_ = CardSpace::Delete;
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
				card[i].space_ = CardSpace::Trash;
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
}

void CardMove::Draw()
{
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
				cardGraph_,
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
				cardGraph_,
				true
			);
		}
	}
}
