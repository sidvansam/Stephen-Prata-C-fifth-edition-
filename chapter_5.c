#include <stdio.h>
#define ADJUST 7.64
#define SCALE 0.325
#define SQUARES 64
#define CROP 1E15
#define SEC_PER_MIN 60
#define MAX 100
#define M_PER_H 60
#define WEEK 7
#define FEET 0.032
#define INCH 0.393

const int S_PER_M = 60;
const int S_PER_H = 3600;
const double M_PER_K = 0.62137;
const double a1 = 1.8;
const double b1 = 32.0;
const double c1 = 273.16;

void pound(int n)
{
	while(n-- > 0)
		printf("#");
	printf("\n");

	return;
}

void cube(float n)
{
	printf("Dimensional cube [%.2f] is [%.2f]\n", n, n * n * n);
	return;
}

void convert(double c)
{
	printf("[Far] = %.2lf\n[Cel] = %.2lf\n[Kelv] = %.2lf\n", c, a1 * c + b1, a1 * c + b1 + c1);
	return;
}

void listing_5_1(void)
{
	double shoe, foot;
	shoe = 9.0;
	foot = SCALE * shoe + ADJUST;
	printf("Size shoe (mens)       size foot\n");
	printf("%10.1f %20.2f inches\n", shoe, foot);

	return;
}

void listing_5_2(void)
{
	double shoe, foot;
	shoe = 9.0;
	foot = SCALE * shoe + ADJUST;
	printf("Size shoe (mens)       size foot\n");
	shoe = 2.0;
	while (shoe++ < 18.5)
	{
		foot = SCALE * shoe + ADJUST;
		printf("%10.1f %20.2f inches\n", shoe, foot);
	}
	printf("If shoe fit you, wear it.\n");

	return;
}

void listing_5_3(void)
{
	int jane , tarzan, cheeta;
	cheeta = tarzan = jane = 68;
	printf("             cheeta tarzan jane\n");
	printf("Sport score: %6d %6d %4d\n", cheeta, tarzan, jane);
	
	return;
}

void listing_5_4(void)
{
	int num = 1;
	while (num < 21)
	{
	printf("%4d %6d\n", num, num * num);
	num = num + 1;
	}

	
	return;
}

void listing_5_5(void)
{
	double current, total;
	int count = 1;

	printf("Square   add          total        ");
	printf("Kikbak  \n");
	printf("         grain        grain        ");
	printf("Harvest USA  \n");
	total = current = 1.0;
	printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total/CROP);
	while(count < SQUARES)
	{
		count = count + 1;
		current = 2.0 * current;
		total = total + current;
		printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total/CROP);
	}
	printf("That's all");

	return;
}

void listing_5_6(void)
{
	printf("Integer division:    5/4   is %d \n", 5/4);
	printf("Integer division:    6/3   is %d \n", 6/3);
	printf("Integer division:    7/4   is %d \n", 7/4);
	printf("Float division:      7./4. is %1.2f \n", 7./4.);
	printf("Mix division:        7./4  is %1.2f \n", 7./4);

	return;
}

void listing_5_7(void)
{
	int top, score;
	top = score = -(2 + 5) * 6 + (4 + 3 * (2 + 3));
	printf("top = %d \n", top);

	return;
}

void listing_5_8(void)
{
	int n = 0;
	size_t intsize;

	intsize = sizeof (int);
	printf("n = %d, [n] consists of %zd bytes; all [int] value have %zd bytes.\n", n, sizeof n, intsize);
	
	return;
}

void listing_5_9(void)
{
	int sec, min, left;
	printf("Transfer seconds to minutes and seconds!\n");
	printf("Enter quantity of seconds: \n");
	scanf("%d", &sec);

	while (sec > 0)
	{
		min = sec / SEC_PER_MIN;
		left = sec % SEC_PER_MIN;
		printf("%d seconds - it's %d minutes %d seconds.\n", sec, min, left);
		printf("Enter next quantity of seconds: \n");
		scanf("%d", &sec);
	}
	printf("Ready!");
	
	return;
}

void listing_5_10(void)
{
	int ultra = 0, super = 0;
	while(super < 5)
	{
		super++;
		++ultra;
		printf("super = %d, ultra = %d\n", super, ultra);
	}
	
	return;
}

void listing_5_11(void)
{
	int a = 1, b = 1;
	int aplus, bplus;
	aplus = a++;
	bplus = ++b;
	printf("a    aplus  b     bplus\n");
	printf("%ld %5d %5d %5d\n", a, aplus, b, bplus);

	return;
}

void listing_5_12(void)
{
	int count = MAX + 1;
	while (--count > 0){
		printf("%d bottles of water on shave, "
			   "%d bottles of water!\n", count, count);
		printf("Take one of them!\n");
		printf("%d bottles of water!\n\n", count - 1);
	}

	return;
}

void listing_5_13(void)
{
	int count, sum;
	count = 0;
	sum = 0;
	while (count++ < 20)
		sum = sum + count;
	printf("sum = %d\n", sum);

	return;
}

