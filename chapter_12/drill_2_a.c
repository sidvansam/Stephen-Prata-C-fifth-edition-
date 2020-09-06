#include <stdio.h>
extern int mode;
static float c;
static float dst;
static float qnt;

void set_get(int c);
void get_info(void);
void show_info(void);

void set_get(int mode)
{
	//printf(" mode = %d\n", mode);
	c = mode;
	if(c > 1)
	{
		printf("Wrong operation! By default use USA system.\n");
		c = 1;
	}

	if(c < 0)
		return;
}

void get_info()
{
	if(c == 0)
		printf("Enter kilometric distance: ");
	if(c == 1)
		printf("Enter mile distance: ");
	
	scanf("%f", &dst);

	if(c == 0)
		printf("Enter quantity of fuel in litres: ");
	if(c == 1)
		printf("Enter quantity of fuel in gallons:");
	
	scanf("%f", &qnt);
}

void show_info()
{
	if(c == 0)
		printf("Fuel consumption compose %f litres on 100 km.\n", (qnt / dst) * 100.0);
	if(c == 1)
		printf("Fuel consumption compose %f miles on gallon.\n", (dst / qnt));
}


