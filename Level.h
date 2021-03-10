#pragma once
#include "Global.h"
#define N 100

struct Enemy enemy[10];

struct Player player[2];

void AllEnemyMove(char mas[N][N], Enemy* enemy, int ec, int a, int b, int PLC, int PLR);
int enemycount1(char mas[N][N], int rows, int cols, Enemy* enemy);

void PrintMap(char mas[N][N], int rows, int cols, int PLR, int PLC);
void SetMapForNewGame(char mas[N][N], int rows, int cols);
void ColorChange(int backcolor, int textcolor);
int KeyboardInput(char mas[N][N], int rows, int cols, int& PLR, int& PLC, int& levelpasscount);

int MainMenu(char mas[N][N], int rows, int cols, int& PLR, int& PLC);
void Tutorial();
void SaveGame(char mas[N][N], int rows, int cols, int PLR, int PLC);
void SetMapForSavedGame(char mas[N][N], int rows, int cols, int& PLR, int& PLC);
void NextLevelPass(char mas[N][N], int rows, int cols, int& PLR, int& PLC, int& levelpasscount);
int StartGameChoice(char mas[N][N], int rows, int cols, int& PLR, int& PLC);
void GameItteration(char mas[N][N], int rows, int cols, int& PLR, int& PLC, int a, int b, Enemy* enemy, int& ec, int& levelpasscount);

void battleSearch(char mas[N][N],int &ec, Player* player, Enemy* enemy, int PLR, int PLC);