#include <stdio.h>
#include <stdlib.h>
typedef struct player {
	int number;
	struct player *next;
} playerinfo;
int main(void)
{
	int n = 0, i = 0;
	playerinfo *start = NULL;
	scanf("%d", &n);
	start = malloc(sizeof(playerinfo) * n);
	if( NULL == start )
		return 0;
	for( i = 0; i < n; ++i )
	{
		start[i].number = i + 1;
		start[i].next = start + i + 1;
	}
	start[i - 1].next = start;
	playerinfo *tmp = start, *prev = start;
	for( i = 0; tmp != tmp->next; ++i, tmp = tmp->next )
	{
		if( 3 == i % 3 + 1 )
			prev->next = tmp->next;
		prev = tmp;
	}
	printf("%d is left!\n", tmp->number);
	free(start);
	return 0;
}
