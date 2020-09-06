#include <stdio.h>

extern int count;		//ссылочное определение, внешнее связывание

static int total = 0;	//статическое определение, внутреннее связывание
void accumulate(int k); //прототип
void accumulate(int k)	//переменная k имеет область видимости в пределах блока,
						//связывание отсутвует
{
	static int subtotal = 0; //статическая переменная, связывание отсутствует
	if(k <= 0)
	{
		printf("loop iteration: %d\n", count);
		printf("intermediate summ: %d; total: %d\n", subtotal, total);
		subtotal = 0;
	}
	else
	{
		subtotal += k;
		total += k;
	}
}