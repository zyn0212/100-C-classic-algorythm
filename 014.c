#include <stdio.h>
static void printzhiyinshu(int n, int startnumber);
static int iszhishu(int n);
int main(void)
{
	int n = 0;
	scanf("%d", &n);
	printf("%d = ", n);
	printzhiyinshu(n, 3);
	return 0;
}
static void printzhiyinshu(int n, int startnumber)
{
	if( n < 2 )
		return;
	int i = 0;
	while( 0 == (n & 1) )
	{
		printf(" 2 %c", n >> 1 > 1 ? '*' : '\n');
		n >>= 1;
	}
	for( i = startnumber; i <= n; i += 2 )
		if( 1 == iszhishu(i) && 0 == n % i )
		{
			printf(" %d %c", i, n / i > 1 ? '*' : '\n');
			printzhiyinshu(n / i, startnumber);
			break;
		}
	return;
}
static int iszhishu(int n)
{
	int i = 0;
	if( 0 == (n & 1) )
		return 0;
	for( i = 3; i <= (n >> 1); i += 2 )
		if( 0 == n % i )
			break;
	if( i > (n >> 1) )
		return 1;
	return 0;
}
