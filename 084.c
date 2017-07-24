#include <stdio.h>
static int isSuShu(int n);
int main(void)
{
	int n = 0, i = 0;
	scanf("%d", &n);
	if( 0 != (n & 1) || n < 2 )
		return 0;
	if( isSuShu(n - 2) )
	{
		printf("%d = 2 + %d\n", n, n - 2);
		return 0;
	}
	for( i = 3; i < n >> 1; i += 2 )
		if( isSuShu(i) && isSuShu(n - i) )
		{
			printf("%d = %d + %d\n", n, i, n - i);
			return 0;
		}
	printf("missed!\n");
	return 0;
}
static int isSuShu(int n)
{
	int i = 0;
	if( 0 == (n & 1) )
		return 0;
	for( i = 3; i < n >> 1; i += 2 )
		if( 0 == n % i )
			return 0;
	return 1;
}
