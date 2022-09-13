#include "Game.h"
#include "DxLib.h"
#include "Result.h"
#include "Title.h"
#include "Burst.h"

GameScene::GameScene(KeyboardInput& key) :
	key(key), isEnd(false),
	nextScene(new ResultScene(key))//元はリザルトが入ってる
{
	LoadDivGraph("resources/player_idle-Animation-Sheet.png", 9, 9, 1, 160,160, (int*)playerTexture,true);
	LoadDivGraph("resources/enemy_dammy-sheet.png", 6, 6, 1, 160, 160, (int*)enemy1Texture, true);
	LoadDivGraph("resources/enemy_slime.png", 6, 6, 1, 160, 160, (int*)enemy2Texture, true);
	LoadDivGraph("resources/enemy_mashroom.png", 6, 6, 1, 160, 160, (int*)enemy3Texture, true);
	LoadDivGraph("resources/enemy_monster.png", 6, 6, 1, 160, 160, (int*)enemy4Texture, true);
	background = LoadGraph("resources/game_background.png");
	particle_ = new Particle;
	particle_->Initialize();

	player.Initialize(playerTexture,texhandle, { 780,1080 / 2 - 150 });
	enemy[0].Initialize(enemy1Texture,texhandle, { 2100,1080 / 2 - 150 }, 10);
	enemy[1].Initialize(enemy2Texture,texhandle, { 2100,1080 / 2 - 150 }, 15, 3, 170);
	enemy[2].Initialize(enemy3Texture,texhandle, { 2100,1080 / 2 - 150 }, 20, 5, 100);
	enemy[3].Initialize(enemy4Texture,texhandle, { 2100,1080 / 2 - 150 }, 20, 12, 300);
	enemy[4].Initialize(enemy4Texture,texhandle, { 2100,1080 / 2 - 150 }, 30, 15, 250);

	charaM.Initialize(&player, enemy);
	cardM.Initialize();
	cost.Initialize();

	{
		texhandle[0] = LoadGraph("resources/a.png");
		texhandle[1] = LoadGraph("resources/healthUI_frame.png");
		texhandle[2] = LoadGraph("resources/UI_energy_orb.png");
		texhandle[4] = LoadGraph("resources/UI_special_attack_gauge.png");
		texhandle[5] = LoadGraph("resources/UI_attack_icon.png");
		texhandle[6] = LoadGraph("resources/UI_defense_icon.png");
	}
}

GameScene::~GameScene() {
	delete particle_;
}

void GameScene::Update()
{
#ifdef _DEBUG
	if (key.GetKeyTrigger(KEY_INPUT_SPACE)) isEnd = true;
	else if (key.GetKeyTrigger(KEY_INPUT_Q))
	{
		isEnd = true;
		delete nextScene;
		nextScene = new TitleScene(key);
	}
#endif 

	if (key.GetKeyTrigger(KEY_INPUT_1)) {
		particle_->BurstGenerate(Vec2(775, 550),5,50,60,225,15.0f,GetColor(200,0,0));
	}
	if (key.GetKey(KEY_INPUT_2)) {
		particle_->FireGenerate(Vec2(775, 550),16);
	}
	if (key.GetKey(KEY_INPUT_3)) {
		particle_->WaterGenerate(Vec2(775, 550), 16);
	}
	if (key.GetKeyTrigger(KEY_INPUT_4)) {
		particle_->LightningGenerate(Vec2(775, 550),500,3,60,1);
	}
	if (key.GetKey(KEY_INPUT_5)) {
		particle_->BuffGenerate(Vec2(775, 550), Vec2(100, 50),15);
	}
	if (key.GetKey(KEY_INPUT_6)) {
		particle_->DebuffGenerate(Vec2(775, 550), Vec2(100, 50),15);
	}
	if (key.GetKey(KEY_INPUT_7)) {
		particle_->SlashGenerate(Vec2(1125, 340));
	}
	if (key.GetKeyTrigger(KEY_INPUT_8)) {
		particle_->OrbGenerate(Vec2(200,200),Vec2 (1000,1000));
	}
	if (key.GetKeyTrigger(KEY_INPUT_9)) {
		particle_->NumberGecerate(Vec2(200, 200),1,279);
	}


	cost.Update();
	charaM.Update();
	cardM.Update(&key, charaM.GetPlayer(), charaM.GetEnemy(), &cost, charaM.GetIsBattle());
	particle_->Update();

	//クリアしたらリザルト画面
	if (charaM.GetIsEnd())
	{
		isEnd = true;
	}

	//playerが死んだらタイトルに戻る
	if (charaM.GetPlayer()->GetIsDead())
	{
		isEnd = true;
		delete nextScene;
		nextScene = new TitleScene(key);
	}
}

void GameScene::Draw()
{
	DrawGraph(0, 0, background, true);
	charaM.Draw();
	cardM.Draw(texhandle);

	cost.Draw(texhandle);

	DrawFormatString(0, 0, 0xFFFFFF, "GAME");
	particle_->Draw();
}

bool GameScene::IsEnd()
{
	return isEnd;
}

Iscene* GameScene::GetNextScene()
{
	return nextScene;
}
