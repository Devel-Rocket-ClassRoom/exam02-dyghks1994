#include "pch.h"
#include "Actor.h"

Actor::Actor()
	: Health(0)
	, HealthMax(0)
	, AttackPowerMin(0)
	, AttackPowerMax(0)
	, CriticalRate(0.0f)
	, CriticalStrikeMultiplier(0.0f)
{
	Initialize();
}

Actor::~Actor()
{
	Release();
}

void Actor::Initialize()
{

}

void Actor::Release()
{

}

void Actor::PrintInfo() const
{
}



int Actor::ApplyDamage(Actor& InActor)
{
	return 0;
}

int Actor::TakeDamage(int Damage)
{
	int ResultDmage = Damage;

	Health -= ResultDmage;
	if (Health < 0)
	{
		Health = 0;
	}

	return ResultDmage;
}
