#include <stdio.h>
static float GetResult(int n);
int main(void)
{
	int n = 0;
	scanf("%d", &n);
	printf("Result = %f\n", GetResult(n));
	return 0;
}
static float GetResult(int n)
{
	float sum = 0.0;
	while( n > 0 )
	{
		sum += 1.0 / n;
		n -= 2;
	}
	return sum;
}
