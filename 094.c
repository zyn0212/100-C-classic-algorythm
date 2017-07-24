#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(void)
{
	clock_t start = clock();
	int const result = rand() % 100 + 1;
	int n = 0;
	do {
		scanf("%d", &n);
		if( result == n )
			break;
		else
			printf("%s\n", n > result ? "Larger" : "Smaller");
	} while( 1 );
	clock_t end = clock();
	printf("You spend %f seconds!\n", (double)(end - start) / CLOCKS_PER_SEC);
	return 0;
}
