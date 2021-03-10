#pragma once
#define N 100
#define ENEMY 10


extern struct Enemy {
	int	hp = 100, attack = 20, defence = 5, ex, ey;
};


extern struct Player {
	int HP = 150, XP = 0, ATK = 25, DF = 10, LVL = 1, ST = 0;
};


extern struct Boss {
	int HP = 300, ATK = 35, DF = 15, x, y;
};
