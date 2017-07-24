#include <stdio.h>
#define MAX 40
int main(void)
{
	char s[(MAX >> 1) - 1] = "ni hao, wo shi", t[(MAX >> 1) - 1] = "zhaoyining", r[MAX];
	sprintf(r, "%s %s", s, t);
	printf("%s\n", r);
	return 0;
}
