#include "DxLib.h"
#include "Def.h"
#include "KeyboardInput.h"
#include "Mouse.h"
#include "Scene.h"
#include "Title.h"
#include "Game.h"



int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
                   _In_ int nCmdShow) {
	SetDef set;
	set.Set();
	KeyboardInput key;
	Mouse mouse;
	Iscene* scene = new TitleScene(key);
	

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

		// �`�揈��
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
