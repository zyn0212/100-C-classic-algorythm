#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 10
int main(void)
{
	char array[MAX][100];
	char *tmp[MAX + 1];
	int i = 0, j = 0;
	srand(time(0));
	for( i = 0; i < MAX; ++i )
	{
		tmp[i] = array[i];
		for( j = 0; j < 30; ++j )
			array[i][j] = rand() % 26 + 'a';
		array[i][j] = '\0';
	}
	for( i = 1; i < MAX; ++i )
		for( j = MAX - 1; j >= i; --j )
			if( strcmp(tmp[j], tmp[j - 1]) < 0 )
			{
				tmp[MAX] = tmp[j - 1];
				tmp[j - 1] = tmp[j];
				tmp[j] = tmp[MAX];
			}
	for( i = 0; i < MAX; ++i )
		printf("%s\n", tmp[i]);
	return 0;
}
