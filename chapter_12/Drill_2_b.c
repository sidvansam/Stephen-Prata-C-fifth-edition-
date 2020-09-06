#include <stdio.h>
#include "drill_2_a.h"

void main (void)
{
	int mode;
	printf("Enter 0 for choise metric system or 1 for choise USA system: ");
	scanf("%d", &mode);
	while(mode >= 0)
	{
		set_get(mode);
		get_info();
		show_info();
		printf("Enter 0 for choise metric system or 1 for choise USA system: ");
		scanf("%d", &mode);
	}
	printf("Ending programm.\n");

	return;
}

