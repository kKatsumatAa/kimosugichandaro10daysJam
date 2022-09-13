#include "Tutorial.h"
#include "DxLib.h"
#include <math.h>

void Tutorial::Initialize()
{
	state = new BattleTutrial;
	state->SetTutorial(this);
}

void Tutorial::Update(Mouse* mouse)
{
	state->Update(mouse);
}

void Tutorial::Draw(unsigned int* texhandle)
{
	state->Draw(texhandle);
	DrawFormatString(0, 500, 0xffffff, "\nstate:%d", state2);

	count += 0.1f;
	//チュートリアル中
	DrawGraph(50, (float)50 + sinf(count)*5.0f, texhandle[7], true);
	DrawGraph(110, (float)160 + sinf(count)*5.0f, texhandle[8], true);
}


//-----------------------------------------------------------
void BattleTutrial::Update(Mouse* mouse)
{
	//クリックしてせつめい画像を進める
	if (mouse->GetLeftClickTrriger()) num++;

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
void CardTutrial::Update(Mouse* mouse)
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
void WasteTutrial::Update(Mouse* mouse)
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
void BreakTutrial::Update(Mouse* mouse)
{
	//クリックで画像を進める（画像が終わったら、ブレークが発動するようにcharamanagerで）
	if (mouse->GetLeftClickTrriger()) num++;

	/*if (num >= numMax)tutorial->SetIsEnd(true);*/
}

void BreakTutrial::Draw(unsigned int* texhandle)
{
	DrawFormatString(0, 500, 0xffffff, "tutorialNum:%d", num);
}