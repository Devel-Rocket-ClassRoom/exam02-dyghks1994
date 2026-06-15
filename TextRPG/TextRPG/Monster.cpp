#include "pch.h"
#include "Monster.h"

Monster::Monster()
	: Exp(0)
	, Reward(0)
{
}

Monster::~Monster()
{
}

void Monster::Initialize()
{
}

void Monster::Release()
{
}

void Monster::PrintInfo() const
{
	printf("[%s] \n", Name.c_str());
}

void Monster::Attack(Actor& InTarget)
{
}

void Monster::Skill(Actor& InTarget)
{
}

int Monster::ApplyDamage(Actor& InActor)
{
	return 0;
}
