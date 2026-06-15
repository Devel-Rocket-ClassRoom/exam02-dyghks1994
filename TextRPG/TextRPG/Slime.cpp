#include "pch.h"
#include "Slime.h"

Slime::Slime()
{
	Initialize();
}



Slime::~Slime()
{
	Release();
}

void Slime::Initialize()
{
	Name = "슬라임";

	// Hp 리셋
	HealthMax = SlimeHealthMax;
	Health = HealthMax;

	// 공격력 설정
	AttackPowerMin = 2;
	AttackPowerMax = 5;

	// 크리티컬 설정
	CriticalRate = 0.2f;
	CriticalStrikeMultiplier = 1.3f;

	// 보상 설정
	Exp = 50;
	Reward = 100;
}

void Slime::Release()
{
}

void Slime::Attack(Actor& InTarget)
{
	/// 랜덤으로 일반공격 or 스킬 
	float RandomNum = GetRandom();

	if (RandomNum < 0.6f)
	{
		// 일반 공격
		ApplyDamage(InTarget);
	}
	else
	{
		// 스킬 사용
		Skill(InTarget);
	}
}

void Slime::Skill(Actor& InTarget)
{
	printf("스킬 사용\n");
}

int Slime::ApplyDamage(Actor& InActor)
{
	return 0;
}

