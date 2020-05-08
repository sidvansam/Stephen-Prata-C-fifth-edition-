#include <stdio.h>
#include <inttypes.h>//заголовок поддерживает переносимые типы

void toobig(void)
{
	int i = 2147483647;
	unsigned int j = 4294967295;
	float toobig = 3.4E38 * 100.0f;
	printf("%d %d %d\n", i, i + 1, i + 2);
	printf("%u %u %u\n", j, j + 1, j + 2);
	printf("%e\n", toobig);

	return;
}

void listing_3_1(void)
{
	float weight;
	float value;

	printf("Do you want to know your weight?\n");
	printf("Let's do it!\n");
	printf("Please, get your weight in pounds: ");

	scanf("%f", &weight); // %f - спецификатор формата
	value = 14.5833 * 770.0 * weight;
	printf("Your rhodium equivalent consists $%.2f.\n", value);
	printf("You'll easy can be worthy this! If value of Rh will get down\n");
	printf("eat more for your cost!\n");

	return;
}

void listing_3_2(void)
{
	int ten = 10;
	int two = 2;

	printf("Carry out correct:\n");
	printf("%d minus %d equal %d\n", ten, two, ten - two);
	printf("Carry out incorrect:\n");
	printf("%d minus %d is %d\n", two );

	return;
}

void listing_3_3(void)
{
	int x = 100;
	printf("Decimal = %d; octal = %o; hexadecimal = %x\n", x, x, x);
	printf("Decimal = %d; octal = %#o; hexadecimal = %#x\n", x, x, x);// # - часть спецификатора отвечающего за вывод значений с префиксами 0, 0х

	return;
}

void listing_3_4(void)
{
	unsigned int un = 3000000000;
	short end = 200;
	long big = 65537;
	long long verybig = 12345678908642;

	printf("un = %u but no %d\n", un, un);
	printf("end = %hd and %d\n", end, end);
	printf("big = %ld but no %hd\n", big, big);
	printf("verybig = %lld but no %ld\n", verybig, verybig);

	return;
}

void listing_3_5(void)
{
	char ch;

	printf("Enter a which simbol: ");
	scanf("%c", &ch);
	printf("Code of character [%c] equial %d.\n", ch, ch);

	return;
}

void listing_3_6(void)
{
	int16_t me16; // me16 - signed hexadecimal variable
	me16 = 4593;
	printf("Supposing [int16_t] have type short: ");  
	printf("me16 = %hd\n", me16);  
	printf("There isn't any assumptions.\n");  
	printf("Instead of this use [macrocommand] from header inttypes.h.\n");
	printf("me16 = %" PRId16 "\n", me16);  
	
	return;
}

void listing_3_7(void)
{
	float aboat = 32000.0;
	double abet = 2.14e9;
	long double dip = 5.32e-5;

	printf("%f may be writing how %e\n", aboat, aboat);
	printf("%f may be writing how %e\n", abet, abet);
	printf("%f may be writing how %e\n", dip, dip);

	return;
}

void listing_3_8(void)//dimentions types on my computer
{
	printf("Type int have dimention %zd byte(s)\n", sizeof(int));
	printf("Type char have dimention %zd byte(s)\n", sizeof(char));
	printf("Type long have dimention %zd byte(s)\n", sizeof(long));
	printf("Type double have dimention %zd byte(s)\n", sizeof(double));
	printf("Type long long have dimention %zd byte(s)\n", sizeof(long long));
	printf("Type float have dimention %zd byte(s)\n", sizeof(float));
	printf("Type short have dimention %zd byte(s)\n", sizeof(short));
	printf("Type long double have dimention %zd byte(s)\n", sizeof(long double));

	return;
}

void listing_3_9(void)
{
	int f = 4;
	int g = 5;
	float h = 5.0f;
	printf("%d\n", f, g);
	printf("%d %d\n", f);
	printf("%d %f\n", h, g);

	return;
}

void listing_3_10(void)
{
	float salary;
	printf("\aEnter your prefer salary in month: ");
	printf(" $ ___ __\b\b\b\b\b\b\b");
	scanf("%f", &salary);
	printf("\n\t$%.2f in month equal $%.2f in year.", salary, salary * 12.0);
	printf("\rWow!\n");

	return;
}

void drill_1()
{
	unsigned int i = 2147483647 + 1;
	float a, b;
	a = 6.3E37 * 10;
	b = 0.123e5 / 10;

	printf("\nint i = 2 147 483 647 + 1 = %d [overflow]", i);
	printf("\nfloat a = 6.3E38 * 10 = %f [overflow]", a);
	printf("\nfloat b = 1.235e5 / 10 = %f [underflow]", b);

	return;
}

void drill_2()
{
	int c;
	printf("Enter your decimal ASCII code: __\b\b");
	scanf("%d", &c);
	printf("Your code come up to ASCII character : [%c]\n", c);

	return;
}

void drill_3()
{
	printf("\aStartled by the sudden sound of a sound, Sally exclaimed: What was it?");

	return;
}

void drill_4()
{
	float f;
	printf("\nEnter floating-point number: __,___\b\b\b\b\b\b ");
	scanf("%f", &f);
	printf("Entered number was %f or %e", f, f);

	return;
}

void drill_5()
{
	float YTS = 3.156E7, PY;
	printf("\nEnter your age: __\b\b ");
	scanf("%f", &PY);
	printf("Your age in seconds is: %e", YTS * PY);

	return;
}

void drill_6()
{
	float mlcl = 3.0E-23, qnt;
	float qrt = 950.0;
	printf("\nEnter quantity of water quarts: __\b\b ");
	scanf("%f", &qnt);
	printf("Quantity molecules in %.2f water quarts are: %.2e", qnt, qrt * qnt / mlcl);

	return;
}

void drill_7()
{
	float inch = 2.56, stature;
	printf("\nEnter your stature in cm: __\b\b ");
	scanf("%f", &stature);
	printf("Your stature in inches is: %.2f inch", stature / inch);

	return;
}

void main (void)

{
	listing_3_1();
	listing_3_2();
	listing_3_3();//печать числа в десятичн., восмеричн., и шестнадцатиричн. системах счисления
	toobig();
	listing_3_4();
	listing_3_5();
	listing_3_7();
	listing_3_8();
	listing_3_9();
	listing_3_10();

	drill_1();
	drill_2();
	drill_3();
	drill_4();
	drill_5();
	drill_6();
	drill_7();

	return;
}