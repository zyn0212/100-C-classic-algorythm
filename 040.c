#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 15
static void print(int *s, int n);
int main(void)
{
	srand(time(0));
	int array[MAX], i = 0;
	for( i = 0; i < MAX; ++i )
		printf("%d\t", array[i] = rand() % 100 + 1);
	printf("\n");
	print(array, MAX);
	printf("\n");
	return 0;
}
static void print(int *s, int n)
{
	if( n > 1 )
		print(s + 1, n - 1);
	printf("%d\t", *s);
}
