#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MSG "you must have a lot of talents. Call others" //константа символьной строки
#define LIM 5
#define LINELEN 81
#define MAX 81
#define MAX40 40
#define SIZE 80
#define STR 3
#define SIZE30 30
#define BUGSIZE 11
#define DEF "I'm a line specified with command #define"
#define ANSWER "GRANT"
#define SIZE81 81
#define LIM100 100
#define LISTSIZE 5
#define STOP "quit"
#define WORDS "beast"
#define SIZE40 40
#define LIM5 5
#define LIM80 80
#define SIZE81 81
#define LIM20 20
#define HALT ""
#define TARGSIZE 7
#define MAX20 20

void put1(const char * string)
{
	while(*string != '\0')
		putchar(*string++); 
	return;
}


int put2(const char * string)
{
	int count = 0;
	while(*string)
	{
		putchar(*string++); 
		count++;
	}
	putchar ('\n');//пропуск символа новой строки
	return(count);
}

void fit(char *string, unsigned int size)
{
	if (strlen (string) > size)
		*(string + size) = '\0';
}

void stsrt(char * strings[], int num)
{
	char *temp;
	int top, seek;

	for (top = 0; top < num - 1; top++)
		for (seek = top + 1; seek < num; seek++)
			if(strcmp(strings[top], strings[seek]) > 0)
			{
				temp = strings[top];
				printf("%c\n", *strings[top]);
				strings[top] = strings[seek];
				strings[seek] = temp;
			}

	return;
}

void ToUpper(char * str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}

	return;
}

int PunctCount(const char * str)
{
	int ct = 0;
	while (*str)
	{
		printf("%c, %p\n", *str, str);
		if(ispunct(*str))
			ct++;
		str++;
	}

	return ct;
}

char * getnchar(char * str, int n)
{
	int ch;
	int i;

	for (i = 0; i < n; i++)
	{
		ch = getchar();
		if(ch != EOF)
			str[i] = ch;
		else
			break;
	}

	if (ch == EOF)
		return NULL;
	else
	{
		*(str + i) = '\0';
		return str;
	}
}

char * getnchar1(char * str, int n)
{
	int ch;
	int i;

	for (i = 0; i < n; i++)
	{
		ch = getchar();
		if(ch != EOF && ch != ' ' && ch != '\n' && ch != '\t')
			str[i] = ch;
		else
			break;
	}

	if (ch == EOF)
		return NULL;
	else
	{
		*(str + i) = '\0';
		return str;
	}
}

char * getnchar3(char * str) //принимает указатель и возвращает тип указателя
{
	int ch;
	char * orig = str;
	while ((ch = getchar()) != EOF && isspace(ch))
		continue;
	if (ch == EOF)
		return NULL;
	else
	{
		*str++ = ch;
	}


	while ((ch = getchar()) != EOF && !isspace(ch))
		*str++ = ch;
	*str = '\0';
	if (ch == EOF)
		return NULL;
	else
	{
		while (ch != '\n')
			ch = getchar();
		return orig;
	}
}

char * strchr1(char *str , char ch)
{
	while (*str != ch)
	{
		if(*str == '\0')
			return NULL;
		str++;
		continue;
	}
	return str;
}

char tr_fls(char ch, char * line)
{
	char * ptr = line;
	while ( *ptr != '\0')
	{
		if (*ptr == ch)
		{
			return true;
		}
		ptr++;
	}
	if (*ptr == '\n')
		return false;
}

char * strncpy1(char * line1, char * line, int qnt)
{
	char * l = line1;
	for (;qnt > 0; qnt--)
	{
		if (*line != '\0');
		else break;
		*line1++ = *line++;
	}

	return l;
}

char * string_in (char * line, char * line1) //	char line[SIZE] = "hats";
											 // char line1[SIZE] = "at";
{
	char * ptr = line1;
	char * return_ptr;
	int count = 0;

	while (*line != '\0')
	{
		if (*line == *line1 && * line1 != '\0')
		{
			count++;
			line1++;
			if (count == 1)
				return_ptr = line;
		}
		if (*line1 == '\0' && count != 0)
			return return_ptr;
		if (*line1 == '\0' && count == 0)
			return NULL;
		line++;
	}
	return NULL;
}

