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

	// �Q�[�����[�v
	while (true) {

		// ��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//

		// �X�V����
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

		// �`�揈��
		charaM.Draw();

		scene->Draw();

		//---------  �����܂łɃv���O�������L�q  ---------//
		// (�_�u���o�b�t�@)����
		ScreenFlip();

		// 20�~���b�ҋ@(�^��60FPS)
		WaitTimer(20);

		// Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1) {
			break;
		}

		// ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dx���C�u�����I������
	DxLib_End();

	delete scene;

	// ����I��//
	return 0;
}
