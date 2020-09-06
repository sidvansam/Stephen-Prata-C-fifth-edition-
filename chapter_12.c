#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEN 10
#define SIZE 100
#define SIZE1 1000

static unsigned long int next = 1; //начальное число
int mode;
float c;
float dst;
float qnt;

int rand(void)
{
	next = next * 11003515245 + 12345;
	return(unsigned int ) (next / 65536) % 32768;
}

int units = 0;
void critic(void)
{
	printf("You haven't luck! Try again.\n ");
	scanf("%d", &units);
}

int critic1(int a)
{
	printf("You haven't luck! Try again.\n ");
	scanf("%d", &a);
	return a;
}

void trystat(void)
{
	int fade = 1;
	static int stay = 1;    //static = обозначает компиляцию переменной один раз во время компиляции
							//и хранение в памяти её значения в предыдущую итерацию
	printf("fade = %d and stay = %d\n", fade++, stay++);
}

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

void get_info(void)
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

void show_info(void)
{
	if(c == 0)
		printf("Fuel consumption compose %f litres on 100 km.\n", (qnt / dst) * 100.0);
	if(c == 1)
		printf("Fuel consumption compose %f miles on gallon.\n", (dst / qnt));
}

int tms(void)
{
	static int times = 1;
	return times++; 
}

void print(int * arr, int s)
{
	for(int i = 0; i < s; i++)
		printf("Element %d: %d\n", i, *(arr + i));
}

void sort(int * arr, int s)
{
	int temp;
	for(int i = 0; i < s - 1; i++)
	{
		for(int n = i + 1; n < s; n++)
		{
			if(*(arr + n) >= *(arr + i))
			{
				temp = arr[i];
				arr[i] = arr[n];
				arr[n] = temp;
			}
		}
	}
}

int rollem(int sides)
{
    int roll;
    return roll = rand() % sides + 1;
}

int * make_array(int elem, int val)
{
	int * ptr;
	ptr = (int *) malloc(elem * sizeof(int));
	for(int i = 0; i < elem; i++)
	{
		//printf("%p\n", ptr + i);
		*(ptr + i) = val;
	}
	return ptr;
}

void show_array(const int * ar, int n)
{
	//printf("%p\n", ar);
	for (int i = 0; i < n; i++)
	{
		if(i % 8 == 0 && i != 0)
			printf("\n");
		//printf("%p\n", ar + i);
		printf("%d\t", *(ar + i));
	}
	printf("\n");
}

void listing_12_1(void)
{
	int x = 30;
	printf("x in exterior loop:%d\n", x);
	{
		int x = 77;
		printf("x in exterior block:%d\n", x);
	}

	printf("x in exterior loop:%d\n", x);
	while (x++ < 33)
	 	{
	 		int x = 100;
	 		x++;
			printf("x in loop:%d\n", x);
	 	}

	printf("x in exterior loop:%d\n", x);

	return;
}

void listing_12_2(void)
{
	int n = 10;
	printf("Primary n = %d\n", n);

	for (int n = 1; n < 3; n++)
		printf("loop 1: n = %d\n", n);
	printf("Upon completion loop 1: n = %d\n", n);

	for(int n = 1; n < 3; n++)
	{
		printf("Index of loop 2 n = %d\n", n);
		int n = 30;
		printf("loop 2 n = %d\n", n);
		n++;
	}
	printf("n in exterior loop 2 = %d\n", n);	

	return;
}

void listing_12_3(void)
{
	int count;
	for (count = 1; count <= 3; count++)
	{
		printf("Start iteration %d:\n", count);
		trystat();
	}
	return;
}

void listing_12_4(void)
{
	extern int units;
	printf("How much weight small keg of mell?\n");
	scanf("%d", &units);
	while(units != 56)
		critic();
	printf("You must check this!\n");

	return;
}