void invers(char * line)
{
	char * begin;
	char * end;
	char temp;

	begin = line; //адрес первого (0) элемента массива
	end = line + strlen(line) - 1;
	printf("\n%d\n", strlen(line));

	for (int i = 0; i < strlen(line) / 2; i++)
	{
		temp = *begin; //запись первого символа массива
		*begin = *end; //запись значения последнего символа в первый элемент масиива
		*end = temp;   //запись в последний элемент массива первого
		begin++;
		end--;
	}

	return;
}

char * s_gets(char * st, int n)
{
	printf("\n%c\n", *st);
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin); //функция fgets принимает указатель на массивб колличество эдементов которое, и откуда будем принимать данные 
	printf("\n%c\n", *ret_val);
	if (ret_val)
	{
		find = strchr(st, '\n'); //адрес строки 
		if (find)
			*find = '\0';  //помещаем в этот адрес символ конца строки 
		else 
			while (getchar() != '\n')
				continue;
	}

	printf("%c\n", *ret_val);
	return ret_val; //возврацает адес начала массива
}

int drop_space(char * s)
{
	char * pos;
	while (*s) //до тех пор пока *s != '\0'
	{
		if (*s == ' ')
		{
			pos = s;
			do 
			{
				* pos = *(pos + 1); 
				pos++; 
			}
			while (*pos); //если позиция не равна '\0'
		}
		else 
			s++;
	}
	return 1;
}

char * s_gets1(char * st, int n)
{
	return fgets(st, n, stdin);
}

void print_strings(char * (*ptr), int str) // как я понимаю тип данных [указатель на char] и само значение перезаваемое функцией является указателем
{
	//printf("---------------- ptr = %p\n", *ptr); //разыменовывание указателя дает нам адрес
	for (int i = 0; i < str; i++)
	{
		//printf("%d\n", strlen(*(ptr + i)));
		for(int l = 0; l < strlen(*(ptr + i)); l++)	
			printf("%c", *(*(ptr + i) + l) );
	}
	puts("");
	return;
}

void print_strings_ASCII( char* strptr[], int str)
{
	char * temp;
	//for(int i = 0; i < str; i++)
	//	printf("%c\n", *strptr[i]);
	char *array[str];
	for(int i = 0; i < str; i++)
	{
		array[i] = strptr[i];
		//printf("%p\n", array[i]);			
	}

	for(int i = 0; i < (str - 1); i++)
	{
		for (int l = i + 1; l < str; l++)
		{
			if(*array[l] < *array[i])
			{
				temp = array[i];
				array[i] = array[l];
				array[l] = temp;
			}
		}
	}
	for(int i = 0; i < str; i++)
		fputs(array[i], stdout);
		//printf("%p\t%c\t%d\t\n", array[i], *array[i], strlen(array[i]), fputs(array[i], stdout));			
	puts("");
	return;
}

void print_strings_increasing_length(char* strptr[], int str)
{
	char * array[str];
	for(int i = 0; i < str; i++)
		array[i] = strptr[i];
	char *temp;

	for(int i = 0; i < (str - 1); i++)
	{
		for (int l = i + 1; l < str; l++)
		{
			if(strlen(array[l]) < strlen(array[i]))
			{
				temp = array[i];
				array[i] = array[l];
				array[l] = temp;
			}
		}
	}	
	for (int i = 0; i < str; i++)
		fputs(array[i], stdout);

	puts("");

	return;	
}

void print_strings_increasing_length_ffirst_word(char * strptr[], int str)
{
	char * array[str];
	for(int i = 0; i < str; i++)
		array[i] = strptr[i];
	char * temp;

	for (int i = 0; i < (str - 1); i++) //это счетчик перебирающий первый элемент их 2-х
	{
		int count = -1, count1 = -1;
		char ch, ch1;

		do
		{	
			count++;
			ch = array[i][count];
		}
		while (ch != isspace(ch));
		//printf("%d\n", count);
		for (int j =  i + 1; j < str; j++) //счетчик для второго элемента
		{
			do
			{
				count1++;
				ch1 = array[i][count1];
			}
			while (ch1 != isspace(ch1));

			if (count1 > count)
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}			
		}
	}

	for(int i = 0; i < str; i++)
		fputs(array[i], stdout);

	puts("");

	return;
}

