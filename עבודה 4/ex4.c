/************************************
Student name:  Eitan kerzhner
Student Id:    205697139
Exercise name: Exercise 4
*************************************/
#include <stdio.h>
#define MIN_N 1
#define MAX_N 1000
#define MIN_NUM 1
#define MAX_NUM 1000000000
#define MIN_NUMBER 0
#define MAX_NUMBER 300
enum shapes { Rock = 0, Paper = 1, Scissors = 2, Lizard = 3, Spock = 4 };
#define ROCK "Rock"
#define PAPER "Paper"
#define SCISSORS "Scissors"
#define LIZARD "Lizard"
#define SPOCK "Spock"
#define ALICE "Alice"
#define BOB "Bob"
/****************************************************************************
* function name: digits, mission 1
* The Input: the number b
* The output: the number of digits in number b
* The Function operation: devideds by 10 and counts the number of operations
to reach b=0 then return counter
*****************************************************************************/
int digits(int num)
{
	int count = 0;
	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	return count;
}
/****************************************************************************
* function name: power, mission 1
* The Input: number of digits b
* The output: 10^number of digits of b
* The Function operation: multiplies 10 by itself num times
*****************************************************************************/
int power(int num)
{
	int count = 1, i;
	for (i = 0; i < num; i++)
	{
		count = 10 * count;
	}
	return count;
}
/****************************************************************************
* function name: pairsNumber, mission 1
* The Input: number 'a' and number 'b'
* The output: 1 if 'a' contains number 'b', 0 if not.
* The Function operation: checks the number of digits in 'b', then take out 
the same amounts of digits out of 'a' to check of the number is equal to 'b'.
if not, a is devided by 10 and so on.. the loop runds until num1 is smaller
then b, which means we can not check anymore.
*****************************************************************************/
int pairsNumber(int num1, int num2)
{
	if (num1 <= MAX_NUM && num2 >= MIN_NUM)
	{
		int d, a_Helper = 0, count = 0;
		d = digits(num2);
		while (num1 >= num2)
		{
			if (num1 == num2)
			{
				return 1;
			}
			a_Helper = num1 % (power(d));
			if (a_Helper == num2)
			{
				count = 1;
			}
			num1 = num1 / 10;
		}
		return count;
	}
	else
	{
		return 0;
	}
}
/****************************************************************************
* function name: funAction, mission 2
* The Input: number 'n'.
* The output: the minimum number of steps to reach 0 from 'n', and prints the
numbers as well.
* The Function operation:we get number 'n', the we use other functions to check
the minimum number of steps to reach 0. following 2 conditions: 
*if the number can be devided into 2 numbers than we change the number to his 
higher devider. *decrease the number by 1, if both  actions gives the same 
resault, action 1 is preferable.
*****************************************************************************/
int funAction(int num)
{
	int d1, num_Help = 0, d2 = 1;
	if (num == 1)
	{
		return d2;
	}
	d1 = 1 + funAction(num - 1);
	d2 = 1 + funAction(div(num, 2));
	num_Help = div(num, 2);
	if (num_Help == 1)
	{
		return d1;
	}
	if (d2 <= d1)
	{
		return d2;
	}
	return d1;
}
/****************************************************************************
* function name: div, mission 2
* The Input: a number from function funAction. 
* The output: the highest devider of the number, if the are no deviders returns
1.
* The Function operation: runs a recursion, the recursion breaks when we find
the first devider for the number. it returns the devision of the number by
it's lowest devider. means: if we have devider lower then the number, it 
returns number/lowest deivder = highest devider. if no deviders, returns 1
(number/number=1).
*****************************************************************************/
int div(int num, int i)
{
	if (num%i == 0)
	{
		return (num / i);
	}

	return div(num, i + 1);
}
/****************************************************************************
* function name: numberPrint, mission 2
* The Input: num = number 'n', count = the minimum number of steps(using funAction).
* The output: prints all the numbers for 'n' to '0' following the correct steps
* The Function operation: using time1 and times2, we count each time the number
of steps and then check if it's equal to the number of steps we have left to reach '0' 
according to the count. each "turn" we substruct 1 from count. 
*****************************************************************************/
int numberPrint(int num, int count)
{
	int times1, times2;
	if (num == 1)
	{
		return printf("0\n");
	}
	times1 = funAction(num - 1);
	times2 = funAction(div(num, 2));
	if (count - 1 == times2)
	{
		printf("%d\n", div(num, 2));
		return numberPrint(div(num, 2), count - 1);
	}
	if (count - 1 == times1)
	{
		printf("%d\n", num - 1);
		return numberPrint(num - 1, count - 1);
	}
}
/****************************************************************************
* function name: biggestNum, mission 3
* The Input: num = number 'x', i = 1, count=0.
* The output: printing all the numbers that following the conditions: *x^a > x , *x > a > 0
and also the amount of numbers the following the condition.
*  The Function operation: using help_Num for the operation num^i. each turn we add 1 to i and add 1 to count
when the conditions are right. the function check if num_Help>num.
when i reachs num means we checked all the numbers from 1 to num as requested. 
*****************************************************************************/
int biggestNum(long num, int i, int count)
{
	long help_Num;
	if ((i == num) && (num >= 1))
	{
		return count;
	}
	help_Num = num ^ i;
	if (help_Num > num)
	{
		count++;
		printf("%d\n", i);
	}
	return biggestNum(num, i + 1, count);
}
/****************************************************************************
* function name: whoWins, mission 4
* The Input: alice = alices's shape, bob = bob's shape
* The output: the characters '>'/'<'/'+' by the conditions who's wins or equal.
* The Function operation: checks all the cases and returns the output.
*****************************************************************************/
char whoWins(enum shapes alice, enum shapes bob)
{
	switch (alice)
	{
	case Rock:
	{
		if (bob == Rock)
		{
			return '=';
		}
		else
			if ((bob == Paper) || (bob == Spock))
			{
				return '<';
			}
			else
				if ((bob == Lizard) || (bob == Scissors))
				{
					return '>';
				}
		break;
	}
	case Paper:
	{
		if (bob == Paper)
		{
			return '=';
		}
		else
		{
			if ((bob == Lizard) || (bob == Scissors))
			{
				return '<';
			}
			else
			{
				if ((bob == Rock) || (bob == Spock))
				{
					return '>';
				}
			}
		}
		break;
	}
	case Scissors:
	{
		if (bob == Scissors)
		{
			return '=';
		}
		else
			if ((bob == Rock) || (bob == Spock))
			{
				return '<';
			}
			else
				if ((bob == Lizard) || (bob == Paper))
				{
					return '>';
				}
		break;
	}
	case Lizard:
	{
		if (bob == Lizard)
		{
			return '=';
		}
		else
			if ((bob == Rock) || (bob == Scissors))
			{
				return '<';
			}
			else
				if ((bob == Spock) || (bob == Paper))
				{
					return '>';
				}
		break;
	}
	case Spock:
	{
		if (bob == Spock)
		{
			return '=';
		}
		else
			if ((bob == Lizard) || (bob == Paper))
			{
				return '<';
			}
			else
				if ((bob == Rock) || (bob == Scissors))
				{
					return '>';
				}
		break;
	}
	default:
		printf("");
	}
}
/****************************************************************************
* function name: nextShapeAlice, mission 4
* The Input: alice = alices's shape, state = character if she won/lost/equaled, bob = bob's shape.
* The output: next alice's shape
* The Function operation: checks all the cases and returns next alices shape following her strategy.
*****************************************************************************/
int nextShapeAlice(enum shapes alice, char state, enum shapes bob)
{
	switch (alice)
	{
	case Rock:
	{
		if (state == '>')
		{
			alice = Rock;
		}
		else
			if (state == '=')
			{
				alice = Paper;
			}
			else
				if (state == '<')
				{
					if (bob == Paper)
					{
						alice = Scissors;
					}
					if (bob == Spock)
					{
						alice = Lizard;
					}
				}
		return alice;
		break;
	}
	case Paper:
	{
		if (state == '>')
		{
			alice = Paper;
		}
		else
			if (state == '=')
			{
				alice = Scissors;
			}
			else
			{
				if (state == '<')
				{
					if (bob == Scissors)
					{
						alice = Spock;
					}
					if (bob == Lizard)
					{
						alice = Rock;
					}
				}
			}
		return alice;
		break;
	}
	case Scissors:
	{
		if (state == '>')
		{
			alice = Scissors;
		}
		else
			if (state == '=')
			{
				alice = Spock;
			}
			else
				if (state == '<')
				{
					if (bob == Rock)
					{
						alice = Paper;
					}
					if (bob == Spock)
					{
						alice = Lizard;
					}
				}
		return alice;
		break;
	}
	case Lizard:
	{
		if (state == '>')
		{
			alice = Lizard;
		}
		else
			if (state == '=')
			{
				alice = Rock;
			}
			else
				if (state == '<')
				{
					if (bob == Scissors)
					{
						alice = Spock;
					}
					if (bob == Rock)
					{
						alice = Paper;
					}
				}
		return alice;
		break;
	}
	case Spock:
	{
		if (state == '>')
		{
			alice = Spock;
		}
		else
			if (state == '=')
			{
				alice = Lizard;
			}
			else
				if (state == '<')
				{
					if (bob == Lizard)
					{
						alice = Rock;
					}
					if (bob == Paper)
					{
						alice = Scissors;
					}
				}
		return alice;
		break;
	}
	}
}
/****************************************************************************
* function name: nextShapeBob, mission 4
* The Input: bob = bob's shape., state = character if she won/lost/equaled.
* The output: next bob's shape
* The Function operation: checks all the cases and returns next bob's shape following his strategy.
*****************************************************************************/
int nextShapeBob(enum shapes bob, char state, int i)
{
	if (i % 2 == 0)
	{
		return Spock;
	}
	else
	{
		if (state == '<')
		{
			bob = Rock;
		}
		else
		{
			if (state == '=')
			{
				bob = Lizard;
			}
			else
			{
				if (state == '>')
				{
					bob = Paper;
				}
			}
		}
	}
	return bob;
}
/****************************************************************************
* function name: shapeOfYou, mission 4
* The Input: a shape by int number as it's defined
* The output: the name of the shape
* The Function operation: checks all the shapes and return for each one the name of it
*****************************************************************************/
void shapeOfYou(enum shapes num) 
{
	switch (num)
	{
	case 0:
	{
		printf(ROCK);
		break;
	}
	case 1:
	{
		printf(PAPER);
		break;
	}
	case 2:
	{
		printf(SCISSORS);
		break;
	}
	case 3:
	{
		printf(LIZARD);
		break;
	}
	case 4:
	{
		printf(SPOCK);
		break;
	}
	default: printf("");
	}
}
/****************************************************************************
* function name: main
* The Input: mission = the number of the mission which we will do
* The output:
mission 1 - the number of pairs which number a contains number b.
mission 2 - the minimum number of moves to reach zero from 'n', also prints the numbers.
mission 3 - counts the amount of numbers from 0 to the input number that following the condition. also prints them.
mission 4 - the order of the game, who won/tied and showing each players choice every turn.
* The Function operation: gets an input of mission number. then going to case mode the inputs:
1 - mission 1.
2 - mission 2.
3 - mission 3.
4 - mission 4.
mission 1 using functions "power", "digits","pairsNumber".
mission 2 using functions "funAction","div","numberPrint".
mission 3 using function "biggestNum".
missioni 4 using functions "whoWins","nextShapeAlice","nextShapeBob","shapeOfYou".
*****************************************************************************/

