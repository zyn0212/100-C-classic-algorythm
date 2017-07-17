#include <stdio.h>
int main(void)
{
	int i = 0;
	for( i = 0; i < 8; ++i )
		printf("%.8s\n", "B B B B B" + (i & 1));
	return 0;
}
