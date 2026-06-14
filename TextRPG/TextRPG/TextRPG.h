#pragma once

#include "Player.h"
#include "MazeMap.h"

enum class GameMenu
{
	NONE = 0,		// 기본값
	NEW_GAME = 1,	// 게임시작
	EXIT	= 2,	// 게임종료
};

enum MoveDirection;
class TextRPG
{
public:
	TextRPG();
	~TextRPG();

	void TextRPG_Run();
	void PrintTitle();

	GameMenu SelectMenu();	// 메뉴선택

	void MainGameLogic();	// 메인 로직

	MoveDirection GetMoveInput(Player& InPlayer);

private:
	GameMenu Menu;

	MazeMap* GameMap;








};

