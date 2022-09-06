#include "DxLib.h"
#include "Def.h"
#include "KeyboardInput.h"
#include "Mouse.h"
#include "Scene.h"
#include "Title.h"
#include "Game.h"
#include "CharacterManager.h"



int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
                   _In_ int nCmdShow) {
	SetDef set;
	set.Set();
	KeyboardInput key;
	Mouse mouse;
	Iscene* scene = new TitleScene(key);

	//
 	unsigned int texhandle = LoadGraph("resources/a.png");
	
	Player player;
	player.Initialize(texhandle, { 780,1080 / 2 });

	Enemy enemy[3];
	enemy[0].Initialize(texhandle, { 2100,1080 / 2 });
	enemy[1].Initialize(texhandle, { 2100,1080 / 2 }, 7, 200);
	enemy[2].Initialize(texhandle, { 2100,1080 / 2 }, 10, 150);

	CharacterManager charaM;
	charaM.Initialize(&player, enemy);

	// ゲームループ
	while (true) {

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		// 更新処理
		mouse.Update();
		key.Update();

		scene->Update();

		if (scene->IsEnd())
		{
			Iscene* nextScene = scene->GetNextScene();
			delete scene;
			scene = nextScene;
		}

		charaM.Update();

		// 描画処理
		charaM.Draw();

		scene->Draw();

		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1) {
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dxライブラリ終了処理
	DxLib_End();

	delete scene;

	// 正常終了//
	return 0;
}
