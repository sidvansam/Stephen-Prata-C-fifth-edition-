#include <stdio.h>

#define MONTHS 12
#define YEARS 5
#define SIZE 4
#define SIZE5 5
#define SIZE1 10
#define SIZE7 7
#define SIZE3 3
#define ROWS 3
#define COLS 4
#define COLS5 5

int data[2] = {100, 200};
int somedata[2] = {300, 400};

int sum (int * arr, int n )
{
	int i;
	int total = 0;
	for (i = 0; i < n; i++)
		total += * ( arr + i );
	printf("Size of variable arr equial %zd bytes.\n", sizeof arr);
	return total;
}

int sump (int * start, int * end )
{
	int total = 0;
	while (start < end)
	{
		total += *start;
		start++;
	}
	return total;
}

void show_array(const double ar[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%8.3f ", ar[i]);
	putchar('\n');
}

void mult_array(double ar[], int n, double mult)
{
	int i;
	for (i = 0; i < n; i++)
		*(ar + i) *= mult; 
}

void sum_rows(int ar[][COLS], int rows)
{
	int r;
	int c;
	int tot;
	for(r = 0; r < rows; r++)
	{
		tot = 0;
		for(c = 0; c < COLS; c++)
			tot += ar[r][c];
		printf("Line %d: sum = %d\n", r, tot);
	}
}

void sum_cols(int ar[][COLS], int rows)
{
	int r;
	int c;
	int tot;
	for(c = 0; c < COLS; c++)
	{
		tot = 0;
		for(r = 0; r < rows; r++)
			tot += ar[r][c];
		printf("Column %d: sum = %d\n", c, tot);
	}
}

int sum2d(int ar[][COLS], int rows)
{
	int r;
	int c;
	int tot = 0;
	for(r = 0; r < rows; r++)
		for(c = 0; c < COLS; c++)
			tot += ar[r][c];
	return tot;
}

int sum2d2(int rows, int cols, int ar[rows][cols])
{
	int r;
	int c;
	int tot = 0;
	for(r = 0; r < rows; r++)
		for(c = 0; c < cols; c++)
			tot += ar[r][c];
	return tot;
}

void copy_arr(double a[], double b[], int size)
{
	for(int i = 0; i < size; i++)
		b[i] = a[i];
}

void copy_ptr(double *a, double *b, int size)
{
	for(int i = 0; i < size; i++)
		*b++ = *a++;
}

void copy_ptr2(double (*a)[COLS5], double (*b)[COLS5], int rows, int cols)
{
	for(int i = 0; i < rows; i++)
	{
		for(int l = 0; l < cols; l++)
			*(*(b + i) + l) = a[i][l];
	}
}

void copy_ptr3(double (*a)[COLS5], double (*b)[COLS5], double (*c)[COLS5], int rows, int cols)
{
	for(int i = 0; i < rows; i++)
	{
		for(int l = 0; l < cols; l++)
			*(*(c + i) + l) = a[i][l] + b[i][l];
	}
}

void show_array2(double (*arr)[COLS5], int rows, int cols)
{
	for(int i = 0; i < rows ; i++)
	{
		for(int n = 0; n < cols; n++)
			printf("\t%.2lf", arr[i][n]);
		printf("\n");
	}
	printf("\n");
}

void biggest(int (*frstArr)[COLS], int rows, int cols)
{
	int r, c;
	int b = 0;
	for(r = 0; r < rows; r++)
	{
		for(c = 0; c < cols; c++)
		{
			if(frstArr[r][c] > b)
				b = *(*(frstArr + r) + c);		
		}
	}
	printf("The biggest number of array is %d.\n", b);
}

void biggest2(double (*frstArr)[COLS], int rows, int cols)
{
	int r, c, r1, c1;
	double b = 0;
	for(r = 0; r < rows; r++)
	{
		for(c = 0; c < cols; c++)
		{
			if(frstArr[r][c] > b)
			{
				b = *(*(frstArr + r) + c);
				r1 = r;
				c1 = c;
			}
		}
	}
	printf("The biggest number of array is %.2lf.\n", b);
	printf("Index of biggest number of array is %d x %d.\n", r1 + 1, c1 + 1);
}

void difference(double (*frstArr)[COLS], int rows, int cols)
{
	int r, c;
	double b = 0;
	double l = *(*(frstArr));
	for(r = 0; r < rows; r++)
	{
		for(c = 0; c < cols; c++)
		{
			if(frstArr[r][c] > b)
				b = *(*(frstArr + r) + c);
			else if(l > frstArr[r][c])
				l = *(*(frstArr + r) + c);
		}
	}
	printf("The biggest number of array is %.2lf.\n", b);
	printf("The lower number of array is %.2lf.\n", l);
	printf("Difference enter biggest and lower number is %.2lf.\n", b - l);
}

void duplication(int ROWs, double (*array)[COLS5])
{
	for(int r = 0; r < ROWs; r++)
	{
		for(int c = 0; c < COLS; c++)
			*(*(array + r) + c) = *(*(array + r) + c) * 2;
	}
}

float rainfall(const float (*data)[MONTHS], int years)
{
	float total = 0;
	printf("YEARS	RAINFALL (in inches)\n");
	for (int y = 0; y < years; y++)
	{
		float subtot = 0;
		for (int month = 0; month < MONTHS; month++)
			subtot += data [y] [month];
		printf("%5d %15.1f\n", 2000 + y, subtot);
		total += subtot;
	}
	return total;
}

void MONTHLY_AVARAGE(const float (*array)[MONTHS], int years)
{
	printf("  Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec \n");
	for(int i = 0; i < MONTHS; i++)
	{
		float subtot = 0;
		for (int l = 0; l < years; l++)
			subtot += array[l][i];
		printf("  ");
		printf("%2.1f", subtot / years);
	}
}

void input_array(double (*array)[], int rows)
{
	char n;
		printf("Please enter value of array's members: \n");
	for (int i = 0; i < rows * COLS5; i++)
	{
		int c = 0;
		c = scanf("%lf", *array + i);
		if (c != 1)
		{
			char n;
			while((n = getchar()) != '\n')
				putchar(n);
			printf(" no is integer!.\n Please ");
			printf("enter int number like 25, -178  or 3: ");
			i--;
		}
	}
	return;
}

void avarage_row(double (*array)[], int cols)
{
	double avarage = 0;
	int i;
	for(i = 0; i < cols; i++)
		avarage += *(*array + i);
	printf("Avarage of line = %.2lf\n", avarage / i);
}

void avarage_array(double (*array)[], int size)
{
	double avarage = 0;
	for(int i = 0; i < size; i++)
		avarage += **array + i;
	printf("\nAvarage = %.2lf\n", avarage);
	printf("\nAvarage of array = %.2lf\n", avarage / size);
}

void bigest_arr(double (*array)[], int size)
{
	double biggest = 0;
	for(int i = 0; i < size; i++)
	{
		if((**array + i) > biggest)
			biggest = **array + i;
	}
	printf("Biggest of array = %.2lf\n", biggest);
}

void input_array1(int rows, int col, double array[rows][col])
{
	char n;
		printf("Please enter value of array's members: \n");
	for (int i = 0; i < rows; i++)
	{
		int c = 0;
		c = scanf("%lf", *array + i);
		if (c != 1)
		{
			char n;
			while((n = getchar()) != '\n')
				putchar(n);
			printf(" no is integer!.\n Please ");
			printf("enter int number like 25, -178  or 3: ");
			i--;
		}
	}
	return;
}

void avarage_row1(int cols, double (*array)[cols])
{
	double avarage = 0;
	int i;
	for(i = 0; i < cols; i++)
		avarage += *(*array + i);
	printf("Avarage of line = %.2lf\n", avarage / i);
}

void avarage_array1(int size, double (*array)[])
{
	double avarage = 0;
	for(int i = 0; i < size; i++)
		avarage += **array + i;
	printf("\nAvarage = %.2lf\n", avarage);
	printf("\nAvarage of array = %.2lf\n", avarage / size);
}

void bigest_arr1(int size, double (*array)[])
{
	double biggest = 0;
	for(int i = 0; i < size; i++)
	{
		if((**array + i) > biggest)
			biggest = **array + i;
	}
	printf("Biggest of array = %.2lf\n", biggest);
}

void show_array3(int rows, int cols, double arr[rows][cols])
{
	for(int i = 0; i < rows ; i++)
	{
		for(int n = 0; n < cols; n++)
			//printf("\t%.2lf", arr[i][n]);
			printf("\t%p", &arr[i][n]);
		printf("\n");
	}
	printf("\n");
}

void show_array4(int rows, int cols, double arr[rows][cols])
{
	for(int i = 0; i < rows ; i++)
	{
		for(int n = 0; n < cols; n++)
			printf("\t%.2lf", arr[i][n]);
			//printf("\t%p", &arr[i][n]);
		printf("\n");
	}
	printf("\n");
}

void input_array3(int cols, double (*arr)[cols])
{
	char n;
		printf("Please enter value of array's members: \n");
	for (int i = 0; i < cols; i++)
	{
		int c = 0;
		//printf("adress = %p\n", &arr[i][l]);
		c = scanf("%lf", *(*arr + i));
		//if (c != 1)
		//{
		//	char n;
		//	while((n = getchar()) != '\n')
		//		putchar(n);
		//	printf(" no is integer!.\n Please ");
		//	printf("enter int number like 25, -178  or 3: ");
		//	l--;
		//}

	}
	return;
}

void store(double ar[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter value #%d: ", i + 1);
        scanf("%lf", &ar[i]);
    }
}

void listing_10_1 (void)
{
	const int days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for (int index = 0; index < MONTHS;  index++)
		printf("Month %d include %2d days\n", index + 1, days[index]);

	return;	
}

void listing_10_2 (void)
{
	int no_data[SIZE];
	printf("%2s%14s\n", "i", "no_data[i]");
	for (int i = 0; i < SIZE;  i++)
		printf("%2d%14d\n", i, no_data[i]);

	return;	
}

void listing_10_3 (void)
{
	int some_data[SIZE] = { 1492, 1066 };
	printf("%2s%14s\n", "i", "some_data[i]");

	for (int i = 0; i < SIZE;  i++)
		printf("%2d%14d\n", i, some_data[i]);

	return;	
}

void listing_10_4 (void)
{
	const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31};
	for (int index = 0; index < sizeof days / sizeof days [0];  index++)
		printf("Month %d include %2d days\n", index + 1, days[index]);

	return;	
}

