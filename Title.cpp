#include "Title.h"
#include "DxLib.h"
#include "Game.h"

TitleScene::TitleScene(KeyboardInput& key):
	key(key), isEnd(false)
{
	particle_ = new Particle;
	particle_->Initialize();
	player.Initialize(texhandle, { 780,1080 / 2 - 150 });
	enemy.Initialize(texhandle, { 2100,1080 / 2 - 150 }, 50);
	charaM.Initialize(&player, &enemy, 1);
	cardM.Initialize();
	cost.Initialize();
	tutorial.Initialize();

	{
		texhandle[0] = LoadGraph("resources/a.png");
		texhandle[1] = LoadGraph("resources/healthUI_frame.png");
		texhandle[2] = LoadGraph("resources/UI_energy_orb.png");
		texhandle[3] = LoadGraph("resources/menu_title.png");
	}
}

void TitleScene::Update()
{
	mouse.Update();

	if (state == TITLESTATE::TITLE)
	{
		if (mouse.GetLeftClickTrriger()) state = TITLESTATE::TUTORIAL;
	}
	else if (state == TITLESTATE::TUTORIAL)
	{
		particle_->Update();

		cost.Update();
		charaM.Update(&tutorial);
		cardM.Update(&key, charaM.GetPlayer(), charaM.GetEnemy(), &cost, charaM.GetIsBattle(), &tutorial);

		//�N���A�����烊�U���g���
		if (charaM.GetIsEnd())
		{
			isEnd = true;
		}

		tutorial.Update();

		//�`���[�g���A���I�������J��
		if (tutorial.GetIsEnd())
		{
			isEnd = true;
		}

		//�X�L�b�v
		if (key.GetKey(KEY_INPUT_SPACE)) skipGauge--;
		else skipGauge = 120;

		if (skipGauge <= 0) isEnd = true;
	}
}

void TitleScene::Draw()
{
	if (state == TITLESTATE::TITLE)
	{
		DrawGraph(0, 0, texhandle[3], true);
	}
	else if (state == TITLESTATE::TUTORIAL)
	{
		DrawFormatString(0, 0, 0xFFFFFF, "TITLE");
		charaM.Draw();
		cardM.Draw(texhandle);

		cost.Draw(texhandle);

		particle_->Draw();

		tutorial.Draw(texhandle);
	}
}

bool TitleScene::IsEnd()
{
	return isEnd;
}

Iscene* TitleScene::GetNextScene()
{
	return new GameScene(key);
}
