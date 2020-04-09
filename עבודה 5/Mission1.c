/******************************************
*Student name: Eitan Kerzhner
*Student ID:205697139
*Submit Info:kerzhne
*Exercise name: ex5
******************************************/

#include "Mission1.h"

void Mission1()
{
	int n, i, count = 0, checker1 = 0, checker2 = 0,flag=0;
	char source[MAX_STRING], target[MAX_STRING];

	printf("Please enter the amount of pairs:\n");
	// Input the n
	scanf("%d", &n);
	if (n >= MIN_PAIRS && (n <= MAX_PAIRS))
	{
		for (i = 0; i < n; i++)
		{
			printf("Please enter the first string of pair %d:\n", i + 1);
			scanf("%s", target);
			checker1 = sizeArray(target); //counts size of target
			if (checkValid(target, checker1) == 1) //checking correct input
			{
				printf("Please enter the second string pair %d:\n", i + 1);
				scanf("%s", source);
				checker2 = sizeArray(source); // count size of source
				if (checkValid(source, checker2) == 1)  //checking correct input
				{
					if (checker1 == checker2) // if sizes of arrays same
					{
						count += isSemiSimilar(target, source);
					}
				}
				else
				{
					flag = 1;
					break;
				}
			}
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag==0)
		{
			printf("The amount of Semi-Similar strings is %d\n", count);
		}
	}
}

/************************************************************************
* function name: isSemiSimilar 											*
* The Input: target - The target string containing a-z letters 			*
* 			 source - The source string containing a-z letters			*
* The output: The function returns 1 or 0								*
* The Function operation: The function checks if target is 				*
*						  semi-similar to source 						*
*************************************************************************/ 
int isSemiSimilar(char target[], char source[])
{
	int i=0, j=0, size=sizeArray(target),counter=0;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (target[i] == source[j])
			{
				counter++;
				target[i] = 0;
				source[j] = 0;
				break;
			}
		}
	}
	if (counter == size)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/************************************************************************
* function name: sizeArray 												*
* The Input: target - The target string                         		*
* 			 source - The source string									*
* The output: The function returns size of arrays if equal size			*
*             The function returns -1 if different size					*
*             The function returns  0 if input if string is not a-z     *
* The Function operation: The function checks the size and input		*
*************************************************************************/
int sizeArray(char a[])
{
	char *ptarget = a;
	int count = 0, i = 0;
	for (i = 0; i < MAX_STRING; i++)
	{
		if (*(ptarget + i) != 0)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	return count;
}
/************************************************************************
* function name: checkValid 											*
* The Input: arr - a string									 			*
* 			 size - the size of the string								*
* The output: The function returns 1 or 0								*
* The Function operation: The function checks if input to string is a-z	*
*************************************************************************/
int checkValid(char arr[],int size) 
{
	int i, check = 1;
	for (i = 0; i < size; i++)
	{
		if (arr[i] < MIN_LETTER || arr[i] > MAX_LETTER)
		{
			return 0;
		}
	}
	return check;
}
