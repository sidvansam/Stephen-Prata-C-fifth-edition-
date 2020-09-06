#include <stdio.h>
#include <stdlib.h>	//для библиотечной функции srand() 
#include <time.h>	//для функции time
#include "listing_12_12.h"	//для функции roll_n_dice и для переменной roll_count

int main(void)
{
	int dice, roll;
	int sides = 1;
	srand((unsigned int) time(0)); //рандомизация начального числа
	printf("Enter quantity of sides or [0] for end programm.\n");
	while (((scanf("%d", &sides)) == 1) && sides > 0);
	{
		printf("How much sides need?\n");
		scanf("%d", &dice);
		roll = roll_n_dice(dice, sides);
		printf("You throu %d times use %d %d-siding bones.\n", roll, dice, sides);
		printf("How much sides should be?\n");
	}
	printf("Function rollem() was call %d times!\n", roll_count);
	printf("Good luck!\n");
	return 0;
}

