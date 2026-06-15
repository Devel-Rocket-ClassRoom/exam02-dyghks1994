#include "pch.h"
#include "Monster.h"
#include "Player.h"

Player::Player()
	: Level(0)
	, Exp(0)
	, ExpToNextLevel()
	, Gold(0)
	, AttackPowerPlus(0)
	, Luck(0.0f)
{
	// 레벨업 필요경험치 테이블
	ExpToNextLevel.insert(std::make_pair(1, 50));
	ExpToNextLevel.insert(std::make_pair(2, 100));
	ExpToNextLevel.insert(std::make_pair(3, 200));
	ExpToNextLevel.insert(std::make_pair(4, 300));
	ExpToNextLevel.insert(std::make_pair(5, 10000));

	HealthMax.insert(std::make_pair(1, 100));
	HealthMax.insert(std::make_pair(2, 150));
	HealthMax.insert(std::make_pair(3, 200));
	HealthMax.insert(std::make_pair(4, 250));
	HealthMax.insert(std::make_pair(5, 300));

	Initialize();
}

Player::~Player()
{
	Release();
}

void Player::Initialize()
{
	Name = "플레이어";

	// 레벨, 경험치 초기화
	Level = 1;
	Exp = 0;

	// Hp 리셋
	Health = HealthMax.at(Level);

	// 공격력 설정
	AttackPowerMin = 10;
	AttackPowerMax = 15;

	// 크리티컬 설정
	CriticalRate = 0.3f;	// 확률
	CriticalStrikeMultiplier = 2.0f;	// 배율

	// 레벨업 추가스탯
	AttackPowerPlus = 0;
	Luck = 0.0f;

	// 보유금 초기화
	Gold = 0;
}

void Player::Release()
{
}

void Player::PrintInfo() const
{
	printf("[%s]\n", Name.c_str());
}

int Player::ApplyDamage(Actor& InActor)
{
	// 기초 대미지 계산
	// (최소공격력 ~ 최대공격력) + 추가공격력
	int Damage = GetRandomRange(AttackPowerMin, AttackPowerMax) + AttackPowerPlus;

	// 크리티컬 적용
	float Rand = GetRandom();
	if (Rand <= CriticalRate + Luck)	// 최종 크리티컬확률 = 기본 크리티컬 + 행운
	{
		Damage *= CriticalStrikeMultiplier;
	}

	return InActor.TakeDamage(Damage);
}

int Player::TakeDamage(int Damage)
{
	// 전달된 대미지에서 장비, 스탯 부분 적용해서 Hp 감소
	int ResultDamage = Damage;

	Health -= ResultDamage;
	if (Health < 0)
	{
		Health = 0;
	}

	return ResultDamage;
}

void Player::NormalAttack(Actor& InActor)
{
	int Damage = GetRandomRange(AttackPowerMin, AttackPowerMax);
	InActor.TakeDamage(Damage);
}

void Player::EarnRewards(Monster* InMonster)
{
	Exp += InMonster->GetExp();
	if (Exp >= ExpToNextLevel.at(Level))
	{
		LevelUp();
	}

	Gold += InMonster->GetReward();
}

void Player::LevelUp()
{
	// 레벨 1 증가
	Level++;

	// 경험치 0 리셋
	Exp = 0;

	// 추가스탯 증가
	AttackPowerPlus += 3;	// 레벨당 3 증가
	Luck += 0.1f;			// 행운(크리티컬 확률 추가) 0.1f 증가
}

void Player::Heal()
{
	// 인벤토리에 포션 있으면 사용
}


