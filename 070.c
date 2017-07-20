#include <stdio.h>
#define MAX 200
int main(void)
{
	char tmp[MAX];
	scanf("%[^\n]", tmp);
	while( '\n' != getchar() )
		NULL;
	printf("\nlength = %d\n", printf("Your input is:\n%s", tmp) - 15);
	return 0;
}
