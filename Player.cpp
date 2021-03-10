#include <iostream>
#include "Player.h"


///Player Movement
int KeyboardInput_W(char mas[N][N], int rows, int cols, int& PLR, int& PLC, int& levelpasscount)
{
	if (mas[PLR - 1][PLC] != 'H')
	{
		if (mas[PLR - 1][PLC] == 'E') { system("cls"); NextLevelPass(mas, rows, cols, PLR, PLC, levelpasscount); }
		else
		{
			mas[PLR - 1][PLC] = '@';
			mas[PLR][PLC] = ':';
			PLR -= 1;
		}
	}
	else return 1;
}

int KeyboardInput_A(char mas[N][N], int rows, int cols, int& PLR, int& PLC, int& levelpasscount)
{
	if (mas[PLR][PLC - 1] != 'H')
	{
		if (mas[PLR][PLC - 1] == 'E') { system("cls"); NextLevelPass(mas, rows, cols, PLR, PLC, levelpasscount); }
		else
		{
			mas[PLR][PLC - 1] = '@';
			mas[PLR][PLC] = ':';
			PLC -= 1;
		}
	}
	else return 1;
}   

int KeyboardInput_D(char mas[N][N], int rows, int cols, int& PLR, int& PLC, int& levelpasscount)
{
	if (mas[PLR][PLC + 1] != 'H')
	{
		if (mas[PLR][PLC + 1] == 'E') { NextLevelPass(mas, rows, cols, PLR, PLC, levelpasscount); }
		else
		{
			mas[PLR][PLC + 1] = '@';
			mas[PLR][PLC] = ':';
			PLC += 1;
		}
	}
	else return 1;
}

int KeyboardInput_S(char mas[N][N], int rows, int cols, int& PLR, int& PLC, int& levelpasscount)
{
	if (mas[PLR + 1][PLC] != 'H')
	{
		if (mas[PLR + 1][PLC] == 'E') { system("cls"); NextLevelPass(mas, rows, cols, PLR, PLC, levelpasscount); }
		else
		{
			mas[PLR + 1][PLC] = '@';
			mas[PLR][PLC] = ':';
			PLR += 1;
		}
	}
	else return 1;
}

