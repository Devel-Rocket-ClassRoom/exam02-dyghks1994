#pragma once
#include "Position.h"

class Actor
{
public:
	Actor();
	virtual ~Actor();

    inline Position GetPosition() { return Pos; }
    inline void SetPosition(const Position InPos)
    {
        Pos = InPos;
    }
    inline void SetPosition(const int InX, const int InY)
    {
        Pos.X = InX;
        Pos.Y = InY;
    }

    inline std::string GetName() { return Name; }

    inline int GetHealth() { return Health; }
    inline void SetHealth(const int InHealth) { Health = InHealth; }

    inline int GetHealthMax() { return HealthMax; }
    inline void SetHealthMax(const int InHealthMax) { HealthMax = InHealthMax; }

    inline int GetAttackPowerMin() { return AttackPowerMin; }
    inline void SetAttackPowerMin(const int InAttackPowerMin) { AttackPowerMin = InAttackPowerMin; }

    inline int GetAttackPowerMax() { return AttackPowerMax; }
    inline void SetAttackPowerMax(const int InAttackPowerMax) { AttackPowerMax = InAttackPowerMax; }

    inline bool IsAlive() { return Health > 0; }

    virtual void Initialize();
    virtual void Release();
    virtual void PrintInfo() const;
    virtual int ApplyDamage(Actor& InActor);
    virtual int TakeDamage(int Damage);

protected:
    std::string Name;
    Position Pos;
    int Health;
    int HealthMax;
    int AttackPowerMin;
    int AttackPowerMax;
    float CriticalRate;
    float CriticalStrikeMultiplier;

};

