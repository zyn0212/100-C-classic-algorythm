#include <stdio.h>
#include <string.h>
#define MAX 100
static void printYH(int *yh, int line, int n);
int main(void)
{
	int yh[MAX];
	int i = 0, n = 0;
	scanf("%d", &n);
	memset(yh, 0, sizeof(int) * MAX);
	yh[1] = 1;
	for( i = 0; i < n; ++i )
	{
		printYH(yh, i, n - i - 1);
		printf("\n");
	}
	return 0;
}
static void printYH(int *yh, int line, int n)
{
	yh[line + 1] += yh[line];
	if( line > 0 )
		printYH(yh, line - 1, n);
	else
	{
		int i = 0;
		for( i = 0; i < n; ++i )
			printf("   ");
	}
	printf("%5d ", yh[line + 1]);
}
