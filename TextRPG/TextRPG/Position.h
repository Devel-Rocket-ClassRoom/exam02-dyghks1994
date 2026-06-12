#pragma once

struct Position
{
public:
	Position() {}
	Position(const int InX, const int InY) 
	{
		this->X = InX;
		this->Y = InY;
	}
	~Position() {}

	Position operator+(const Position& InPosition) const
	{
		Position Result;
		Result.X = this->X + InPosition.X;
		Result.Y = this->Y + InPosition.Y;

		return Result;
	}

	Position operator-(const Position& InPosition) const
	{
		Position Result;
		Result.X = this->X - InPosition.X;
		Result.Y = this->Y - InPosition.Y;

		return Result;
	}

	int X = 0;
	int Y = 0;
};