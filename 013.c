#include <stdio.h>
#include <math.h>
#include <string.h>
int g_matrix[10][10];
static int getnumberbit(int n);
int main(void)
{
	int i = 0, j = 0, n = 0, check = 0, tmp = 0;
	for( i = 0; i < 10; ++i )
		for( j = 0; j < 10; ++j )
			g_matrix[i][j] = (int)pow(i, j);
	for( i = 10; i < 99999; ++i )
	{
		for( j = 1, n = getnumberbit(i), tmp = i, check = 0; j <= n; ++j )
		{
			check += g_matrix[tmp % 10][n];
			tmp /= 10; 
		}
		if( check == i )
			printf("%d\n",i);
	}
	return 0;
}
static int getnumberbit(int n)
{
	char tmp[20];
	sprintf(tmp, "%d", n);
	return (int)strlen(tmp);
}	
