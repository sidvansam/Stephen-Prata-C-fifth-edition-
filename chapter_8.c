#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define TIME 40.0
#define TARIFE 10.0
#define STOP1 (TIME * TARIFE)
#define DUTY1 300
#define DUTY2 450
#define PERSENT1 0.15
#define PERSENT2 0.2
#define PERSENT3 0.05
#define TAX1 (DUTY1 * PERSENT1)
#define TAX2  (TAX1 + ((DUTY2 - DUTY1) * PERSENT2))
#define RAISE 1.5

#define LIMIT 5
#define SIZE 1000

const int MIN = -1000;
const int MAX = +1000;

void menu(void)
{
	printf("*********************************************************\n");
	printf("Enter number, corresponding rate for salary or action:\t*\n");
	printf("a) $8.74 per hour\tb) $9.33 per hour\t\t*\n");
	printf("c) $10.00 per hour\td) $11.20 per hour\t\t*\n");
	printf("e) Exit\t\t\t\t\t\t\t*\n");
	printf("*********************************************************\n");
	return;
}

void menu8_8(void)
{
	printf("Enter operation:\n");
	printf("a) addition\ts) substraction\n");
	printf("i) incriase\tp) partition\n");
	printf("e) Exit\n");
	return;
}

float get_f(int i)
{
	float a;
	char ch;
	if (i == 1)
		printf("Enter first nomber: ");
	else if (i == 2)
		printf("Enter second nomber: ");
	
	while (scanf("%f", &a) != 1)
	{
		while((ch = getchar()) != '\n')
			putchar(ch);
		if (ch == '\n')
			ch = ' ';
		printf("%cno is integer!\nPlease ", ch);
		printf("enter int number like 25, -178  or 3: ");
	}
	return a;
}

void operation(char ch)
{
	int i = 1;
	float a, b;
	a = get_f(i);
	i++;
	b = get_f(i);
	switch(ch)
	{
		case 'a' : printf("\n%.2f + %.2f = %.2f\n", a, b, a + b);
			break;
		case 's' : printf("\n%.2f - %.2f = %.2f\n", a, b, a - b);
			break;
		case 'i' : printf("\n%.2f * %.2f = %.2f\n", a, b, a * b);
			break;
		case 'p' : printf("\n%.2f / %.2f = %.2f\n", a, b, a / b);
			break;
	}
}

char getfirst(void)
{
	char ch;
	ch = getchar();

	while (getchar() != '\n')
		continue;
	return ch;
}

char getfirst1(void)
{
	char ch;
	while(isspace(ch = getchar()));

	while (getchar() != '\n')
		continue;		
	
	return ch;
}

char get_choice1(void)
{
	char ch;
	printf("Enter letter of your choise:\n");
	printf("a) Advice\t b) Ring\n");
	printf("c) Count\t d) EXIT\n");
	ch = getfirst1();
	while( ch != 'a' && ch != 'b' && ch != 'c' && ch != 'd')
	{
		printf("Choise a, b , c or d.\n");
		ch = getfirst1();
	}

	return ch;
}

int get_int2(void)
{
	int input;
	char ch;
	while (scanf("%d", &input) != 1)
	{
		while((ch = getchar()) != '\n')
			putchar(ch);
		printf(" no is integer!.\n Please ");
		printf("enter int number like 25, -178  or 3: ");
	}
	return input;
}

void count(void)
{
	int n, i;
	printf("Count before which limit? Enter integer number: \n");
	n = get_int2();
	for (i = 1; i <= n; i++)
		printf("%d\n", i);
	while(getchar() != '\n')
		continue;
}

char get_choice(void)
{
	char ch;
	printf("Enter letter of your choise:\n");
	printf("a) Advice\t b) Ring\n");
	printf("c) Count\t d) EXIT\n");
	ch = getfirst();
	while( ch != 'a' && ch != 'b' && ch != 'c' && ch != 'd')
	{
		printf("Choise a, b , c or d.\n");
		ch = getfirst();
	}

	return ch;
}

double sum_squares (int a, int b) 
{ 
	double  total = 0; 
	int i; 
	for (i = a; i <= b; i++) 
		total += i * i; 
	return total;
} 

_Bool bad_limits (int begin, int end, int low, int high) 
{ 
	_Bool not_good = false;
	if (begin > end)
	{
		printf("%d no less than %d.", begin, end);
		not_good = true;
	} 

	if (begin < low || end < low)
	{
		printf("Values must be equal %d or more.", low);
		not_good = true;
	} 

	if (begin > high || end > high)
	{
		printf("Values must be equal %d or more.", high);
		not_good = true;
	} 
	return not_good;
}

int get_int(void)
{
	int input;
	char ch;
	while (scanf("%d", &input) != 1)
	{
		while ((ch = getchar()) != '\n')
			putchar(ch);
		printf("No integer number.\n"
			   "Please enter new limit like 25, -178 or 3:");
	}

	return input;
} 