void listing_11_1(void)
{
	char name[LINELEN];
	char talents[LINELEN];

	const char m1[40] = "Try pack in one line.";

	const char m2[] = "If you thing nothing invent whatever.";

	const char *m3 = "\nThat's all, sufficient about me, what's your name?"; // инициализация и декларация указателя

	const char *mytal[LIM] = { //массив указателей на строку, массив из 5 указателей
		"Momentary adding numbers",
		"Exact increase", "Accumulation of data",
		"Execution instructions accurate to last characters",
		"Knowing program language"
	};

	printf("Hello! I'm computer, my name Klade. I have a lot of talents.\n");
	printf("Now I tell about it.\n");
	puts("What kind of talents? There're partial list\n"); 
	for(int i = 0; i < LIM; i++)
		puts(mytal[i]); //печать массива указателей mytal
	puts(m3);
	gets(name);
	printf("Good, %s, %s\n", name, MSG);
	printf("%s\n%s\n", m1, m2);
	gets(talents);
	puts("Look, have I some of this list:");
	puts(talents);
	printf("Thank you for informatoin, %s.\n", name);

 	return;	
}

void listing_11_2(void)
{
	printf("%s, %p, %c\n", "We", "are", *"space farers");
 	return;	
}

void listing_11_3(void)
{
	const char * mesg = "Keep out of confuse you!";
	const char * copy;
	copy = mesg;
	printf("%s\n", copy);
	printf("mesg = %s; mesg = %p; value = %p\n", mesg, &mesg, mesg);
	printf("copy = %s; copy = %p; value = %p\n", copy, &copy, copy);
 	return;	
}

void listing_11_4(void)
{
	char name[MAX]; //выделяем пространство в памяти//
	printf("What's your name?\n");
	gets(name);     //помещение строки в массив
	printf("Beautiful name, %s!\n", name);
	return;	
}

void listing_11_5(void)
{
	char name[MAX]; //выделяем пространство в памяти//
	char * ptr;
	printf("What's your name?\n");
	ptr = gets(name);     //помещение строки в массив
	printf("%s? A! %s!\n", name, ptr);
	return;	
}

void listing_11_6(void)
{
	char name[MAX]; //выделяем пространство в памяти//
	char * ptr;
	printf("What's your name?\n");
	ptr = fgets(name, MAX, stdin);
	printf("%s? A! %s!\n", name, ptr);
	return;	
}

void listing_11_7(void)
{
	char name1[11], name2[11];
	int count;

	printf("Please, enter two name.\n");
	count = scanf("%5s %10s", name1, name2);
	printf("Read %d names: %s and %s.\n", count, name1, name2);

	return;
}

void listing_11_8(void)
{
	char str1[80] = "Array was initialization with my value.";
	const char * str2 = "Pointer was initialization with my value.";
	puts("I'm argument of function puts()");
	puts(DEF);
	puts(str1);
	puts(str2);
	puts(&str1[2]);
	puts(str2 + 4);

	return;	
}

void listing_11_9(void)
{
	char side_a[] = "Side A";
	char dont[] = {'W', 'A', 'W', '!' };
	char side_b[] = "Side B";

	puts(dont); //dont не строка

	return;	
}

/*void listing_11_10(void)
{
	void put1(const char * string)
	{
		while(*string != '\0')
			putchar(*string++); 
	}

	return;	
}

/*
int listing_11_11(void)
{
	int put2(const char * string)
	{
		while(*string)
		{
			putchar(*string++); 
			count++;
		}
		putchar ('\n');//пропуск символа новой строки
		return(count);
	}

	return;	
}
*/

void listing_11_12(void)
{
	put1("If I have so much money, ");
	put1("how much I may spen?\n");
	printf("There're have %d characters.\n", put2("I would never repair old things."));

	return;	
}

void listing_11_13(void)
{
	char mesg[] = "Things should be as simple as possible "
					"but not as simple as that.";
	puts(mesg);
	fit(mesg, 37);
	puts(mesg);
	puts("Consider a few more lines");
	puts(mesg + 38);

	return;	
}

