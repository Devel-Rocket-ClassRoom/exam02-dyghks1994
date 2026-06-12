#pragma once


class Map
{
public:
	Map();
	~Map();

	void Initialize();
	void Release();

	void PrintMap();

private:
	std::array<std::array<int, 10>, 10> Area;
};

