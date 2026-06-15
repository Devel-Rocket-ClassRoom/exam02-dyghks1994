#pragma once

enum MazeTile
{
	MazePath			= 0,
	MazeWall			= 1,
	MazeStart			= 2,
	MazeEnd				= 3,
	Maze_Mon_Sime		= 4,
	Maze_Mon_Orc		= 5,
	Maze_Mon_Skeleton	= 6
};

// MazeTile 표시용
const char* const ShapePlayer = "P ";
const char* const ShapeWall = "# ";
const char* const ShapePath = ". ";
const char* const ShapeStart = "S ";
const char* const ShapeEnd = "E ";
const char* const ShapeMonster = "★ ";

enum MoveDirection
{
	DirNone		= 0,
	DirUp		= 1 << 0,	// 1
	DirDown		= 1 << 1,	// 2
	DirLeft		= 1 << 2,	// 4
	DirRight	= 1 << 3	// 8
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
	MazeTile GetMazeData(int x, int y);
	void SetMazeData(int x, int y, MazeTile Data);
	int GetAvailableMoves(Actor& InPlayer);

	bool IsWall(const int x, const int y);

private:
	static const int MapWidth = 20;
	static const int MapHeight = 20;
	int Map[MapHeight][MapWidth];

	//std::array<std::array<int, 10>, 10> Area;
};