void listing_11_14(void)
{
	char flower[SIZE];
	char addon[] = " small like a old felt boots.";
	puts("What is your favourite flower?");
	gets(flower); //функция gets позволяет записать строковый массив
	strcat(flower, addon); //string concatention - связывание "строк"
	puts(flower);
	puts(addon);

	return;	
}

void listing_11_15(void)
{
	char flower[SIZE30];
	char addon[] = " small like a old felt boots.";
	char bug[BUGSIZE];
	int available;
	puts("What is your favourite flower?");
	gets(flower); //функция gets позволяет записать строковый массив
	if ((strlen(addon) + strlen(flower) + 1) <= SIZE30)
		strcat(flower, addon);
	puts(flower);
	puts("What is your favourite bug?");
	gets(bug);
	available = BUGSIZE - strlen(bug) - 1;
	strncat(bug, addon, available);
	puts(bug);

	return;	
}

void listing_11_16(void)
{
	char try[40];
	puts("Who bury in grave \"Grant\"");
	gets(try);
	while(try != ANSWER)
	{
		puts("No, not right! Try again.");
		gets(try);
	}
	puts("Now you're right!");

	return;	
}

void listing_11_17(void)
{
	char try[MAX40];
	puts("Who bury in grave \"Grant\"");
	gets(try);
	while(strcmp(try, ANSWER))
	{
		puts("No, not right! Try again.");
		gets(try);
	}
	puts("Now you're right!");

	return;	
}

void listing_11_18(void)
{
	printf("strcmp(\"A\", \"A\") mismo ");
	printf("%d\n", strcmp("A", "A"));

	printf("strcmp(\"A\", \"b\") mismo ");
	printf("%d\n", strcmp("A", "b"));

	printf("strcmp(\"B\", \"A\") mismo ");
	printf("%d\n", strcmp("B", "A"));

	printf("strcmp(\"C\", \"A\") mismo ");
	printf("%d\n", strcmp("C", "A"));

	printf("strcmp(\"Z\", \"a\") mismo ");
	printf("%d\n", strcmp("Z", "a"));

	printf("strcmp(\"apples\", \"apple\") mismo ");
	printf("%d\n", strcmp("apples", "apple"));

	return;	
}

void listing_11_19(void)
{
	char input[LIM100][SIZE81];
	int ct = 0;
	printf("Enter no more %d lines (or quit for ending):\n", LIM100);
	while(ct < LIM100 && gets(input[ct]) != NULL
					  && input[ct][0] != '\0')
	{
		ct++;
	}
	printf("Enter %d lines.\n", ct);

	return;	
}

void listing_11_20(void)
{
	const char * list[LISTSIZE] =
	{
		"astronomy", "astounding",
		"astrophysics", "ostracize",
		"asterism"
	};
	int count = 0;
	int i;

	for (i = 0; i < LISTSIZE; i++)
		if (strncmp(list[i], "astro", 5) == 0)
		{
			printf("Find: %s\n", list[i]);
			count++;
		}
	printf("List consists %d words, start with \"astro\"", count);

	return;	
}

void listing_11_21(void)
{
	char qwords[LIM5][SIZE40];
	char temp[SIZE40];
	int i = 0;
	printf("Enter %d word, start with [q]:\n", LIM);
	while (i < LIM5 && gets(temp))
	{
		if (temp[0] != 'q')
			printf("%s no start with [q]");
		else 
		{
			strcpy(qwords[i], temp);
			i++;
		}
	}
	puts("List words meet certain conditions:\n");
	for (i = 0; i < LIM5; i++)
		puts(qwords[i]);

	return;	
}

void listing_11_22(void)
{
	const char * orig = WORDS;
	char copy[SIZE40] = "Be the best that you can be.";
	char * ps;

	puts (orig);
	puts (copy);
	ps = strcpy(copy + 7, orig);
	puts(copy);
	puts(ps);

	return;	
}

void listing_11_23(void)
{
	char qwords[LIM5][TARGSIZE];
	char temp[SIZE40];
	int i = 0;
	printf("Enter %d word, start with [q]:\n", LIM);
	while (i < LIM5 && gets(temp))
	{
		if (temp[0] != 'q')
			printf("%s no start with [q]");
		else 
		{
			strncpy(qwords[i], temp, TARGSIZE - 1);
			qwords[i][TARGSIZE - 1] = '\0';
			i++;
		}
	}
	puts("List words meet certain conditions:\n");
	for (i = 0; i < LIM5; i++)
		puts(qwords[i]);

	return;	
}

