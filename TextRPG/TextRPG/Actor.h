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

protected:
	std::string Name;
	Position Pos;

};