void listing_10_5 (void)
{
	const int days[MONTHS] = {31, 28, [4] = 31, 30, 31, [1] = 29};
	for (int index = 0; index < MONTHS;  index++)
		printf("%2d %d\n", index + 1, days[index]);

	return;	
}

void listing_10_6 (void)
{
	int value1 = 44;
	int arr[SIZE];
	int value2 = 88;
	int i;
	printf("value1 = %d, value2 = %d\n", value1, value2);
	for(i = -1; i <= SIZE; i++)
		arr[i] = 2 * i + 1;
	for(i = -1; i < 7; i++)
		printf("%2d %d\n", i, arr[i]);
	printf("value1 = %d, value2 = %d\n", value1, value2);

	return;	
}

void listing_10_7(void)
{
	const float rain [YEARS] [MONTHS] = 
	{
		{ 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },		
		{ 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 },
		{ 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4 },	 
		{ 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },
		{ 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2 },
	};
	int year, month;
	float subtot, total;

	printf("YEARS	RAINFALL (in inches)");
	for (year = 0, total = 0; year < YEARS; year++)
	{
		for (month = 0, subtot = 0; month < MONTHS; month++)
			subtot += rain [year] [month];
		printf("%5d %15.1lf\n", 2000 + year, subtot);
		total += subtot;
	}
	printf("YEARLY AVARAGE: %.1f\n\n", total / YEARS);
	printf("MONTHLY AVARAGE:\n");
	printf("  Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec \n");
	for (month = 0; month < MONTHS; month++)
	{
		for (year = 0, subtot = 0; year < YEARS; year++)
			subtot += rain [year] [month];
		printf("  ");
		printf("%2.1f", subtot / YEARS);
	}
	printf("\n");

	return;	
}


