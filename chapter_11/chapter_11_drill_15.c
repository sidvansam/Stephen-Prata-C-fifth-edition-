//#include <stdio.h>
//#include <stdlib.h>
//
//void main(int argc, char * argv[])
//{
//	puts("Enter frases!\n");
//	char * ch;
//	for(int i = 0; *argv[i] != ' '; i++)
//		*argv[i] = getchar();
//
//	return;
//}

#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	int state = 0;
	char ch;
	printf("%c\n", argv[1][0]);
	printf("%c\n", argv[1][1]);
	printf("%c\n", argv[1][2]);



	if(argv[1][state] == '-')
	{
		state++;
		if(argv[1][state] == 'p' || argv[1][state] == 'u' || argv[1][state] == 'l')
			state = 1;
		else 
		{
			while ((ch = getchar()) != 'p' || ch != 'u' || ch != 'l')
				printf("Programm take only command [-p] || [-u] || [-l]\nPlease enter your choice: ");
			argv[1][state] = ch;
		}
	}
	else state = 0;

	printf("state = %d\n", state);
	printf("argv[1][state] = %c\n", argv[1][state]);

	if (state == 1)
	{
		while ((ch = getchar()) != EOF)
		{
			switch(argv[1][state])
			{
				case 'p': printf("%c", ch);
						break;
				case 'u': putchar(toupper(ch));
						break;
				case 'l': putchar(tolower(ch));
						break;
			}
		}
	}
	else 
		printf("Programm take only command [-p] || [-u] || [-l]\n");
	

	return 0;
}