int main() // main
{
	int mission, i = 0, n = 0, a = 0, b = 0, counter = 0, dig = 0, multi = 0,
		count_Alice = 0, count_Bob = 0;
	long x = 0;
	enum shapes AliceShape, BobShape;
	char condition;
	printf("Please enter the mission number:\n");
	scanf("%d", &mission);
	while ((mission >= 1) && (mission <= 4))
	{
		switch (mission) // entering switch mode to choose the correct mission by the input.
		{
		case 1: // mission 1
		{
			counter = 0;
			printf("Please enter the number of pairs:\n");
			scanf("%d", &n);
			if (n >= MIN_N && n <= MAX_N) // checks the define 
			{
				for (i = 1; i <= n; i++) //runs n times by entering n pairs 
				{
					printf("Please enter the larger number of pair %d (a)"
						":\n", i);
					scanf("%d", &a);
					printf("Please enter the smaller number of pair %d (b)"
						":\n", i);
					scanf("%d", &b);
					counter = counter + pairsNumber(a, b); // counts the paris, also prints the numbers when the condition works.
				}
				printf("The number of pairs satisfying the condition"
					" is: %d\n", counter);
			}
			printf("Please enter the mission number: \n");
			scanf("%d", &mission);
			break;
		}
		case 2: // mission 2
		{
			counter = 0;
			printf("Please enter the number: \n");
			scanf("%d", &n);
			if (n > MIN_NUMBER && n<MAX_NUMBER) // checks the define
			{
				printf("The sequence of numbers produced by the actions is:"
					"\n");
				numberPrint(n, funAction(n)); // function to prints all the numbers.
				counter = funAction(n); // functions to count the minimum number of steps
			}
			
			printf("The minimum number of moves is %d\n", counter);
			printf("Please enter the mission number:\n");
			scanf("%d", &mission);
			break;
		}
		case 3: // mission 3
		{
			counter = 0;
			printf("Please enter the number: \n");
			scanf("%d", &x);
			printf("The numbers are: \n");
			counter = biggestNum(x, 1, 0); // counts how many numbers the condition works for them, also prints them.
			printf("A total of %d numbers \n", counter);
			printf("Please enter the mission number: \n");
			scanf("%d", &mission);
			break;
		}
		case 4: // mission 4
		{
			i = 0, counter = 2, n=0;
			printf("Please enter the shape Alice chose:\n");
			scanf("%d", &AliceShape);
			printf("Please enter the shape Bob chose:\n");
			scanf("%d", &BobShape);
			if (BobShape == Spock) // important to know if bob started with spock
			{
				counter = 1;
			}
			printf("Please enter the number of rounds:\n");
			scanf("%d", &n);
			for (i = 0; i < n; i++) //runs n times 
			{
				condition = whoWins(AliceShape, BobShape); // checks who won/equal
				shapeOfYou(AliceShape); //prints alices's shape
				printf(" %c ", condition); // prints the charagter who won/eqauled
				shapeOfYou(BobShape); // prints bob's shape
				printf("\n");
				if (condition == '>')
				{
					count_Alice++; // counts the wins of alice
				}
				if (condition == '<')
				{
					count_Bob++; // counts the wins of bob
				}
				AliceShape = nextShapeAlice(AliceShape, condition, BobShape); // next shape of alice
				BobShape = nextShapeBob(BobShape, condition, counter); // next shape of bob
				counter++;
			}
			// printing who won, and how many ties were between them.
			if (count_Alice == count_Bob)
			{
				printf("Alice and Bob tie, each winning %d game(s) and "
					"tying %d game(s)\n", count_Alice,
					n - count_Alice - count_Bob);
			}
			else
			{
				if (count_Alice > count_Bob)
				{
					printf("Alice wins, by winning %d game(s) and tying "
						" %d game(s)\n",
						count_Alice, n - count_Alice - count_Bob);
				}
				else
				{
					printf("Bob wins, by winning %d game(s) and tying "
						" %d game(s)\n",
						count_Bob, n - count_Bob - count_Alice);
				}
			}
			printf("Please enter the mission number:\n");
			scanf("%d", &mission);
			break;
		}
		default:
			printf("");
		}
	} 
	return 0;
}
