#include "Game.h"
#include "DxLib.h"
#include "Result.h"
#include "Title.h"
#include "Burst.h"

GameScene::GameScene(KeyboardInput& key):
	key(key), isEnd(false),
	nextScene(new ResultScene(key))//Œ³‚ÍƒŠƒUƒ‹ƒg‚ª“ü‚Á‚Ä‚é
{
	particle_ = new Particle;
	particle_->Initialize();
	cardMove_ = new CardMove;
	cardMove_->Initialize();
}

GameScene::~GameScene() {
	delete particle_;
	delete cardMove_;
}

void GameScene::Update()
{
	if (key.GetKeyTrigger(KEY_INPUT_SPACE)) isEnd = true;
	else if (key.GetKeyTrigger(KEY_INPUT_Q))
	{
		isEnd = true;
		delete nextScene;
		nextScene = new TitleScene(key);
	}

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
		particle_->BuffGenerate(Vec2(775, 550), Vec2(100, 50));
	}

	particle_->Update();
	cardMove_->Update();
}

void GameScene::Draw()
{
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