void dislay(char ch, int lines, int width)
{
	int row, col;
	for (row = 1; row <= lines; row++ )
	{
		for (col = 1; col <= width; col++ )
			putchar(ch);
		putchar('\n'); //закончить строку и начать новую
	}
	return;
}

int binary(int a, int guess)
{
	
	char response;
	printf("The number more or lower than %d?\n", guess);
	printf("[m] - for more, [l] - for lower\n");

	while((response = getchar()))
	{
		while (getchar() != '\n') //пропуск оставшейся части строки! читается только первый символ
			continue;
		
		if (response == 'm')
		{
			guess += a;
			break;
		}

		else if (response == 'l')
		{
			guess -= a;
			break;
		}	
		else				
			printf("Unfortunately I understand only 'l' or 'm'.\n");
	}
	return guess;
}

void listing_8_1(void)
{
	char ch;
	while((ch = getchar()) != '#')
		putchar(ch);

	return;
}

void listing_8_2(void)
{
	char ch;
	while((ch = getchar()) != EOF)
		putchar(ch);

	return;
}

void listing_8_3(void)
{
	int ch;
	FILE * fp;
	char fname [50];
	printf("Enter name of file: ");
	scanf("%s", fname);
	fp = fopen(fname, "r");
	if (fp == NULL)
	{
		printf("No puede abrir file! Terminacion de programma!\n");
		exit(1);
	}

	while( (ch = getc(fp) != EOF))
		putchar(ch);
	fclose(fp);


	return;
}

void listing_8_4(void)
{
	int guess = 1;
	char response;

	printf("Elige one number between 1 and 100. I try guess ");
	printf("it.\n Click setter 'y' if my guess us true and ");
	printf("setter 'n' otherwise.\n");
	printf("Your number is %d? \n", guess);
	while((response = getchar()) != 'y')
	{
		if (response == 'n')
			printf("Your number is %d?\n", ++guess);
		else 
			printf("Unfortunately I understand only 'y' and 'n'.\n");

		while (getchar() != '\n') //пропуск оставшейся части строки! читается только первый символ
			continue;
	}	

	printf("I known what I can!!!\n");

	return;
}

void listing_8_5(void)
{
	int ch;
	int rows, cols;

	printf("Enter character and two int number;\n");
	while((ch = getchar()) != '\n')
	{
		scanf("%d %d", &rows, &cols);
		dislay(ch, rows, cols);
		printf("Enter next character and two int number;\n");
		printf("enter character of new line for ending programm.\n");

	}
	printf("End of programm!\n");

	return;
}

void listing_8_6(void)
{
	int ch;
	int rows, cols;

	printf("Enter character and two int number;\n");
	while((ch = getchar()) != '\n') // если ввели новую строку в вводе символа программа закрывается
	{
		if (scanf("%d %d", &rows, &cols) != 2)
			break;

		dislay(ch, rows, cols);

		while (getchar() != '\n') //пропускает символ новой строки после воода даных
			continue;

		printf("Enter next character and two int number;\n");
		printf("enter character of new line for ending programm.\n");

	}
	printf("End of programm!\n");

	return;
}

void listing_8_7(void)
{
	int start;
	int stop;
	double answer;

	printf("This programm count sum of squares int numbers"
		   "fron -1000 to 1000.\nEnter limit of range (0 for end):\n"
		   "\tLow limit: ");
	start = get_int();
	printf("\tUpper limit: ");
	stop = get_int();
	while (start != 0 || stop != 0)
	{
		if (bad_limits(start, stop, MIN, MAX))
			printf("Please repeate attampt!\n");
		else 
		{
			answer = sum_squares(start, stop);
			printf("Sum of squares "
				   " from %d to %d = %g\n", start, stop, answer);
		}
		printf("This programm count sum of squares int numbers"
		   "fron -1000 to 1000.\n Enter limit of range (0 for end):\n"
		   "\tLow limit: ");

		start = get_int();
		printf("\tUpper limit: ");
		stop = get_int();
	}
	printf("End of programm!\n");
	return;
}

void listing_8_8(void)
{
	int choice;
	while ((choice = get_choice()) != 'd')
	{
		switch(choice)
		{
			case 'a': printf("Buy cheap, sell costly!\n");
					break;
			case 'b': putchar('\a');
					break;
			case 'c': count();
					break;
			default : printf("Program ERROR!\n");
					break;										
		}
	}
	printf("Cheerio!");
	return;
}

void drill_1(void)
{
	int i = 0;
	while(getchar() != EOF)
		i++;
	printf("Quantity of characters before EOF = [%d].\n", i);

	return;
}

