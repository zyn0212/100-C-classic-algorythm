#include <stdio.h>
static void getfibonacci(int m, int n, int month);
int main(void)
{
	int i1 = 1, i2 = 1, month = 0;
	scanf("%d", &month);
	getfibonacci(i1, i2, month);
	return 0;
}
static void getfibonacci(int m, int n, int month)
{
	if( month > 2 )
		getfibonacci(n, m + n, month - 1);
	else
		printf("total = %d\n", n << 1);
	return;
}
