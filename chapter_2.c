#include <stdio.h>

void butler(void)
{
	printf("Sr,Have you been called?");
	return;
}

void firstStringBill(void)
{
	printf("Our Bill is good guy!\n");
	return;
}

void secondStringBill(void)
{
	printf("Our Bill is the best of all!\n");
	return;
}
 
void smile(void)
{
	printf("Smile! ");
	return;
}

void two(void)
{
	printf("\ntwo\n");
	return;
}

void one_three(void)
{
	printf("one");
	two();
	printf("three\n");
	return;
}

void listing_2_1 (void)
{
	int num = 1;
	printf("I'm a simple ");
	printf("computer\n");
	printf("My favorite number is %d, because it's first!", num);

	return;	
}
 
void listing_2_2 (void)
{
	int feet, fathoms;
	fathoms = 2;
	feet = 6 * fathoms;
	printf("There are %d feets in %d fathoms!\n", feet, fathoms);
	printf("Yes, I sad %d feets!\n", 6 * fathoms);

	return;
}

void listing_2_3 (void)
{
	printf("I'm calling the butler.\n");
	butler();
	printf("\nYes. Give me please tea and CDs.");

	return;
}

void listing_2_4 (void)
{
	int n, n2, n3;

	n = 5;
	n2 = n * n;
	n3 = n2 * n;
	printf("\nn = %d, n square = %d, n cubed = %d\n", n, n2, n3);

	return;
}

void drill_1 (void)
{
	printf("Ivan Sidortsov\n");
	printf("Ivan\nSidortsov\n");
	printf("Ivan");
	printf(" Sidortsov\n");

	return;
}

void drill_2 (void)
{
	printf("\nIvan Sidortsov:\nDireccion: PM TDF AR");

	return;
}

void drill_3 (void)
{
	int year, age;
	year = 365;
	age = 23;
	printf("\nMy age to years: %d\nMy age to days: %d \n", age, age * year);

	return;
}

void drill_4 (void)
{
	firstStringBill();
	firstStringBill();
	firstStringBill();
	secondStringBill();

	return;
}

void drill_5 (void)
{
	int toes;
	toes = 10;
	printf("\nToes: %d\nDouble toes: %d\nSquare toes: %d\n", toes, 2 * toes, toes * toes);

	return;
}

void drill_6 (void)
{
	smile();
	smile();
	smile();
	printf("\n");
	smile();
	smile();
	printf("\n");
	smile();

	return;
}

void drill_7 (void)
{
	printf("\n\nStart now:\n");
	one_three();
	printf("All right!");

	return;
}

void main (void)
{
	listing_2_1();
	listing_2_2();
	listing_2_3();
	listing_2_4();

	drill_1();
	drill_2();
	drill_3();
	drill_4();
	drill_5();
	drill_6();
	drill_7();

	return;
}