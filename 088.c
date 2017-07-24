#include <stdio.h>
int main(void)
{
	int i = 0, n = 0, j = 0;
	for( i = 0; i < 7; ++i )
	{
		scanf("%d", &n);
		for( j = 0; j < n >> 3; ++j )
			printf("********");
		printf("%s\n", "*******" + 7 - (n & 7));
	}
	return 0;
}
