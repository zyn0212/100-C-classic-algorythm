#include <stdio.h>
#include <string.h>
#define MAX 10
int main(void)
{
	int array[MAX]  = {1, 3, 5, 7, 9, 11, 13, 15, 17,}, tmp = 0;
	int *start = array, *end = array + MAX - 2;
	scanf("%d", &tmp);
	if( tmp <= array[0] )
	{
		memmove(array + 1, array, sizeof(int) * 9);
		array[0] = tmp;
	}
	else if( tmp >= array[MAX - 2] )
		array[MAX - 1] = tmp;
	else
	{
		while( start < end )
			if( tmp < *(start + (end - start >> 1)) )
				end = start + (end - start >> 1) - 1;
			else if( tmp > *(start + (end - start >> 1)) )
				start = start + (end - start >> 1) + 1;
			else
				break;
		memmove(start + 2, start + 1, sizeof(int) * (array + MAX - 2 - (start + 1) + 1));
		*(start + 1) = tmp;
	}
	for( tmp = 0; tmp < MAX; ++tmp )
		printf("%d\t", array[tmp]);
	printf("\n");
	return 0;
}
