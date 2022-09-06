#include "CharacterManager.h"


void CharacterManager::Initialize(Player* player, Enemy* enemy)
{
	this->player = player;
	this->enemy = enemy;
}


void CharacterManager::Update()
{
	if (enemy != nullptr)
	{
		this->enemy->Update();
		this->player->Update();

		//UŒ‚€”õ‚ª‚Å‚«‚½‚ç
		if (enemy->GetIsAttack())
		{
			player->Damage(enemy->GetPower());
			enemy->SetIsAttack(false);

			player->AddScale(0.6f);
			enemy->AddAngle(0.6f);

		}
		if (player->GetIsAttack())
		{
			enemy->Damage(player->GetPower());
			player->SetIsAttack(false);

			enemy->AddScale(0.6f);
			player->AddAngle(-0.6f);
		}

		if (enemy->GetIsDead())
		{
			enemy = nullptr;
		}
	}
}

void CharacterManager::Draw()
{
	if (enemy != nullptr)
		enemy->Draw();

	player->Draw();
}
