#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define SPASE ' '
#define STOP '|'
#define PERIOD '.'
#define RATE1 0.12589
#define RATE2 0.17901
#define RATE3 0.20971
#define BREAK1 360.0
#define BREAK2 680.0
#define BASE1 (RATE1 * BREAK1)
#define BASE2 (BASE1 + (RATE2 * (BREAK2 - BREAK1 )))
#define COVERAGE 200
#define RAISE 1.5
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
#define PRCNT 0.15
#define PRCNT1 0.28

#define ARTICHOKE 1.25
#define BEET 0.65
#define CARROT 0.89
#define S_F_DISCOUNT 100
#define DISCOUNT 0.05
#define TARIF1 3.50
#define TARIF2 10.0
#define TARIF3 8.0 
#define TARIF4 0.1 



const int FREEZING = 0;
const float MIN = 0.0f;
const float MAX = 100.0f;

void menu(void)
{
	printf("*********************************************************\n");
	printf("Enter number, corresponding rate for salary or action:\t*\n");
	printf("1) $8.74 per hour\t2) $9.33 per hour\t\t*\n");
	printf("3) $10.00 per hour\t4) $11.20 per hour\t\t*\n");
	printf("5) Exit\t\t\t\t\t\t\t*\n");
	printf("*********************************************************\n");
	return;
}

void menu1(void)
{
	printf("*********************************************************\n");
	printf("Elect category for yourself:\n");
	printf("1) Single\n2) Wage earner\n");
	printf("3) Marriege join\n4) Marriage separate \n");
	printf("5) Exit\n");
	printf("*********************************************************\n");
	return;
}



void listing_7_1(void)
{
	float temperature;
	int cold_days = 0;
	int all_days = 0;
	printf("Enter temperature list of days.\n");
	printf("Use Celsium scale; foe end programm enter [q].\n");
	while (scanf("%f", &temperature) == 1)
	{
		all_days++;
		if(temperature < FREEZING)
			cold_days++;
	}
	if (all_days != 0)
		printf("%d - all quantity of days: %.1f%% days with freezing temperature.\n",
			all_days, 100.0 * (float) cold_days / all_days);
	else
	printf("Data temperature didn't get!\n");

	return;
}

void listing_7_2(void)
{
	char ch;
	while ((ch = getchar()) != '\n')
	{
		if (ch == SPASE)
			putchar(ch);
		else 
			putchar(ch + 1);
	}
	putchar(ch);
	return;
}

void listing_7_3(void)
{
	char ch;
	while ((ch = getchar()) != '\n')
	{
		if (isalpha(ch))//функция isalpha()- возвращает 1 если не символ введен, 0 - если буква
			putchar(ch + 1);
		else 
			putchar(ch);
	}
	putchar(ch);
	return;
}

void listing_7_4(void)
{
	double kwh, bill;

	printf("Enter quantity of intake in [kwh].\n");
	scanf("%lf", &kwh);
	if (kwh <= BREAK1)
		bill = kwh * RATE1;
	else if (kwh <= BREAK2)
		bill = BASE1 + (RATE2 * (kwh - BREAK1));
	else if (kwh >= BREAK2)
		bill = BASE2 + (RATE3 * (kwh - BREAK2));
	printf("Amount to be paid for [%.1f] kwh = $%.2f.\n", kwh, bill);

	return;
}

void listing_7_5(void)
{
	unsigned long num;
	unsigned long div_;
	_Bool isPrime;
	printf("Enter integer number for analysis; ");
	printf("for ending push [q].\n");
	while(scanf("%lu", &num) == 1)
	{
		for (div_= 2, isPrime = true; (div_ * div_) <= num; div_++)
		{	
			if(num % div_ == 0)
			{
				if ((div_  * div_) != num)
					printf("%lu exchange on %lu and %lu.\n", num, div_, num / div_);
				else
					printf("%lu exchange on %lu.\n", num, div_);
				isPrime = false;
			}
		}
	if (isPrime)
		printf("%lu is a prime number.\n", num);
	printf("Enter next integer number for analysis; ");
	printf("for ending push [q].\n");
	}

	return;
}

void listing_7_6(void)
{
	int ch;
	int charcount = 0;
	while ((ch = getchar()) != PERIOD)
	{
		if (ch != '"' && ch != '\'')
		charcount++;
	}
	printf("there're %d characters contains in this senyence, no quotation marks.\n", charcount);
	return;
}