void listing_10_8(void)
{
	short dates [SIZE];
	short * pti;
	short index;
	double bills[SIZE];
	double * ptf;

	pti = dates; // назначаем указатель на адрес первого элемента массива
	ptf = bills; // назначаем указатель на адрес первого элемента массива
	printf("%23s %10s\n", "short", "double");
	for(index = 0; index < SIZE; index++)
		printf("reference + %d: %10p %10p\n", index, pti + index, ptf + index);
		//печать адресов элементов массива

	return;	
}

void listing_10_9(void) // это прототип функции
{
	const int days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for (int index = 0; index < MONTHS;  index++)
		printf("Month %d include %2d days\n", index + 1, * (days + index));
		//* (days + index) == days[index]
	return;	
}

void listing_10_10(void) // это прототип функции
{
	int marbless [SIZE1] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20 };
	long answer;
	answer = sum(marbless, SIZE1);
	printf("Aggregate total of array marbless equial %ld.\n", answer);
	printf("Storage space turn off array marbless wquial %zd bytes.\n", sizeof marbless);

	return;	
}

void listing_10_11(void) // это прототип функции
{
	int marbless [SIZE1] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20 };
	long answer;
	answer = sump(marbless, marbless + SIZE1);
	printf("Aggregate total of array marbless equial %ld.\n", answer);

	return;	
}

void listing_10_12(void) // это прототип функции
{
	int * p1, * p2, * p3;
	p1 = p2 = data; //присваивание значения первого элемента массива указателям 
	// p1 == 100, p2 == 100;
	p3 = somedata;
	// p3 == 300;
	printf("	*p1 = %d,	*p2 = %d,	*p3 = %d\n", *p1, *p2, *p3);
	printf("	*p1++ = %d,	*++p2 = %d,	(*p3)++ = %d\n", *p1++, *++p2, (*p3)++);
	printf("	*p1 = %d,	*p2 = %d,	*p3 = %d\n", *p1, *p2, *p3);

	return;	
}

