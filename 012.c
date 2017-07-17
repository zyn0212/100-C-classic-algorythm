#include <stdio.h>
#define MAX 200
#define MIN 101
int main(void)
{
	int i = 0, j = 0;
	for( i = MIN + (0 == (MIN & 1) ? 1 : 0 ); i <= MAX; i += 2 )
	{
		for( j = 3; j <= (i >> 1); j += 2 )
			if( 0 == i % j )
				break;	
		if( j > (i >> 1) )
			printf("%d\n", i);
	}
	return 0;
}
