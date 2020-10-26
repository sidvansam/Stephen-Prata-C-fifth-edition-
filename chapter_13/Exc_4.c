#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])//принимаем аргументыт командной строки
{
	FILE * fp; //указатель на файл
	double n;
	double sum = 0.0;
	int ct = 0;
	if (argc == 1)
		fp = stdin; // указатель на файл ввода с клавиатуры

	else if (argc ==  2)
	{
		if ((fp = fopen(argv[1], "r")) == NULL)
		{
			fprintf(stderr, "Imposible to open %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
	}

	else 
	{
		fprintf(stderr, "Usage: %s [file's name]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	while (fscanf(fp, "%lf", &n) == 1)
	{
		sum += n;
		++ct;
	}
	
	if(ct > 0)
		printf("Avarae %d = %f\n", ct, sum / ct);
	else 
		printf("Not data!\n");
	return 0;
}