void listing_10_13(void) // это прототип функции
{
	int urn[5] = {100, 200, 300, 400, 500};
	int * ptr1, * ptr2, * ptr3;
	ptr1 = urn;			//присваивание указателю адреса первого элемента массива
	ptr2 = &urn[2];		

						//разыменовывание указателя и взятие 
						//адреса указателя
	printf("Pointer value, dereferencing pointer, pointer adress:\n");
	printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n\n", ptr1, *ptr1, &ptr1);
						
	ptr3 = ptr1 + 4;	// сложение указателей
	printf("Sum integer value with pointer:\n");
	printf("ptr1 + 4 = %p, *(ptr1 + 3) = %d\n\n",ptr1 + 4, *(ptr1 + 3));

	ptr1++;				//увеличение значения указателя на 1
	printf("Value after operation ptr1++:\n");
	printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n\n", ptr1, *ptr1, &ptr1);

	ptr2--;				//увеличение значения указателя на 1
	printf("Value after operation ptr2--:\n");
	printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n\n", ptr2, *ptr2, &ptr2);

	--ptr1;				//восстановление исходного значения
	++ptr2;				//восстановление исходного значения
	printf("Refreshing primary value pointer:\n");
	printf("ptr1 = %p, ptr2 = %p\n\n", ptr1, ptr2);

						//вычитание одного указателя из другого
	printf("Subtraction one from second:\n");
	printf("ptr2 = %p, ptr1 = %p, ptr2 - ptr1 = %d\n\n", ptr1, ptr2, ptr2 - ptr1);

						//вычитание целого значения из указателей
	printf("Subtraction int value from pointer:\n");
	printf("ptr3 = %p, ptr3 - 2 = %p\n", ptr3, ptr3 - 2);

	return;	
}

void listing_10_14(void) // это прототип функции
{
	double dip [SIZE5] = {20.0, 17.66, 8.2, 15.3, 22.22};
	printf("Sourse array dip:\n");
	show_array(dip, SIZE5);
	mult_array(dip, SIZE5, 2.5);
	printf("Array dip after function call mult_array():\n");
	show_array(dip,SIZE5);

	return;	
}

void listing_10_15(void) // это прототип функции
{
	int zippo [4][2] = { {2, 4}, {6, 8}, {1, 3}, {5, 7} };
	//печатаются адреса первого и второго элемента составного массива
	printf("	zippo = %p, 	zippo + 1 = %p\n", zippo, zippo + 1);

	//
	printf("	zippo[0] = %p, 	zippo[0] + 1 = %p\n", zippo[0], zippo[0] + 1);

	//
	printf("	*zippo = %p, 	*zippo + 1 = %p\n", * zippo, * zippo + 1);

	printf("	zippo[0][0] = %d\n", zippo[0][0]);
	printf("	*zippo[0] = %d\n", * zippo[0]);
	printf("	**zippo = %d\n", ** zippo);
	printf("	zippo[2][1] = %d\n", zippo[2][1]);
	printf("	*(*(zippo + 2) + 1) = %d\n", *(*(zippo + 2) + 1));

	return;	
}

void listing_10_16(void)
{
	int zippo [4][2] = { {2, 4}, {6, 8}, {1, 3}, {5, 7} };
	int (*pz)[2]; //создание 2х указателей на массив 
	pz = zippo;
	printf("	pz = %p, 	pz + 1 = %p\n", pz, pz + 1);
	printf("	pz[0] = %p\tpz[0] + 1 = %p\n",pz[0], pz[0] + 1);
	printf("	*pz = %p\t*pz + 1 = %p\n",*pz, *pz + 1);
	printf("	pz[0][0] = %d\n", pz[0][0]);
	printf("	*pz[0] = %d\n", * pz[0]);
	printf("	**pz = %d\n", ** pz);
	printf("	pz[2][1] = %d\n", pz[2][1]);
	printf("	*(*(pz + 2) + 1) = %d\n", *(*(pz + 2) + 1));

	return;	
}

void listing_10_17(void)
{
	int junk [ROWS][COLS] = {
			 {2,	 4,		6,	 8},
			 {3,	 5,		7,	 9},
			 {12,	 10,	8,	 6}
	};

	sum_rows(junk, ROWS);
	sum_cols(junk, ROWS);
	printf("Sum of all elements = %d\n", sum2d(junk, ROWS));

	return;	
}

