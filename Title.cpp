#include "Title.h"
#include "DxLib.h"
#include "Game.h"

TitleScene::TitleScene(KeyboardInput& key):
	key(key), isEnd(false)
{
	particle_ = new Particle;
	particle_->Initialize();
	LoadDivGraph("resources/player_idle-Animation-Sheet.png", 9, 9, 1, 160, 160, (int*)playerTexture, true);
	LoadDivGraph("resources/enemy_dammy-sheet.png", 6, 6, 1, 160, 160, (int*)enemy1Texture, true);
	background = LoadGraph("resources/game_backGround.png");
	player.Initialize(playerTexture,texhandle, { 780,1080 / 2 - 150 });
	enemy.Initialize(enemy1Texture,texhandle, { 2100,1080 / 2 - 150 }, 50);
	charaM.Initialize(&player, &enemy, 1);
	cardM.Initialize();
	cost.Initialize();
	tutorial.Initialize();

	{
		texhandle[0] = LoadGraph("resources/a.png");
		texhandle[1] = LoadGraph("resources/healthUI_frame.png");
		texhandle[2] = LoadGraph("resources/UI_energy_orb.png");
		texhandle[3] = LoadGraph("resources/menu_title.png");
		texhandle[4] = LoadGraph("resources/UI_special_attack_gauge.png");
		texhandle[5] = LoadGraph("resources/UI_attack_icon.png");
		texhandle[6] = LoadGraph("resources/UI_defense_icon.png");
		texhandle[7] = LoadGraph("resources/UI_tutorial_text.png");
		texhandle[8] = LoadGraph("resources/UI_tutorial_text2.png");
	}
}

void TitleScene::Update()
{
	mouse.Update();

	
	if (state == TITLESTATE::TUTORIAL)
	{

		particle_->Update();

		cost.Update();
		charaM.Update(&tutorial);
		cardM.Update(&key, charaM.GetPlayer(), charaM.GetEnemy(), &cost, charaM.GetIsBattle(), &tutorial);

		//クリアしたらリザルト画面
		if (charaM.GetIsEnd())
		{
			endTimer++;

			if (endTimer >= 180) isEnd = true;
		}

		tutorial.Update(&mouse);

		//チュートリアル終わったら遷移
		if (tutorial.GetIsEnd())
		{
			isEnd = true;
		}

		//スキップ
		if (key.GetKeyTrigger(KEY_INPUT_SPACE)) isEnd = true;
		/*else skipGauge = 120;

		if (skipGauge <= 0) isEnd = true;*/
	}
	else if (state == TITLESTATE::TITLE)
	{
		if (mouse.GetLeftClickTrriger()) state = TITLESTATE::TUTORIAL;
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
		DrawGraph(0, 0, background, true);
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
