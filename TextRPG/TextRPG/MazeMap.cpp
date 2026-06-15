#include "pch.h"
#include "Player.h"
#include "MazeMap.h"

MazeMap::MazeMap()
{
    Initialize();
}

MazeMap::~MazeMap()
{
    Release();
}

void MazeMap::Initialize()
{
    /// 맵 초기상태 설정
    int temp[MapHeight][MapWidth] =
    {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    };

    // 멤버변수에 적용
    std::copy(&temp[0][0], &temp[0][0] + MapWidth * MapHeight, &Map[0][0]);
}

void MazeMap::Release()
{
}

void MazeMap::PrintMap(Actor& InPlayer)
{
    // 이중 for를 통해서 미로 전체를 순회하기
    for (unsigned int y = 0; y < MapHeight; y++)
    {
        for (unsigned int x = 0; x < MapWidth; x++)
        {
            // 현재 위치에 맞는 모양 찍어주기
            if (InPlayer.GetPosition().X == x && InPlayer.GetPosition().Y == y)
            {
                printf(ShapePlayer);    //printf("P ");와 같음                
            }
            else if (Map[y][x] == MazeWall)
            {
                printf(ShapeWall);
            }
            else if (Map[y][x] == MazePath)
            {
                printf(ShapePath);
            }
            else if (Map[y][x] == MazeStart)
            {
                printf(ShapeStart);
            }
            else if (Map[y][x] == MazeEnd)
            {
                printf(ShapeEnd);
            }
            else if (Map[y][x] == Maze_Mon_Sime)
            {
                printf(ShapeMonster);
            }
            else if (Map[y][x] == Maze_Mon_Orc)
            {
                printf(ShapeMonster);
            }
            else if (Map[y][x] == Maze_Mon_Skeleton)
            {
                printf(ShapeMonster);
            }

        }
        printf("\n");   // 줄바꿈 추가
    }
}

MazeTile MazeMap::GetMazeData(int x, int y)
{
    return static_cast<MazeTile>(Map[y][x]);
}

void MazeMap::SetMazeData(int x, int y, MazeTile Data)
{
    Map[y][x] = Data;
}

int MazeMap::GetAvailableMoves(Actor& InPlayer)
{
    int Flags = DirNone;

    // w(↑) s(↓) a(←) d(→)
    if (!IsWall(InPlayer.GetPosition().X, InPlayer.GetPosition().Y - 1))
    {
        //printf("w(↑) ");
        Flags |= DirUp;
    }
    if (!IsWall(InPlayer.GetPosition().X, InPlayer.GetPosition().Y + 1))
    {
        //printf("s(↓) ");
        Flags |= DirDown;
    }
    if (!IsWall(InPlayer.GetPosition().X - 1, InPlayer.GetPosition().Y))
    {
        //printf("a(←) ");
        Flags |= DirLeft;
    }
    if (!IsWall(InPlayer.GetPosition().X + 1, InPlayer.GetPosition().Y))
    {
        //printf("d(→) ");
        Flags |= DirRight;
    }
    //printf("\n");

    return Flags;
}

bool MazeMap::IsWall(const int x, const int y)
{
    return (
        x < 0 || x >= MapWidth
        || y < 0 || y >= MapHeight
        || Map[y][x] == MazeWall);
}
