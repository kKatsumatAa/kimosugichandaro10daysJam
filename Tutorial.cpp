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
	//DrawFormatString(0, 500, 0xffffff, "\nstate:%d", state2);

	count += 0.1f;
	//チュートリアル中
	DrawGraph(50, (float)50 + sinf(count)*5.0f, texhandle[7], true);
	DrawGraph(110, (float)160 + sinf(count)*5.0f, texhandle[8], true);
}


//-----------------------------------------------------------
BattleTutrial::BattleTutrial()
{
	texhandle[0] = LoadGraph("resources/battleInfo1.png");
	texhandle[1] = LoadGraph("resources/battleInfo2.png");
	texhandle[2] = LoadGraph("resources/box.png");
	texhandle[3] = LoadGraph("resources/UI_click_left.png");
}

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
	count += 0.1f;

	if(num==0) DrawExtendGraph(500 + sinf(count) * 5.0f, 250 + sinf(count) * 5.0f, 1500 - sinf(count) * 5.0f, 700 - sinf(count) * 5.0f, 
		this->texhandle[2], true);
	if(num==1) DrawExtendGraph(500 + sinf(count) * 5.0f, 230 + sinf(count) * 5.0f, 1500 - sinf(count) * 5.0f, 370 - sinf(count) * 5.0f,
		this->texhandle[2], true);

	DrawRotaGraph(1600, 200, 0.8f + sinf(count) * 0.01f, 0, this->texhandle[num], true);

	if ((int)count % 6 < 3)
		DrawGraph(1550, 330, this->texhandle[3], true);
	else
		DrawGraph(1550, 310, this->texhandle[3], true);

	//DrawFormatString(0, 500, 0xffffff, "tutorialNum:%d", num);
}

//-----------------------------------------------------------------
CardTutrial::CardTutrial()
{
	texhandle[0] = LoadGraph("resources/CardInfo1.png");
	texhandle[1] = LoadGraph("resources/CardInfo2.png");
	texhandle[2] = LoadGraph("resources/CardInfo3.png");
	texhandle[3] = LoadGraph("resources/box.png");
	texhandle[4] = LoadGraph("resources/arrow.png");
	texhandle[5] = LoadGraph("resources/UI_click_left.png");
}

void CardTutrial::Update(Mouse* mouse)
{
	if (num > 0)
	{
		//クリックしてせつめい画像を進める
		if (mouse->GetLeftClickTrriger()) num++;
	}

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
	count += 0.1f;

	DrawExtendGraph(100 + sinf(count) * 5.0f, 600 + sinf(count) * 5.0f, 1800 - sinf(count) * 5.0f, 1200 - sinf(count) * 5.0f,
		this->texhandle[3], true);

	DrawRotaGraph(1600, 200, 0.8f + sinf(count) * 0.01f, 0, this->texhandle[num], true);
	//矢印
	SetDrawBright(255, 0, 0);
	DrawRotaGraph(1920 / 2, 700 + sinf(-count) * 10.0f, 0.2f, 0, this->texhandle[4], true);
	SetDrawBright(255, 255, 255);

	if (num > 0)
	{
		if ((int)count % 6 < 3)
			DrawGraph(1550, 330, this->texhandle[5], true);
		else
			DrawGraph(1550, 310, this->texhandle[5], true);
	}

	//DrawFormatString(0, 500, 0xffffff, "tutorialNum:%d", num);
}



//------------------------------------------------------------------
WasteTutrial::WasteTutrial()
{
	texhandle[0] = LoadGraph("resources/WasteInfo1.png");
	texhandle[1] = LoadGraph("resources/WasteInfo2.png");
	texhandle[2] = LoadGraph("resources/WasteInfo3.png");
	texhandle[3] = LoadGraph("resources/box.png");
	texhandle[4] = LoadGraph("resources/UI_click_left.png");
	texhandle[5] = LoadGraph("resources/UI_click_left.png");
}

void WasteTutrial::Update(Mouse* mouse)
{
	if (num > 0)
	{
		//クリックしてせつめい画像を進める
		if (mouse->GetLeftClickTrriger()) num++;
	}

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
	DrawExtendGraph(100 + sinf(count) * 5.0f, 600 + sinf(count) * 5.0f, 1800 - sinf(count) * 5.0f, 1200 - sinf(count) * 5.0f,
		this->texhandle[3], true);

	DrawRotaGraph(1600, 200, 0.8f + sinf(count) * 0.01f, 0, this->texhandle[num], true);

	count += 0.1f;

	if (num > 0)
	{
		if ((int)count % 6 < 3)
			DrawGraph(1550, 330, this->texhandle[5], true);
		else
			DrawGraph(1550, 310, this->texhandle[5], true);
	}

	//DrawFormatString(0, 500, 0xffffff, "tutorialNum:%d", num);
}




//-------------------------------------------------------------------
BreakTutrial::BreakTutrial()
{
	texhandle[0] = LoadGraph("resources/BreakInfo1.png");
	texhandle[1] = LoadGraph("resources/BreakInfo2.png");
	texhandle[2] = LoadGraph("resources/BreakInfo4.png");
	texhandle[4] = LoadGraph("resources/UI_click_left.png");
}

void BreakTutrial::Update(Mouse* mouse)
{
	//クリックで画像を進める（画像が終わったら、ブレークが発動するようにcharamanagerで）
	if (mouse->GetLeftClickTrriger()) num++;

	/*if (num >= numMax)tutorial->SetIsEnd(true);*/
}

void BreakTutrial::Draw(unsigned int* texhandle)
{
	//DrawExtendGraph(100 + sinf(count) * 5.0f, 600 + sinf(count) * 5.0f, 1800 - sinf(count) * 5.0f, 1200 - sinf(count) * 5.0f,
	//	this->texhandle[3], true);

	if (num < numMax)
	{
		DrawRotaGraph(1600, 200, 0.8f + sinf(count) * 0.01f, 0, this->texhandle[num], true);

		count += 0.1f;

		{
			if ((int)count % 6 < 3)
				DrawGraph(1550, 330, this->texhandle[4], true);
			else
				DrawGraph(1550, 310, this->texhandle[4], true);
		}

		//DrawFormatString(0, 500, 0xffffff, "tutorialNum:%d", num);
	}
}


