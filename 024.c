#include <stdio.h>
int main(void)
{
	int a = 1, b = 2, n = 0;
	float sum = 2.0;
	scanf("%d", &n);
	printf("2/1");
	while( n-- > 1 )
	{
		a ^= b ^= a ^= b;
		b += a;
		printf(" + %d/%d", b, a);
		sum += b * 1.0 / a;
	}
	printf(" = %f\n", sum);
	return 0;
}