void drill_2(void)
{
	char ch;
	int i = LIMIT, l;
	char chars[SIZE];
	for(l = 0; (ch = getchar()) != EOF && l < SIZE; l++ ) 
	{
		if (l == SIZE - 1)
			ch = EOF;
		chars[l] = ch;
	}

	int k = 0;
	ch = chars[k];
	while (k < l)
	{
		if (i == 0 )
		{
			i = LIMIT;
			printf("\n");
		}

		if (ch == '\n')
		{
			i = 0;
			printf("[\\n] = %d", ch);
		}
		else if (ch == '\t')
		{
			printf("[\\t] = %d\t", ch);
			i--;
		}
		else if (i >= 0)
		{
			printf("[%c] = %d\t", ch, ch);
			i--;
		}
		k++;
		ch = chars[k];
	}

	return;
}

void drill_3(void)
{
	char ch;
	int uppercase = 0, lowercase = 0;  
	while ((ch = getchar()) != EOF)
	{
		if(ch >= 65 && ch <= 90)
			uppercase++;
		else if (ch >= 97 && ch <= 122)
			lowercase++;
		else ;
	}
	printf("characters of uppercase = %d;\n", uppercase);
	printf("characters of lowercase = %d;\n", lowercase);

	return;
}

void drill_4(void)
{
	char ch;
	int chars = 0, words = 0;
	_Bool inword = false, outword = true;
	while((ch = getchar()) != EOF)
	{
		if((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
		{
			inword = false;
		}
		else if (inword == false)
		{
			words++;
			inword = true;
		}
		if((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
			chars++;

	}
	printf("Quantity of characters = %d\n", chars);
	printf("Quantity of words = %d\n", words);
	printf("Avarage of letter for word = %d\n", chars / words);

	return;
}

void drill_5(void)
{
	int guess = 100, a;
	char response;
	printf("Elige one number between 1 and 100. I try guess ");
	printf("it.\n Click setter 'y' if my guess us true and ");
	printf("setter 'n' otherwise.\n");
	printf("Your number is %d? \n", guess /= 2);
	a = guess / 2;
	while((response = getchar()) != 'y')
	{	
		while (getchar() != '\n') //пропуск оставшейся части строки! читается только первый символ
			continue;

		if (response == 'n')
			guess = binary(a, guess);
		else 
			printf("Unfortunately I understand only 'y' and 'n'.\n");

		printf("Your number is %d? \n", guess);
		if (a > 1)
			a /= 2;
		else
			a = 1;
	}
	printf("I known what I can!!!\n");

	return;
}

void drill_6(void)
{
	int choice;
	while ((choice = get_choice1()) != 'd')
	{
		switch(choice)
		{
			case 'a': printf("Buy cheap, sell costly!\n");
					break;
			case 'b': putchar('\a');
					break;
			case 'c': count();
					break;
			default : printf("Program ERROR!\n");
					break;										
		}
	}
	printf("Cheerio!");
	return;
}

void drill_7(void)
{

	char i;
	float a, b, h, TARIFE1;
	menu();
	while ((i = getchar()) != 0 && i >= 97 && i < 101 || i == '\n' || i == ' ')
	{
		if (i == '\n' || i == ' ')
			continue;
		switch(i)
		{
			case 'a' : TARIFE1 = 8.74;
				break;
			case 'b' : TARIFE1 = 9.33;
				break;
			case 'c' : TARIFE1 = 10.00;
				break;
			case 'd' : TARIFE1 = 11.20;
				break;
		}					

		printf("Enter the working hours: ");
		if ((scanf("%f", &h)) == 1)
		{
			a = b = 0.0;
			if(h <= 0.0)
			{
				printf(" ERROR!!! [Nesecary unsigned value]\n");
				printf("Enter the working hours: ");
				continue;
			}

			if ( h < 40.0 )
				a = h * TARIFE1;
			else
				a = TARIFE1 * TIME + ((h - TIME) * RAISE * TARIFE1);

			if (a < DUTY1)
				b = a * PERSENT1;
			else if (a >= DUTY1 && a < DUTY2) 
				b = TAX1 + ((a - DUTY1) * PERSENT2);
			else if(a >= DUTY2)
				b = TAX2 + ((a - DUTY2) * PERSENT3);


			printf("Without take-home pay = %.3f\n", a);
			printf("Contribution = %.3f\n", b);
			printf("Take-home pay = %.3f\n\n", a - b);
		}
		menu();
	}
}

void drill_8(void)
{
	char i;
	menu8_8();
	while ((i = getchar()) != 'e' || i == 'a' || i == 'p'  || i == 'i' || i == 's' || i == '\n' || i == ' ')
	{
		if (i == '\n' || i == ' ')
			continue;
		switch(i)
		{
			case 'a' : operation(i);
				break;
			case 's' : operation(i);
				break;
			case 'i' : operation(i);
				break;
			case 'p' : operation(i);
				break;
		}					
		menu8_8();
	}
}

void main (void)

{
	//listing_8_1();
	//listing_8_2();
	//listing_8_3();
	//listing_8_4();
	//listing_8_5();
	//listing_8_6();
	//listing_8_7();
	//listing_8_8();

	//drill_1();
	//drill_2();
	//drill_3();
	//drill_4();
	//drill_5();
	drill_6();
	//drill_7();
	//drill_8();
	
	return;
}