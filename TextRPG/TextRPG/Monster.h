#pragma once
#include "Actor.h"

class Monster : public Actor
{
public:
	Monster();
	virtual ~Monster();

	virtual void Initialize() override;
	virtual void Release() override;
	virtual void PrintInfo() const override;
	virtual void Attack(Actor& InTarget);
	virtual void Skill(Actor& InTarget);
	virtual int ApplyDamage(Actor& InActor) override;

	inline int GetExp() const { return Exp; }
	inline int GetReward() const { return Reward; }

protected:
	int Exp;	// 泥섏튂???뚮젅?댁뼱媛 ?띾뱷?섎뒗 寃쏀뿕移?
	int Reward;	// 泥섏튂???뚮젅?댁뼱媛 ?띾뱷?섎뒗 ??
};

