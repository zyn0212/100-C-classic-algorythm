#include <stdio.h>
#define PATHMAX 50
#include <string.h>
int main(int argc, char *argv[])
{
	if( 2 != argc ) {
		printf("wrong parameters!\n");
		return 1;
	}
	char path[PATHMAX];
	memset(path, 0, sizeof path);
	FILE *fp = NULL;
	sprintf(path, "%s%s", '/' == *argv[1] ? "" : "./", argv[1]);
	if( NULL == (fp = fopen(path, "w")) ) {
		printf("open file %s failed!\n", path);
		return 2;
	}
	int c = 0;
	while( '\n' != (c = getchar()) && EOF != c )
		fputc(c >= 'a' && c <= 'z' ? c ^ 0x20 : c, fp);
	fclose(fp);
	fp = NULL;
	return 0;
}
