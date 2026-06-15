#pragma once
#include "Monster.h"

class Slime : public Monster
{
public:
	Slime();
	virtual ~Slime();

	virtual void Initialize() override;
	virtual void Release() override;
	virtual void Attack(Actor& InTarget) override;
	virtual void Skill(Actor& InTarget) override;
	virtual int ApplyDamage(Actor& InActor) override;

protected:

private:
	const int SlimeHealthMax = 20;

};