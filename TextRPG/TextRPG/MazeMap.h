#pragma once

enum MazeTile
{
	MazePath = 0,
	MazeWall = 1,
	MazeStart = 2,
	MazeEnd = 3
};

// MazeTile 표시용
const char* const ShapePlayer = "P ";
const char* const ShapeWall = "# ";
const char* const ShapePath = ". ";
const char* const ShapeStart = "S ";
const char* const ShapeEnd = "E ";

enum MoveDirection
{
	DirNone = 0,
	DirUp = 1 << 0,		// 1
	DirDown = 1 << 1,	// 2
	DirLeft = 1 << 2,	// 4
	DirRight = 1 << 3	// 8
};

class Actor;
class MazeMap
{
public:
	MazeMap();
	~MazeMap();

	void Initialize();
	void Release();

	void PrintMap(Actor& InPlayer);
	int GetAvailableMoves(Actor& InPlayer);

	bool IsWall(const int x, const int y);

private:
	static const int MapWidth = 10;
	static const int MapHeight = 10;
	int Map[MapHeight][MapWidth];

	//std::array<std::array<int, 10>, 10> Area;
};

