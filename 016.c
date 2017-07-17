#include <stdio.h>
static int getgcd(int m, int n);
int main(void)
{
	int m = 0, n = 0, gcd = 0;
	scanf("%d,%d", &m, &n);
	printf("the gcd of %d and %d is %d\n", m, n, gcd = getgcd(m, n));
	printf("the lcm of %d and %d is %d\n", m, n, m / gcd * n);
	return 0;
}
static int getgcd(int m, int n)
{
	if( 0 == m % n )
		return n;
	else
		return getgcd(n, m % n);
}
