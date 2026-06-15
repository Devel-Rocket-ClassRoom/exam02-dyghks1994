#include "pch.h"
#include "Orc.h"

Orc::Orc()
{
	Initialize();
}

Orc::~Orc()
{
	Release();
}

void Orc::Initialize()
{
	Name = "오크";

	// Hp 리셋
	HealthMax = OrcHealthMax;
	Health = HealthMax;

	// 공격력 설정
	AttackPowerMin = 2;
	AttackPowerMax = 5;

	// 크리티컬 설정
	CriticalRate = 0.2f;
	CriticalStrikeMultiplier = 1.3f;

	// 보상 설정
	Exp = 80;
	Reward = 200;
}

void Orc::Release()
{
}

void Orc::Attack(Actor& InTarget)
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

void Orc::Skill(Actor& InTarget)
{
}

int Orc::ApplyDamage(Actor& InActor)
{
	int Damage = GetRandomRange(AttackPowerMin, AttackPowerMax);
	InActor.TakeDamage(Damage);
	return Damage;
}
