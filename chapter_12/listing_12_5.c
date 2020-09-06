#include <stdio.h>

void report_count();
void accumulate(int k);
int count = 0; //область видимости в пределах файла

int main (void)
{
	int value;			//автоматическая переменная
	register int i;		//регистровая переменная
	printf("Enter unsigned integer number (0 for ending):");
	while((scanf("%d", &value) == 1) && value > 1)
	{
		++count;		//использование переменной с областью видимости в пределах файла
		for(i = value; i >= 0; i--)
			accumulate(i);
		printf("Enter unsigned integer number (0 for ending):");
	}
	report_count();

	return 0;
}

void report_count()
{
	printf("Iteraions done %d time(s).\n", count);
}

