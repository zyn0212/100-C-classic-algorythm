#include <stdio.h>
static int getresult(int start, int n);
int main(void)
{
	int start = 0, n = 0;
	scanf("%d,%d", &start, &n);
	getresult(start, n);
	return 0;
}
static int getresult(int start, int n)
{
	if( --n > 0 )
		return getresult(start + 2, n);
	else
		return printf("the first is %d\n", start);
}
