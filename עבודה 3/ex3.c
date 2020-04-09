/**********************************************
Student name:  Eitan kerzhner
Student ID:    205697139
exercise name: exercise 3
***********************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_BASE 10 //max base for mission 1
#define MIN_BASE 2 //min base for mission 1
#define MAX_TIME 10000000 //max time for mission 2
#define MIN_TIME 0 //min time for mission 2
#define MAX_NUM 10000 //max number for mission 3 
#define MIN_NUM 0 //min number for mission 3

/*the main gets a mission number into mission parameter then checks if the input
is indeed between 1-4 and enters the cases which are the missions. after each 
mission is finished we are requested to enter another mission number, the program
will run until mission input will be >4 or <1
mission 1 - adding two numbers in base between 2-10 that we enter
mission 2 - strange timer output. prints the time in the timer after t seconds
mission 3 - prints all the numbers in a range we enter that are following the
pribciple: if you multiply the number by it's self, then devide it into 2 
parts in the middle, add those parts you will get the number we started with
mission 4 - it's a game that we enter an initial number, then each player by his 
turn prints the number accrding to the rules.  */

int main()
{
	int mission,b=0,res = 0,num1,num2,digit1,digit2,sum,i = 0,counter = 1;
	int t, value = 3, v, change_Num1, change_Num2, big_Num;
	int p, q, j, r = 0, l, d = 0, n, times=0;
	int k = 0, bin_Num = 0, luice = 0, richard = 0;
	char dummy;
	printf("Please enter the mission number:\n");
	scanf("%d", &mission);
	while ((mission <= 4)&&(mission>0))
	{
		switch (mission)
		{
/*case 1 gets an input of a base number, then 2 numbers. the mission is to add 
the two numbers in that base */
		case 1:
		{
			i=0;
			num1=0;
			num2=0;
			change_Num1=0;
			change_Num2=0;
			big_Num=0;
			counter=1;
			res=0;
			printf("Please enter the base of the problem:\n");
			scanf("%d", &b);
			if (b >= MIN_BASE && b <= MAX_BASE)
			{
				printf("Please enter the first number in base %d", b);
				printf(":\n");
				scanf("%d", &num1);
				printf("Please enter the second number in base %d", b);
				printf(":\n");
				scanf("%d", &num2);
				change_Num1 = num1;
				change_Num2 = num2;
// essential check to run the while loop until the bigger number isnt't 0
				if (num1 >= num2)
				{
					big_Num = num1;
				}
				else
				{
					big_Num = num2;

				}
/*res is the number that we get after adding the two numbers in the base.
the while does an operation of adding the first digits of the two numbers.
the number is devided  by 10, then we take again the first digit of each number.
we always add the 'i' to the digits  which is either 1 in case the digits sum is bigger or
equal then the base number, or 0 if the sum is smaller then the base number. all is saved in 
'sum' and then printed */
				while (res <= big_Num)
				{
					digit1 = change_Num1 % 10;
					digit2 = change_Num2 % 10;
					sum = digit1 + digit2 + i;
					i = 0;
					if (sum >= b)
					{
						i++;
						sum = sum - b;
					}
					res = res + (sum * counter);
					counter = counter * 10;
					change_Num1 = change_Num1 / 10;
					change_Num2 = change_Num2 / 10;
				}

				printf("The result of %d + %d in base %d is %d\n",num1,num2,
				b, res);
			}
			else
			{
				printf("ERROR - The base %d is not between 2 and 10\n",b);
			}
			
			printf("Please enter the mission number:\n");
			scanf("%c%d", &dummy, &mission);
			break;
		}
/*mission 2 is a strange timer, it has a circles of countdowns. the case
gets an input of the time, then checks if the input is ok. inside the while 
as long as time is not 0, it enters the for loop and changes v value according to 
the time.
after each circle the value multiplies by 2 from it's previous start point.*/
		case 2:
		{
			times=0;
			i=0;
			t=0;
			value=3;
                        counter=1;
			v = value;
			printf("Please enter the time:\n");
			scanf("%d", &t);
			times = t;
			if (t > MIN_TIME && t < MAX_TIME)
			{
				while (t != 0)
				{
					for (i = 0; i < value; i++)
					{
						t--;
						v = value - i;
						if (t == 0)
						{
							break;
						}
					}
/*after every for loop must be checked if time>0, if so- v value multiplied by
2 relatively to value before entering the for loop, then  entering another for loop*/
					if (t > 0)
					{
						counter = counter * 2;
						value = 3 * counter;
						v = value;
					}
				}
				printf("The time in the timer after %d seconds is %d\n"
				,times, v);
			}
// if the time input is not good 
			else
			{
				printf("ERROR - The time %d is invalid\n",times);
			}
			printf("Please enter the mission number:\n");
			scanf("%c%d", &dummy, &mission);
			break;
		}
/*case 3 is printing all the numbers between two limits we get as input(high and low) that
if the number is multiplied by it'self and then devided into two parts and those
parts are added you get the number we started with, if no numbers like that in the range it
prints 'no numbers in the range'. also the program checks if the input is
good, printing error */
		case 3:
		{
			d=0;
			r=0;
			counter=1;
			printf("Please enter the lower limit of the range (p):\n");
			scanf("%d", &p);
			printf("Please enter the upper limit of the range (q):\n");
			scanf("%d", &q);
			if (p > MIN_NUM && p < MAX_NUM && (p <= q))
			{
				for (i = p; i <= q; i++)
				{
					n = i;
					n = n * n;
					l = n;
					while (n > 0)
					{
						n = n / 10;
						d++;
					}
					if (d % 2 == 1)
					{
						d = d + 1;
					}
					for (j = 1; j <= d / 2; j++)
					{
						r = r + ((l % 10)*counter);
						l = l / 10;
						counter = counter * 10;
					}
					if ((l + r) == i)
					{
						times++;
						if (times == 1)
						{
							printf("The numbers between %d and %d are:\n",
							p, q);

						}
						printf("%d\n", i);
					}
					r = 0;
					counter = 1;
					d = 0;
				}
//times check the number of times we got a number that does the operation.
//if times=0 it means there are no numbers in the range
				if (times == 0)
				{
					printf("NO NUMBERS BETWEEN %d AND %d\n", p, q);
				}

			}
//if the range inputs are not good
			else
			{
				printf("ERROR - The range %d to %d isn't valid\n", p, q);
			}
			printf("Please enter the mission number:\n");
			scanf("%c%d", &dummy, &mission);
			break;
		}
/*this is a game with two possible outcomes - either luise wins or richard.
the game is very simple - we get a number as input, if the number is a power
of 2 each player gets the next power on the way down to 0.
if the number isn't a power of 2, the next player subtructs the number from the closest
power of 2 with the number.
the first to reach 0 wins. louise starts*/
		case 4:
		{
			n=0;
			printf("Please enter the initial value for the game:\n");
			scanf("%d", &n);
			k = 2;
			if (n != 1)
			{
				while (n / k >= 2)
				{
					k = k << 1;
				}
				bin_Num = n & k;
				luice = n;
//check if the initial number is a power of 2
				if (bin_Num == n)
				{
//the initial number is a power of 2
					luice = n;
					printf("Louise: %d\n", luice);
					n = n >> 1;
					richard = n;
					printf("Richard: %d\n", richard);
					while (n >= 2)
					{
						n = n >> 1;
						luice = n;
						printf("Louise: %d\n", luice);
						if (n == 1)
						{
							break;
						}
						n = n >> 1;
						richard = n;
						printf("Richard: %d\n", richard);
					}
				}
				else
				{
//the initial number is not a power of 2
					while (n != 1)
					{
						if (bin_Num == n)
						{
							printf("Louise: %d\n", n);
							n = n >> 1;
						}
						else
						{
							printf("Louise: %d\n", n);
							n = n ^ k;
						}
						if (n == 1)
						{
							richard = 1;
							printf("Richard: %d\n", n);
							break;
						}
						k = 2;
						while (n / k >= 2)
						{
							k = k << 1;
						}
						bin_Num = n & k;
						if (bin_Num == n)
						{
							printf("Richard: %d\n", n);
							n = n >> 1;
						}
						else
						{
							printf("Richard: %d\n", n);
							n = n ^ k;
						}
						if (n == 1)
						{
							luice = 1;
							printf("Louise: %d\n", n);
							break;
						}
						k = 2;
						while (n / k >= 2)
						{
							k = k << 1;
						}
						bin_Num = n & k;
					}
				}
			}
			else
			{
//the initial number is 1
				printf("Louise: %d\n", n);
			}
//who has 1, the other wins.
			if (richard == 1)
			{
				printf("The winner is: Louise\n");
			}
			else
			{
				printf("The winner is: Richard\n");

			}
			printf("Please enter the mission number:\n");
			scanf("%c%d", &dummy, &mission);
			break;
		}
		default:
			printf("");
		}
	}
	return 0;
}
