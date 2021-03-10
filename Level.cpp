#pragma once
#include<iostream>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#include<math.h>
#include <string.h>
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
	case '$': ColorChange(7, 7); break;
	case '&': ColorChange(7, 4); break;
	case 'E': ColorChange(6, 6); break;
	default: ColorChange(0, 15);
	}

}

void PrintMap(char mas[N][N], int rows, int cols, int PLR, int PLC)
{
	char sign;
	for (int i = 0; i < rows; i++)
	{
		printf("\t\t\t");
		for (int j = 0; j < cols; j++)
		{
			if (mas[i][j] == 'H' || mas[i][j] == 'S' || mas[i][j] == ':' || mas[i][j] == 'E') 
			{
				sign = mas[i][j];
				ColorCheck(sign);
				printf("%c", mas[i][j]);
			}
			else if (abs(i - PLR) <= 2 && abs(j - PLC) <= 2)
			{
				switch (mas[i][j])
				{
				case 'h': mas[i][j] = 'H'; break;
				case 's': mas[i][j] = 'S'; break;
				case ';': mas[i][j] = ':'; break;
				case '*': mas[i][j] = '$'; break;
				case 'e': mas[i][j] = 'E'; break;
				default: break;
				}
				if (mas[i][j] == '$') ColorCheck('&');
				else
				{
					sign = mas[i][j];
					ColorCheck(sign);
				}
				printf("%c", mas[i][j]);
			}
			else if (mas[i][j] == '$')
			{
				ColorCheck('$');
				printf("%c", mas[i][j]);
			}
			else
			{
				printf(" ");
				ColorChange(0, 15);
			}
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

void NextLevelPass(char mas[N][N], int rows, int cols, int& PLR, int& PLC, int& levelpasscount)
{
	levelpasscount += 1;
	char levelname[15] = "level1.txt";
	PLR = 1; PLC = 1;

	printf("Уровень пройден!\n");
	system("pause");
	system("cls");
	switch (levelpasscount)
	{
	case 2: levelname[5] = '2'; break;
	case 3: levelname[5] = '3'; break;
	default: printf("Вы прошли игру!!!!!!!!");
	}

	FILE* input;

	fopen_s(&input, levelname, "r");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			fscanf_s(input, "%c ", &mas[i][j], 100);
		}
	}
	fclose(input);
}

void SetMapForSavedGame(char mas[N][N], int rows, int cols, int& PLR, int& PLC)
{
	char keyboardinput;
	int SwitchCheck;
	char savename[15] = "save1.txt";

	do
	{
		printf("Выберите слот сохраниения:\n\
1 Слот.\n\
2 Слот.\n\
3 Слот.\n\
Нажмите 1, 2 или 3.");
		SwitchCheck = 0;
		keyboardinput = _getch();
		switch (keyboardinput)
		{
		case '1': break;
		case '2': savename[4] = '2'; break;
		case '3': savename[4] = '3'; break;
		default: SwitchCheck = 1;
		}
		system("cls");
	} while (SwitchCheck == 1);
	
	FILE* input;

	fopen_s(&input, savename, "r");
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

int KeyboardInput(char mas[N][N], int rows, int cols, int& PLR, int& PLC, int& levelpasscount)
{
	char input;
	int MoveCheck;
	do
	{
		int exit = 0;
		MoveCheck = 0;
		// PLR = PlayerLocationRow
		// PLC = PlayerLocationCol
		input = _getch();
		switch (input)
		{
		case 'ц':
		case 'w': MoveCheck = KeyboardInput_W(mas, rows, cols, PLR, PLC, levelpasscount); break;
		case 'ы':
		case 's': MoveCheck = KeyboardInput_S(mas, rows, cols, PLR, PLC, levelpasscount); break;
		case 'в':
		case 'd': MoveCheck = KeyboardInput_D(mas, rows, cols, PLR, PLC, levelpasscount); break;
		case 'ф':
		case 'a': MoveCheck = KeyboardInput_A(mas, rows, cols, PLR, PLC, levelpasscount); break;
		case 'й':
		case 'q': exit = MainMenu(mas, rows, cols, PLR, PLC); return exit; break;
		default: MoveCheck = 1;
		}
	} while (MoveCheck == 1);
}

void SaveGame(char mas[N][N], int rows, int cols, int PLR, int PLC)
{
	char keyboardinput;
	int SwitchCheck;
	char savename[15] = "save1.txt";

	do
	{
		printf("Выберите слот сохраниения:\n\
1 Слот.\n\
2 Слот.\n\
3 Слот.\n\
Нажмите 1, 2 или 3.");
		SwitchCheck = 0;
		keyboardinput = _getch();
		switch (keyboardinput)
		{
		case '1': break;
		case '2': savename[4] = '2'; break;
		case '3': savename[4] = '3'; break;
		default: SwitchCheck = 1;
		}
		system("cls");
	} while (SwitchCheck == 1);

	FILE* save;

	fopen_s(&save, savename, "w");
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

int StartGameChoice(char mas[N][N], int rows, int cols, int& PLR, int& PLC)
{
	char input;
	int inputcheck;
	printf("Добро пожаловать!\n\
    1.Новая игра.\n\
    2.Загрузить игру.\n\
    3.Справка.\n\
    4.Выход.\n");
	do
	{
		inputcheck = 0;
		input = _getch();
		switch (input)
		{
		case '1': system("cls"); SetMapForNewGame(mas, rows, cols); break;
		case '2': system("cls"); SetMapForSavedGame(mas, rows, cols, PLR, PLC); break;
		case '3': system("cls"); Tutorial(); StartGameChoice(mas, rows, cols, PLR, PLC); break;
		case '4': system("cls"); return(1);  break;
		default: inputcheck = 1;
		}
	} while (inputcheck == 1);
}

int MainMenu(char mas[N][N], int rows, int cols, int& PLR, int& PLC)
{
	system("cls");
	char input;
	printf("ПАУЗА\n\
    1.Новая игра\n\
    2.Загрузить игру\n\
    3.Сохранить игру\n\
    4.Справка\n\
    5.Выход\n\
    Нажмите q, чтобы продолжить.\n");
	int inputcheck;
	do
	{
		inputcheck = 0;
		input = _getch();
		switch (input)
		{
		case '1': system("cls"); PLR = 1; PLC = 1; SetMapForNewGame(mas, rows, cols); break;
		case '2': system("cls"); SetMapForSavedGame(mas, rows, cols, PLR, PLC); break;
		case '3': system("cls"); SaveGame(mas, rows, cols, PLR, PLC); break;
		case '4': system("cls"); Tutorial(); MainMenu(mas, rows, cols, PLR, PLC); break;
		case '5': system("cls"); return(1); break;
		case 'й':
		case 'q': system("cls"); PrintMap(mas, rows, cols, PLR, PLC); return(0); break;
		default: inputcheck = 1; 
		}
	} while (inputcheck == 1);
}

void Tutorial()
{
	char input;
	printf("СПРАВКА\n");
	printf("w, a, d, s - ходьба.\n");
	printf("q - открыть/закрыть меню.\n");
	printf("нажмите q, чтобы закрыть справку.\n");
	do
	{
		input = _getch();
	} while (input != 'q' && input != 'й');
	system("cls");
}

void GameItteration(char mas[N][N], int rows, int cols, int& PLR, int& PLC, int a, int b, Enemy* enemy, int& ec, int& levelpasscount)
{
	int exit = 0;
	do
	{
		ec = enemycount1(mas, rows, cols, enemy);
		exit = KeyboardInput(mas, rows, cols, PLR, PLC, levelpasscount);
		if (exit == 1) break;
		AllEnemyMove(mas, enemy, ec, a, b, PLC, PLR);
		battleSearch(mas,ec,player, enemy, PLR, PLC);
		system("cls");
		PrintMap(mas, rows, cols, PLR, PLC);
	} while (true);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	srand(time(0));
	system("chcp 1251");
	system("cls");
	char mas[N][N];
	int rows = 30, cols = 80, ec = 0, a = 0, b = 0, exit = 0, levelpasscount = 1;
	//PLR = PlayerLocationRows
	//PLC = PlayerLocationCols
	int PLR = 1, PLC = 1;
	do
	{
		exit = StartGameChoice(mas, rows, cols, PLR, PLC);
		if (exit == 1) break;
		PrintMap(mas, rows, cols, PLR, PLC);
		GameItteration(mas, rows, cols, PLR, PLC, a, b, enemy, ec, levelpasscount);
	} while (exit == 1);

	//system("pause");
	return 0;
}