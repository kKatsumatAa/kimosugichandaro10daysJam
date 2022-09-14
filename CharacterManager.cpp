#include "CharacterManager.h"


void CharacterManager::Initialize(Player* player, Enemy* enemy, int enemyMax)
{
	this->player = player;
	this->enemy = enemy;
	particle = new Particle;
	particle->Initialize();

	this->enemyMax = enemyMax;

	isBattle = false;
	isEnd = false;
	enemyNum = 0;

	soundHandle = LoadSoundMem("resources/sound/slash_SFX.mp3");
	ChangeVolumeSoundMem(100, soundHandle);
}


void CharacterManager::Update(Tutorial* tutorial)
{
	bool oldIsBattle = isBattle;

	if (!isEnd && isBattle)
	{
		this->enemy[enemyNum].Update();
		this->player->Update();

		//敵の攻撃準備ができたら
		if (enemy[enemyNum].GetIsAttack())
		{
			PlaySoundMem(soundHandle, DX_PLAYTYPE_BACK);

			player->Damage(enemy[enemyNum].GetPower());
			particle->NumberGecerate(Vec2(player->GetPos().x - 190, player->GetPos().y - 20), 1, enemy[enemyNum].GetPower() - player->GetGuardPower());
			enemy[enemyNum].SetIsAttack(false);

			player->AddScale(0.6f);
			enemy[enemyNum].AddAngle(0.6f);
			shakeTimer = 10;
		}
		//playerの〃
		if (player->GetIsAttack())
		{
			PlaySoundMem(soundHandle, DX_PLAYTYPE_BACK);

			enemy[enemyNum].Damage(player->GetPower());
			particle->NumberGecerate(Vec2(enemy[enemyNum].GetPos().x + 190,enemy[enemyNum].GetPos().y - 20), 1, player->GetPower() - enemy[enemyNum].GetGuardPower());
			player->SetIsAttack(false);

			enemy[enemyNum].AddScale(0.6f);
			player->AddAngle(-0.6f);
			shakeTimer = 10;
		}

		if (enemy[enemyNum].GetIsHitStop()) {
			enemy[enemyNum].SetIsHitStop(false);
			SetHitStopTimer(30);
		}

		if (enemy[enemyNum].GetIsDead())
		{
			enemyNum++;

			isBattle = false;
			

			if (enemyNum > enemyMax - 1)
			{
				enemyNum = enemyMax - 1;
				isEnd = true;
			}
		}
	}
	if(!isBattle && !isEnd)
	{
		enemy[enemyNum].AddPos({ -10,0 });

		if (enemy[enemyNum].GetPos().x <= 1180)
		{
			isBattle = true;
		}


		//バトルが終わった瞬間
		if (!isBattle && oldIsBattle)
		{
			player->InitializeBattle();//
		}
		particle->Update();
	}

	//ブレークのチュートリアルになって、説明を読み進めたら、相手のhpを半分にしてブレーク発動
	if (tutorial != nullptr && (tutorial->GetState() != TUTORIAL::BATTLE || (tutorial->GetState() == TUTORIAL::BREAK))
		&& tutorial->GetStateNum() < tutorial->GetStateNumMax())
	{
		if (enemy[enemyNum].GetHpMAX() > enemy[enemyNum].GetHP()) enemy[enemyNum].AddHP(1);
		if (player->GetHpMAX() > player->GetHP()) player->AddHP(1);
	}
	else if (tutorial != nullptr && tutorial->GetState() == TUTORIAL::BREAK && tutorial->GetStateNum() >= tutorial->GetStateNumMax())
	{
		while (enemy[enemyNum].GetHP() > enemy[enemyNum].GetHpMAX() / 2.0f)
		{
			enemy[enemyNum].Damage(1);
		}
		
	}

	particle->Update();
	
}

void CharacterManager::Draw()
{
	if (!isEnd)
	{
		if(enemyNum==0)SetDrawBright(255, 255, 255);
		if(enemyNum==1)SetDrawBright(255, 255, 255);
		if(enemyNum==2)SetDrawBright(255, 255, 255);
		if(enemyNum==3)SetDrawBright(255, 255, 255);
		if(enemyNum==4)SetDrawBright(255, 255, 255);
		enemy[enemyNum].Draw();
		SetDrawBright(255, 255, 255);
	}

	player->Draw();
	particle->Draw();

	DrawFormatString(5, 0, 0xffffff, "\nisBattle:%d", isBattle);
	DrawFormatString(5, 0, 0xffffff, "\n\nisEnd:%d", isEnd);
	DrawFormatString(5, 0, 0xffffff, "\n\n\nenemyNumber:%d", enemyNum);

	////hp
	//DrawFormatString(player->GetPos().x -32, player->GetPos().y - 100, 0xffffff, "playerHP:%d", player->GetHP());
	//DrawFormatString(enemy[enemyNum].GetPos().x -32, enemy[enemyNum].GetPos().y - 100, 0xffffff, "enemyHP:%d", enemy[enemyNum].GetHP());

	////
	////DrawRotaGraph3(player->GetPos().x - 32, 1080 / 2 -50, 32, 32, 1.0 * player->GetAttackGauge(), 0.3f, 0, player->GetTexHandle(), false);
	////DrawRotaGraph3(enemy[enemyNum].GetPos().x - 32, 1080 / 2 -50, 32, 32, 1.0 * enemy[enemyNum].GetAttackGauge(), 0.3f, 0, player->GetTexHandle(), false);

	////攻撃ゲージ
	//DrawBox(player->GetPos().x - 32, player->GetPos().y - 50, 
	//	(player->GetPos().x - 32) + player->GetAttackGauge() * 64, player->GetPos().y - 40, 0xffffff, false);

	//DrawBox(enemy[enemyNum].GetPos().x - 32, enemy[enemyNum].GetPos().y - 50,
	//	(enemy[enemyNum].GetPos().x - 32) + enemy[enemyNum].GetAttackGauge() * 64, enemy[enemyNum].GetPos().y - 40, 0xffffff, false);
}
