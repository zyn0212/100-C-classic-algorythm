#include <stdio.h>
int main(void)
{
	int i = 0, j = 0, k = 0, count = 0;
	for( i = 1; i < 5; ++i )
		for( j = 1; j < 5; ++j )
			for( k = 1; k < 5; ++k )
				if( i != j && i != k && j != k )
				{
					printf("%d %d %d\n", i, j, k);
					++count;
				}
	printf("total = %d\n", count);
	return 0;	
}
////////////
