#include <stdio.h>
#include <string.h>
#define MAX 100
int main(int argc, char *argv[])
{
	if( 3 != argc ) {
		printf("wrong parameters!\n");
		return 0;
	}
	char tmp[MAX], base[MAX];
	memset(tmp, 0, sizeof tmp);
	memset(base, 0, sizeof base);
	strncpy(tmp, argv[2], MAX - 1);
	strncpy(base, argv[1], MAX - 1);
	int sum = 0, i = 0;
	char *basep = base, *tmpp = tmp, *baseplast = base;
	while( '\0' != *basep ) {
		tmpp = tmp;
		basep = baseplast;
		while( '\0' != *tmpp && '\0' != *basep ) {
			if( *tmpp != *basep )
				break;
			++i;
			++tmpp;
			++basep;
		}
		if( i > 0 && '\0' == *tmpp )
			++sum;
		++baseplast;
	}
	printf("%d\n", sum);
	return 0;
}
