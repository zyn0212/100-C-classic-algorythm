#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 10
int main(void)
{
	srand(time(0));
	int i = 0, j = 0, array[MAX], change = 0;
	for( i = 0; i < MAX; ++i )
		printf("%d\t", array[i] = rand() % 100 + 1);
	printf("\n");
	for( i = 1; i < MAX; ++i )
	{
		for( j = MAX - 1, change = 0; j >= i; --j )
			if( array[j] < array[j - 1] )
			{
				array[j] ^= array[j - 1] ^= array[j] ^= array[j - 1];
				++change;
			}
		if( 0 == change )
			break;
	}
	for( i = 0; i < MAX; ++i )
		printf("%d\t", array[i]);
	printf("\n");
	return 0;
}
