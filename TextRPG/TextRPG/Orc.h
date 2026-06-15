#pragma once
#include "Monster.h"

class Orc : public Monster
{
public:
	Orc();
	virtual ~Orc();

	virtual void Initialize() override;
	virtual void Release() override;
	virtual void Attack(Actor& InTarget) override;
	virtual void Skill(Actor& InTarget) override;
	virtual int ApplyDamage(Actor& InActor) override;

protected:

private:
	const int OrcHealthMax = 50;

};

