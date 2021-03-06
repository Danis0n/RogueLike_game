#include <iostream>
#include "Player.h"



void KeyboardInput_W(char mas[N][N], int rows, int cols, int& PLR, int& PLC)
{
	if (mas[PLR - 1][PLC] != 'H')
	{
		mas[PLR - 1][PLC] = '@';
		mas[PLR][PLC] = ':';
		PLR -= 1;
	}
}

void KeyboardInput_A(char mas[N][N], int rows, int cols, int& PLR, int& PLC)
{
	if (mas[PLR][PLC - 1] != 'H')
	{
		mas[PLR][PLC - 1] = '@';
		mas[PLR][PLC] = ':';
		PLC -= 1;
	}
}   ///Player Movement

void KeyboardInput_D(char mas[N][N], int rows, int cols, int& PLR, int& PLC)
{
	if (mas[PLR][PLC + 1] != 'H')
	{
		mas[PLR][PLC + 1] = '@';
		mas[PLR][PLC] = ':';
		PLC += 1;
	}
}

void KeyboardInput_S(char mas[N][N], int rows, int cols, int& PLR, int& PLC)
{
	if (mas[PLR + 1][PLC] != 'H')
	{
		mas[PLR + 1][PLC] = '@';
		mas[PLR][PLC] = ':';
		PLR += 1;
	}
}
