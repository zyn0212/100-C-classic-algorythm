#include <stdio.h>
int main(void)
{
	int i = 0, j = 0;
	for( i = 1; i < 10; ++i )
	{
		for( j = 1; j < i; ++j )
			printf("%s", "            ");
		for( j = i; j < 10; ++j )
			printf("%d x %d = %2d  ", i, j, i * j);		
		printf("\n");
	}
	return 0;
}
