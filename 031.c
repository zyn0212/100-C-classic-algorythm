#include <stdio.h>
int main(void)
{
	int c = 0, week = 0;
	c = getchar();
	char *weekday[8] = {"Invalid day", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	while( '\n' != getchar() )
		NULL;
	switch( c )
	{
		case 'S': case 's':
			week = 7;
			c = getchar();
			if( 'a' == c )
				--week;
			else if( 'u' == c )
				NULL;
			else
				week = 0;
			break;
		case 'F': case 'f':
			week = 5;
			break;
		case 'W': case 'w':
			week = 3;
			break;
		case 'T': case 't':
			week = 2;
			c = getchar();
			if( 'h' == c )
				week += 2;
			else if( 'u' == c )
				NULL;
			else
				week = 0;
			break;
		case 'M': case 'm':
			week = 1;
			break;
		default:
			break;
	}
	printf("Your input is %s!\n", weekday[week]);
	return 0;
}
