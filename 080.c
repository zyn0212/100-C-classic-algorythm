#include <stdio.h>
int main(void)
{
	int n = 0, result = 6;
	scanf("%d", &n);
	while( n-- > 1 )
		result = result * 5 + 1;
	printf("there are %d pinks!\n", result);
	return 0;
}
