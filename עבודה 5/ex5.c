/******************************************
*Student name: Eitan Kerzhner
*Student ID:205697139
*Submit Info:kerzhne
*Exercise name: ex5
******************************************/

#include "Mission1.h"
#include "Mission2.h"
#include "Mission3.h"
#include "Mission4.h"
#include "Mission5.h"

void main()
{
	int missionNum;						// The mission number
	printf("Please enter the mission number:\n");
	scanf("%d", &missionNum);			// Reading the mission number

	while (missionNum <= 5 && missionNum >= 1)
	{
		switch (missionNum)
		{
		case 1: Mission1();				// Run the appropriate mission 1
			break;
		case 2: Mission2();				// Run the appropriate mission 2
			break;
		case 3: Mission3();				// Run the appropriate mission 3
			break;
		case 4: Mission4();				// Run the appropriate mission 4
			break;
		case 5: Mission5();				// Run the appropriate mission 5
			break;
		}
		printf("Please enter the mission number:\n");
		scanf("%d", &missionNum);		// Reading the mission number
	}
}