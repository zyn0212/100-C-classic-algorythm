#include <stdio.h>
#include <math.h>
#define MAX 400
int main(void)
{
	char result[MAX];
	int n = 0, i = 0, num = 0;
	long int sum = 0, base = 0;
	scanf("%d,%d", &n, &num);
	for( i = 0; i < n; ++i )
	{
		base = base * 10 + 1;
		sum += base;
		sprintf(result, "%s + %ld", result, base * num); 
	}
	printf("%ld = %d %s", sum * num, num, result);
	printf(" %ld\n", (base * 10 + 1) * num);
	return 0;
}
