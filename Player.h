#pragma once
#include "Character.h"


class Player : public Character
{
public:
	void Initialize(unsigned int texhandle) override;
};

