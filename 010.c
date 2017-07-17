#include <stdio.h>
char const blank[50] = "                                                  ";
int main(void)
{
	int i = 0;
	for( i = 0; i < 20; ++i )
		printf("%.*s%s\n", 40 - (i << 1), blank, "_|");
	return 0;
}
