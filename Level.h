#pragma once
#include "Global.h"
#define N 100

struct Enemy enemy[10];

struct Player player[2];

struct Boss boss[2];

void AllEnemyMove(char mas[N][N], Enemy* enemy, int ec, int a, int b, int PLC, int PLR);
int enemycount1(char mas[N][N], int rows, int cols, Enemy* enemy);

void PrintMap(char mas[N][N], int rows, int cols, int PLR, int PLC, Player* player, int colorlessmodecheck);
void SetMapForNewGame(char mas[N][N], int rows, int cols);
void ColorChange(int backcolor, int textcolor, int colorlessmodecheck);
int KeyboardInput(char mas[N][N], int rows, int cols, int& PLR, int& PLC, int& levelpasscount, Player* player, int& colorlessmodecheck);

int MainMenu(char mas[N][N], int rows, int cols, int& PLR, int& PLC, Player* player, int& colorlessmodecheck);
void Tutorial();
void SaveGame(char mas[N][N], int rows, int cols, int PLR, int PLC);
void SetMapForSavedGame(char mas[N][N], int rows, int cols, int& PLR, int& PLC);
void NextLevelPass(char mas[N][N], int rows, int cols, int& PLR, int& PLC, int& levelpasscount);
int StartGameChoice(char mas[N][N], int rows, int cols, int& PLR, int& PLC);
void GameItteration(char mas[N][N], int rows, int cols, int& PLR, int& PLC, int a, int b, Enemy* enemy, int& ec, int& levelpasscount, Player* player, Boss* boss, int& colorlessmodecheck);

void battleSearch(char mas[N][N], int& ec, Player* player, Enemy* enemy, int& PLR, int& PLC);
void Bseach(char mas[N][N], Player* player, Boss* boss, int& PLR, int& PLC);
void Bfind(char mas[N][N], int rows, int cols, Boss* boss);

void PlayerStatus(Player* player);