void listing_7_7(void)
{
	char c;						//считанный символ
	char prev;					//предыдущий считанный символ
	long n_chars = 0;			//счетчик символов
	int n_lines = 0;			//счетчик новых строк
	int n_words = 0;			//счетчик слов
	int p_lines = 0;			//колличество частичных слов
	_Bool inword = false;		// == true если внутри слова

	printf("Enter text for analys ( '|' - for end ): \n");
	prev = '\n';

	while ((c = getchar()) != STOP) // если не стоп-символ
	{
		n_chars++; //увеличивем счетчик символов
		if (c == '\n')
			n_lines++; //подсчет строк
		if (!isspace(c) && !inword)
		{
			inword = true;	//начало нового слова
			n_words++;		//подсчет нового слова
		}
		if (isspace(c) && inword)
			inword = false;
		prev = c;
	}
	if(prev != '\n')
		p_lines = 1;
	printf("Quantity of characters = %ld, quantity of words = %d, quantity "
		"of strings = %d, ", n_chars, n_words, n_lines);
	printf("Quantity of partial line = %d.\n", p_lines);

	return;
}

void listing_7_8(void)
{
	int sq_feet;
	int cans;

	printf("Enter quantity of squares for paint: \n");
	while (scanf("%d", &sq_feet) == 1)
	{
		cans = sq_feet / COVERAGE;
		cans += ((sq_feet % COVERAGE == 0)) ? 0 : 1;
		printf("For this nesecary %d %s of color.\n", cans, cans == 1 ? "can" : "cans");
		printf("Enter next quantity of squares for paint (or [q] for end): \n");
	}

	return;
}

void listing_7_9(void)
{
	float score;
	float total = 0.0f;
	int n = 0;
	float min = MAX;
	float max = MIN;

	printf("Enter result of first game (or [q] for end): ");
	while (scanf("%f", &score) == 1 )
	{
		if (score < MIN || score > MAX)
		{
			printf("%0.1f is illegal value. Repeate attempt: ", score);
			continue;
		}
		printf("Recieve %.1f:\n", score);
		min = (score < min) ? score : min;
		max = (score > max) ? score : max;
		total += score;
		n++;
		printf("Enter result of next game (or [q] for end): ");
	}
	if (n > 0)
	{
		printf("Avarage of %d results are %0.1f.\n", n , total / n);
		printf("Minimal = %0.1f, maximal = %0.1f.\n", min , max);
	}
	else
		printf("Allow results of game not input!\n");

	return;
}

void listing_7_10(void)
{
	float lenght, width;
	printf("Enter lenght of square: ");
	while (scanf("%f", &lenght) == 1)
	{
		printf("Lenght = %0.2f: \n", lenght);
		printf("ENter width of square: ");
		if (scanf("%f", &width) != 1)
			break;
		printf("Width = %0.2f: \n", width);
		printf("Square = %0.2f: \n", width * lenght);
		printf("Enter lenght of square: ");
	}
	printf("End of programm!\n");

	return;
}

void listing_7_11(void)
{
	char ch;

	printf("Give me letter of alphabet and I say you ");
	printf("nomber of animal which starts\n with this letter.\n");
	printf("Enter letter or [#] for ending.\n");
	while ((ch = getchar()) != '#')
	{
		if ('\n' == ch)
			continue;
		if (islower(ch)) //только строчные буквы
			switch (ch)
			{
				case 'a':
					printf("algari\n");
					break;
				case 'b':
					printf("babirusa\n");
					break;		
				case 'c':
					printf("coati\n");
					break;
				case 'd':
					printf("desman\n");
					break;
				case 'e':
					printf("echidna\n");
					break;
				case 'm':
					printf("marten\n");
					break;
				default :
					printf("It's a hard problem!\n");				
			}// конец оператора выбора
		else
			printf("Define only small letters!\n");
		while ((ch = getchar()) != '\n')
			continue;
		printf("Enter next letter or [#] for ending.\n");
	}
	printf("Programm is ending!\n");

	return;
}

void listing_7_12(void)
{
	char ch;
	int a_ct, e_ct, i_ct, o_ct, u_ct;
	a_ct = e_ct = i_ct = o_ct = u_ct = 0;
	printf("Enter text or [#] for ending\n");
	while ((ch = getchar()) != '#')
	{
		switch(ch)
		{
			case 'a' :
			case 'A' : a_ct++;
						break;
			case 'e' :
			case 'E' : e_ct++;
						break;
			case 'i' :
			case 'I' : i_ct++;
						break;
			case 'o' :
			case 'O' : o_ct++;
						break;
			case 'u' :
			case 'U' : u_ct++;
						break;
			default: break;
		}
	}
	printf("Quantity of vowels: A   E   I   O   U\n");
	printf("                 %4d%4d%4d%4d%4d\n", a_ct, e_ct, i_ct, o_ct, u_ct);


	return;
}

