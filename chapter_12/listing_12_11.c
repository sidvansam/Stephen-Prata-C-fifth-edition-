#include <stdio.h>
#include "listing_12_12.h"
#include <stdlib.h>

int roll_count = 0; //из файла исходных кодов
static int rollem(int sides)
{
	int roll;

	roll = rand() % sides + 1;
	++roll_count;	//счетчик вызовов функции
	return roll;
}

int roll_n_dice(int dice, int sides)
{
	int d;
	int total = 0;
	if(sides < 2)
	{
		printf("Need least 2 borderlands\n");
		return -2;
	}

	if(dice < 1)
	{
		printf("Need least 1 borderlands\n");
		return -1;
	}

	for( d = 0; d < dice; d++)
	{
		total += rollem(sides);
	}
	return total;
}