void listing_5_14(void)
{
	char ch;
	int i;
	float fl;
	fl = i = ch = 'C';
	printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl);
	ch = ch + 1;
	i = fl + 2 * ch;
	fl = 2.0 * ch + i;
	printf("ch = %c, i = %d, fl = %2.2f\n", ch, i, fl);
	//ch = 5212205.17;
	//printf("Now ch = %c\n", ch);

	return;
}

void listing_5_15(void)
{
	int times = 5; 
	char ch = '!';
	float f = 6.0;

	pound(times);
	pound(ch);
	pound((int) f);

	return;
}

void listing_5_16(void)
{
	double distk, distm;
	double rate;
	int min, sec;
	int ntime;
	double mtime;
	int mmin, msec;

	printf("This programm calculate rate time of distance in metric system\n");
	printf("in rate time of one mile and calculate your half\n");
	printf("speed in miles per hours.\n");
	printf("Enter rate distance in [km]:\n");
	scanf("%lf", &distk);
	printf("Than enter time in minutes and seconds.\n");
	printf("Start with input minutes:\n");
	scanf("%d", &min);	
	printf("Now with input seconds:\n");
	scanf("%d", &sec);	

	ntime = S_PER_M * min + sec;
	distm = M_PER_K * distk;
	rate = distm / ntime *  S_PER_H;
	mtime = (double) ntime / distm;
	mmin = (int) mtime / S_PER_M;
	msec = (int) mtime % S_PER_M;
	printf("You ran %1.2f km (%1.2f miles) out of %d minutes, %d seconds\n", distk, distm, min, sec);
	printf("This speed is equial one mile rate out of %d minutes, ", mmin);
	printf("%d seconds.\nYour half speed is %1.2f miles per hour.\n", msec, rate);

	return;
}

void drill_1(void)
{
	int min, hour;
	printf("Enter time in minutes: ");
	scanf("%d", &min);
	while (min > 0)
	{
		printf("In %d minutes is %d hours and %d minutes.\n", min, min / M_PER_H, min % M_PER_H);
		printf("Enter time in minutes: ");
		scanf("%d", &min);
	}
	return;
}

void drill_2(void)
{
	int a, b;
	printf("Enter number [a]: ");
	scanf("%d", &a);
	b = a + 10;
	while(a <= b)
		{
			printf("%d  ", a);
			a++;
		}
	return;
}

void drill_3(void)
{
	int a;
	printf("Enter numbers of days: ");
	scanf("%d", &a);
	while(a > 0)
		{
		printf("%d days consist %d weeks and %d days.\n", a, a / WEEK, a % WEEK);
		printf("Enter numbers of days: ");
		scanf("%d", &a);		
		}
	return;
}

void drill_4(void)
{
	float a;
	printf("Enter your stature in [cm]: ");
	scanf("%f", &a);
	while(a > 0)
		{
		printf("%.1f [cm] = %.0f feets, %.1f inches.\n", a, a * FEET, a * INCH);
		printf("Enter your stature in [cm]: ");
		scanf("%f", &a);		
		}
	return;
}

void drill_5(void)
{
	int a;
	printf("Enter salary days: ");
	scanf("%d", &a);
	while (a > 0)
		{
			int  sum = 0, count = 0;
			while( count++ < a)
			{
			sum += count;
			printf("You salary reach in %d day = %d\n",count,  sum);
			}
		printf("Enter salary days: ");
		scanf("%d", &a);
		}
	return;
}

void drill_6(void)
{
	int a;
	printf("Enter salary days: ");
	scanf("%d", &a);
	while (a > 0)
		{
			int  sum = 0, count = 0;
			while( count++ < a)
			{
			sum += count * count;
			printf("You salary reach in %d day = $%d\n",count,  sum);
			}
		printf("Enter salary days: ");
		scanf("%d", &a);
		}
	return;
}

void drill_7(void)
{
	float a;
	printf("Enter float number: ");
	scanf("%f", &a);
	while (a > 0)
		{
		cube(a);
		printf("Enter float number: ");
		scanf("%f", &a);
		}
	return;
}

void drill_8(void)
{
	float a;
	printf("Enter Far temperature: ");
	while (scanf("%f", &a) != 0)
		{
			convert(a);
			printf("\nEnter Far temperature: ");
		}
	return;
}


void main (void)

{
	//listing_5_1();
	//listing_5_2();
	//listing_5_3();
	//listing_5_4();
	//listing_5_5();
	//listing_5_6();
	//listing_5_7();
	//listing_5_8();
	//listing_5_9();
	//listing_5_10();
	//listing_5_11();
	//listing_5_12();
	//listing_5_13();
	//listing_5_14();
	//listing_5_15();
	//listing_5_16();
	
	//drill_1();
	//drill_2();
	//drill_3();
	//drill_4();
	//drill_5();
	//drill_6();
	//drill_7();
	drill_8();

	return;
}