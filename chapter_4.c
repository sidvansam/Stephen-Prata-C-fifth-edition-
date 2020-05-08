#include <stdio.h>
#include <string.h>
#include <float.h>  // пределы для чисел с плавающей запятой
#include <limits.h> // целоцичленные пределы
#define DESTINY 62.4
#define PRAISE "What a beautiful name!"
#define PI 3.14159
#define PAGES 336
#define BLURB "Authentic imitation!"
#define WORDS 65618
#define GALLON 3.785
#define MILE 1.609

void listing_4_1(void)
{
	float weight, volume;
	int size, letters;
	char name[40]; // массив способен запомнить по 1 символу на элемент массива

	printf("Hello! What's your name?\n");
	scanf("%s", name);
	printf("%s, what is your weight in pounds?\n", name);
	scanf("%f", &weight);
	size = sizeof name;
	letters = strlen(name);
	volume = weight / DESTINY;
	printf("Ok, %s, your weight is %2.2f cubic foots.\n", name, volume);
	printf("Then your name consists of %d characters,\n", letters);
	printf("And we use %d bytes for hold it.\n", size);
	printf("%c %c %c\n", 'H', 105, '\041');

	return;
}

void listing_4_2(void)
{
	char name[40]; // массив способен запомнить по 1 символу на элемент массива

	printf("Hello! What's your name?\n");
	scanf("%s", name);
	printf("Hello, %s! %s\n", name, PRAISE);

	return;
}

void listing_4_3(void)
{
	char name[40]; // массив способен запомнить по 1 символу на элемент массива

	printf("Hello! What's your name?\n");
	scanf("%s", name);
	printf("Your name consist of %d characters and hold %d memory cells.\n", strlen(name), sizeof name);
	printf("PRAISE consists of %d character ", strlen(PRAISE));
	printf("and hold %d memory cells.\n", sizeof PRAISE);

	return;
}

void listing_4_4(void)
{
	float area, circum, radius;

	printf("Which radius of your pizza?\n");
	scanf("%f", &radius);
	area = PI * radius * radius;
	circum = 2 * PI * radius;
	printf("Based parameters of your pizza:\n");
	printf("perimeter of circle: [%1.2f], area: [%1.2f]\n",circum, area);

	return;
}

void listing_4_5(void)
{
	printf("Some limits for this system:\n");
	printf("Biggest [int] value: %d\n", INT_MAX);
	printf("Least [long long] value: %lld\n", LLONG_MIN);
	printf("One byte = %d data bits in system.\n", CHAR_BIT);
	printf("Biggest [double] value: %e\n", DBL_MAX);
	printf("Least [float] normal value: %e\n", FLT_MIN);
	printf("Accuracy [float] = %d\n", FLT_DIG);
	printf("Different between 1.00 and least [float] value overstep 1.00 = %e\n", FLT_EPSILON);

	return;
}

void listing_4_6(void)
{
	int number = 5;
	float espresso = 13.5;
	int cost = 3100;

	printf("%d administrators drinck %f caps espresso.\n",number, espresso);
	printf("Number PI equal %f.\n", PI);
	printf("By! Your art is very expensive for me,\n");
	printf("%c%d\n", '$', 2 * cost);

	return;
}

void listing_4_7(void)
{
	printf("*%d*\n", PAGES);
	printf("*%2d*\n", PAGES);
	printf("*%10d*\n", PAGES);
	printf("*%-10d*\n", PAGES);

	return;
}

void listing_4_8(void)
{
	const double RENT = 3852.99;

	printf("*%f*\n", RENT);
	printf("*%e*\n", RENT);
	printf("*%4.2f*\n", RENT);
	printf("*%3.1f*\n", RENT);
	printf("*%10.3f*\n", RENT);
	printf("*%10.3e*\n", RENT);
	printf("*%+4.2f*\n", RENT);
	printf("*%010.2f*\n", RENT);

	return;
}

void listing_4_9(void)
{
	printf("%x %X %#x\n", 31, 31, 31);
	printf("**%d**%  d**%  d\n", 42, 42, -42);
	printf("**%5d**%5.3d**%05d**%05.3d**\n", 6, 6, 6, 6);

	return;
}

void listing_4_10(void)
{
	printf("/%2s/\n", BLURB);
	printf("/%24s/\n", BLURB);
	printf("/%24.5s/\n", BLURB);
	printf("/%-24.5s/\n", BLURB);

	return;
}

void listing_4_11(void)
{
	short num = PAGES;
	short mnum = -PAGES;
	printf("num how type [short] and type [unsigned short]: %hd %hu\n", num, num);
	printf("-num how type [short] and type [unsigned short]: %hd %hu\n", mnum, mnum);
	printf("num how type [int] and type [char]: %d %c\n", num, num);
	printf("WORDS how type [int], [short] and [char]: %d %hd %c \n", WORDS, WORDS, WORDS);

	return;
}

