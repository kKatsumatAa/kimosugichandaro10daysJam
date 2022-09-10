#include "Game.h"
#include "DxLib.h"
#include "Result.h"
#include "Title.h"
#include "Burst.h"

GameScene::GameScene(KeyboardInput& key):
	key(key), isEnd(false),
	nextScene(new ResultScene(key))//元はリザルトが入ってる
{
	particle_ = new Particle;
	particle_->Initialize();
	cardMove_ = new CardMove;
	cardMove_->Initialize();

	player.Initialize(texhandle, { 780,1080 / 2 - 150 });
	enemy[0].Initialize(texhandle, { 2100,1080 / 2 - 150 }, 10);
	enemy[1].Initialize(texhandle, { 2100,1080 / 2 - 150}, 15, 3, 170);
	enemy[2].Initialize(texhandle, { 2100,1080 / 2 - 150}, 20, 5, 100);
	charaM.Initialize(&player, enemy);
	cardM.Initialize();
	cost.Initialize();
}

GameScene::~GameScene() {
	delete particle_;
	delete cardMove_;
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

	particle_->Update();
	cardMove_->Update();

	cost.Update();
	charaM.Update();
	cardM.Update(&key, charaM.GetPlayer(), charaM.GetEnemy(), &cost, charaM.GetIsBattle());

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
	charaM.Draw();
	cardM.Draw(&texhandle);

	cost.Draw(&texhandle);

	DrawFormatString(0, 0, 0xFFFFFF, "GAME");
	particle_->Draw();
	cardMove_->Draw();
}

bool GameScene::IsEnd()
{
	return isEnd;
}

Iscene* GameScene::GetNextScene()
{
	return nextScene;
}