void listing_10_18(void)
{
	int i, j;
	int rs = 3;
	int cs = 10;
	int junk [ROWS][COLS] = {
			 {2,	 4,		6,	 8},
			 {3,	 5,		7,	 9},
			 {12,	 10,	8,	 6}
	};

	int morejunk [ROWS - 1] [COLS + 2] = {
			{ 20, 30, 40, 50, 60, 70}, 
			{ 5, 6, 7, 8, 9, 10 },
	};

	int varr [rs][cs];
	for (i = 0; i < rs; i++)
	{
		for(j = 0; j < cs; j++)
			varr[i][j] = i * j + j;
	}

	printf("Array dimention 3x5\n");
	printf("Sum of all elements = %d\n\n", sum2d2(ROWS, COLS, junk));

	printf("Array dimention 2x6\n");
	printf("Sum of all elements = %d\n\n", sum2d2(ROWS - 1, COLS + 2, morejunk));

	printf("Array of variable length 3x10\n");
	printf("Sum of all elements = %d\n\n", sum2d2(rs, cs, varr));

	return;	
}

void listing_10_19(void)
{
	int total1, total2, total3;
	int * pt1;
	int (* pt2)[COLS];

	pt1 = (int [2]) {10, 20};
	pt2 = (int [2][COLS]) { {1, 2, 3, -9}, {4, 5, 6, -8}};

	total1 = sum(pt1, 2);
	total2 = sum2d(pt2, 2);
	total3 = sum((int []){4, 4, 4, 5, 5, 5}, 6);
	printf("total1 = %d\n", total1);
	printf("total2 = %d\n", total2);
	printf("total3 = %d\n", total3);

	return;
}

void drill_1 (void)
{
	const float rain [YEARS][MONTHS] = 
	{
		{ 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },
		{ 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 },
		{ 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4 },	 
		{ 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },
		{ 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2 },
	};
	int year, month;
	float subtot, total;

	printf("YEARS	RAINFALL (in inches)\n");
	for (year = 0, total = 0; year < YEARS; year++)
	{
		for (month = 0, subtot = 0; month < MONTHS; month++)
			subtot += *(*(rain + year) + month);
		printf("%5d %15.1lf\n", 2000 + year, subtot);
		total += subtot;
	}
	printf("YEARLY AVARAGE: %.1f\n\n", total / YEARS);
	printf("MONTHLY AVARAGE:\n");
	printf("  Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec \n");
	for (month = 0; month < MONTHS; month++)
	{
		for (year = 0, subtot = 0; year < YEARS; year++)
			subtot += *(*(rain + year) + month);
		printf("  ");
		printf("%2.1f", subtot / YEARS);
	}
	printf("\n");

	return;	
}

