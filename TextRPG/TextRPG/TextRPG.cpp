#include "pch.h"
#include "Monster.h"
#include "Slime.h"
#include "TextRPG.h"

TextRPG::TextRPG()
	: Menu(GameMenu::NONE)
	, GameMap(nullptr)
{
	if (GameMap == nullptr)
	{
		GameMap = new MazeMap();
	}
}

TextRPG::~TextRPG()
{
	if (GameMap)
	{
		delete GameMap;
		GameMap = nullptr;
	}
}

void TextRPG::TextRPG_Run()
{
	// 게임 종료 선택 전까지 프로그램 실행
	while (Menu != GameMenu::EXIT)
	{
		// 타이틀 및 메뉴 출력
		PrintTitle();

		// 메뉴 선택
		Menu = SelectMenu();
		
		switch (Menu)
		{
			case GameMenu::NEW_GAME:
			{
				/// 게임 로직진행
				//printf("게임 시작");
				MainGameLogic();

				break;
			}

			case GameMenu::EXIT:
			{
				/// 게임 종료
				system("cls");
				printf("게임 종료");
				break;
			}

			default:
			{
				system("cls");
				break;
			}
		}
	}
}

void TextRPG::PrintTitle()
{
	printf("[타이틀]\n");
	printf("1. 시작하기\n");
	printf("2. 종료\n");
}

GameMenu TextRPG::SelectMenu()
{
	int Input = 0;

	do 
	{
		std::cin >> Input;
		std::cin.ignore(10000, '\n');
	} while (Input < static_cast<int>(GameMenu::NEW_GAME) && Input > static_cast<int>(GameMenu::EXIT));

	Menu = static_cast<GameMenu>(Input);

	return Menu;
}

void TextRPG::MainGameLogic()
{
	// 플레이어 초기 세팅
	Player MyPlayer;
	Position StartPos = { 1, 1 };	// 시작 위치
	MyPlayer.SetPosition(StartPos);

	// 메인 루프
	while (true)
	{
		/// 맵 출력
		system("cls");
		GameMap->PrintMap(MyPlayer);


		/// 키 입력
		printf("이동할 방향을 선택하세요 (w:위, s:아래, a:왼쪽, d:오른쪽):\n");

		MoveDirection Direction = GetMoveInput(MyPlayer);
		Position Pos = MyPlayer.GetPosition();  // 이동할 좌표 담을 임시 변수

		switch (Direction)
		{
			case DirUp:
				Pos.Y--;
				break;
			case DirDown:
				Pos.Y++;
				break;
			case DirLeft:
				Pos.X--;
				break;
			case DirRight:
				Pos.X++;
				break;
			case DirNone:
			default:
				//printf("ERROR!!! 비정상적인 방향입니다!!!!\n");
				break;
		}

		// 이동할 좌표를 실제 플레이어 좌표로 세팅
		MyPlayer.SetPosition(Pos);


		/// 이벤트 처리
		// 현재 위치에 있는 값 확인
		Position CurPos = MyPlayer.GetPosition();
		int Target = GameMap->GetMazeData(CurPos.X, CurPos.Y);
		
		/// 몬스터 전투
		Monster* Enemy = nullptr;
		switch (Target)
		{
			case MazeTile::Maze_Mon_Sime:
			{
				Enemy = new Slime();
				Battle(MyPlayer, Enemy);
				break;
			}

			case MazeTile::Maze_Mon_Orc:
			{
				break;
			}
			
			case MazeTile::Maze_Mon_Skeleton:
			{
				break;
			}
			
			
			// 상점 진입
		}

		if (Enemy)
		{
			delete Enemy;
			Enemy = nullptr;
		}

	}

}

MoveDirection TextRPG::GetMoveInput(Player& InPlayer)
{
	int AvailableFlags = GameMap->GetAvailableMoves(InPlayer);

	MoveDirection Result = DirNone;
	char KeyInput = 0;

	while (true)
	{
		//printf("방향 입력 : ");
		KeyInput = _getch();
		

		if ((KeyInput == 'w' || KeyInput == 'W') && (AvailableFlags & DirUp))
		{
			Result = DirUp;
			break;
		}
		if ((KeyInput == 's' || KeyInput == 'S') && (AvailableFlags & DirDown))
		{
			Result = DirDown;
			break;
		}
		if ((KeyInput == 'a' || KeyInput == 'A') && (AvailableFlags & DirLeft))
		{
			Result = DirLeft;
			break;
		}
		if ((KeyInput == 'd' || KeyInput == 'D') && (AvailableFlags & DirRight))
		{
			Result = DirRight;
			break;
		}
		
		//printf("잘못된 입력입니다. 이동 가능한 방향 중에서 선택하세요.\n");
	}

	return Result;
}

bool TextRPG::Battle(Player& InPlayer, Monster* InMonster) const
{
	bool Result = false;
	int TurnCount = 1;

	// 전투 로직
	printf("[%s]이 나타났다!! 전투 시작!\n", InMonster->GetName().c_str());

	while (InPlayer.IsAlive() && InMonster->IsAlive())
	{
		// 상태 출력
		InPlayer.PrintInfo();
		InMonster->PrintInfo();

		// 턴 진행
		printf("------------턴 %d------------\n", TurnCount);

		// 유저 행동 입력
		BattleMenu Menu = SelectBattleMenu();
		
		switch (Menu)
		{
			case BattleMenu::NORMAL_ATTACK:		// 기본 공격
			{
				InPlayer.NormalAttack(*InMonster);
				//printf("일반공격\n");
				break;
			}

			case BattleMenu::SKILL_ATTACK:		// 스킬 사용
			{
				break;
			}
		}

		// 플레이어 공격에 몬스터가 살아있으면
		// 몬스터 공격 진행
		if (InMonster->IsAlive())
		{
			InMonster->Attack(InPlayer);
		}

		TurnCount++;
	}
	
	// 플레이어 승리시 true 리턴
	if (InPlayer.IsAlive())
	{
		Result = true;

		// 경험치, 보상 획득
		InPlayer.EarnRewards(InMonster);

		// 현재 플레이어 위치 빈 구역으로 표시
		GameMap->SetMazeData(InPlayer.GetPosition().X, InPlayer.GetPosition().Y, MazeTile::MazePath);

	}

	return Result;
}

BattleMenu TextRPG::SelectBattleMenu() const
{
	BattleMenu Menu = BattleMenu::NONE;

	int MenuInput = 0;
	do
	{
		printf("1. 기본공격 %t 2. 특수공격 %t 3. 포션사용-> ");

		//MenuInput = _getch();
		std::cin >> MenuInput;
		std::cin.clear();
		std::cin.ignore(10000, '\n');

		Menu = static_cast<BattleMenu>(MenuInput);
	} while (Menu <= BattleMenu::NONE
		&& Menu > BattleMenu::BATTLE_MENU_COUNT);

	return Menu;
}

