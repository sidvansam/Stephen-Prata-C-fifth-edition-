#include <stdio.h>
#include <string.h>
//#include "hotel.h"

#define NAME "GIGATHINK, INC."
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, CA 94904"
#define WIDTH 40
#define SPACE ' '

int imax( int n, int m); //First time: int imax(n, m);

void starbar(void)
{
	int count;

	for (count = 1; count <= WIDTH; count++)
		putchar('*');
	putchar('\n');
}

void show_n_char(char ch, int num)
{
	int count;

	for (count = 1; count <= num; count++)
		putchar(ch);
}

int imin(int n, int m)
{
	/*int min;
	if (n < m)
		min = n;
	else 
		min = m;*/
	return (n < m) ? n : m;
}

int imax1(int n, int m)
{
	int max;
	if (n > m)
		max = n;
	else 
		max = m;
	return max;
}

int up_and_down(int n)
{
	printf("Level %d: cell n %p\n", n , &n);
	if (n < 4)
		up_and_down(n + 1);
	printf("LEVEL %d: cell n %p\n", n , &n);
}

long fact(int n)
{
	long ans;
	for (ans = 1; n > 1; n--)
		ans *= n;
	return ans;
}

long rfact(int n)
{
	long ans;
	
	if (n > 0)
		ans = n * rfact(n - 1);
	else 
		ans = 1;

	return ans;
}

void to_binary(unsigned long n)
{
	int r;
	r = n % 2;
	if (n >= 2)
		to_binary(n / 2);
	putchar( '0' + r );

	return ;
}

void mikado(int bah)
{
	int pooh = 10;
	printf("\nIn function mikado() pooh = %d and &pooh = %p\n", pooh, &pooh);
	printf("In function mikado() bah = %d and &bah = %p\n", bah, &bah);

	return ;
}

int interchange(int u,int v)
{
	int temp;
	printf("Fist time x = %d and y = %d.\n", u, v);
	temp = u;
	u = v;
	v = temp;
	printf("Now x = %d and y = %d.\n", u, v);

	return u;
}

void interchange1(int * u,int * v)//получает значение адреса переменных u и v
{
	int temp;	//инициализация переменной
	temp = *u; 	//декларация переменной temp значение переменной x
	*u = *v;	//присваиваем переменной x значение y
	*v = temp;	//присваивание переменной y значение x ранее присвоеной переменой temp
}

double min(double *x, double *y)
{
	if (*x > *y)
		return *x;
	else 
		return *y;
}

void chline(char ch, int i, int j)
{
	int k;

	for (k = 0; k < i; k++)
		printf(" ");
	for (k = i; k < j; k++)
		printf("%c", ch);
}

void chline1(char ch, int i, int j)// 
{
	for (int k = 0; k < j; k++)
	{
		for (int l = 0; l < i; l++)
			printf("%c ", ch);
		printf("\n");
	}
}

double harm_avarage(double a, double b)
{
	return 2 / (1 / a + 1 / b);
}

double max_value(double * a, double * b)// принимаем указатели на адреса
{
	if (*a > *b)
		return *b = *a;
	else if (*b > *a)
		return *a = *b;
}

void number_in_alphabet(char ch)
{
	if (ch >= 65 && ch <= 90)
		printf("number in alphabet = %d\n", ch - 64);
	else if (ch >= 97 && ch <= 122)
		printf("number in alphabet = %d\n", ch - 96);
	else if (ch != '\n')
		printf("\n[%c] = %d\n", ch, 1);
}

double power(double n, int p)
{
	double pow1 = 1;
	int l = p;

	if (p < 0)
		p *= -1;

	for (int i = 1; i <= p; i++)
		pow1 *= n;
	if (l < 0 && n != 0)
		pow1 = 1 / pow1;
	else if (n == 0)
		pow1 = 0;

	return pow1;
}

