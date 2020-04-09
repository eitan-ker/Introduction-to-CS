/******************************************
*Student name: Eitan Kerzhner
*Student ID:205697139
*Submit Info:kerzhne
*Exercise name: ex5
******************************************/

#ifndef _MISSION2_H_
#define _MISSION2_H_
#include <stdio.h>
#define MIN_N 1
#define MAX_N 1000
#define MIN_SWEET 0
#define MAX_SWEET 10000
#define MIN_NUM_COOK 0
#define MAX_NUM_COOK 100000
void Mission2();
int SweetCookies(int cookies[], int n, int K);
void sort(int a[], int n);
int countingSteps(int a[], int n, int K, int count);
#endif