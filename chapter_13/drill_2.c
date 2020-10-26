#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20

int main(int argc, char *argv[])
{
	int ch; //место, куда помещается каждый прочитанный символ
	FILE *fp; //указатель на исходный файл 
	FILE *fp1; //указатель на файл копию

	if (argc > 3 || argc == 1 )
	{
		fprintf(stderr, "Usage %s: filename\tfilename\n", argv[0]);
		exit(1);
	}

	if ((fp = fopen(argv[1], "rb")) == NULL) //открываем файл в режиме чтения (read)
											//если указатель не равен 0 
		//первый элемент это указатель на имя файла который стоит открыть
		//иными словами это адрес строки содержащей имя файла
		//второй элемент это режим открытия файла
	{
		printf("No succeed open %s\n", argv[1]);
		exit(1);
	}

		if ((fp1 = fopen(argv[2], "wb")) == NULL) //открываем файл в режиме чтения (read)
											//если указатель не равен 0 
		//первый элемент это указатель на имя файла который стоит открыть
		//иными словами это адрес строки содержащей имя файла
		//второй элемент это режим открытия файла
	{
		printf("No succeed open %s\n", argv[2]);
		exit(1);
	}

	while ((ch = getc(fp)) != EOF)
		putc(ch, fp1);

	fclose(fp);
	fclose(fp1);
	printf("Copy end.\n");

	return 0;
}

