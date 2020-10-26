#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20

int main(int argc, char *argv[])
{
	int ch; //место, куда помещается каждый прочитанный символ
	FILE *fp; //указатель на файл
	char file[LEN];
	int count = 0;

	if (argc > 1)
	{
		printf("Usage: write name of file after initialization.\n");
		exit(1);
	}

	printf("Enter name of file to open: ");
	gets(file); //запись имени файла в массив

	if ((fp = fopen(file, "r")) == NULL) //открываем файл в режиме чтения (read)
											//если указатель не равен 0 
		//первый элемент это указатель на имя файла который стоит открыть
		//иными словами это адрес строки содержащей имя файла
		//второй элемент это режим открытия файла
	{
		printf("No succeed open %s\n", file);
		exit(1);
	}

	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}

	fclose(fp);
	printf("\nFile %s consist %d characters\n", file, count);

	return 0;
}