void power1(double n, int p, double pow2)
{
	if ( n == 0 && p < 0)
		printf("ERROR!!!");
	else if( p == 0 )
		printf("1");
	else if (p < 0)
	{
		pow2 = pow2 * (1 / n);
		++p;
		power1(n, p, pow2);
		if (p == 0)
		{
			printf("\b%.3g", pow2);
		}
	}
	else if (p > 0)
	{
		pow2 *= n;
		p--;
		power1(n, p, pow2);
		if (p == 0)
			printf("\b%.3g", pow2);
	}

	return;
}

void to_binary1(unsigned long n, int b)
{
	int r;
	r = n % b;
	if (n >= b)
		to_binary1(n / b, b);
	putchar( '0' + r );

	return ;
}

void Fibonacci(int n)
{
	printf("First %d members of Fibonacci number = 1 ", n);
	unsigned long second = 1;
	for (unsigned long first = 1; n > 1; n--)
	{
		if ((n % 2) == 0)
			printf("%lu ", first += second );
		else if((n % 2) == 1)
			printf("%lu ", second += first );
	}
	printf("\n");
}

void listing_9_1(void)
{
	starbar();
	printf("%s\n", NAME);
	printf("%s\n", ADDRESS);
	printf("%s\n", PLACE);
	starbar();

	return;
}

void listing_9_2(void)
{
	int spaces;

	show_n_char('*', WIDTH);

	putchar('\n');
	show_n_char(SPACE, 12);

	printf("%s\n", NAME);
	spaces = (WIDTH - strlen(ADDRESS)) / 2;

	show_n_char(SPACE, spaces);

	printf("%s\n", ADDRESS);
	show_n_char(SPACE, (WIDTH - strlen(PLACE)) / 2);

	printf("%s\n", PLACE);
	show_n_char('*', WIDTH);
	putchar('\n');

	return;
}

void listing_9_3(void)
{
	int evil1, evil2;

	printf("Enter two integer numbers (q - for ending programm):\n");
	while (scanf("%d%d", &evil1, &evil2) == 2)
	{
		printf("%d %d\n", evil1, evil2);
		printf("Minor numbers out of %d and %d is %d.\n",
			evil1, evil2, imin(evil1, evil2));
		printf("Enter two integer numbers (q - for ending programm):\n");
	} 
	printf("End of programm!\n");

	return;
}

/*void listing_9_4(void)
{
	printf("Upper-range value out of %d and %d is %d.\n", 3, 5 , imax(3));
	printf("Upper-range value out of %d and %d is %d.\n", 3, 5 , imax(3.0, 5.0));
	
	return;
}*/

void listing_9_5(void)
{
	printf("Upper-range value out of %d and %d is %d.\n", 3, 5 , imax1(3 , 5));
	printf("Upper-range value out of %d and %d is %d.\n", 3, 5 , imax1(3.0, 5.0));
	
	return;
}

void listing_9_6(void)
{
	up_and_down(1);
	return;
}

void listing_9_7(void)
{
	int num;

	printf("This programm calculate factorials.\n");
	printf("Enter numbers in range 0 - 12 (or q for ending programm): \n");
	while (scanf("%d", &num) == 1)
	{
		if (num < 0)
			printf("Please, don't enter signed numbers.\n");
		else if (num > 12)
			printf("Enrer value must be lower than 13.\n");
		else 
		{
			printf("Iteration: factorial %d! = %ld\n", num, fact(num));
			printf("Recursion: factorial %d! = %ld\n", num, rfact(num));
		}
	}
	return;
}

void listing_9_8(void)
{
	unsigned long number;
	printf("Enter integer number (or q for ending programm):\n");
	while(scanf("%lu", &number) == 1)
	{
		printf("Binary equivalent: 0");
		to_binary(number);
		putchar('\n');
		printf("Enter integer number (or q for ending programm):\n");
	}
	printf("Ending programm!\n");

	return;
}

