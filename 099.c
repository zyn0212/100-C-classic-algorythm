#include <stdio.h>
#define PATHMAX 50
#include <string.h>
int main(int argc, char *argv[])
{
	if( 4 != argc ) {
		printf("wrong parameters!\n");
		return 1;
	}
	char path[PATHMAX], result[128];
	memset(path, 0, sizeof path);
	memset(result, 0, sizeof result);
	FILE *fp = NULL, *fpA = NULL, *fpB = NULL;
	if( NULL == (fpA = fopen(argv[1], "r")) ) {
		printf("open file %s failed!\n", argv[1]);
		return 2;
	}
	if( NULL == (fpB = fopen(argv[2], "r")) ) {
		printf("open file %s failed!\n", argv[2]);
		fclose(fpA);
		fpA = NULL;
		return 3;
	}
	sprintf(path, "%s%s", '/' == *argv[3] ? "" : "./", argv[3]);
	if( NULL == (fp = fopen(path, "w")) ) {
		printf("open file %s failed!\n", path);
		fclose(fpA);
		fpA = NULL;
		fclose(fpB);
		fpB = NULL;
		return 4;
	}
	int c = 0;
	while( EOF != (c = fgetc(fpA)) )
		++result[c];
	while( EOF != (c = fgetc(fpB)) )
		++result[c];
	for( c = 0x20; c < 0x7F; ++c )
		while( result[c]-- > 0 )
			fputc(c, fp);
	fclose(fp);
	fp = NULL;
	fclose(fpA);
	fpA = NULL;
	fclose(fpB);
	fpB = NULL;
	return 0;
}
