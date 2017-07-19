#include <stdio.h>
static int recursivecompute(int n, int result);
int main(void)
{
	int n = 0, sum = 0;
	scanf("%d", &n);
	recursivecompute(n, sum);
	return 0;
}
static int recursivecompute(int n, int result)
{
	if( 0 == n )
		return printf("result = %d\n", result);
	return recursivecompute(n - 1, result + n);
}
