#include <stdio.h>
#define MAX 100
static void recursiveprint(char *s);
int main(void)
{
	char input[MAX];
	fgets(input, MAX, stdin);
	recursiveprint(input);
	printf("\n");
	return 0;
}
static void recursiveprint(char *s)
{
	if( '\0' == *s )
		return;
	recursiveprint(s + 1);
	printf("%c", *s);
}
