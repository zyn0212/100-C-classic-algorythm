#include <stdio.h>
static void printresult(int n);
int main(void)
{
	int n = 0;
	while( 1 )
	{
		scanf("%d", &n);
		if( n > 9999 || n < 1000 )
			break;
		printresult(n);
		printf("\n");
	}
	return 0;
}
static void printresult(int n)
{
	printf("%d", n % 10 > 4 ? n % 10 - 5 : n % 10 + 5);
	if( n > 9 )
		printresult(n / 10);
}
