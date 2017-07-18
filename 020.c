#include <stdio.h>
int main(void)
{
	int i = 0, n = 0;
	float height = 100.0, total = 0.0, jmp = 0.0;
	scanf("%d", &n);
	for(i = 0; i < n; ++i )
		total += (jmp = height * 1.0 / ( 1 << i)) * 2;
	printf("Total walk = %f, last jump = %f\n", total - height, jmp);
	return 0;
}
