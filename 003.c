#include <stdio.h>
#include <math.h>
int main(void)
{
	int i = -100;

	for( i = 1; i < 9000; ++i )
		if( i + 100 == (int)sqrt(i + 100) * (int)sqrt(i + 100)
			&& i + 268 == (int)sqrt(i + 268) * (int)sqrt(i + 268) )
			printf("%d\n", i);
	return 0;
}
