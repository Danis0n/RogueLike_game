#include <iostream>
#include "Player.h"


///Player Movement
int KeyboardInput_W(char mas[N][N], int rows, int cols, int& PLR, int& PLC)
{
	if (mas[PLR - 1][PLC] != 'H')
	{
		mas[PLR - 1][PLC] = '@';
		mas[PLR][PLC] = ':';
		PLR -= 1;
	}
	else return 1;
}

int KeyboardInput_A(char mas[N][N], int rows, int cols, int& PLR, int& PLC)
{
	if (mas[PLR][PLC - 1] != 'H')
	{
		mas[PLR][PLC - 1] = '@';
		mas[PLR][PLC] = ':';
		PLC -= 1;
	}
	else return 1;
}   

int KeyboardInput_D(char mas[N][N], int rows, int cols, int& PLR, int& PLC)
{
	if (mas[PLR][PLC + 1] != 'H')
	{
		mas[PLR][PLC + 1] = '@';
		mas[PLR][PLC] = ':';
		PLC += 1;
	}
	else return 1;
}

int KeyboardInput_S(char mas[N][N], int rows, int cols, int& PLR, int& PLC)
{
	if (mas[PLR + 1][PLC] != 'H')
	{
		mas[PLR + 1][PLC] = '@';
		mas[PLR][PLC] = ':';
		PLR += 1;
	}
	else return 1;
}
