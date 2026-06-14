#pragma once
#include "Actor.h"

class Player : public Actor
{
public:
	Player();
	virtual ~Player();


	virtual void Initialize() override;
	virtual int ApplyDamage(Actor& InActor) override;
	virtual int TakeDamage(int Damage) override;


private:


};