void listing_4_12(void)
{
	float n1 = 1201;
	double n2 = 1201;
	long n3 = 2000000000;
	long n4 = 1234567890;

	printf("%2.3e %2.3e %.le %.le\n", n1, n2, n3, n4);
	printf("%ld %ld\n", n3, n4);
	printf("%ld %ld %ld %ld\n", n1, n2, n3, n4);

	return;
}

void listing_4_13(void)
{
	int bph2o = 212;
	int rv;

	rv = printf("%d degrees on F is boiling point of water.\n", bph2o);
	printf("Function printf() puts %d characters.\n", rv);
	
	return;
}

void listing_4_14(void)
{
	printf("There is one of output methods ");
	printf("large strings. \n");
	printf("Second output method \
	large strings.\n");
	printf("The new output method "
		"large strings.\n");

	return;
}

void listing_4_15(void)
{
	int age; 		//variable
	float assets;   //variable
	char pet[30];   //string

	printf("Enter information of your age, bank account and your pet's name.\n");
	scanf("%d %f", &age, &assets);
	scanf("%s", pet);
	printf("%d %.2f %s\n", age, assets, pet);

	return;
}

void listing_4_16(void)
{
	unsigned width, precision;
	int number = 256; 
	double weight = 242.5;
	printf("Which field width?\n");
	scanf("%d", &width);
	printf("value is: %*d: \n", width, number);// если указывается модификатор * , то на его место будет подставлео определенное занчение которое вы захотите
	printf("Now enter width and validity:\n");
	scanf("%d %d", &width, &precision);
	printf("Weight = %*.*f\n", width, precision, weight);
	printf("Ready!\n");

	return;
}

void listing_4_17(void)
{
	int fin;

	printf("Put 3 integer numbers:\n");
	scanf("%*d %*d %d", &fin); //%*d - пропуск вводимого int числа
	printf("Last put number is %d.\n", fin);

	return;
}

void drill_1(void)
{
	char name[10];
	char surname[10];
	printf("Enter your name: \n");
	scanf("%s", name);
	printf("Enter your surname: \n");
	scanf("%s", surname);
	printf("%s, %s", surname, name);

	return;
}

void drill_2(void)
{
	char name[10];
	printf("Enter your name: \n");
	scanf("%s", name);
	printf("\"%s\"\n", name);
	printf("\"%20s\"\n", name);
	printf("\"%-20s\"\n", name);
	printf("\"%*s\"\n", sizeof name, name);
	printf("\"%*s\"\n", sizeof name + 3, name);

	return;
}

void drill_3(void)
{
	float n;
	printf("Enter float number: \n");
	scanf("%f",&n);
	printf("a) Entered number is %.1f or %.1e\n", n, n);
	printf("b) Entered number is %+.3f or %.3E\n", n, n);
	
	return;
}

void drill_4(void)
{

	float sttr, f = 0.032808;
	char name[10];
	printf("Enter your stature in cm: ");
	scanf("%f",&sttr);
	printf("Enter your name: ");
	scanf("%s",name);
	printf("%s, your stature is %.2f feets.", name, sttr * f);
	
	return;
}

void drill_5(void)
{
	char name[10];
	char surname[10];
	printf("Enter your name: \n");
	scanf("%s", name);
	printf("Enter your surname: \n");
	scanf("%s", surname);
	printf("%s %s\n", surname, name);
	printf("%*d %*d", strlen(surname), sizeof surname, strlen(name), sizeof name);
	printf("\n\n%s %s\n", surname, name);
	printf("%-*d %-*d", strlen(surname), sizeof surname, strlen(name), sizeof name);

	return;
}

void drill_6(void)
{
	double a = 1.0/3.0;
	float b = 1.0/3.0;
	printf("%.4f %.4f\n", a, b);
	printf("%.12f %.12f\n", a, b);
	printf("%.16f %.16f\n", a, b);
	printf("%d %d\n", DBL_DIG, FLT_DIG);
	
	return;
}

void drill_7(void)
{
	float m;
	float g;
	printf("Enter miles: ");
	scanf("%f",&m);
	printf("Enter gallons: ");
	scanf("%f",&g);

	printf("%.1f miles for 1 gallon.\n", m / g);
	printf("%.1f km for %.1f lt.\n", m = m * MILE, g = GALLON * g);
	printf("Fuel consumption [ES] = %.1f lt for %.1f kms.\n", g*100.0/m, m*100.0/m);
	
	return;
}

void main (void)

{
	//listing_4_1();
	//listing_4_2();
	//listing_4_3();
	//listing_4_4();
	//listing_4_5();
	//listing_4_6();
	//listing_4_7();
	//listing_4_8();
	//listing_4_10();
	//listing_4_11();
	//listing_4_12();
	//listing_4_13();
	//listing_4_14();
	//listing_4_15();
	//listing_4_16();
	//listing_4_17();

	//drill_1();
	//drill_2();
	//drill_3();
	//drill_4();
	//drill_5();
	//drill_6();
	//drill_7();

	return;
}