#include <stdio.h>
#define MAX 8
int main(void)
{
	int i = 0, suminloop = 4, sum = 4;
	for( i = 2; i <= MAX; ++i )
	{
		if( MAX == i )
			suminloop *= 8;
		else
			suminloop *= 7;
		sum += suminloop;
	}
	printf("result = %d\n", sum);
	return 0;
}
