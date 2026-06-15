#pragma once

#include "Player.h"
#include "MazeMap.h"
#include "MenuInfo.h"


enum MoveDirection;
class Monster;
class TextRPG
{
public:
	TextRPG();
	~TextRPG();

	void TextRPG_Run();
	void PrintTitle();

	GameMenu SelectMenu();	// 메뉴선택

	void MainGameLogic();	// 메인 로직

	MoveDirection GetMoveInput(Player& InPlayer);	// 입력 처리
	bool Battle(Player& InPlayer, Monster* InMonster) const;
	BattleMenu SelectBattleMenu() const;


private:
	GameMenu Menu;

	MazeMap* GameMap;


};

