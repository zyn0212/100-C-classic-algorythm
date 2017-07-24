#include <stdio.h>
int main(void)
{
	long int sum = 9, n = 0;
	int i = 0;
	scanf("%ld", &n);
	for( i = 0; i < 19; ++i )
		if( 0 == sum % n )
		{
			printf("%ld %% %ld = 0\n", sum, n);
			return 0;
		}
		else
			sum = sum * 10 + 9;
	printf("missed!\n");
	return 0;
}