void drill_1(void)
{
	char ch;
	int space, newline, otherChar;
	space = newline = otherChar = 0;
	printf("Enter characters: \n");
	while((ch = getchar()) != '#')
	{
		if(ch == ' ')
			space++;
		else if (ch == '\n')
			newline++;
		else 
			otherChar++;
	}
	printf("\nQuantity of space = %d\nQuantity of newline = %d\n"
		"Quantity of other = %d\n", space, newline, otherChar);

	return;
}

void drill_2(void)
{
	char ch;
	int i = 0;
	printf("Enter characters: \n");
	while((ch = getchar()) != '#')
	{
		if (ch == '\n')
		{
			printf("\n");
			i = 0;
			continue;
		}
			
		if( i != 0 && i % 8 == 0)
		{
			printf("\n");
			printf("\t[%c] = [%d]", ch, ch);
		}
		else
			printf("\t[%c] = [%d]", ch, ch);
		i++;
		
	}

	return;
}

void drill_3(void)
{
	int e, o, num, even, odd;
	e = o = num = even = odd = 0;
	printf("Enter integer number ( [0] - for ending): ");
	while( (scanf("%d", &num)) != 0 && num != 0)
	{
		if (num % 2 == 0)
		{
			e++;	
			even += num;
		}		
		else
		{
			o++;
			odd += num;
		}
		printf("Enter next integer number ( [0] - for ending): ");

	}

	printf("Quantity of even integer = %d\n", e);
	printf("Avarege value of odd integer = %.2f\n", (float)even / e);	
	printf("Quantity of odd integer = %d\n", o);
	printf("Avarege value of even integer = %.2f\n", (float)odd / o);

	return;
}

void drill_4(void)
{
	char ch;
	int i = 0, l = 0;
	while((ch = getchar()) != '#')
	{
		if(ch == '.')
		{
			ch = '!';	
			i++;
		}
		else if (ch == '!')
		{
			ch = '!';
			putchar('!');
			l++;
		}

		putchar(ch);
	}
	printf("Quantity of displacement [.] = %d\n", i);
	printf("Quantity of displacement [!!] = %d\n", l);
	return;
}


void drill_5(void)
{
	int e, o, num, even, odd;
	e = o = num = even = odd = 0;
	printf("Enter integer number ( [0] - for ending): ");
	while( (scanf("%d", &num)) != 0 && num != 0)
	{
		switch(num % 2)
		{
			case 0 :
			{
				e++;
				even += num;
				break;
			}	
			case 1 :
			{
				o++;
				odd += num;
				break;
			}		
		}
		printf("Enter next integer number ( [0] - for ending): ");
	}

	printf("Quantity of even integer = %d\n", e);
	printf("Avarege value of odd integer = %.2f\n", (float)even / e);	
	printf("Quantity of odd integer = %d\n", o);
	printf("Avarege value of even integer = %.2f\n", (float)odd / o);

	return;
}
void drill_6(void)
{
	int i = 0, l = 0;
	char ch;
	printf("Enter message ( [#] - for ending): \n");
	while( (ch = getchar()) != '#')
	{
		if (i == 1 && ch == 'i')
		{
			i = 0;
			l++;
		}
		else if (ch == 'e')
			i++;
		else
			i = 0;
	}

	printf("Quantity of slab [ei] = %d\n", l);

	return;
}

void drill_7(void)
{
	float a, b, h;
	printf("Enter the working hours: ");
	while ((scanf("%f", &h)) == 1)
	{
		a = b = 0.0;
		if(h <= 0.0)
		{
			printf(" ERROR!!! [Nesecary unsigned value]\n");
			printf("Enter the working hours: ");
			continue;
		}

		if (h < 40.0 )
			a = h * TARIFE;
		else
			a = STOP1 + ((h - TIME) * RAISE * TARIFE);

		if (a < DUTY1)
			b = a * PERSENT1;
		else if (a >= DUTY1 && a < DUTY2) 
			b = TAX1 + ((a - DUTY1) * PERSENT2);
		else if(a >= DUTY2)
			b = TAX2 + ((a - DUTY2) * PERSENT3);


		printf("Without take-home pay = %.3f\n", a);
		printf("Contribution = %.3f\n", b);
		printf("Take-home pay = %.3f\n\n", a - b);

		printf("Enter the working hours: ");
	}

	return;
}

