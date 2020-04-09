/******************************************
*Student name: Eitan Kerzhner
*Student ID:205697139
*Submit Info:kerzhne
*Exercise name: ex5
******************************************/

#include "Mission2.h"

/************************************************************************
* function name: SweetCookies 											*
* The Input: cookies[] - cookoies array									*
*            n - amount of cookies										*
*            k - minimum required sweetnes								*
* The output: The function returns number of steps to remake the cookies*
*              or -1 if can;t be done									*
* The Function operation: sorting and calling countingSteps to count the*
*                         steps											*
*************************************************************************/
int SweetCookies(int cookies[], int n, int K)
{
	int i = 0, steps = 0;
	sort(cookies, n);
	steps = countingSteps(cookies, n, K, 0);
	return steps;
}
/************************************************************************
* function name: sort 													*
* The Input:  a[] - cookoies array										*
*             n - amount of cookies										*
* The output: The function returns sorted array from small to big		*
* The Function operation: the function rearranges the cookies by size	*
*************************************************************************/
void sort(int a[], int n) 
{
	int i = 0, j = 0, temp = 0;
	for (i = 0; i < n - 1; i++) 
	{
		for (j = 0; j < n - 1; j++)
		{
			if (a[j] >= a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	printf("");
	//return a;
}
/************************************************************************
* function name: countingSteps 											*
* The Input: a[] - cookoies array										*
*            n - amount of cookies										*
*            k - minimum required sweetnes								*
*            count - the number of steps								*
* The output: The function returns -1 or count							*
* The Function operation: the function using a recursion to sort the	*
*                         array using function sort and checks if the	*	
*						  cookies can be remade by the principal		*
*************************************************************************/
int countingSteps(int a[], int n, int K, int count) 
{
	int i = 0, j=0, b[MAX_N];
	if (a[1] >= K)
	{
		if (a[0] >= K)
		{
			return count;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		b[0] = a[0] + (2 * a[1]);
		count++;
		for (i = 1; i < n-1; i++)
		{
			b[i] = a[i + 1];
		}
		sort(b, n - 1); //sorting array b
		return countingSteps(b, n - 1, K, count);
	}
		 
}
/************************************************************************
* function name: Mission2 												*
* The Input: n - amount of cookies										*
*            sweet - minimum sweetness required							*
* The output: The function number of steps or -1 if not possible		*
* The Function operation: The function using functions sort,			*
*                         countingSteps and SweetCookies				*
*************************************************************************/
void Mission2()
{
	int n, sweet;
	int cookies[MAX_N];
	int i;
	int result;
	int flag = 0;
	printf("Please enter the amount of cookies:\n");
	scanf("%d", &n);
	if (n >= MIN_N && n <= MAX_N) //check if number of cookies in the range
	{
		printf("Please enter the minimum required sweetness:\n");
		scanf("%d", &sweet);
		if (sweet >= MIN_SWEET && sweet <= MAX_SWEET) //check if minimum sweetnes in the range
		{
			for (i = 0; i < n; i++)
			{
				printf("Please enter cookie number %d:\n", i + 1);
				scanf("%d", &cookies[i]); // check if input in range
				if (cookies[i]<MIN_NUM_COOK || cookies[i]>MAX_NUM_COOK)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				result = SweetCookies(cookies, n, sweet);
				printf("The number of operations that are needed is %d\n", result);
			}
		}
	}
} 