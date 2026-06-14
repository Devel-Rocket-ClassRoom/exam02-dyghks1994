#pragma once
#include "Actor.h"

class Monster : public Actor
{
public:
	Monster();
	virtual ~Monster();

	virtual void Initialize() override;
	virtual int ApplyDamage(Actor& InActor) override;
	virtual int TakeDamage(int Damage) override;

protected:
	int Exp;	// 泥섏튂???뚮젅?댁뼱媛 ?띾뱷?섎뒗 寃쏀뿕移?
	int Reward;	// 泥섏튂???뚮젅?댁뼱媛 ?띾뱷?섎뒗 ??
};

