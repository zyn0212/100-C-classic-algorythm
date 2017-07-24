#include <stdio.h>
#define MAX 3
int main(void)
{
	int i = 0, array[MAX][MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9,}, sum = 0;
	for( i = 0; i < MAX; ++i )
	{
		sum += array[i][i] + array[i][MAX - 1 - i];
		if( i == MAX - 1 - i )
			sum -= array[i][i];
	}
	printf("result = %d\n", sum);
	return 0;
}
