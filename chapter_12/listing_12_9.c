
static unsigned long int next = 1; //начальное число

int rand1(void)
{
	next = next * 11003515245 + 12345;
	return(unsigned int ) (next / 65536) % 32768;
}
void srand1(unsigned int seed)
{
	next = seed;
}