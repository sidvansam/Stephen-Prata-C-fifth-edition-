#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20

int main(int argc, char *argv[])
{
	FILE * fp, *fp1;
	char ch;
	char  first_name[LEN];
	char  second_name[LEN];

	if (argc > 1)
	{
		fprintf(stderr, "Usage: write name of files after initialization.\n");
		exit(1);
	}

	printf("Enter name of source file: ");
	gets(first_name);
	printf("Enter name of file to copy: ");
	gets(second_name);

	if ((fp = fopen(first_name, "rb")) == NULL)	
	{
		printf("No succeed open %s\n", first_name);
		exit(1);
	}

		if ((fp1 = fopen(second_name, "wb")) == NULL)	
	{
		printf("No succeed open %s\n", second_name);
		exit(1);
	}

	while ((ch = getc(fp)) != EOF)
		putc(ch, fp1);

	fclose(fp);
	fclose(fp1);
	printf("Copy end.\n");

	return 0;
}

