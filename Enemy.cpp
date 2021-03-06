#pragma once
#include <iostream>
#include "Enemy.h"
#include "Player.h"



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Enemy_W(char mas[N][N], Enemy* enemy, int i)
{
	if (mas[enemy[i].ex - 1][enemy[i].ey] == ';')
	{
		if (mas[enemy[i].ex][enemy[i].ey] == '*')
		{
			mas[enemy[i].ex - 1][enemy[i].ey] = '*';
			mas[enemy[i].ex][enemy[i].ey] = ';';
			enemy[i].ex -= 1;
		}
		else if (mas[enemy[i].ex][enemy[i].ey] == '$')
		{
			mas[enemy[i].ex - 1][enemy[i].ey] = '*';
			mas[enemy[i].ex][enemy[i].ey] = ':';
			enemy[i].ex -= 1;
		}
	}
	else if (mas[enemy[i].ex - 1][enemy[i].ey] == ':')
	{
		if (mas[enemy[i].ex][enemy[i].ey] == '$')
		{
			mas[enemy[i].ex - 1][enemy[i].ey] = '$';
			mas[enemy[i].ex][enemy[i].ey] = ':';
			enemy[i].ex -= 1;
		}
		else if (mas[enemy[i].ex][enemy[i].ey] == '*')
		{
			mas[enemy[i].ex - 1][enemy[i].ey] = '$';
			mas[enemy[i].ex][enemy[i].ey] = ';';
			enemy[i].ex -= 1;
		}
	}
}

void Enemy_A(char mas[N][N], Enemy* enemy, int i)
{
	if (mas[enemy[i].ex][enemy[i].ey - 1] == ';')
	{
		if (mas[enemy[i].ex][enemy[i].ey] == '*')
		{
			mas[enemy[i].ex][enemy[i].ey - 1] = '*';
			mas[enemy[i].ex][enemy[i].ey] = ';';
			enemy[i].ey -= 1;
		}
		else if (mas[enemy[i].ex][enemy[i].ey] == '$')
		{
			mas[enemy[i].ex][enemy[i].ey - 1] = '*';
			mas[enemy[i].ex][enemy[i].ey] = ':';
			enemy[i].ey -= 1;
		}
	}
	else if (mas[enemy[i].ex][enemy[i].ey - 1] == ':')
	{
		if (mas[enemy[i].ex][enemy[i].ey] == '$')
		{
			mas[enemy[i].ex][enemy[i].ey - 1] = '$';
			mas[enemy[i].ex][enemy[i].ey] = ':';
			enemy[i].ey -= 1;
		}
		else if (mas[enemy[i].ex][enemy[i].ey] == '*')
		{
			mas[enemy[i].ex][enemy[i].ey - 1] = '$';
			mas[enemy[i].ex][enemy[i].ey] = ';';
			enemy[i].ey -= 1;
		}
	}
}

void Enemy_D(char mas[N][N], Enemy* enemy, int i)
{
	if (mas[enemy[i].ex][enemy[i].ey + 1] == ';')
	{
		if (mas[enemy[i].ex][enemy[i].ey] == '*')
		{
			mas[enemy[i].ex][enemy[i].ey + 1] = '*';
			mas[enemy[i].ex][enemy[i].ey] = ';';
			enemy[i].ey += 1;
		}
		else if (mas[enemy[i].ex][enemy[i].ey] == '$')
		{
			mas[enemy[i].ex][enemy[i].ey + 1] = '*';
			mas[enemy[i].ex][enemy[i].ey] = ':';
			enemy[i].ey += 1;
		}
	}
	else if (mas[enemy[i].ex][enemy[i].ey + 1] == ':')
	{
		if (mas[enemy[i].ex][enemy[i].ey] == '$')
		{
			mas[enemy[i].ex][enemy[i].ey + 1] = '$';
			mas[enemy[i].ex][enemy[i].ey] = ':';
			enemy[i].ey += 1;
		}
		else if (mas[enemy[i].ex][enemy[i].ey] == '*')
		{
			mas[enemy[i].ex][enemy[i].ey + 1] = '$';
			mas[enemy[i].ex][enemy[i].ey] = ';';
			enemy[i].ey += 1;
		}
	}
}
// Enemy movement
void Enemy_S(char mas[N][N], Enemy* enemy, int i)
{
	if (mas[enemy[i].ex + 1][enemy[i].ey] == ';')
	{
		if (mas[enemy[i].ex][enemy[i].ey] == '*')
		{
			mas[enemy[i].ex + 1][enemy[i].ey] = '*';
			mas[enemy[i].ex][enemy[i].ey] = ';';
			enemy[i].ex += 1;
		}
		else if (mas[enemy[i].ex][enemy[i].ey] == '$')
		{
			mas[enemy[i].ex + 1][enemy[i].ey] = '*';
			mas[enemy[i].ex][enemy[i].ey] = ':';
			enemy[i].ex += 1;
		}
	}
	else if (mas[enemy[i].ex + 1][enemy[i].ey] == ':')
	{
		if (mas[enemy[i].ex][enemy[i].ey] == '$')
		{
			mas[enemy[i].ex + 1][enemy[i].ey] = '$';
			mas[enemy[i].ex][enemy[i].ey] = ':';
			enemy[i].ex += 1;
		}
		else if (mas[enemy[i].ex][enemy[i].ey] == '*')
		{
			mas[enemy[i].ex + 1][enemy[i].ey] = '$';
			mas[enemy[i].ex][enemy[i].ey] = ';';
			enemy[i].ex += 1;
		}
	}
}

