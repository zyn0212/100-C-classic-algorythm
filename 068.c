#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
static int swap(int *input, int n, int m);
int main(void)
{
	srand(time(NULL));
	int i = 0, n = 0, m = 0;
	printf("input n,m:");
	scanf("%d,%d", &n, &m);
	int *iarray = calloc(n, sizeof(int));
	if( NULL == iarray )
		return 0;
	for( i = 0; i < n; ++i )
		printf("%3d\t", iarray[i] = rand() % 100 + 1);
	printf("\n");
	swap(iarray, n, m);
	for( i = 0; i < n; ++i )
		printf("%3d\t", iarray[i]);
	printf("\n");
	free(iarray);
	return 0;
}
static int swap(int *input, int n, int m)
{
	int *tmp = calloc(m, sizeof(int));
	if( NULL == tmp || NULL == input )
		exit(0);
	memcpy(tmp, input + n - m, sizeof(int) * m);
	memmove(input + m, input, sizeof(int) * (n - m));
	memcpy(input, tmp, sizeof(int) * m);
	free(tmp);
	return 0;
}
