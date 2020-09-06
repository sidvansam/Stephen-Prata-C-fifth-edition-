#include <stdio.h>

void main(int argc, char * argv[])
{
	printf("Have %d words:\n", argc - 1);
	for(int i = argc; i > 0; i--)
		printf("%s\n", argv[i]);

	return;
}