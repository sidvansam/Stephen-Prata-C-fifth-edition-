#include <stdio.h>

extern void srand1(unsigned int x);
extern int rand1(void);

int main (void)
{
	int count;
	unsigned seed;
	printf("Enter start number.\n");
	while(scanf("%u", &seed) == 1 && seed != 0)
	{
		srand1(seed);
		for(count = 0; count < 5; count++)
			printf("%hd\n", rand1());
		printf("Enter next number or 0 for ending: \n");
	}
	printf("End programm.\n");
	return 0;
}