int enemycount1(char mas[N][N], int rows, int cols, Enemy* enemy)
{
	int ec1 = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			if (mas[i][j] == '$' || mas[i][j] == '*')
			{
				ec1++;
				enemy[ec1].ex = i;
				enemy[ec1].ey = j;
			}
		}
	return ec1;
}

int getRandom(int a, int b)
{
	return rand() % 4 + 1;
}

void AllEnemyMove(char mas[N][N], Enemy* enemy, int ec, int a, int b, int PLC, int PLR)
{
	int i = 1, move, distance;
	// dPLC , dPLR - разница между координатой противника и игрока
	// aPLC, aPLR - модуль
	int ay,ax,dy,dx;

	for (; i <= ec; i++)
	{
		dx = enemy[i].ex - PLR; dy = enemy[i].ey - PLC;

		ay = abs(dy); ax = abs(dx); distance = ay + ax;

		if (distance <= 5)
		{
			if (ax > ay) //Moves along x-axis
			{
				if (dx > 0) //Right of player
					Enemy_A(mas, enemy, i);

				else
					Enemy_D(mas, enemy, i);
			}

			else
			{
				if (dy > 0) //Right of player
					Enemy_W(mas, enemy, i);

				else
					Enemy_S(mas, enemy, i);
			}
		}
		else 
		{
			move = getRandom(1, 4);
			switch (move)
			{
			case 1:Enemy_W(mas, enemy, i); break;
			case 2:Enemy_A(mas, enemy, i); break;
			case 3:Enemy_D(mas, enemy, i); break;
			case 4:Enemy_S(mas, enemy, i); break;
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//FIGHTING

void battleSearch(char mas[N][N],int &ec, Player* player, Enemy* enemy, int PLR, int PLC)
{
	int i = 1;
	for (; i <= ec; i++)
		if (PLR == enemy[i].ex && PLC == enemy[i].ey)
			battle(mas,i, player , enemy,ec);
	if (player[1].XP >= 100)
	{
		player[1].LVL++;
		player[1].XP -= 100;
		printf("LEVEL UP!\n YOUR LEVEL IS %i", player[1].LVL);
		player[1].HP += 100;
		player[1].ATK += 5;
		player[1].DF += 5;
		system("pause");
	}
}

int attack(char mas[N][N],int & i, Player* player, Enemy* enemy, int & ec) // добавить описание текстовое
{
	int PlayerAttackChance = player[1].ATK - enemy[i].defence;
	
	//check if attack does damage
	if (PlayerAttackChance > 0)
	{
		enemy[i].hp -= PlayerAttackChance;
		//Check if it died
		if (enemy[i].hp <= 0)
		{
			printf("You won!");
			system("pause");
			player[1].XP = player[1].XP + 20;
			enemydead(mas, enemy, i,ec);
			return player[1].XP;
		}
		else {
			printf("You dealed %i damage", PlayerAttackChance);
			system("pause");
		} //добавить описание и system pauses и $ на : !!!
	}
	return 0;
}

int defence(int i, Player* player, Enemy* enemy) // добавить описание текстовое
{
	int EnemyAttackChance = enemy[i].attack - player[1].DF;

	if (EnemyAttackChance > 0)
	{
		player[1].HP -= EnemyAttackChance;
		printf("You got %i damage", EnemyAttackChance);
		system("pause");
		if (player[1].HP <= 0)
		{
			return player[1].ST = 0;
			printf("LOOOOL");
		}
	}
	return 0;
}

void battle(char mas[N][N],int & i, Player* player, Enemy* enemy, int& ec)
{
	printf("FIGHT");
	do {
		if (player[1].ST == 1)
		{
			printf("Game Over!");
			system("pause");
			exit(1);
		}
		defence(i, player, enemy);
		attack(mas,i, player, enemy,ec);
	} while (enemy[i].hp > 0 && player[1].HP > 0);
}

void enemydead(char mas[N][N], Enemy* enemy, int & i, int &ec)
{
		mas[enemy[i].ex][enemy[i].ey] = ':';
}

///////////////////////////////////////////////////////////////////////////////////////

