#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define ROWS 6
#define CHARS 10
#define CHARS2 6
#define SIZE 26
#define PAR 72
#define SIZE8 8
#define SIZE255 255
#define DEPOSIT 100

const int NUMBER = 22;
const int FIRST_OZ = 37;
const int NEXT_OZ = 23;
const int secret_code = 13;

double power(double n, int p)
{
	double pow1 = 1;
	int i;
	for (i = 1; i <= p; i++)
		pow1 *= n;

	return pow1;
}

float difference(float a, float b)
{
		return((a - b) / (a * b));
}

void listing_6_1(void)
{
	long num;
	long sum = 0L;
	printf("Enter integer number for next sum ");
	printf("(or [q] for ending programm) = ");
	while (scanf("%ld", &num) == 1)
	{
		sum = sum + num;
		printf("Enter integer number for next sum (or [q] for ending programm) = ");
	}
	printf("Sum of getting number = [%ld].\n", sum);

	return;
}

void listing_6_2(void)
{
	int n = 5;
	while (n < 7)
	{
		printf("n = %d\n", n);
		n++;
		printf("Now n = %d\n", n);
	}
	printf("End iterations.\n");
	return;
}

void listing_6_3(void)
{
	int n = 0;
	while (n < 3)
	
		printf("n = %d\n", n);
		n++;
	
	printf("End iterations.\n");
	return;
}

void listing_6_4(void)
{
	int n = 0;
	while (n++ < 3);
	
		printf("n = %d\n", n);
	printf("End iterations.\n");

	return;
}

void listing_6_5(void)
{
	const double ANSWER = 3.14159;
	double response;
	printf("Which value is PI number:\n");
	scanf("%lf", &response);
	while (fabs(response - ANSWER) > 0.0001)
	{
		printf("Enter number again!\n");
		scanf("%lf", &response);
	}
	printf("Necessary validity is available!\n");

	return;
}

void listing_6_6(void)
{
	int tru_val, false_val;

	tru_val = (10 > 2);
	false_val = (10 == 2);
	printf("true = %d\nfalse = %d\n", tru_val, false_val);

	return;
}

void listing_6_7(void)
{
	int n = 3;
	while (n)
		printf("%2d is true\n", n--);
	printf("%2d is false\n", n);	

	n = -3;
	while (n)
		printf("%2d is true\n", n++);
	printf("%2d is false\n", n);		

	return;
}

void listing_6_8(void)
{
	long num;
	long sum = 0L;
	int status;

	printf("Enter integer number for next sum ");
	printf("(or [q] for ending programm) = ");
	status = scanf("%ld", &num);
	while (status == 1) // instead while (status = 1)
	{
		sum = sum + num;
		printf("Enter integer number for next sum (or [q] for ending programm) = ");
		status = scanf("%ld", &num);
	}
	printf("Sum of getting number = [%ld].\n", sum);

	return;
}

void listing_6_9(void)
{
	long num;
	long sum = 0L;
	_Bool input_is_good;

	printf("Enter integer number for next sum ");
	printf("(or [q] for ending programm) = ");
	input_is_good = (scanf("%ld", &num) == 1);
	while (input_is_good) // instead while (status = 1)
	{
		sum = sum + num;
		printf("Enter integer number for next sum (or [q] for ending programm) = ");
		input_is_good = (scanf("%ld", &num) == 1);
	}
	printf("Sum of getting number = [%ld].\n", sum);

	return;
}

void listing_6_10(void)
{
	int count = 1;

	while (count++ <= NUMBER)
		printf("Be my Valentine!\n");
	

	return;
}

void listing_6_11(void)
{
	for (int count = 1; count <= NUMBER; count++)
		printf("Be my Valentine!\n");
	

	return;
}

void listing_6_12(void)
{
	int num;
	printf("    n     n in cube\n");
	for (num = 1; num*num*num <= 1000; num++)
	printf("%5d %5d\n", num, num*num*num);	

	return;
}

void listing_6_13(void)
{
	int ounces, cost;
	printf("Ounces  Cost\n");
	for (ounces = 1, cost = FIRST_OZ; ounces <= 16; ounces++, cost += NEXT_OZ)
	printf("%5d $%4.2f\n", ounces, cost / 100.0);

	return;
}

void listing_6_14(void)
{
	int t_ct;
	double time_, x;
	int limit;
	printf("Enter necessary numbers of series elements: ");
	scanf("%d", &limit);
	for (time_ = 0.0, x = 1, t_ct = 1; t_ct <= limit; t_ct++, x *= 2.0)
	{
		time_ += 1.0 / x;
		printf("Time = %f, when numbers of elemrnts - %d\n", time_, t_ct);
	}
	
	return;
}

void listing_6_15(void)
{
	int code_entered;
	do 
	{
		printf("IF you want enter in spy club \n");
		printf("please get the secret code: ");
		scanf("%d", &code_entered);
	} while (code_entered != secret_code);
	printf("Congratulations! You are healthy!\n");
	
	return;
}

