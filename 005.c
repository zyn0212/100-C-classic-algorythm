#include <stdio.h>
int main(void)
{
	int a = 0, b = 0, c = 0, min = 0, max = 0;
	scanf("%d,%d,%d", &a, &b, &c);
	min = a, max = a;
	if( b > max )
		max = b;
	else if( b < min )
		min = b;
	if( c > max )
		max = c;
	else if( c < min )
		min = c;
	a ^= b ^ c;
	printf("sort your input from min to max :%d, %d, %d\n", min, a ^ min ^ max, max);
	return 0;
}
