#pragma once
#include "Actor.h"

class Monster : public Actor
{
public:
	Monster();
	virtual ~Monster();



protected:
	int Exp;	// 처치시 플레이어가 획득하는 경험치
	int Reward;	// 처치시 플레이어가 획득하는 돈
};

