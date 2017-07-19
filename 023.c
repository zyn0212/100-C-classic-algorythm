#include <stdio.h>
int main(void)
{
	int i = 0;
	for( i = 0; i < 7; ++i )
		printf("%.*s\n\n", i * 3 + (i > 0 ? 0 : 1),  "********" + (i > 3 ? 0x7A >> (i - 4) * (i - 4) & 7 : 0));
	return 0;
}
