#pragma once
#include "Monster.h"

class Skeleton : public Monster
{
public:
	Skeleton();
	virtual ~Skeleton();

	virtual void Initialize() override;
	virtual void Release() override;
	virtual void Attack(Actor& InTarget) override;
	virtual void Skill(Actor& InTarget) override;
	virtual int ApplyDamage(Actor& InActor) override;

protected:

private:
	const int SkeletonHealthMax = 100;

};

