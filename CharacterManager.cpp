#include "CharacterManager.h"


void CharacterManager::Initialize(Player* player, Enemy* enemy, int enemyMax)
{
	this->player = player;
	this->enemy = enemy;

	this->enemyMax = enemyMax;

	isBattle = false;
	isEnd = false;
	enemyNum = 0;
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
			player->Damage(enemy[enemyNum].GetPower());
			enemy[enemyNum].SetIsAttack(false);

			player->AddScale(0.6f);
			enemy[enemyNum].AddAngle(0.6f);

		}
		//playerの〃
		if (player->GetIsAttack())
		{
			enemy[enemyNum].Damage(player->GetPower());
			player->SetIsAttack(false);

			enemy[enemyNum].AddScale(0.6f);
			player->AddAngle(-0.6f);
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
	}

	//ブレークのチュートリアルになって、説明を読み進めたら、相手のhpを半分にしてブレーク発動
	if (tutorial != nullptr && tutorial->GetState() == TUTORIAL::BREAK && tutorial->GetStateNum() >= tutorial->GetStateNumMax())
	{
		while (enemy[enemyNum].GetHP() > enemy[enemyNum].GetHpMAX() / 2.0f)
		{
			enemy[enemyNum].Damage(1);
		}
		
	}
}

void CharacterManager::Draw()
{
	if (!isEnd)
	{
		if(enemyNum==0)SetDrawBright(255, 0, 0);
		if(enemyNum==1)SetDrawBright(0, 255, 0);
		if(enemyNum==2)SetDrawBright(100, 100, 0);
		if(enemyNum==3)SetDrawBright(255, 255, 255);
		if(enemyNum==4)SetDrawBright(255, 0, 255);
		enemy[enemyNum].Draw();
		SetDrawBright(255, 255, 255);
	}

	player->Draw();

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
