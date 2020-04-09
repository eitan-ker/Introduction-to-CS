/******************************************
*Student name: Eitan Kerzhner
*Student ID:205697139
*Submit Info:kerzhne
*Exercise name: ex5
******************************************/

#ifndef _MISSION5_H_
#define _MISSION5_H_
#include <stdio.h>		
#define MAX_BIG 25
#define MIN_BIG 1
void Mission5();
int min_Num(int left, int right, int up, int down, int counter);
void loadCastleBoard(char mat[][MAX_BIG], int rows, int cols);
int getMinLength(char mat[][MAX_BIG], int r, int c, int goalR, int goalC, int n);
#endif