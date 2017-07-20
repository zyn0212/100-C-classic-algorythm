#include <stdio.h>
#include <string.h>
#define MAX 20
int main(void)
{
	unsigned long int n = 0, length = 0;
	char input[MAX];
	scanf("%lu", &n);
	sprintf(input, "%lu", n);
	length = strlen(input);
	if( 0 == (length & 1) )
		printf("%lu is not huiwenshu!\n", n);
	else
	{
		int i = 0;
		for( i = 0; i < (length >> 1); ++i )
			if( input[i] != input[length - 1 - i] )
				break;
		if( i >= (length >> 1) )
			printf("%lu is huiwenshu!\n", n);
		else
			printf("%lu is not huiwenshu!\n", n);
	}
	return 0;
}
