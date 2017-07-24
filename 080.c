#include <stdio.h>
static void GetResult(int n, int base, int result);
int main(void)
{
	GetResult(5, 1, 4);
	return 0;
}
static void GetResult(int n, int base, int result)
{
	if( 0 == n )
		printf("there are %d peachs on the beach!\n", result);
	else
	{
		while( 0 != (result & 3) )
			result += base;
		GetResult(n - 1, base * 5, (result >> 2) * 5 + 1);
	}
}
