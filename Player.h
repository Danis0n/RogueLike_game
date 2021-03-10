#pragma once
#define N 100



int KeyboardInput_W(char mas[N][N], int rows, int cols, int& PLR, int& PLC, int& levelpasscount);
int KeyboardInput_S(char mas[N][N], int rows, int cols, int& PLR, int& PLC, int& levelpasscount);
int KeyboardInput_D(char mas[N][N], int rows, int cols, int& PLR, int& PLC, int& levelpasscount);
int KeyboardInput_A(char mas[N][N], int rows, int cols, int& PLR, int& PLC, int& levelpasscount);
void NextLevelPass(char mas[N][N], int rows, int cols, int& PLR, int& PLC, int& levelpasscount);
