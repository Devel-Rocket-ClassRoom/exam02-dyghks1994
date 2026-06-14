#include "pch.h"

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
		system("cls");

		/// 맵 출력
		GameMap->Initialize();
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
		
		switch (Target)
		{
			// 몬스터 전투
			case MazeTile::Maze_Mon_Sime:
			{

				break;
			}

			//case MazeTile::MazeWall:
			//{
			//	break;
			//}
			//
			//case MazeTile::MazeWall:
			//{
			//	break;
			//}
			
			
			// 상점 진입
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