/*
void listing_9_9(void)
{
	int nights;
	double hotel_rate;
	int code;

	while((code = menu()) != QUIT)
	{
		switch(code)
		{
			case 1: hotel_rate = HOTEL1;
					break;
			case 2: hotel_rate = HOTEL2;
					break;
			case 3: hotel_rate = HOTEL3;
					break;
			case 4: hotel_rate = HOTEL4;
					break;
			default: hotel_rate = 0.0;
					 printf("Error!\n");
					 break;
		}
		nights = getnights();
		showprice(hotel_rate, nights);
	}
	printf("Thank you for using and wish good speed!\n");
	return;
}

void listing_9_10(void)
{
	
	
	return;
}

void listing_9_11(void)
{
	
	
	return;
}
*/

void listing_9_12(void)
{
	int pooh = 2, bah = 5;
	printf("In function main() pooh = %d and &pooh = %p\n", pooh, &pooh);
	printf("In function main() bah = %d and &bah = %p\n", bah, &bah);

	mikado(pooh);
	
	return;
}

void listing_9_13(void)
{
	int x = 5, y = 10;
	printf("Fist time x = %d and y = %d.\n", x, y);
	x = interchange(x, y);
	printf("Now x = %d and y = %d.\n", x, y);

	return;
}

void listing_9_14(void)
{
	int x = 5, y = 10;
	printf("Fist time x = %d and y = %d.\n", x, y);
	x = interchange(x, y);
	printf("Now x = %d and y = %d.\n", x, y);

	return;
}

void listing_9_15(void)
{
	int x = 5, y = 10;
	printf("Fist time x = %d and y = %d.\n", x, y);
	interchange1(&x, &y);//в функцию поступают значения адресов переменных u и v
	printf("Now x = %d and y = %d.\n", x, y);

	return;
}

void drill_1(void)
{
	char ch;
	double x, y;
	printf("Enter two float numbers: ");
	while (scanf("%lf %lf", &x, &y) != 2) // принимает только целочисленные значения
		{
			while((ch = getchar()) != '\n')
				putchar(ch);
			printf(" no is number!.\n");
			printf("Please enter int number like 25, -178  or 3: ");
		}

	printf("The biggest number is %.2lf.\n", min(&x, &y));

	return;
}

void drill_2(void)
{
	char ch, n;
	int i, j;
	printf("Enter one character and 2 integer numbers: \n");
	printf("First enter one character: \n");

	ch = getchar();
	while (getchar() != '\n')// принимает только первый символ из строки
		continue;
	printf("Use character [%c].\n", ch);

	printf("Now enter 2 integer numbers: \n");
	while (scanf("%d %d", &i, &j) != 2) // принимает только целочисленные значения
	{
		while((n = getchar()) != '\n')
			putchar(n);
		printf(" no is integer!.\n Please ");
		printf("enter int number like 25, -178  or 3: ");
	}

	chline(ch, i, j);

	return;
}

void drill_3(void)
{
	char ch, n;
	int i, j;
	printf("Enter one character and 2 integer numbers: \n");
	printf("First enter one character: \n");

	ch = getchar();
	while (getchar() != '\n')// принимает только первый символ из строки
		continue;
	printf("Use character [%c].\n", ch);

	printf("Now enter 2 integer numbers: \n");
	while (scanf("%d %d", &i, &j) != 2) // принимает только целочисленные значения
	{
		while((n = getchar()) != '\n')
			putchar(n);
		printf(" no is integer!.\n Please ");
		printf("enter int number like 25, -178  or 3: ");
	}

	chline1(ch, i, j);

	return;
}

void drill_4(void)
{
	char ch;
	double x, y;
	printf("Enter two float numbers: ");
	while (scanf("%lf %lf", &x, &y) != 2) // принимает только целочисленные значения
		{
			while((ch = getchar()) != '\n')
				putchar(ch);
			printf(" no is number!.\n");
			printf("Please enter int number like 25, -178  or 3: ");
		}

	printf("Harmonic average is %.2lf.\n", harm_avarage(x, y));

	return;
}

