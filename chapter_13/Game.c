#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	char ch;

	char * persons[] = {"Zeus", "Mad Max", "Khabib", "Mum", "Dad", "Leha", "I", "Edinorog", "Gnom", "Figter"};
	char * location[] = {"Russia", "Ukrain", "Argentina", "World", "Moon", "Sun", "Shop", "Bryansk", "Chernigov", "Ocean"};
	char * action[] = {"Run", "Sit", "Fight", "Read", "Stand", "Fly", "Jump", "Hate", "Love", "Drink"};
	
	while((ch = getchar()) != EOF)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		printf("%s\t%s\t%s\t\n", *(persons + a),
								 *(action + b),
								 *(location + c));

		printf("\n\n");
		printf("%d\t%d\t%d\t\n", rand()%9, rand()%9, rand()%9);
		printf("%s\t%s\t%s\t\n", *(persons + rand()%9),
								 *(action + rand()%9),
								 *(location + rand()%9));
		printf("Continue?\n");
	}	
	printf("End programm.\n");
	return;	
}