#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(void)
{
	srand(time(0));
	int const result = rand() % 100 + 1;
	int n = 0;
	time_t start = time(0), end;
	clock_t s = clock(), e;
	do {
		if( 1 != scanf("%d", &n) ) {
			while( '\n' != getchar() )
				NULL;
			printf("Wrong input, please input number!\n");
			continue;
		}
		if( result == n )
			break;
		else
			printf("%s\n", n > result ? "Larger" : "Smaller");
	} while( 1 );
	end = time(0);
	e = clock();
	printf("You spend %6.3f seconds!\n", difftime(end, start) + ((double)(e - s)) / CLOCKS_PER_SEC * 1000);
	return 0;
}
