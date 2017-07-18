#include <stdio.h>
int main(void)
{
	int total = 1, day = 10;
	while( --day > 0 )
		total = total + 1 << 1;
	printf("total = %d\n", total);
	return 0;
}
