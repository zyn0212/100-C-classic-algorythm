#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
int main(void)
{
	srand(time(NULL));
	int i = 0;
	int unsorted[MAX];
	int *ipmin = unsorted, *ipmax = unsorted;
	for( i = 0; i < MAX; ++i )
	{
		printf("%3d%c", unsorted[i] = rand() % 100 + 1, 0 == (i + 1) % 10 ? '\n' : '\t');
		ipmin = unsorted[i] < *ipmin ? unsorted + i : ipmin;
	}
	if( ipmin != unsorted + MAX - 1 )
		*ipmin ^= unsorted[MAX - 1] ^= *ipmin ^= unsorted[MAX - 1];
	for( i = 0; i < MAX; ++i )
		ipmax = unsorted[i] > *ipmax ? unsorted + i : ipmax;
	if( ipmax != unsorted )
		*ipmax ^= unsorted[0] ^= *ipmax ^= unsorted[0];
	for( i = 0; i < MAX; ++i )
		printf("%3d%c", unsorted[i], 0 == (i + 1) % 10 ? '\n' : '\t');
	return 0;
}
