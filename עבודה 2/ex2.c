/******************************************
*Student name: Eitan Kerzhner
*Student ID:205697139
*Exercise name: ex2
******************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_TEMP 37
#define MIN_TEMP 10
enum weather { HOT = 30, NORMAL = 20, COLD = 10 };
/*the main program gets a number into 'operator', then entering the mission the
 mission by the input. for 
 input 1 is the structure check
 input 2 is the calculator
 input 3 is the avarage weather.
 if the operator is not 1,2,3 then it ends the program.*/
main()
{
	int operator, num1, num2; //operator-function, num1,num2-calculator
	char key1, key2, key3, key4, key, dummy, temp = 0; /*key1,key2,key3,key4
	-structure inputs, key-calculator operator, dummy-correct input,
	temp=weather checker*/
	float temp1, temp2, temp3, temp4, sum, avg;/*temp1,temp2,temp3,temp4-season
	temprture inputs, sum-calculator sum for function, avg-avarage temprature*/ 
	enum weather hot, normal, cold;//enum function hot normal cold
	hot = HOT;
	normal = NORMAL;
	cold = COLD;
	printf("Please choose an option:\n"); //entering operation
	scanf("%d", &operator);
	switch (operator)//
	{
	case 1:	//structure check - option 1 
	{
		printf("Please enter four chars: \n");/*input for the chars, dummy
		for avoid input problems*/
		scanf("%c\t%c\t%c\t%c\t%c", &dummy, &key1, &key2, &key3, &key4);
		//checking if the inputs are correct. 
		if ((key1 != 'a') && (key1 != '(') && (key1 != ')') && (key1 != '[') 
			&& (key1 != ']')) //key1 is correct
		{
			printf("Invalid input\n");//"invalid input" output	
		}
		else
		{
			if ((key2 != 'a') && (key2 != '(') && (key2 != ')') 
				&& (key2 != '[') && (key2 != ']')) //key2 is correct
			{
				printf("Invalid input\n");//"invalid input" output
			}
			else
			{
				if ((key3 != 'a') && (key3 != '(') && (key3 != ')')
					&& (key3 != '[') && (key3 != ']'))//key3 is correct
				{
					printf("Invalid input\n");//"invalid input" output
				}
				else
					if ((key4 != 'a') && (key4 != '(') && (key4 != ')')
						&& (key4 != '[') && (key4 != ']'))//key4 is correct
					{
						printf("Invalid input\n");//"invalid input" output
					}
					else //all inputs are correct - checking the structure.
					{
						switch (key1)
						{
						case 'a'://first char is 'a'
						{
							if (key2 == 'a')//check if key 2 is 'a'
							{/*check if key3 and key 4 are in the correct
							 structure*/
								if (((key3 == 'a') && (key4 == 'a')) 
									|| ((key3 == '(') && (key4 == ')')))
								{
									printf("Ok\t");//good strcture
								}
								else
								{
									printf("Bad Structure\n");//"bad structure" 
								}
							}
							else //key2 != 'a', checking if it's '('
							{
								if (key2 == '(')
								{/*check if key3 and key 4 are in the correct
								 structure*/
									if (((key3 == ')') && (key4 == 'a')) 
										|| ((key3 == 'a') && (key4 == ')'))) 
										
									{
										printf("Ok\t");//good strcture
									}
									else
									{
										printf("Bad Structure\n");/*"bad 
									    structure"*/
									}
								}
								else //in case key 2 != '(' or 'a'
								{
									printf("Bad structure\n");//"bad structure" 
								}
							}
							break;
						}
						case '(': //first char is '('
						{
							if (key2 == 'a') //check if key2 is 'a'
							{/*check if key3 and key 4 are in the correct 
							 structure*/
								if (((key3 == 'a') && (key4 == ')')) 
									|| ((key3 == ')') && (key4 == 'a'))) 
								{
									printf("Ok\t");//good strcture
								}
								else
								{
									printf("Bad Structure\n");//"bad structure" 
								}
							}
							else //if key2 != 'a', checking if it's ')'
							{
								if (key2 == ')')
								{/*check if key3 and key 4 are in the
								 correct structure*/
									if (((key3 == '(') && (key4 == ')')) 
										|| ((key3 == 'a') && (key4 == 'a')))//
									{
										printf("Ok\t");//good strcture
									}
									else
									{
										printf("Bad Structure\n");/*"bad 
							            structure"*/ 
									}
								}
								else //in case key 2 != 'a' or ')'
								{
									printf("Bad Structure\n");//"bad structure"
								}
							}
							break;
						}
						case '[': // key1 is '['
						{/*check if key2, key3 and key 4 are in the correct 
						 structure - only one optiong is correct*/
							if ((key2 == '(') && (key3 == ')') 
								&& (key4 == ']'))
							{
								printf("Ok\t"); //good structure 
							}
							else
							{
								printf("Bad Structure\n"); //"bad structure" 
							}
							break;
						}
						default:
							printf("Bad Structure\n"); //"bad structure" 
						}
					}
			}

		}
		break;
	}
	case 2: //calculator - option 2
	{	
		printf("Please enter first number: \n"); //num1 input
		scanf("%d", &num1);
		printf("Please enter second number: \n"); //num2 input
		scanf("%d", &num2);
		printf("Please enter operator: \n"); //key inout for function
		scanf("%c%c", &dummy, &key);
		if ((key != '+') && (key != '-') && (key != '*') && (key != '/')
			&& (key != '%')) //checking correct key
		{
			printf("Invalid input\n");//"invalid input" output
		}
		else //if key correct - entering calculator
		{
			switch (key)
			{

			case '+':
			{
				sum = (float)num1 + num2;
				//output for num1+num2
				printf("The result is: %7.2f \n", sum);
				break;
			}
			case '-':
			{
				sum = (float)num1 - num2;
				//output for num1-num2
				printf("The result is: %7.2f \n", sum);
				break;
			}
			case '*':
			{
				sum = (float)num1 * num2;
				//output for num1*num2
				printf("The result is: %7.2f \n", sum);
				break;
			}
			case '/':
			{
				if (num2 != 0) //checking if num2!=0, ca't devide by 0
				{
					sum = (float)num1 / num2;
					//output for num1/num2
					printf("The result is: %7.2f \n", sum);
				}
				else
				{
					printf("Invalid input\n");//"invalid input" output
				}
				break;
			}
			case '%':
			{
				if (num2 != 0)  //checking if num2!=0, can't devide by 0
				{
					sum = num1 % num2;
					//output for num1%num2
					printf("The result is: %7.2f \n", sum);
				}
				else
				{
					printf("Invalid input \n");//"invalid input" output
				}
				break;
			}
			default:
			{
				printf("Invalid input \n");//"invalid input" output
			}
			}
		}
		break;
	}
	case 3: //weather - option 3
	{
		printf("Please enter the average temperature per season: \n");
		//input of season avareges
		scanf("%f%f%f%f", &temp1, &temp2, &temp3, &temp4);
		//checking seassin that all input are between 10-37
		if (temp1<MIN_TEMP || temp1>MAX_TEMP) 
			//checking key1 is between 10-37
		{
			printf("invalid input\n");//"invalid input" output
		}
		else
		{   //checking key2 is between 10-37
			if (temp2<MIN_TEMP || temp2>MAX_TEMP)
			{
				printf("invalid input \n");//"invalid input" output
			}
			else
			{   //checking key3 is between 10-37
				if (temp3<MIN_TEMP || temp3>MAX_TEMP)
				{
					printf("invalid input\n");//"invalid input" output
				}
				else
				{   //checking key4 is between 10-37
					if (temp4<MIN_TEMP || temp4>MAX_TEMP)
					{
						printf("invalid input\n");//"invalid input" output
					}
					else
					{   //all inputs correct - make an avarage.
						avg = (temp1 + temp2 + temp3 + temp4) / 4; 
					}
				}
			}
		}
		//input for char temp by the avarage temprature
		if (avg >= hot)//if avarage is 30-37
		{
			temp = 'H';
		}
		else
			if (avg >= normal)//if avarge if 20-30
			{
				temp = 'N';
			}
			else
				if (avg >= cold)//if avarge is 10-20
				{
					temp = 'C';
				}
		switch (temp)//using tem as the switch case
		{
		case 'H'://in case avarge temprature is hot (between 30-37)
		{
			printf("This year the weather was hot \n");//cold weather 
			printf("Estimated average: %7.2f \n", avg);//estemated weather 
			break;
		case 'N'://in case avarge temprature is normal (between 20-30)
		{
			printf("This year the weather was normal \n");//normal weather 
			printf("Estimated average: %7.2f \n", avg);//estemated weather 
		}
		break;
		case 'C'://in case avarge temprature is cold (between 10-20)
		{
			printf("This year the weather was cold \n");//cold weather 
			printf("Estimated average: %7.2f \n", avg); //estemated weather 
		}
		break;
		default:
			printf("");
		}
		}
	}
	break;
	default:
		printf("Invalid input \n");//"invalid input" output
	}
	return 0;//end of program
}