void listing_11_24(void)
{
	char first[MAX40];
	char last[MAX40];
	char formal[2 * MAX40 + 10];
	double prize;

	puts("Enter your name:");
	gets(first);

	puts("Enter your surname:");
	gets(last);

	puts("Enter money prize:");
	scanf("%lf", &prize);

	sprintf(formal, "%s, %-19s: $%6.2f\n", last, first, prize);
	puts(formal);

	return;	
}

void listing_11_25(void)
{
	char input[LIM20][SIZE81];
	char *ptstr[LIM20];
	int ct = 0;
	int k;

	printf("Enter no more %d lines and its will be sort.\n", LIM20);
	printf("If you want stop input, press key Enter in inception of line.\n");
	while(ct < LIM20 && gets(input[ct]) != NULL
					 && input[ct][0] != '\0')
	{
		ptstr[ct] = input[ct];
		ct++;
	}

	stsrt(ptstr, ct);
	puts("\n Sort list:\n");
	for (k = 0; k < ct; k++)
		puts(ptstr[k]);

	return;	
}

void listing_11_26(void)
{
	char line[LIM80];
	puts ("Enter a line:\n");
	gets (line);
	ToUpper(line);
	puts(line);
	printf("This line consists %d punctuation marks.\n", PunctCount(line)); 

	return;	
}

void listing_11_27(void)
{
	char line[LIM80];
	puts ("Enter a line:\n");
	gets (line);
	ToUpper(line);
	puts(line);
	printf("This line consists %d punctuation marks.\n", PunctCount(line)); 

	return;	
}

/*void listing_11_28(void)
{
	int i, times;
	if(argc < 2 || (times = atoi(argv[1])) < 1)
		printf("Using: %s positive number\n", argv[0]);
	else 
		for(i = 0; i < times; i++)
			puts("All good!");
	return;	
}*/

void listing_11_29(void)
{
	char number[30];
	char * end;
	long value;

	puts("Enter number or empty line for ending prugramm.\n");	
	while(gets(number) && number[0] != '\0')
	{
		value = strtol(number, &end, 10);
		printf("Value: %ld finish on %s (%d)\n", value, end, *end);

    	value = strtol(number, &end, 16);
		printf("Value: %ld finish on %s (%d)\n", value, end, *end);

		puts("Next number:\n");
		
	}
	puts("Keep fit!");

	return;	
}

void task1(void)
{
	char note[] = "Let's see you in cafe";
	char *ptr;
	ptr = note;
	puts(ptr);
	puts(++ptr);
	puts(ptr++);
	puts(++ptr);

	note[7] = '\0';
	puts(note);

	return;
}

char * pr (char *str)
{
	char *pc;
	pc = str;
	printf("%p %x %c\n", str, str, str);
	printf("%p %x %c\n", *str, *str, *str);
	while(*pc)
	{
		printf("!");
		putchar(*pc++);
	}
	do 
	{
		putchar(*--pc);
	}
	while (pc - str);
	return(pc);
}

char * task10(char *ptr)
{
	while(*ptr != ' ' && *ptr != '\0')
		ptr++;
	if(*ptr == '\0')
		return NULL;
	
	return ptr;
}

void task11(void)
{
	char try[MAX40];
	puts("Who bury in grave \"Grant\"");
	gets(try);
	for (int i = 0; try[i] != '\0'; i++)
	{
		if (try[i] >= 97 && try[i] <= 122)
			{
				try[i] = try[i] - 32;
				printf("%d %c\n", i, try[i]);
			}
	}

	while(strcmp(try, ANSWER))
	{
		puts("No, not right! Try again.");
		gets(try);
	}
	puts("Now you're right!");

	return;	
}

void drill_1 (void)
{
	printf("Hi! Enter other's frases!\n");
	char line[SIZE30];
	char *check; //создание указателя

	check = getnchar(line, SIZE30 - 1);//по этому адресу вызываем функцию getnchar
	if(check == NULL)
		puts("Input failed!");
	else 
		puts(line);
	puts("Done!\n");
	return;	
}

