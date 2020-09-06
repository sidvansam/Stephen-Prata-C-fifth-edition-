#include <stdio.h>
#include <stdlib.h>

void main(int argc, char * argv[])
{
	int nmb = atoi(argv[2]);     //int
	int e = nmb;
	double nmb1 = atof(argv[1]); //float
	double ans = nmb1;

	if(nmb == 0.0)
	{
		ans = 1.0;
	}
	else if(nmb > 0)
	{
		while(nmb > 1)
		{
			nmb--;
			ans *= nmb1;
		}
	}	

	else if(nmb < 0)
	{
		while(nmb < -1)
		{
			nmb++;
			ans *= nmb1;
		}
	}	
	

	printf("Number:\t%lf\nPower:\t%d\nAnswer:\t%lf\n", nmb1, e, ans);

	return;
}