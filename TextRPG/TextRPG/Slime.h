#pragma once
#include "Monster.h"

class Slime : public Monster
{
public:
	Slime();
	Slime(Position InPos, std::string InName = "슬라임", int InHealth = 20, int InHealthMax = 20, int InAttackPowerMin = 2, int InAttackPowerMax = 5);
	virtual ~Slime();

	virtual void Initialize() override;
	virtual int ApplyDamage(Actor& InActor) override;
	virtual int TakeDamage(int Damage) override;

protected:

private:
	const int SlimeHealthMax = 20;

};