void drill_8(void)
{
	int i = 0;
	float a, b, h, TARIFE1;
	menu();
	while ((scanf("%d", &i)) != 0 && i > 0 && i < 5)
	{
		switch(i)
		{
			case 1 : TARIFE1 = 8.74;
				break;
			case 2 : TARIFE1 = 9.33;
				break;
			case 3 : TARIFE1 = 10.00;
				break;
			case 4 : TARIFE1 = 11.20;
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
		

	return;
}

void drill_9(void)
{
	int d;
	_Bool t_f;
	printf("Enter integer number [ or character for ending ]: ");
	while((scanf("%d", &d)) == 1)
	{
		printf("Prime numbers before %d are:\n ", d);
		for (int i = 2; i <= d; i++ )
		{	
			t_f = true;
			for (int k = 2; (k * k) <= i; k++)
			{		
				if ((i % k) == 0)
				{
					t_f = false;
					break;
				}
			}
			if (t_f == true)
				printf("%4d, ", i);
		}
		printf("\b\b.\n\nEnter integer number [ or character for ending ]: ");
	}
	return;
}

void drill_10(void)
{
	int i = 0;
	float contrb = 0, salary, TARIFE1;
	menu1();
	while ((scanf("%d", &i)) != 0 && i > 0 && i < 5)
	{
		switch(i)
		{
			case 1 : TARIFE1 = 17850;
				break;
			case 2 : TARIFE1 = 23900;
				break;
			case 3 : TARIFE1 = 29750;
				break;
			case 4 : TARIFE1 = 14875;
				break;
		}
		printf("Enter your salary: ");
		if ((scanf("%f", &salary)) == 1)
		{
			if (salary < TARIFE1)
				contrb = salary * PRCNT;
			else if (salary >= TARIFE1)
				contrb = PRCNT1 * (salary - TARIFE1) + TARIFE1 * PRCNT;
			printf("Contribution consists = %.3f\n\n\n", contrb);
		}
		menu1();
	}

	return;
}

void drill_11(void)
{
	char ch;
	float a, b, c, a1, b1, c1, w = 0, sum = 0, disc = 0, dlvr = 0;
	a = b = c = 0;

	printf("Enter your order in pounds:\n[a] - for weight artichoke;\n"
		   "[b] - for weight beet;\n[c] - for weight carrot;\n"
		   "[q] - for EXIT.\n");
	while ((scanf("%c", &ch)) != 0 && ch != 'q')
	{
		if (ch == 'a' || ch == 'b' || ch == 'c')
			switch(ch)
			{
				case 'a':
				{
					printf("Enter weight of artichoke: ");
					scanf("%f", &a1);
					a += a1;
					break;
				}
				case 'b':
				{
					printf("Enter weight of beet: ");
					scanf("%f", &b1);
					b += b1;
					break;
				}
				case 'c':
				{
					printf("Enter weight of carrot: ");
					scanf("%f", &c1);
					c += c1;
					break;
				}
			}
		else 
		{	
			printf("What else?\n");
			continue;	
		}
	}
	getchar();
	w = a + b + c; //общая сумма веса продуктов
	sum = a * ARTICHOKE + b * BEET + c * CARROT;
	disc = (sum >= S_F_DISCOUNT) ? sum * DISCOUNT : 0; // скидка
	if (w < 5) // сумма за доставку
		dlvr += TARIF1;
	else if (w >= 5 && w < 20)
		dlvr += (TARIF1 + TARIF2);
	else if (w >= 20)
		dlvr = TARIF1 + TARIF2 + TARIF3 + ((w - 20) * TARIF4);
	

	printf("\tCost artichoke per pound - [%.2f$]\n", ARTICHOKE);
	printf("\tCost beet per pound - [%.2f$]\n", BEET);
	printf("\tCost carrot per pound - [%.2f$]\n\n", CARROT);

	printf("\tOrdered artichoke pounds: %.2f\n", a);
	printf("\tOrdered beet pounds: %.2f\n", b);
	printf("\tOrdered carrot pounds: %.2f\n\n", c);

	printf("\tValue for artichoke: %.2f$\n", a * ARTICHOKE);
	printf("\tValue for beet: %.2f$\n", b * BEET);
	printf("\tValue for carrot: %.2f$\n\n", c * CARROT);

	printf("\tTotal cost every vegitable: %.2f$\n\n", sum);

	printf("\tDiscount: %.2f$\n\n", disc);

	printf("\tDelivery: %.2f$\n\n", dlvr);

	printf("\tTOTAL COST (with delivery): %.2f$\n", sum - disc + dlvr);
	return;
}

void main (void)

{
	//listing_7_1();
	//listing_7_2();
	//listing_7_3();
	//listing_7_4();
	//listing_7_5();
	//listing_7_6();
	//listing_7_7();
	//listing_7_8();
	//listing_7_9();
	//listing_7_10();
	//listing_7_11();
	//listing_7_12();

	//drill_1();
	//drill_2();
	//drill_3();
	//drill_4();
	//drill_5();
	drill_6();
	//drill_7();
	//drill_8();
	//drill_9();
	//drill_10();
	//drill_11();
	
	return;
}