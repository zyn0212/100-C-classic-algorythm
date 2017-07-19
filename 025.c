#include <stdio.h>
int main(void)
{
	long int n = 0, sum = 0, i = 0;
	scanf("%ld", &n);
	for( i = 0; i < n; ++i )
		sum += (n - i) * (i + 1);
	printf("result = %ld\n", sum);
	return 0;
}
