#pragma once
enum class GameMenu
{
	NONE = 0,		// 기본값
	NEW_GAME = 1,	// 게임시작
	EXIT = 2,		// 게임종료
};

enum class BattleMenu
{
	NONE = 0,
	NORMAL_ATTACK = 1,	// 기본 공격
	SKILL_ATTACK = 2,	// 특수 공격
	BATTLE_MENU_COUNT = 3,
		
};