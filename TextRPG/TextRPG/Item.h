#pragma once

enum class ItemType
{
	Weapon	= 1,
	Armor	= 2,
	Amulet	= 3,
	Potion	= 4
};

struct Item
{
public:
	std::string Name;
	ItemType Type;
	int Price;
};