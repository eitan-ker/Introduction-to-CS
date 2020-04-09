/******************************************
*Student name: Eitan Kerzhner
*Student ID:205697139
*Submit Info:kerzhne
*Exercise name: ex5
******************************************/
#include "Mission3.h"
#include "Mission1.h"

/************************************************************************
* function name: CanAnagram 											*
* The Input: str - string containing a-z letters 						*
* The output: the palindrome of str string if possible					*
* The Function operation: The function prints if str can be changed to 	*
							be a polindrom or not						*
*************************************************************************/
void CanAnagram(char str[])
{
	int i = 0, j=0, n, count=0, temp=0, flag=0, index=0, index2=0, arr[26];
	char *pst1 = str, a[100], cflag = 0;
	n = size(str);
	for (i = 0; i < n; i++)
	{
		a[i] = str[i];
	}
	if ((n % 2) == 0)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (str[i] == str[j])
				{
					count++;
				}
			}
			if (count % 2 != 0)
			{
				printf("The string %s does not have a palindrome\n", str);
				flag = 1;
				break;
			}
			count = 0;
		}
		if (flag == 0)
		{
			sortArr(str, 0, n);
			for (i = 1; i < n / 2; i++)
			{
				temp = str[i];
				str[i] = str[n-i];
				str[n-i] = temp;
				sortArr(str, i, n - i);
			}
			printf("The string ");
			for (i = 0; i < n; i++)
			{
				printf("%c",a[i]);
			}
			printf(" has the palindrome %s\n", str);
		}
	}
	else
	{
		count = 0;
		for (i = 0; i < 26; i++) //nulling the helparray
		{
			arr[i] = 0;
		}
		index = 0;
		for (i = 0; i < n; i++) //input to helparray
		{
			arr[((int)str[i]) - 97]++;
		}
		for (i = 0; i < 26; i++) //sorting the amount of each letter by letter index
		{
			if (arr[i] % 2 != 0)
			{
				count++;
			}
		}
		if (count == 1)
		{
			for (i = 0; i < 26; i++)
			{
				if (arr[i] % 2 != 0)
				{
					str[(n / 2)] = i + 97;
					arr[i]--;
				}
				for (j = index; j < index + (arr[i] / 2); j++)
				{
					str[j] = i + 97;
					str[n - j - 1] = i + 97;
				}
				index = index + (arr[i] / 2);
			}
			printf("The string ");
			for (i = 0; i < n; i++)
			{
				printf("%c", a[i]);
			}
			printf(" has the palindrome %s\n", str);
		}
		else
		{
			printf("The string ");
			for (i = 0; i < n; i++)
			{
				printf("%c", a[i]);
			}
			printf(" does not have a palindrome\n");
		}
	}
}
/************************************************************************
* function name: sortArr 												*
* The Input: arr - string containing a-z letters 						*
*			 start - the starting index to sort							*
*			 end - the ending index	to sort								*
* The output: sorted string arr											*
* The Function operation: returns sorted lexicographical orded string	*
*************************************************************************/
void sortArr(char arr[],int start, int end)
{
	int j = 0, i = 0;
	char *pstr = arr, temp;
	for (j = start; j < end - 1; j++)
	{
		for (i = start; i < end - 1; i++)
		{
			if (*(pstr + i) >= *(pstr + i + 1))
			{
				temp = *(pstr + i);
				*(pstr + i) = *(pstr + i + 1);
				*(pstr + i + 1) = temp;
			}
		}
	}
	//return pstr;
}
/************************************************************************
* function name: size	 												*
* The Input: arr - The arr string		                         		*
* The output: The function returns size of array						*
* The Function operation: The function checks the size					*
*************************************************************************/
int size(char arr[]) //couting size of array
{
	char *pstr = arr;
	int i = 0, count = 0;
	for (i = 0; i < 100; i++)
	{
		if (* (pstr+i) != 0)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	pstr = NULL;
	return count;
}
/************************************************************************
* function name: Mission3 												*
* The Input: none						                        		*
* The output: The function returns the palindrome of str if possible	*
* The Function operation: The function calls CanAnagram					*
*************************************************************************/
void Mission3()
{
	char str[100];
	printf("Please enter the string:\n");
	scanf("%s", str);	// input the str
	if (checkValid(str, size(str)) == 1)
	{
		CanAnagram(str);
	}
}