void drill_2 (void)
{
	printf("Hi! Enter other's frases!\n");
	char line[SIZE30];
	char *check; //создание указателя

	check = getnchar1(line, SIZE30 - 1);//по этому адресу вызываем функцию getnchar
	if(check == NULL)
		puts("Input failed!");
	else 
		puts(line);
	puts("Done!\n");
	return;	
}

void drill_3 (void)
{
	printf("Hi! Enter other's frases!\n");
	char line[SIZE30];
	char *check; //создание указателя

	check = getnchar3(line);//по этому адресу вызываем функцию getnchar
	if(check == NULL) //если указатель указаывает на 0 то "Input failed!"
		puts("Input failed!");
	else 
		puts(line); //иначе выводим слово
	puts("Done!\n");
	return;	
}

void drill_4 (void)
{
	printf("Hi! Enter other's frases!\n");
	char line[SIZE];
	gets(line);
	char chrctr;
	printf("What character find?\n");
	scanf("%c", &chrctr);

	char *check = line; //создание указателя
	printf("%p\n", line);
	printf("%p\n", check + 6);

	printf("%p\n", strchr(line, chrctr));

	printf("\n%p\n", check = strchr1(line, chrctr));

	if(check == NULL) //если указатель указаывает на 0 то "Input failed!"
		puts("Not found!");
	else 
		puts(line); //иначе выводим слово
	puts("Done!\n");
	return;	
}

void drill_5 (void)
{
	char line[SIZE];
	char character;
	char ans;
	printf("Hi! Print any frases!\n");
	gets(line);
	printf("What character find?\n");
	scanf("%c", &character);

	ans = tr_fls(character, line);
	if (ans == true)
		printf("%s", "true");
	else
		printf("%s", "false");

	return;	
}

void drill_6 (void)
{
	char line[SIZE];
	char line1[SIZE];
	char * ptr = line1;
	int qnt;
	printf("Hi! Print any frases!\n");
	gets(line);
	printf("How much characters copy?\n");
	scanf("%d", &qnt);

	printf("line:  %s\n", line);
	printf("line1: %s\n", line1);

    strncpy1(line1, line, qnt);
	//strncpy(line1, line, qnt);
    while(*ptr != '\0')
    {
        printf ("%c", *ptr);
        ptr++;
    }

	return;	
}

void drill_7 (void)
{
	char line[BUGSIZE] = "hats love";
	char line1[BUGSIZE] = "ol";
	char * ptr = NULL;
	printf("return pointer:\t%p\n", ptr);

	for (int i = 0; i < BUGSIZE; i++)
		printf("%d:\t%p\t%c\n", i, &line[i], line[i]);
	printf("\n");

	for (int i = 0; i < BUGSIZE; i++)
		printf("%d:\t%p\t%c\n", i, &line1[i], line1[i]);

	ptr = string_in(line, line1);
	if (ptr == NULL)
		printf("return pointer:\t%p\n",ptr);
	else
		printf("return pointer:\t%p\ncharacter:\t%c",ptr, *ptr);

	return;	
}

void drill_8 (void)
{
	char line[SIZE] = DEF;
	printf("%p\n", line);
	for(int i = 0; i < SIZE; i++)
		printf("%c", *(line + i));
	invers(line);
	printf("\n");
	for(int i = 0; i < SIZE; i++)
		printf("%c", *(line + i));

	return;	
}

void drill_9 (void)
{
	char orig[SIZE];
	puts("Enter a string  of 80 characters or less:");
	while (s_gets(orig, SIZE) && orig[0] != '\0') //до тех пор пока будет s_gets == 1 И нулевой жлемент массива не равен концу строки
	{
		drop_space(orig);
		puts(orig);
		puts("Enter next string (or just Enter to quit)");
	}
	printf("Bye!");
	return;	
}

