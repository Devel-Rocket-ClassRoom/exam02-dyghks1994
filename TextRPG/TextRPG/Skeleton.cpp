#include "pch.h"
#include "Skeleton.h"

Skeleton::Skeleton()
{
	Initialize();
}

Skeleton::~Skeleton()
{
	Release();
}

void Skeleton::Initialize()
{
	Name = "스켈레톤";

	// Hp 리셋
	HealthMax = SkeletonHealthMax;
	Health = HealthMax;

	// 공격력 설정
	AttackPowerMin = 15;
	AttackPowerMax = 25;

	// 크리티컬 설정
	CriticalRate = 0.3f;
	CriticalStrikeMultiplier = 1.3f;

	// 보상 설정
	Exp = 100;
	Reward = 300;
}

void Skeleton::Release()
{
}

void Skeleton::Attack(Actor& InTarget)
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

void Skeleton::Skill(Actor& InTarget)
{
}

int Skeleton::ApplyDamage(Actor& InActor)
{
	int Damage = GetRandomRange(AttackPowerMin, AttackPowerMax);
	InActor.TakeDamage(Damage);
	return Damage;
}
