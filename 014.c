#include <stdio.h>
int main(void)
{
	int i = 0, n = 0;
	scanf("%d", &n);
	printf("%d = ", n);
	for( i = 2; i <= n; ++i )
		while( n != i )
			if( 0 == n % i )
			{
				printf(" %d *", i);
				n /= i;
			}
			else
				break;
	printf(" %d\n", n);
	return 0;
}