void drill_2(void)
{
	double sourse[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double target1[5];
	double target2[5];
	
	copy_arr(sourse, target1, 5);
	copy_ptr(sourse, target2, 5);
	for (int i = 0; i < 5; i++)
	{
		printf("sourse[%d] = %.1lf \t", i, *(sourse + i));
		printf("target1[%d] = %.1lf\t", i, target1[i]);
		printf("target2[%d] = %.1lf\t", i, *(target2 + i));
		printf("\n");
	}

	return;
}

void drill_3(void)
{
	int junk [ROWS][COLS] = {
		 {2,	 4,		6,	 8},
		 {3,	 5,		7,	 9},
		 {12,	 100,	8,	 6}
	};
	biggest(junk, ROWS, COLS);
	return;
}

void drill_4(void)
{
	double junk [ROWS][COLS] = {
		 {200.0, 400,		6.0,	 8.0},
		 {3.0,	 5.0,		7.0,	 9.0},
		 {12.0,	 100.5,		8.0,	 600.0}
	};
	biggest2(junk, ROWS, COLS);
	return;
}

void drill_5(void)
{
	double junk [ROWS][COLS] = {
		 {200,	 400,		6.0,	 8.0},
		 {3.0,	 5.0,		7.0,	 9.0},
		 {12.0,	 100.5,		8.0,	 1}
	};
	difference(junk, ROWS, COLS);
	return;
}

void drill_6(void)
{
	double array_1 [ROWS][COLS] = {
		 {200,	 400,		6.0,	 8.0},
		 {3.0,	 5.0,		7.0,	 9.0},
		 {12.0,	 100.5,		8.0,	 1}
	};

	double array_2 [ROWS][COLS] = {
		 {0,	 0,		0,	 0},
		 {0,	 0,		0,	 0},
		 {0,	 0,		0,	 0}
	};

	printf("array_1 [0][0] = adress %p = %.2lf\n",	 &array_1[0][0], array_1[0][0]);		//array_1 [0][0] = adress 0061FE98 = 200.00
	printf("array_1 [0][1] = adress %p = %.2lf\n",	 &array_1[0][1], array_1[0][1]);		//array_1 [0][1] = adress 0061FEA0 = 400.00
	printf("array_1 [0][2] = adress %p = %.2lf\n", 	 &array_1[0][2], array_1[0][2]);		//array_1 [0][2] = adress 0061FEA8 = 6.00
	printf("array_1 [0][3] = adress %p = %.2lf\n\n", &array_1[0][3], array_1[0][3]);		//array_1 [0][3] = adress 0061FEB0 = 8.00
 
	printf("array_1 [1][0] = adress %p = %.2lf\n",	 &array_1[1][0], array_1[1][0]);		//array_1 [1][0] = adress 0061FEB8 = 3.00
	printf("array_1 [1][1] = adress %p = %.2lf\n",	 &array_1[1][1], array_1[1][1]);		//array_1 [1][1] = adress 0061FEC0 = 5.00
	printf("array_1 [1][2] = adress %p = %.2lf\n", 	 &array_1[1][2], array_1[1][2]);		//array_1 [1][2] = adress 0061FEC8 = 7.00
	printf("array_1 [1][3] = adress %p = %.2lf\n\n", &array_1[1][3], array_1[1][3]);		//array_1 [1][3] = adress 0061FED0 = 9.00
 
	printf("array_1 [2][0] = adress %p = %.2lf\n",	 &array_1[2][0], array_1[2][0]);		//array_1 [2][0] = adress 0061FED8 = 12.00
	printf("array_1 [2][1] = adress %p = %.2lf\n",	 &array_1[2][1], array_1[2][1]);		//array_1 [2][1] = adress 0061FEE0 = 100.50
	printf("array_1 [2][2] = adress %p = %.2lf\n", 	 &array_1[2][2], array_1[2][2]);		//array_1 [2][2] = adress 0061FEE8 = 8.00
	printf("array_1 [2][3] = adress %p = %.2lf\n\n", &array_1[2][3], array_1[2][3]);		//array_1 [2][3] = adress 0061FEF0 = 1.00

	printf("array_2 [0][0] = adress %p = %.2lf\n",	 &array_2[0][0], array_2[0][0]);		//array_1 [0][0] = adress 0061FE98 = 200.00
	printf("array_2 [0][1] = adress %p = %.2lf\n",	 &array_2[0][1], array_2[0][1]);		//array_1 [0][1] = adress 0061FEA0 = 400.00
	printf("array_2 [0][2] = adress %p = %.2lf\n", 	 &array_2[0][2], array_2[0][2]);		//array_1 [0][2] = adress 0061FEA8 = 6.00
	printf("array_2 [0][3] = adress %p = %.2lf\n\n", &array_2[0][3], array_2[0][3]);		//array_1 [0][3] = adress 0061FEB0 = 8.00
 
	printf("array_2 [1][0] = adress %p = %.2lf\n",	 &array_2[1][0], array_2[1][0]);		//array_1 [1][0] = adress 0061FEB8 = 3.00
	printf("array_2 [1][1] = adress %p = %.2lf\n",	 &array_2[1][1], array_2[1][1]);		//array_1 [1][1] = adress 0061FEC0 = 5.00
	printf("array_2 [1][2] = adress %p = %.2lf\n", 	 &array_2[1][2], array_2[1][2]);		//array_1 [1][2] = adress 0061FEC8 = 7.00
	printf("array_2 [1][3] = adress %p = %.2lf\n\n", &array_2[1][3], array_2[1][3]);		//array_1 [1][3] = adress 0061FED0 = 9.00
 
	printf("array_2 [2][0] = adress %p = %.2lf\n",	 &array_2[2][0], array_2[2][0]);		//array_1 [2][0] = adress 0061FED8 = 12.00
	printf("array_2 [2][1] = adress %p = %.2lf\n",	 &array_2[2][1], array_2[2][1]);		//array_1 [2][1] = adress 0061FEE0 = 100.50
	printf("array_2 [2][2] = adress %p = %.2lf\n", 	 &array_2[2][2], array_2[2][2]);		//array_1 [2][2] = adress 0061FEE8 = 8.00
	printf("array_2 [2][3] = adress %p = %.2lf\n\n", &array_2[2][3], array_2[2][3]);		//array_1 [2][3] = adress 0061FEF0 = 1.00

	for(int i = 0; i < ROWS; i++)
		copy_ptr(array_1[i], array_2[i], COLS);

	for (int i = 0; i < ROWS; i++)
	{
		for(int l = 0; l < COLS; l++)
			printf("%.2lf\t", array_2[i][l]);//
		printf("\n");
	}
	return;
}

void drill_7(void)
{
	double fist_array[SIZE7] = {1, 2, 3, 4, 5, 6, 7};
	double second_array[SIZE3] = {0, 0, 0};
	copy_ptr(fist_array + 2, second_array, SIZE3);
	for(int i = 0; i < SIZE3; i++)
		printf("\t%.2lf", *(second_array + i));

	return;
}

void drill_8(void)
{
	double array_1 [ROWS][COLS5] = {
		 {200.0, 400.0,		6.0,	 8.0,	56.0},
		 {3.0,	 5.0,		7.0,	 9.0,	96.0},
		 {12.0,	 100.5,		8.0,	 1.0,	5.0}
	};

	double array_2 [ROWS][COLS5] = {
		 {0,	 0,		0,	 0,	0},
		 {0,	 0,		0,	 0,	0},
		 {0,	 0,		0,	 0,	0}
	};

	copy_ptr2(array_1, array_2, ROWS, COLS5);

	show_array2(array_1, ROWS, COLS5);
	show_array2(array_2, ROWS, COLS5);
	return;
}

void drill_9(void)
{
	double array_1 [ROWS][COLS5] = {
		 {200.0, 400.0,		6.0,	 8.0,	56.0},
		 {3.0,	 5.0,		7.0,	 9.0,	96.0},
		 {12.0,	 100.5,		8.0,	 1.0,	5.0}
	};

	double array_2 [ROWS][COLS5] = {
		 {200.0, 400.0,		6.0,	 8.0,	56.0},
		 {3.0,	 5.0,		7.0,	 9.0,	96.0},
		 {12.0,	 100.5,		8.0,	 1.0,	5.0}
	};

	double array_3[ROWS][COLS5];

	copy_ptr3(array_1, array_2, array_3, ROWS, COLS5);

	show_array2(array_1, ROWS, COLS5);
	show_array2(array_2, ROWS, COLS5);
	show_array2(array_3, ROWS, COLS5);
	return;
}

void drill_10(void)
{
	printf("\nDeclaration of array_1.\n");
	double array_1 [ROWS][COLS5] = {0};
	printf("Please enter value of array's members: \n");
	for (int i = 0; i < ROWS * COLS5; i++)
	{
		int c = 0;
		c = scanf("%lf", *array_1 + i);
		if (c != 1)
		{
			char n;
			while((n = getchar()) != '\n')
				putchar(n);
			printf(" no is integer!.\n Please ");
			printf("enter int number like 25, -178  or 3: ");
			i--;
		}
	}

	show_array2(array_1, ROWS, COLS5);
	duplication(ROWS, array_1);

	show_array2(array_1, ROWS, COLS5);

	return;
}

void drill_11(void)
{
	const float rain [YEARS] [MONTHS] = 
	{
		{ 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },		
		{ 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 },
		{ 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4 },	 
		{ 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },
		{ 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2 },
	};
	float c = rainfall(rain, YEARS);
	printf("YEARLY AVARAGE: %.1f\n\n", c / YEARS);
	MONTHLY_AVARAGE(rain, YEARS);

	return;	
}

void drill_12(void)
{
	printf("\nDeclaration of array.\n");
	double array_1 [ROWS][COLS5] = {0};
	input_array(array_1, ROWS);
	show_array2(array_1, ROWS, COLS5);
	for(int i = 0; i < ROWS; i++)
		avarage_row(array_1 + i, COLS5);
	avarage_array(array_1, ROWS * COLS5);
	bigest_arr(array_1, ROWS * COLS5);

	return;
}

void drill_13(void)
{
	int col = 0;
	int row = 0;
	printf("\nDeclaration of array.\n");
	printf("Please enter quantity of columns:");
	scanf("%d", &col);
	printf("Please enter quantity of lines:");
	scanf("%d", &row);
	printf("col = %d, row = %d\n", col, row);
	double array_1[row][col];
	show_array3(row, col, array_1);

    for (int r = 0; r < row; r++)
    {
        printf("Enter %d numbers for row %d\n", col, r + 1);
        store(array_1[r], col);
    }

	show_array4(row, col, array_1);

	for(int i = 0; i < row; i++)
		avarage_row1(col, array_1 + i);

	avarage_array1(row * col, array_1);
	bigest_arr1(row * col, array_1);

	return;
}

void example(void)
{
	double array_1 [ROWS][COLS] = {
		 {200,	 400,		6.0,	 8.0},
		 {3.0,	 5.0,		7.0,	 9.0},
		 {12.0,	 100.5,		8.0,	 1}
	};
	double (*ptr)[COLS] = array_1;

	printf("array_1 [0][0] = adress %p\n\n", array_1);		//array_1 [0][0] = adress 0061FE98
	
	printf("array_1 [0][0] = adress %p = %.2lf\n",	 &array_1[0][0], array_1[0][0]);		//array_1 [0][0] = adress 0061FE98 = 200.00
	printf("array_1 [0][1] = adress %p = %.2lf\n",	 &array_1[0][1], array_1[0][1]);		//array_1 [0][1] = adress 0061FEA0 = 400.00
	printf("array_1 [0][2] = adress %p = %.2lf\n", 	 &array_1[0][2], array_1[0][2]);		//array_1 [0][2] = adress 0061FEA8 = 6.00
	printf("array_1 [0][3] = adress %p = %.2lf\n\n", &array_1[0][3], array_1[0][3]);		//array_1 [0][3] = adress 0061FEB0 = 8.00
 
	printf("array_1 [1][0] = adress %p = %.2lf\n",	 &array_1[1][0], array_1[1][0]);		//array_1 [1][0] = adress 0061FEB8 = 3.00
	printf("array_1 [1][1] = adress %p = %.2lf\n",	 &array_1[1][1], array_1[1][1]);		//array_1 [1][1] = adress 0061FEC0 = 5.00
	printf("array_1 [1][2] = adress %p = %.2lf\n", 	 &array_1[1][2], array_1[1][2]);		//array_1 [1][2] = adress 0061FEC8 = 7.00
	printf("array_1 [1][3] = adress %p = %.2lf\n\n", &array_1[1][3], array_1[1][3]);		//array_1 [1][3] = adress 0061FED0 = 9.00
 
	printf("array_1 [2][0] = adress %p = %.2lf\n",	 &array_1[2][0], array_1[2][0]);		//array_1 [2][0] = adress 0061FED8 = 12.00
	printf("array_1 [2][1] = adress %p = %.2lf\n",	 &array_1[2][1], array_1[2][1]);		//array_1 [2][1] = adress 0061FEE0 = 100.50
	printf("array_1 [2][2] = adress %p = %.2lf\n", 	 &array_1[2][2], array_1[2][2]);		//array_1 [2][2] = adress 0061FEE8 = 8.00
	printf("array_1 [2][3] = adress %p = %.2lf\n\n", &array_1[2][3], array_1[2][3]);		//array_1 [2][3] = adress 0061FEF0 = 1.00
	
	printf("array_1     = adress %p\n",	  array_1);		//array_1	  = adress 0061FE98
	printf("array_1 + 1 = adress %p\n",	  array_1 + 1);	//array_1 + 1 = adress 0061FEB8
	printf("array_1 + 2 = adress %p\n",	  array_1 + 2);	//array_1 + 2 = adress 0061FED8
	printf("array_1 + 3 = adress %p\n\n", array_1 + 3);	//array_1 + 3 = adress 0061FEF8 - тут уже нет массива

	printf("*array_1     = adress %x\n",	*array_1);		//*array_1     = adress 61fe98
	printf("*array_1 + 1 = adress %x\n",	*array_1 + 1);	//*array_1 + 1 = adress 61fea0
	printf("*array_1 + 2 = adress %x\n",	*array_1 + 2);	//*array_1 + 2 = adress 61fea8
	printf("*array_1 + 3 = adress %x\n\n",  *array_1 + 3);	//*array_1 + 3 = adress 61feb0

	printf("*(array_1    ) = adress %x\n",	*(array_1));	    //*(array_1    ) = adress 61fe98
	printf("*(array_1 + 1) = adress %x\n",	*(array_1 + 1));	//*(array_1 + 1) = adress 61feb8
	printf("*(array_1 + 2) = adress %x\n",	*(array_1 + 2));	//*(array_1 + 2) = adress 61fed8
	printf("*(array_1 + 3) = adress %x\n\n",*(array_1 + 3));	//*(array_1 + 3) = adress 61fef8

	printf("array_1 [0][0] = adress %p\n", &array_1[0][0]);	//array_1 [0][0] = adress 0061FE98		
	printf("array_1 [0][0] = adress %lf\n", **array_1);		//array_1 [0][0] = adress 200.000000
	printf("array_1 [0][0] = adress %x\n", ptr);			//array_1 [0][0] = adress 61fe98
	printf("array_1 [0][1] = adress %x\n", ptr[0] + 1);		//array_1 [0][1] = adress 61fea0	
	printf("array_1 [0][1] = adress %lf\n", *(ptr[0] + 1));	//array_1 [0][1] = adress 400.000000
	printf("array_1 [0][] = adress %x\n", *ptr + 1);		//array_1 [0][1] = adress 400.000000
	return;
}

void main (void)
{
	//listing_10_1();
	//listing_10_2();	
	//listing_10_3();
	//listing_10_4();
	//listing_10_5();
	//listing_10_6();
	//listing_10_7();
	//listing_10_8();
	//listing_10_9();
	//listing_10_10();
	//listing_10_11();
	//listing_10_12();
	//listing_10_13();
	//listing_10_14();
	//listing_10_15();
	//listing_10_16();
	//listing_10_17();
	//listing_10_18();
	//listing_10_19();

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

	//example();


	return;
}