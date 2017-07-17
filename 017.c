#include <stdio.h>
#include <ctype.h>
#define ALPHA 1
#define BLANK 2
#define DIGIT 3
#define OTHER 4
static int gettype(int c);
int main(void)
{
	int c = 0, nc = 0, nb = 0, nn = 0, no = 0;
	while( '\n' != (c = getchar()) )
		switch( gettype(c) )
		{
			case ALPHA:
				++nc;
				break;
			case BLANK:
				++nb;
				break;
			case DIGIT:
				++nn;
				break;
			default:
				++no;
				break;
		}
	printf("There is %d character%s, %d blank%s, %d digit%s, %d other in your input\n",
			nc, nc > 1 ? "s" : "", nb, nb > 1 ? "s" : "", nn, nn > 1 ? "s" : "", no);
	return 0;
}
static int gettype(int c)
{
	if( 1 == isalpha(c) )
		return ALPHA;
	else if( 1 == isdigit(c) )
		return DIGIT;
	else if( ' ' == c || '\t' == c )
		return BLANK;
	else
		return OTHER;
}
