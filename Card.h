#pragma once
#include "Enemy.h"


enum Attibute
{
    ATTACK,
    GUARD,
    BUFF,
    DEBUF
};


class Card
{
private:


protected:
    int attribute;
    int cost;
    bool isSelect = false;
    //”pŠü‚³‚ê‚½ƒJ[ƒh‚©
    bool isWaste = false;

    Enemy* enemy = nullptr;
    Player* player = nullptr;

    Vec2 cardLength = { 150,200 };

    int cardOrder = 0;

public:
    virtual void Update();
    virtual void Draw(unsigned int texhandle, Vec2 pos) = 0;

    virtual void Effect(Player* player, Enemy* enemy) = 0;

    void SetWaste(bool waste) {
        this->isWaste = waste;
    }
    bool GetIsWaste() {
        return isWaste;
    }

    int GetCost() {
        return cost;
    }

    int GetAttribute() {
        return attribute;
    }

    void SetCardOrder(int cardO) { cardOrder = cardO; }

    int GetCardOrder() { return cardOrder; }

};


class AttackCard : public Card
{
private:
    int power;

public:
    void Initialize(int cost = 1, int power = 1);

    void Draw(unsigned int texhandle, Vec2 pos) override;

    void Effect(Player* player, Enemy* enemy) override;

    int GetPower() {
        return power;
    }
};


class GuardCard : public Card
{
private:
    int guardPower;

public:
    void Initialize(int cost = 1, int guardPower = 1);

    void Draw(unsigned int texhandle, Vec2 pos) override;

    void Effect(Player* player, Enemy* enemy) override;

    int GetPower() {
        return guardPower;
    }
};


class BuffCard : public Card
{
private:
    int buffPower;

public:
    void Initialize(int cost = 1, int buffPower = 1);

    void Draw(unsigned int texhandle, Vec2 pos) override;

    void Effect(Player* player, Enemy* enemy) override;

    int GetPower() {
        return buffPower;
    }
};