void listing_6_16(void)
{
	int code_entered = 0;
		printf("IF you want enter in spy club \n");
		printf("please get the secret code: ");
		scanf("%d", &code_entered);
	while (code_entered != secret_code)
	{
		printf("IF you want enter in spy club \n");
		printf("please get the secret code: ");
		scanf("%d", &code_entered);
	}
	printf("Congratulations! You are healthy!\n");
	
	return;
}

void listing_6_17(void)
{
	int row;
	char ch;

	for (row = 0; row < ROWS; row++)
	{
		for (ch = 'A'; ch < ('A' + CHARS); ch++)
			printf("%c", ch);
		printf("\n");
	}

	return;
}

void listing_6_18(void)
{
	int row;
	char ch;

	for (row = 0; row < ROWS; row++)
	{
		for (ch = ('A' + row); ch < ('A' + CHARS2); ch++)
			printf("%c", ch);
		printf("\n");
	}

	return;
}

void listing_6_19(void)
{
	int index, score[SIZE];
	int sum = 0;
	float avarage;

	printf("Enter %d resultes of golf game: \n", SIZE);
	for (index = 0; index < SIZE; index++)
		scanf("%d", &score[index]);
	printf("Enter the next resultes:\n");

	for (index = 0; index < SIZE; index++)
		printf("%5d", score[index]);
	printf("\n");

	for(index = 0; index < SIZE; index++)
		sum += score[index];
	avarage = (float) sum / SIZE;
	printf("Ending sum of points = %d, avarage value is = %.2f\n", sum, avarage);
	printf("Handicap is %.0f.\n", avarage - PAR);

	return;
}

void listing_6_20(void)
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

	printf("Hope you are fulfill of quality our programm!\n");

	return;
}

void drill_1(void)
{
	char ArrayChar[SIZE];
	for (int i = 0; i < SIZE; i++)
		printf("%c", ArrayChar[i] = i + 97);
	printf("\n");
	for (int i = 0; i < SIZE; i++)
		printf("%c", ArrayChar[i]);

	return;
}

void drill_2(void)
{
	for(int i = 1; i < ROWS; i++)
	{	for (int k = i; k > 0; k--)
			printf("$");
		printf("\n");
	}
	
	return;
}

void drill_3(void)
{
	char c;
	for(int i = 1; i <= ROWS; i++)
	{	for (int k = i, c = 'G'; k > 0 ; k--)
		printf("%c", c -= 1);
	printf("\n");
	}
	
	return;
}

void drill_4(void)
{
	char ch, nch = 65;
	int s, str, w, i = 0;//i - количество строк которое уже напечаталось
	printf("Enter upper case character: ");
	scanf("%c", &ch);
	
	while (( s = ch - nch) >= 0)
	{
		str = s;
		w = s;

		while(str > 0)//цикл ставит колличство пробелов в зависимости от введенной буквы
		{
			printf(" ");
			str--;
		}

	  	for(int k = 0; k <= i ; k++)//цикл печатает символы до центрального
	  		printf("%c", nch + k);

		int q = i - 1;
	  	int y = q;
	  	for(int f = 0; f <= q ; f++)//цикл печатает символы после центрального
	 		{
	  			printf("%c", nch + y);
		  		y--;
			}
	  	printf("\n");
	  	i++;
		ch -= 1;
	}
}

void drill_5(void)
{
	int up, down, i, k;
	printf("Enter down level of table: ");
	i = scanf("%d", &down);

	printf("Enter upper level of table: ");
	k = scanf("%d", &up);
	for(; i + k == 2; )
	{
		for ( ; down <= up; down += 1)
		printf("Int = %d, square = %d, cube = %d\n", down, down * down, down * down * down);
	printf("Enter down level of table: ");
	i = scanf("%d", &down);

	printf("Enter upper level of table: ");
	k = scanf("%d", &up);
	}
		
	return;
}

void drill_6(void)
{
	int i;
	char ArrayCh[CHARS];
	printf("Enter word(s): ");
	scanf("%s", ArrayCh);
	i = strlen(ArrayCh);
	printf("Lenght of entered words = %d\n", i);
	for ( ; i > 0 ; i--)
		printf("%c", ArrayCh[i - 1]);
	
	return;
}

void drill_7(void)
{
	int i, k;
	float a, b;
	printf("Enter float number [a]: ");
	i = scanf("%f", &a);
	printf("Enter float number [b]: ");
	k = scanf("%f", &b);

	while(i + k == 2)
	{
		printf("(a - b) / (a * b) = %.4f\n", (a - b) / (a * b));

		printf("Enter float number [a]: ");
		i = scanf("%f", &a);
		printf("Enter float number [b]: ");
		k = scanf("%f", &b);
	}
	return;
}

void drill_8(void)
{
	int i, k;
	float a, b, c;
	printf("Enter float number [a]: ");
	i = scanf("%f", &a);
	printf("Enter float number [b]: ");
	k = scanf("%f", &b);

	while(i + k == 2)
	{
		c = difference(a, b);
		printf("(a - b) / (a * b) = %.4f\n", c);

		printf("Enter float number [a]: ");
		i = scanf("%f", &a);
		printf("Enter float number [b]: ");
		k = scanf("%f", &b);
	}
	return;
}

