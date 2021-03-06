#pragma once
#include "Global.h"




////////////////////////////////////////////////////////////////////
void Enemy_W(char mas[N][N], Enemy* enemy, int ec);
void Enemy_A(char mas[N][N], Enemy* enemy, int ec);
void Enemy_D(char mas[N][N], Enemy* enemy, int ec);
void Enemy_S(char mas[N][N], Enemy* enemy, int ec);
int getRandom(int a, int b);
void AllEnemyMove(char mas[N][N], Enemy* enemy, int ec, int a, int b, int PLC, int PLR);
int enemycount1(char mas[N][N], int rows, int cols, Enemy* enemy);

void battle(char mas[N][N],int &i, Player* player, Enemy* enemy, int& ec);
int defence(int i, Player* player, Enemy* enemy);
int attack(char mas[N][N], int &i, Player* player, Enemy* enemy, int& ec);
void battleSearch(char mas[N][N], int &ec, Player* player, Enemy* enemy, int PLR, int PLC);
void enemydead(char mas[N][N], Enemy* enemy, int &i, int & ec);

///////////////////////////////////////////////////////////////////