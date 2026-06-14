#pragma once

namespace Utils
{
	/// <summary>
	/// 콘솔창에서 커서 위치 옮기기
	/// </summary>
	/// <param name="x">x좌표</param>
	/// <param name="y">y좌표</param>
	inline void GoToXY(const int x, const int y)
	{
		COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}


	bool IsFloatEqual(float Num1, float Num2);

	/// <summary>
	/// 0.0f ~ 1.0f 사이를 리턴하는 함수
	/// </summary>
	/// <returns>0.0f ~ 1.0f 사이의 랜덤값</returns>
	float GetRandom();

	/// <summary>
	/// Min ~ Max 사이의 랜덤한 값을 리턴하는 함수
	/// </summary>
	/// <param name="Min">랜덤의 최소값(포함)</param> 
	/// <param name="Max">랜덤의 최대값(포함)</param>
	/// <returns>Min ~ Max 사이의 랜덤한 값</returns>
	int GetRandomRange(int Min, int Max);
}

