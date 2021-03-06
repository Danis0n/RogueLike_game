#pragma once
#include<iostream>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#include<math.h>
#include "Level.h"
#include "Player.h"

///////////////////////////////////////////////////////////////////////////////////////

void ColorChange(int backcolor, int textcolor)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((backcolor << 4) | textcolor));
}

void ColorCheck(char sign)
{
	int backcolor = 0, textcolor = 15;
	switch (sign)
	{
	case 'H': ColorChange(8, 8); break;
	case 'S': ColorChange(8, 8); break;
	case ':': ColorChange(7, 7); break;
	case '@': ColorChange(7, 0); break;
	case '$': ColorChange(7, 4); break;
	default: ColorChange(0, 15);
	}

}

void PrintMap(char mas[N][N], int rows, int cols)
{
	char sign;
	for (int i = 0; i < rows; i++)
	{
		printf("\t\t\t");
		for (int j = 0; j < cols; j++)
		{
			sign = mas[i][j];
			ColorCheck(sign);
			printf("%c", mas[i][j]);
		}
		printf("\n");
	}
	ColorChange(0, 15);
}

void SetMapForNewGame(char mas[N][N], int rows, int cols)
{
	FILE* input;

	fopen_s(&input, "level1.txt", "r");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			fscanf_s(input, "%c ", &mas[i][j], 200);
		}
	}
	fclose(input);
}

void SetMapForSavedGame(char mas[N][N], int rows, int cols, int& PLR, int& PLC)
{
	FILE* input;

	fopen_s(&input, "save1.txt", "r");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			fscanf_s(input, "%c ", &mas[i][j], 100);
		}
	}
	fscanf_s(input, "%i %i", &PLR, &PLC);
	fclose(input);
}

int KeyboardInput(char mas[N][N], int rows, int cols, int& PLR, int& PLC)
{
	char input;
	int defaultcheck;
	do
	{
		int exit = 0;
		defaultcheck = 0;
		// PLR = PlayerLocationRow
		// PLC = PlayerLocationCol
		input = _getch();
		switch (input)
		{
		case 'w': KeyboardInput_W(mas, rows, cols, PLR, PLC); break;
		case 's': KeyboardInput_S(mas, rows, cols, PLR, PLC); break;
		case 'd': KeyboardInput_D(mas, rows, cols, PLR, PLC); break;
		case 'a': KeyboardInput_A(mas, rows, cols, PLR, PLC); break;
		case 'q': exit += 1; return exit; break;
		default: defaultcheck += 1;
		}
	} while (defaultcheck == 1);
}

void SaveGame(char mas[N][N], int rows, int cols, int PLR, int PLC)
{

	FILE* save;

	fopen_s(&save, "save1.txt", "w");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			fprintf_s(save, "%c", mas[i][j], 100);
		}
		fprintf_s(save, "\n");
	}
	fprintf_s(save, "%i %i\n", PLR, PLC);
	fclose(save);
}

void StartGameChoice(char mas[N][N], int rows, int cols, int& PLR, int& PLC)
{
	char input;
	printf("\n\
    1.Новая игра\n\
    2.Продолжить сохранение\n");
	do
	{
		input = _getch();
		switch (input)
		{
		case '1': system("cls"); SetMapForNewGame(mas, rows, cols); break;
		case '2': system("cls"); SetMapForSavedGame(mas, rows, cols, PLR, PLC); break;
		}
	} while (input != '1' && input != '2');
}

void GameItteration(char mas[N][N], int rows, int cols, int& PLR, int& PLC, int a, int b, Enemy* enemy, int& ec)
{
	int exit = 0;

	do
	{
		ec = enemycount1(mas, rows, cols, enemy);
		exit = KeyboardInput(mas, rows, cols, PLR, PLC);
		if (exit == 1) break;
		AllEnemyMove(mas, enemy, ec, a, b, PLC, PLR);
		battleSearch(mas,ec,player, enemy, PLR, PLC);
		system("cls");
		PrintMap(mas, rows, cols);
	} while (true);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	srand(time(0));
	system("chcp 1251");
	system("cls");
	char mas[N][N];
	int rows = 25, cols = 80, ec = 0, a = 0, b = 0;
	//PLR = PlayerLocationRows
	//PLC = PlayerLocationCols
	int PLR = 1, PLC = 1;
	
	StartGameChoice(mas, rows, cols, PLR, PLC);

	PrintMap(mas, rows, cols);

	GameItteration(mas, rows, cols, PLR, PLC,a,b,enemy,ec);

	SaveGame(mas, rows, cols, PLR, PLC);

	system("pause");
	return 0;
}