void drill_10 (void)
{
	char s[STR][SIZE]; //создание двумерного массива
	char *strptr[STR]; //сосздание массива из 10 указателей
	int cnt = 0;

	for (int i = 0; i < STR; i++)
	{
		strptr[i] = s[i]; //запись указателя на начало каждой строки
		//printf("\n%p\t%x\n", s[i], strptr[i]);
	}

	printf("Enter %d string  or [Ctr + Z] for finish.\n", STR);
	while (s_gets1(s[cnt], SIZE) && *s[cnt] != EOF) // EOF == '\0'
		{
			//printf("%p\n", s[cnt]);
			cnt++;
			//printf("%d\n\n", cnt);
			if (cnt == STR)
				break;			//ввод 10 строк
		}

	//for(int i = 0; i < STR; i++)//вывод на экран этих 10 строк для проверки
	//	printf("%s\n", s[i]);

		int nmb = 0; 	//вводимый номер
		char ch; 		//для вводимых символов
		int i;  	 	//маркер состояния ввода 
		while (1)
		{
			puts("Operations:");
			puts("1. Print initial strings;");
       		puts("2. Print the strings in ASCII collating sequence");
       		puts("3. Print the strings in order of increasing length");
       		puts("4. Print the strings in order of the length of the first word in the string");
       		puts("5. quit");
       		printf("Please choose number of operation: ");

			i = scanf("%d", &nmb);
			if (i == 0)
			{
				printf("\n");
				while((ch = getchar()) != '\n')
					putchar(ch);
				printf(" no is integer number!.Try one more!\n");
				continue;			
			}
			else if (i == 1)
			{
				switch(nmb)
       		{
       			case 1 : print_strings(strptr, STR);
       					break;
       			case 2 : print_strings_ASCII(strptr, STR);
       					break;
       			case 3 : print_strings_increasing_length(strptr, STR);
       					break;
       			case 4 : print_strings_increasing_length_ffirst_word(strptr, STR);
       					break;
				case 5 : puts("Exit.");
						return;
				default  : puts("Error! Try one more!");
							break;
       		}
       	}
    }

	return;	
}

void drill_11(void)
{
	char ch;
	int count_words = 0;
	int count_lower = 0;
	int count_upper = 0;
	int count_punctuation_marks = 0;
	int count_numbers = 0;

	puts("Enter anything!");
	while((ch = getchar()) != EOF)
	{
		if(isdigit(ch))
			count_numbers++;
		else if(ispunct(ch))
			count_punctuation_marks++;
		else if(isspace(ch) || ispunct(ch))
			count_words++;
		else if(islower(ch))
			count_lower++;
		else if(isupper(ch))
			count_upper++;

	}
	printf("Quantity of words:\t%d\n", count_words);
	printf("Quantity of numbers:\t%d\n", count_numbers);
	printf("Quantity of punctuation marks:\t%d\n", count_punctuation_marks);
	printf("Quantity of lowercase characters:\t%d\n", count_lower);
	printf("Quantity of uppercase characters:\t%d\n", count_upper);

	return;
}

int drill_14(char * ch)
{
	int count = 0;
	int cnt = 0;

	while(*ch != '\0')
	{
		if(*ch < '0' || *ch > '9')
			return count;

		cnt++;

		if(cnt == 1) //если первый символ то его просто оставляем
			count = *ch - '0';
		else //если после первого символа
			count = count * 10 + *ch - '0';

		ch++;
	}

	return count;
}


void main (void)
{
	//listing_11_1();
	//listing_11_2();	
	//listing_11_3();
	//listing_11_4();
	//listing_11_5();
	//listing_11_6();
	//listing_11_7();
	//listing_11_8();
	//listing_11_9();
	//listing_11_10();
	//listing_11_11();
	//listing_11_12();
	//listing_11_13();
	//listing_11_14();
	//listing_11_15();
	//listing_11_16();
	//listing_11_17();
	//listing_11_18();
	//listing_11_19();
	//listing_11_20();
	//listing_11_21();
	//listing_11_22();
	//listing_11_23();
	//listing_11_24();
	//listing_11_25();
	//listing_11_26();
	//listing_11_27();
	//listing_11_28();
	//listing_11_29();
	
	drill_1();
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
	//printf("%d\n", drill_14("123fdsa"));
	//printf("%d\n", drill_14("123"));
	//printf("%d\n", drill_14("helllo"));
	//drill_15();


	//task1();
	//task11();
	//printf("%p %p %p", DEF, task10(DEF), DEF + 3);
	//char *x = pr("Ho Ho Ho!");
	return;
}