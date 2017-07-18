#include <stdio.h>
#define MAX 1000 + 1
int main(void)
{
	int i = 0, j = 0, check = 0;
	for( i = 1; i < MAX; ++i )
	{
		for( j = 2, check = 1; j < i; ++j )
			if( 0 == i % j )
				check += j;
		if( i == check )
			printf("%d\n", i);
	}
	return 0;
}
