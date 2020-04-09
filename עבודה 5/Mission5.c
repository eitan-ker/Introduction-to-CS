/******************************************
*Student name: Eitan Kerzhner
*Student ID:205697139
*Submit Info:kerzhne
*Exercise name: ex5
******************************************/

#include "Mission5.h"

/************************************************************************
* function name: Mission5	 											*
* The Input: borad - empty board										*
*			 startX - the row which we start with						*
			 startY - the column which we start with					*
			 goalX - the rows which we need to get to					*
			 goalY - the column which we need to ge to					*
* The output: the minimum number of steps to get from starting position	*
			  to the end position. or -1 if not possible				*
* The Function operation: using loadCastleBoard to load the board, and	*
*						  getMinLength to get min steps					*
*************************************************************************/
void Mission5()
{
	int n;
	char board[MAX_BIG][MAX_BIG];

	int startX, startY, goalX, goalY, result;

	printf("Please enter the number of rows and columns (n):\n");
	scanf("%d", &n);
	if (n<MAX_BIG && n>MIN_BIG)
	{
		printf("Please enter the X of the starting position:\n");
		scanf("%d", &startX);
		if ((startX <= n)&&(startX>=0))
		{
			printf("Please enter the Y of the starting position:\n");
			scanf("%d", &startY);
			if ((startY <= n) && (startY >= 0))
			{
				printf("Please enter the X of the goal position:\n");
				scanf("%d", &goalX);
				if ((goalX <= n) && (goalX >= 0))
				{
					printf("Please enter the Y of the goal position:\n");
					scanf("%d", &goalY);
					if ((goalY <= n) && (goalY >= 0))
					{
						printf("Please enter the grid:\n");
						loadCastleBoard(board, n, n);		// Reading the Board

						result = getMinLength(board, startX, startY, goalX, goalY, n);	// Getting the Minimum Value
						if (result != -1)
						{
							printf("The minimum number of steps is %d\n", result);
						}
						else
						{
							printf("No path was found from (%d,%d) to (%d,%d)\n", startX, startY, goalX, goalY);
						}
					}
				}
			}
		}
	}
}

/************************************************************************
* function name: getMinLength	 										*
* The Input: board - empty board										*
*			 r - the row which we start with							*
			 c - the column which we start with							*
			 goalR - the rows which we need to get to					*
			 goalC - the column which we need to ge to					*
			 n - the size of the board by rows and columns				*
* The output: the minimum number of steps to get from starting position	*
			  to the end position.										*
* The Function operation: using min_Num to find the min number of steps	*
						  between going right, up, down or left         *
*************************************************************************/
int getMinLength(char mat[][MAX_BIG], int r, int c, int goalR, int goalC, int n)
{
	int right = 0, left = 0, up = 0, down = 0, i=0;
	if ((r == goalR) && (c == goalC))
	{
		return 0;
	}
	if (mat[r][c+1]=='-')
	{
		mat[r][c] = 'r';
		right = 1 + getMinLength(mat, r, c + 1, goalR, goalC, n);
	}
	if (mat[r][c-1]=='-')
	{
		mat[r][c] = 'l';
		left = 1 + getMinLength(mat, r, c - 1, goalR, goalC, n);
	}

	if (mat[r+1][c]=='-')
	{
		mat[r][c] = 'd';
		down = 1 + getMinLength(mat, r+1, c, goalR, goalC, n);
	}
	if (mat[r-1][c]=='-')
	{
		mat[r][c] = 'u';
		up = 1 + getMinLength(mat, r-1, c, goalR, goalC, n);
	}
	mat[r][c] = '-';
	return min_Num(left, right, up, down,0);
}
/************************************************************************
* function name: min_Num	 											*
* The Input: left - number of steps reaching the target by going left	*
*			 right - number of steps reaching the target by going right *
*			 up - number of steps reaching the target by going up		*
*			 down - number of steps reaching the target by going down	*
*			 counter - starting with 0, checker for the minimum number	*
*					   bigger then 0									*
* The output: the minimum number higher the 0							*
* The Function operation: reducing 1 for each parameter and adding 1 to *
*					      counter, stops when the first parameter		*
*						  reaching 0, returning counter					*
*************************************************************************/
int min_Num(int left, int right, int up, int down, int counter)
{
	if ((left == 0) && (right == 0) && (up == 0) && (down == 0))
	{
		return -1;
	}
	else
	{
		counter++;
		right--;
		left--;
		up--;
		down--;
		if ((right == 0) || (left == 0) || (up == 0) || (down == 0))
		{
			return counter;
		}
		else
		{
			return min_Num(left, right, up, down, counter);
		}
	}
}
/************************************************************************
function name: loadBoard	 											*
* The Input: rows - number of rows										*
*			 cols - number of columns									*
*			 mat - clean board of the game								*
* The output: the board of the game										*
* The Function operation: input the board first state					*
*************************************************************************/
void loadCastleBoard(char mat[][MAX_BIG], int rows, int cols)
{
	int i;
	for (i = 0; i < rows; i++)
	{
		scanf("%s", mat[i]);
	}
}