void drill_5(void)
{
	char ch;
	double x, y;
	printf("Enter two float numbers: ");
	while (scanf("%lf %lf", &x, &y) != 2) // принимает только целочисленные и дроюные значения
		{
			while((ch = getchar()) != '\n')
				putchar(ch);
			printf(" no is number!.\n");
			printf("Please enter int number like 25, -178  or 3: ");
		}
	max_value(&x, &y); //посылаем значения адресов (& - операция передачи адресов в функцию)

	printf("x = %.2lf	y = %.2lf.\n", x, y);

	return;
}

void drill_6(void)
{
	char ch;
	while((ch = getchar()) != EOF)
	{
		if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
			printf("[%c] this is a symbol, ", ch);
		number_in_alphabet(ch);
	}

	return;
}

void drill_7(void)
{
	double x, xpow;
	int exp1;

	printf("Enter number and unsigned integer power,");
	printf(" involving\nnumber. For programm end enter [q].\n");

	while (scanf("%lf%d", &x, &exp1) == 2)
	{
		xpow = power(x, exp1);
		printf("%.3g in power %d is %.5g\n", x, exp1, xpow);
		printf("Enter next number or [q] for end programm.\n");		
	}

	printf("Hope you are fulfill!\n");

	return;
}

void drill_8(void)
{
	double x, xpow;
	int exp1;

	printf("Enter number and unsigned integer power,");
	printf(" involving\nnumber. For programm end enter [q].\n");

	while (scanf("%lf%d", &x, &exp1) == 2)
	{
		double pow1 = 1;
		printf("%.3g in power %d is ", x, exp1);
		power1(x, exp1, pow1);
		printf("\nEnter next number or [q] for end programm.\n");		
	}

	printf("Hope you are fulfill!\n");

	return;
}

void drill_9(void)
{
	unsigned long number;
	int number_system;
	printf("Enter integer numbers:\n"
	"First is a number, second is a number base (or q for ending programm)\n");
	while(scanf("%lu %d", &number, &number_system) == 2 )
	{
		printf("Equivalent of number %lu for number base %d = [",number, number_system );
		to_binary1(number, number_system);

		printf("]\n\n");
		printf("Enter next numbers:\n"
		"First is a number, second is a number base (or q for ending programm)\n");
	}
	printf("Ending programm!\n");

	return;
}

void drill_10(void)
{
	char ch;
	int quantity, i;
	printf("Enter quantity of numbers Fibonacci [or Ctrl + C for ending]: ");
	while (1) // принимает только целочисленные значения
		{
			i = (scanf("%d", &quantity));
			if (i == 0 || quantity == 0)
			{
				while((ch = getchar()) != '\n')
					putchar(ch);
				printf(" no is integer number!.\n");
				continue;			
			}
			else if (i == 1)
				Fibonacci(quantity);	
		}
	printf("Ending programm!\n");

	return;
}

void drill_11(void)
{
	double n, b = 0;
	int c = 0;
	printf("Enter float number (or some character for ending): ");
	while(scanf("%lf",&n) != 0)
	{
		c++;
		b += 1 / n; 
		printf("Enter float number (or some character for ending): ");
	}
	printf("Harmonic average is %.2lf.\n", c / b);

	return;
}

void main (void)

{
	//listing_9_1();
	//listing_9_2();
	//listing_9_3();
	//listing_9_4();
	//listing_9_5();
	//listing_9_6();
	//listing_9_7();
	//listing_9_8();
	//listing_9_9();
	//listing_9_10();
	//listing_9_11();
	//listing_9_12();
	//listing_9_13();
	//listing_9_14();
	//listing_9_15();


	//drill_1();
	//drill_2();
	//drill_3();
	//drill_4();
	//drill_5();
	//drill_6();
	drill_7();
	//drill_8();
	//drill_9();
	//drill_10();
	//drill_11();
	
	return;
}

int imax(n, m)
int n, m;
{
	int max;
	if (n > m)
		max = n;
	else 
		max = m;
	return max;
}