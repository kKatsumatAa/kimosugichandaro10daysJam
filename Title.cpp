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
	}
}

void TitleScene::Update()
{
	particle_->Update();

	cost.Update();
	charaM.Update(&tutorial);
	cardM.Update(&key, charaM.GetPlayer(), charaM.GetEnemy(), &cost, charaM.GetIsBattle(),&tutorial);

	//クリアしたらリザルト画面
	if (charaM.GetIsEnd())
	{
		isEnd = true;
	}

	tutorial.Update();

	//チュートリアル終わったら遷移
	if (tutorial.GetIsEnd())
	{
		isEnd = true;
	}
}

void TitleScene::Draw()
{
	DrawFormatString(0, 0, 0xFFFFFF, "TITLE");
	charaM.Draw();
	cardM.Draw(texhandle);

	cost.Draw(texhandle);

	particle_->Draw();

	tutorial.Draw(texhandle);
}

bool TitleScene::IsEnd()
{
	return isEnd;
}

Iscene* TitleScene::GetNextScene()
{
	return new GameScene(key);
}
