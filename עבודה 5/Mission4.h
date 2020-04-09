/******************************************
*Student name: Eitan Kerzhner
*Student ID:205697139
*Submit Info:kerzhne
*Exercise name: ex5
******************************************/

#ifndef _MISSION4_H_
#define _MISSION4_H_
#include <stdio.h>
#define MAX_SIZE 26
#define MIN_SIZE 3
#define MIN_TURNS 1
#define MAX_TURNS 100000
void Mission4();
void RunGame(int n, int m, long c, char board[][MAX_SIZE]);
void loadBoard(char mat[][MAX_SIZE], int rows, int cols);
int numOfLiving(char mat[][MAX_SIZE], int rows, int cols, int row, int col);
#endif