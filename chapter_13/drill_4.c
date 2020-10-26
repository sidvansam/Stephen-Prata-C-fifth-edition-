#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int a = argc;
	char ch; //для символов
	FILE * fp;

	while (a > 1)
	{

		if ((fp = fopen(argv[argc - a + 1], "r")) == NULL) //открываем файл в режиме чтения (read)
														   //если указатель не равен 0 
				//первый элемент это указатель на имя файла который стоит открыть
				//иными словами это адрес строки содержащей имя файла
				//второй элемент это режим открытия файла
			{
				printf("No succeed open %s\n", argv[argc - a + 1]);
				printf("\n\n***********************************************************************\n");

				a--;
			}
		else
		{
			while ((ch = getc(fp)) != EOF)
				putc(ch, stdout);
			printf("\n\n***********************************************************************\n");
			fclose(fp);
			a--;
		}
	}
	
	return 0;
}

