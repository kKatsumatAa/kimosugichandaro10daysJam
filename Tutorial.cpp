#include "Tutorial.h"
#include "DxLib.h"

void Tutorial::Initialize()
{
	state = new BattleTutrial;
	state->SetTutorial(this);
}

void Tutorial::Update()
{
	mouse.Update();
	state->Update();
}

void Tutorial::Draw(unsigned int* texhandle)
{
	state->Draw(texhandle);
	DrawFormatString(0, 500, 0xffffff, "\nstate:%d", state2);
}


//-----------------------------------------------------------
void BattleTutrial::Update()
{
	//�N���b�N���Ă��߂��摜��i�߂�
	if (tutorial->mouse.GetLeftClickTrriger()) num++;

	if (num >= numMax)
	{
		tutorial->AddState();
		tutorial->AddState2();
		tutorial->ChangeState(new CardTutrial);
	}
}

void BattleTutrial::Draw(unsigned int* texhandle)
{
	DrawFormatString(0, 500, 0xffffff, "tutorialNum:%d", num);
}

//-----------------------------------------------------------------
void CardTutrial::Update()
{
	//�J�[�h���v���C�����num�𑝂₷������cardManager��
	if (num >= numMax)
	{
		tutorial->AddState();
		tutorial->AddState2();
		tutorial->ChangeState(new WasteTutrial);
	}
}

void CardTutrial::Draw(unsigned int* texhandle)
{
	DrawFormatString(0, 500, 0xffffff, "tutorialNum:%d", num);
}

//------------------------------------------------------------------
void WasteTutrial::Update()
{
	//�J�[�h��p�������num�𑝂₷������cardManager��
	if (num >= numMax)
	{
		tutorial->AddState();
		tutorial->AddState2();
		tutorial->ChangeState(new BreakTutrial);
	}
}

void WasteTutrial::Draw(unsigned int* texhandle)
{
	DrawFormatString(0, 500, 0xffffff, "tutorialNum:%d", num);
}

//-------------------------------------------------------------------
void BreakTutrial::Update()
{
	//�N���b�N�ŉ摜��i�߂�i�摜���I�������A�u���[�N����������悤��charamanager�Łj
	if (tutorial->mouse.GetLeftClickTrriger()) num++;

	/*if (num >= numMax)tutorial->SetIsEnd(true);*/
}

void BreakTutrial::Draw(unsigned int* texhandle)
{
	DrawFormatString(0, 500, 0xffffff, "tutorialNum:%d", num);
}