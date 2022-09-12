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
	//クリックしてせつめい画像を進める
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
	//カードをプレイするとnumを増やす処理をcardManagerで
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
	//カードを廃棄するとnumを増やす処理をcardManagerで
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
	//クリックで画像を進める（画像が終わったら、ブレークが発動するようにcharamanagerで）
	if (tutorial->mouse.GetLeftClickTrriger()) num++;

	/*if (num >= numMax)tutorial->SetIsEnd(true);*/
}

void BreakTutrial::Draw(unsigned int* texhandle)
{
	DrawFormatString(0, 500, 0xffffff, "tutorialNum:%d", num);
}