#include "Card.h"


void Card::Update()
{
}


//---------------------------------------------------------------
void AttackCard::Initialize(int cost, int power)
{
	this->cost = cost;
	this->power = power;
	attribute = Attibute::ATTACK;
}

//---------------------------------------------------------------
void AttackCard::Draw(unsigned int texhandle, Vec2 pos)
{
	DrawBox(pos.x - cardLength.x / 2, pos.y - cardLength.y,
		pos.x + cardLength.x / 2, pos.y + cardLength.y, 0xff0101, true);
}

void AttackCard::Effect(Player* player, Enemy* enemy)
{
	enemy->Damage(power);
}


//--------------------------------------------------------------
void GuardCard::Initialize(int cost, int guardPower)
{
	this->cost = cost;
	this->guardPower = guardPower;
	attribute = Attibute::GUARD;
}

void GuardCard::Draw(unsigned int texhandle, Vec2 pos)
{
	DrawBox(pos.x - cardLength.x / 2, pos.y - cardLength.y,
		pos.x + cardLength.x / 2, pos.y + cardLength.y, 0x0001ff, true);
}

void GuardCard::Effect(Player* player, Enemy* enemy)
{
	player->AddGuardPower(guardPower);
}


//-------------------------------------------------------------------
void BuffCard::Initialize(int cost, int buffPower)
{
	this->cost = cost;
	this->buffPower = buffPower;
	attribute = Attibute::BUFF;
}

void BuffCard::Draw(unsigned int texhandle, Vec2 pos)
{
	DrawBox(pos.x - cardLength.x / 2, pos.y - cardLength.y,
		pos.x + cardLength.x / 2, pos.y + cardLength.y, 0x01ff01, true);
}

void BuffCard::Effect(Player* player, Enemy* enemy)
{
	player->AddPower(buffPower);
}



//--------------------------------------------------------------
void DeBuffCard::Initialize(int cost, int deBuffPower)
{
	this->cost = cost;
	this->deBuffPower = deBuffPower;
	attribute = Attibute::DEBUFF;
}

void DeBuffCard::Draw(unsigned int texhandle, Vec2 pos)
{
	DrawBox(pos.x - cardLength.x / 2, pos.y - cardLength.y,
		pos.x + cardLength.x / 2, pos.y + cardLength.y, 0x01ffff, true);
}

void DeBuffCard::Effect(Player* player, Enemy* enemy)
{
	enemy->AddDeBuff(deBuffPower);
}
