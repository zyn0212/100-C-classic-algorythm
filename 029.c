#include <stdio.h>
int main(void)
{
	int n = 0, count = 0;
	scanf("%d", &n);
	do
	{
		printf("%d", n % 10);
		n /= 10;
		++count;
	} while( n > 0 );
	printf(", number length is %d\n", count);
	return 0;
}