void drill_9(void)
{
	int a, b, c = 0;
	printf("Enter down and upper limits: ");
	scanf("%d %d", &a, &b);

	while(a < b)
	{
		for(int i = a; i <= b; i++)
			c = c + i * i;
	printf("Sum of square integer numbers %d and %d = %d\n", a * a, b * b, c);
	printf("\nEnter next limits: ");
	scanf("%d %d", &a, &b);
	}
	printf("\nWork finish.");
	return;
}

void drill_10(void)
{
	int i, ArrayInt[SIZE8];
	printf("Enter number: ");
	for (i = 0; i < SIZE8; i++)
		scanf("%d", &ArrayInt[i]);
	while (i-- > 0)
		printf("%d ", ArrayInt[i]);	
}

void drill_11(void)
{
	int a, r;
	printf("Enter number: ");
	r = scanf("%d", &a);
	while (r == 1)
	{
		int l = -1;
		float frst = 0, scnd = 0;
		for(float i = 1; i <= a; i++ )
		{
			frst = frst + 1 / i;
			l *=-1;	
			scnd = scnd + l * (1 / i);
		}

		printf("Sum of [%d] elemrnts:\n\ta + 1/(a+1) + ... + 1/(a+n) = %.4f\n", a, frst);
		printf("Sum of [%d] elemrnts:\n\ta - 1/(a+1) + ... - 1/(a+n) = %.4f\n", a, scnd);
		printf("\nEnter number: ");
		r = scanf("%d", &a);
	}
	return;
}

void drill_12(void)
{
	int numbers[SIZE8];
	int two = 1, i;
	for (i = 0; i < SIZE8; i++)
	{
		two *= 2; 
		numbers[i] = two;
	}
	i = 0;
	do 
	{
		printf("Degree [%d] = %d\n", i + 1, numbers[i]);
		i++;
	}
	while(i < SIZE8);
	return;
}

void drill_13(void)
{
	double frst[SIZE8];
	double scnd[SIZE8];
	double a, b;

	for (int i = 0; i < SIZE8; i++) //декларация элементов массива
	{
		printf("Enter [%d] element of array:", i + 1);
		scanf("%lf", &frst[i]);
	}
	for (int i = 0; i < SIZE8; i++)
	{
		a = frst[i];
		b += a;
		scnd[i] = b;
	}
	printf("First array:\t[");
	for (int i = 0; i < SIZE8; i++)
		printf("  %.2lf,", frst[i]);
	printf("]\nSecond array:\t[");

	printf("");
	for (int i = 0; i < SIZE8; i++)
		printf("  %.2lf,", scnd[i]);
	printf("\b]\n");
}

void drill_14(void)
{
	char ArrayChar[SIZE255];
	char a;
	int c;
	while( c = scanf("%c", &a) != EOF)
	{
		int i = 0;
		while( a != '\n')
			{
				ArrayChar[i] = a;
			//	printf("%c", ArrayChar[i]);
				i++;
				scanf("%c", &a);
			}
		for(int k = i - 1; k >= 0; k--)
			printf("%c", ArrayChar[k]);	
		printf("\n");
	}
}

void drill_15(void)
{
	float a, b, m;
	a = b = m = DEPOSIT;
	int i = 0;
	do
	{
		i++;
		a = a + 0.1 * m;
		b = b + b * 0.05;
	}
	while(a > b);
	printf("Necessary [%d] years. \n", i);
	printf("Deidra's count = $%.2f\n", a);
	printf("Daphna's count = $%.2f\n", b);

	return;
}

void drill_16(void)
{
	float mil = 1000000;
	float give = 100000;
	int i;
	for (i = 1; mil - 100000 > 0; i++)
	{
		mil -= give;
		mil *= 1.08;
		printf("Year [%d] = $%.2f keep\n", i, mil);
	}
	printf("After %d years he'll stay with $%.2f. That's all!", i - 1, mil);
	return;
}

void main (void)

{
	//listing_6_1();
	//listing_6_2();
	//listing_6_3();
	//listing_6_4();
	//listing_6_5();
	//listing_6_7();
	//listing_6_8();
	//listing_6_9();
	//listing_6_10();
	//listing_6_11();
	//listing_6_12();
	//listing_6_13();
	//listing_6_14();
	//listing_6_15();
	//listing_6_16();
	//listing_6_17();
	//listing_6_18();
	//listing_6_19();
	//listing_6_20();

	//drill_1();
	//drill_2();
	//drill_3();
	//drill_4();
	//drill_5();
	//drill_6();
	//drill_7();
	//drill_8();
	//drill_9();
	//drill_10();
	//drill_11();
	//drill_12();
	//drill_13();
	//drill_14();
	//drill_15();
	//drill_16();
	
	return;
}