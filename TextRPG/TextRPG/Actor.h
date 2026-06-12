#pragma once
#include "Position.h"

class Actor
{
public:
	Actor();
	virtual ~Actor();

protected:
	std::string Name;
	Position Pos;

};