void listing_12_14(void)
{
	double * ptd;
	int max;
	int number;
	int i = 0;

	puts("Enter max lengt of elements type double: ");
	scanf("%d", &max);
	ptd = (double *) malloc(max * sizeof(double)); //умножение дает массив с заданным колличеством элементов

	if(ptd == NULL)
	{
		puts("Don't succeeded memory allotment!! Emergency completion!\n");
		exit(EXIT_FAILURE);
	}
	printf("Enter value or q for ending: ");
	while(i < max && scanf("%lf", &ptd[i]) == 1)
		i++;
	printf("Input %d elements\n", number = i);
	for(i = 0; i < number; i++)
	{
		printf("%7.2f", ptd[i]);
		if(i % 7 == 6)
			putchar('\n');
	}
	if (i % 7 != 0)
		putchar('\n');
	puts("Ending programm.");
	free(ptd);
	

	return;
}

void drill_1(void)
{
	int units1;
	printf("How much weight small keg of mell?\n");
	scanf("%d", &units);
	while(units1 != 56)
		units1 = critic1(units1);
	printf("You must check this!\n");

	return;
}

void drill_3(void)
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

void drill_4(void)
{
	int times;
	printf("Enter quantity of times: ");
	scanf("%d", &times);
	while(times > 0)
	{
		printf("The function has been called for %d times.\n", tms());
		times--;
	}
	
	return;
}

void drill_5(void)
{
	int array[SIZE];
	for(int i = 0; i < SIZE; i++)
	{
		array[i] = rand()%10 + 1;
		printf("%d\n", array[i]);
	}
	print(array, SIZE);
	sort(array, SIZE);
	printf("\n");
	print(array, SIZE);
	return;
}

void drill_6(void)
{
	int array[SIZE1];
	for(int i = 0; i < SIZE1; i++)
	{
		array[i] = rand()% TEN + 1;
		printf("%d\n", array[i]);
	}
	print(array, SIZE1);
	for(int i = 0; i < TEN; i++)
	{
		int count = 0;
		for(int s = 0; s < SIZE1; s++)
		{
			if (array[s] == i + 1 )
				count++;
		}
		printf("%d's = %d\n", i + 1, count);
	}
	return;
}

int drill_7(void)
{
    int dice, count, roll;
    int sides;
    int set, sets;

    srand((unsigned int) time(0));  /* randomize rand() */

    printf("Enter the number of sets; enter q to stop: ");
    while (scanf("%d", &sets) == 1)
    {
        printf("How many sides and how many dice?  ");
        if (scanf("%d %d", &sides, &dice) != 2)
        {
            puts("not integers -- terminating input loop.");
            break;
        }
        printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
        for (set = 0; set < sets; set++)
        {
            for (roll = 0, count = 0; count < dice; count++)
                roll += rollem(sides);
                /* running total of dice pips */
            printf("%4d ", roll);
            if (set % 15 == 14)
                putchar('\n');
        }
        if (set % 15 != 0)
            putchar('\n');
        printf("How many sets? Enter q to stop: ");
    }
    puts("GOOD FORTUNE TO YOU!\n");
    return 0;
}

void drill_8(void)
{
	int * pa; //pointer
	int size;
	int value;
	printf("Enter quantity of array's members: ");
	scanf("%d", &size);
	while(size > 0)
	{
		printf("Enter initial value ");
		scanf("%d", &value);
		pa = make_array(size, value);
		if(pa)
		{
			show_array(pa, size);
			free(pa);
		}
		printf("Enter Enter quantity of array's members (or value < 0 for termination): ");
		scanf("%d", &size);
	}
	printf("programm terminated!\n");
}

void main (void)
{
	//listing_12_1();
	//listing_12_2();	
	//listing_12_3();
	//listing_12_4();
	//listing_12_5();
	//listing_12_6();
	//listing_12_7();
	//listing_12_8();
	//listing_12_9();
	//listing_12_10();
	//listing_12_11();
	//listing_12_12();
	//listing_12_13();
	//listing_12_14();
	
	//drill_1();
	//drill_2();
	//drill_3();
	//drill_4();
	//drill_5();
	//drill_6();
	//drill_7();
	drill_8();
	//drill_9();
	
	return;
}