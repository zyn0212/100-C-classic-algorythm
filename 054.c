#include <stdio.h>
int main(void)
{
	int n = 0;
	scanf("%d", &n);
	printf("%d\n", n & (0xF << 3));
	return 0;
}
