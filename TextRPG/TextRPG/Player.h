#pragma once
#include "Actor.h"

class Monster;
class Player : public Actor
{
public:
	Player();
	virtual ~Player();


	virtual void Initialize() override;
	virtual void Release() override;
	virtual void PrintInfo() const override;
	virtual int ApplyDamage(Actor& InActor) override;
	virtual int TakeDamage(int Damage) override;

	void NormalAttack(Actor& InActor);
	void Skill(Actor& InActor);
	void EarnRewards(Monster* InMonster);
	void LevelUp();

	void Heal();

private:
	int Level;				// 현재 레벨
	int Exp;				// 경험치
	std::map<int,int> ExpToNextLevel;	// 레벨업 필요 경험치
	std::map<int,int> HealthMax;		// 레벨별 최대 Hp
	
	int Gold;

	int AttackPowerPlus;		// 추가 공격력(레벨에 비례)
	float Luck;					// 행운(크리티컬 확률에 추가)
};

