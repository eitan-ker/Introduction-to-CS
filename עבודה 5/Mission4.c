/******************************************
*Student name: Eitan Kerzhner
*Student ID:205697139
*Submit Info:kerzhne
*Exercise name: ex5
******************************************/

#include "Mission4.h"

/************************************************************************
* function name: Mission4	 											*
* The Input: n - number of rows											*
*			 m - number of columns										*
*			 c - number of iterarations									*
* The output: state of board after c iterations, or the minimum number 	*
*			  of iterztions to get clean board							* 
* The Function operation: using load board to load the board, and		*
*						  rungame to run the game						*
*************************************************************************/
void Mission4()
{
	int n, m, size_Coll=0, temp=0;
	long c;
	char board[MAX_SIZE][MAX_SIZE];

	printf("Please enter the number of rows (n):\n");
	scanf("%d", &n);
	if(n >= MIN_SIZE && n < MAX_SIZE)
	{
	printf("Please enter the number of columns (m):\n");
	scanf("%d", &m);
	if (m >= MIN_SIZE && m < MAX_SIZE)
	{
		printf("Please enter the number of iterations (c):\n");
		scanf("%ld", &c);
		if (c >= MIN_TURNS && c <= MAX_TURNS)
		{
			printf("Please enter the board:\n");
			loadBoard(board, n, m);	// Reading the Board
			RunGame(n, m, c, board);
		}
	}
	}
}
/************************************************************************
function name: RunGame	 												*
* The Input: n - number of rows											*
*			 m - number of columns										*
*			 c - number of iterarations									*
*			 board - the board of the game								*
* The output: state of board after c iterations, or the minimum number 	*
*			  of iterztions to get clean board							*
* The Function operation: checking for neighbours using numOfLiving and	*
*						  chnages the board every iteration according	*
*						  the rules of the game							*
*************************************************************************/
void RunGame(int n, int m, long c, char board[][MAX_SIZE])
{
	int i = 0, j = 0, k = 0, temp=0, counter=0;
	char helping_Arr[MAX_SIZE][MAX_SIZE];
	for (i = 0; i < c; i++) //might have problem with <= c
	{	
		if (counter == (n*m))
		{
			break;
		}
		counter = 0;
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < m; k++)
			{
				if (board[j][k] == '*')
				{
					temp = numOfLiving(board, n, m, j, k);
					if ((temp > 3) || (temp < 2))
					{
						helping_Arr[j][k] = '-';
					}
					else
					{
						helping_Arr[j][k] = '*';
					}
				}
				else
				{
					temp = numOfLiving(board, n, m, j, k);
					if (temp == 3)
					{
						helping_Arr[j][k] = '*';
					}
					else
					{
						helping_Arr[j][k] = '-';
					}
				}
			}
		}
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < m; k++)
			{
				if (helping_Arr[j][k] == '-')
				{
					counter++;
				}
				board[j][k] = helping_Arr[j][k];
				helping_Arr[j][k] = 0;
			}
		}
	}
	printf("The board after %d iterations is:\n", i);
	for (j = 0; j < n; j++)
	{
		printf("%s\n", board[j]);
	}
}
/************************************************************************
function name: loadBoard	 											*
* The Input: n - number of rows											*
*			 m - number of columns										*
*			 board - clean board of the game							*
* The output: the board of the game										*
* The Function operation: input the board first state					*
*************************************************************************/
void loadBoard(char mat[][MAX_SIZE], int rows, int cols)
{
	int i = 0, j = 0;
	for (i = 0; i < rows; i++)
	{
		scanf("%s", mat[i]); //input lines
	}

	// The Function reads from the IO and loads to the array
}
/************************************************************************
function name: numOfLiving	 											*
* The Input: rows - number of rows										*
*			 cols - number of columns									*
*			 board - clean board of the game							*
*			 row - the row of the specific place we check neighbours	*
*			 col - the col of the specific place we check neighbours	*
* The output: number of neighbours  									*
* The Function operation: looking for living neighbours on the right,	*
*						  left, up down and 4 angels.					*
*						  if the place is on the edge, checking on the	*
*						  other side.									*
*************************************************************************/
int numOfLiving(char mat[][MAX_SIZE], int rows, int cols, int row, int col)
{
	int counter = 0, i = 0, j = 0, help_Row=0, help_Col=0;
	for (i = row - 1; i <= row + 1; i++)
	{
		for (j = col - 1; j <= col + 1; j++)
		{
			if (i < 0)
			{
				help_Row = rows-1;
				if (j < 0)
				{
					help_Col = cols-1;
				}
				else
				{
					if (j > cols-1)
					{
						help_Col = 0;
					}
					else
					{
						help_Col = j;
					}
				}
			}
			else
			{
				if (i > rows-1)
				{
					help_Row = 0;
					if (j < 0)
					{
						help_Col = cols-1;
					}
					else
					{
						if (j > cols-1)
						{
							help_Col = 0;
						}
						else
						{
							help_Col = j;
						}
					}
				}
				else
				{
					help_Row = i;
					if (j < 0)
					{
						help_Col = cols-1;
					}
					else
					{
						if (j > cols-1)
						{
							help_Col = 0;
						}
						else
						{
							help_Col = j;
						}
					}
				}
			}
			if ((i == row) && (j == col))
			{
				continue;
			}
			else
			{
				if (mat[help_Row][help_Col] == '*')
				{
					counter++;
				}
			}
		}
	}
	return counter;
}
