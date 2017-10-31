#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAMEMAX 20
typedef struct PlayerInformation {
	char name[NAMEMAX];
	char team;
	char Location;
	char OpponentLeft;
	char ignore;
	int OpponentStatus;
} PlayerInfo;
static void InitPlayerInformation(PlayerInfo *a, PlayerInfo *b, int n);
static void DeleteOpponent(PlayerInfo *a, PlayerInfo *b, char *a_name, char *b_name, int max);
static void ObtainOpponent(PlayerInfo *a, PlayerInfo *b, char *a_name, char *b_name, int max);
static int GetMatchList(PlayerInfo *a, PlayerInfo *b, int max);
static void PrintMatchList(PlayerInfo *a, PlayerInfo *b, int max);
static void InputPlayerInfo(PlayerInfo *PlayerInfo, char team, char loc, char playernumber);
static void	ObtainOpponent_loc(PlayerInfo *a, PlayerInfo *b, int a_loc, int b_loc, int max);
static void UpdateOpponentStatus(PlayerInfo *a, PlayerInfo *b, int max);
int main(int argc, char *argv[])
{
	int n = 0, i = 0;
	printf("input the number of players in team:\n");
	while ( 1 != scanf("%d", &n) ) {
		while( '\n' != getchar() )
			NULL;
	}
	while( '\n' != getchar() )
		NULL;
	PlayerInfo *a = NULL, *b = NULL;
	if( NULL == (a = (PlayerInfo*)calloc(n, sizeof(PlayerInfo))) ) {
		printf("malloc for team a failed!\n");
		return 1;
	}
	if( NULL == (b = (PlayerInfo*)calloc(n, sizeof(PlayerInfo))) ) {
		printf("malloc for team b failed!\n");
		free(a);
		a = NULL;
		return 1;
	}
	InitPlayerInformation(a, b, n);
	printf("input team a:\n");
	for( i = 0; i < n; ++i )
		InputPlayerInfo(a + i, 'a', (char)i, (char)n);
	printf("input team b:\n");
	for( i = 0; i < n; ++i )
		InputPlayerInfo(b + i, 'b', (char)i, (char)n);
	UpdateOpponentStatus(a, b, n);
	UpdateOpponentStatus(a, b, n);
	UpdateOpponentStatus(a, b, n);
	if( 0 == GetMatchList(a, b, n) )
		PrintMatchList(a, b, n);
	else
		printf("analyse match list failed!\n");
	free(a);
	a = NULL;
	free(b);
	b = NULL;
	return 0;
}
static void InitPlayerInformation(PlayerInfo *a, PlayerInfo *b, int n)
{
	memset(a, 0, sizeof(PlayerInfo) * n);
	memset(b, 0, sizeof(PlayerInfo) * n);
	return;
}
static void UpdateOpponentStatus(PlayerInfo *a, PlayerInfo *b, int max)
{
	char a_tmp[NAMEMAX];
	char b_tmp[NAMEMAX];
	memset(a_tmp, 0, sizeof a_tmp);
	memset(b_tmp, 0, sizeof b_tmp);
	printf("input name of player to delete opponent in team a:\n");
	fgets(a_tmp, NAMEMAX, stdin);
	if( '\n' == a_tmp[strlen(a_tmp) - 1] )
		a_tmp[strlen(a_tmp) - 1] = '\0';
	printf("input name of player to delete opponent in team b:\n");
	fgets(b_tmp, NAMEMAX, stdin);
	if( '\n' == b_tmp[strlen(b_tmp) - 1] )
		b_tmp[strlen(b_tmp) - 1] = '\0';
	DeleteOpponent(a, b, a_tmp, b_tmp, max);
	return;
}
static void DeleteOpponent(PlayerInfo *a, PlayerInfo *b, char *a_name, char *b_name, int max)
{
	int i = 0, a_loc = -1, b_loc = -1;
	for( i = 0; i < max; ++i )
		if( 0 == strcmp(a[i].name, a_name) ) {
			a_loc = i;
			break;
		}
	if( -1 == a_loc ) {
		printf("%s can not find in team a!\n", a_name);
		return;
	}
	for( i = 0; i < max; ++i )
		if( 0 == strcmp(b[i].name, b_name) ) {
			b_loc = i;
			break;
		}
	if( -1 == b_loc ) {
		printf("%s can not find in team b!\n", b_name);
		return;
	}
	if( 0 != (1 << b_loc & a[a_loc].OpponentStatus) ) {
		a[a_loc].OpponentStatus ^= 1 << b_loc;
		a[a_loc].OpponentLeft -= 1;
	}
	if( 0 != (1 << a_loc & b[b_loc].OpponentStatus) ) {
		b[b_loc].OpponentStatus ^= 1 << a_loc;
		b[b_loc].OpponentLeft -= 1;
	}
	if( 1 == a[a_loc].OpponentLeft && 0 == a[a_loc].ignore )
		ObtainOpponent_loc(a, b, a_loc, -1, max);
	if( 1 == b[b_loc].OpponentLeft && 0 == b[b_loc].ignore )
		ObtainOpponent_loc(a, b, -1, b_loc, max);
	return;
}
static int GetMatchList(PlayerInfo *a, PlayerInfo *b, int max)
{
	int i = 0;
	for( i = 0; i < max; ++i )
		if( 1 != a[i].OpponentLeft || 1 != b[i].OpponentLeft )
			break;
	return max == i ? 0 : 1;
}
static void PrintMatchList(PlayerInfo *a, PlayerInfo *b, int max)
{
	int i = 0, j = 0;
	for( i = 0; i < max; ++i ) {
		for( j = 0; a[i].OpponentStatus != (1 << j); ++j )
			continue;
		printf("%*s\tVS\t%*s\n", NAMEMAX, a[i].name, NAMEMAX, b[j].name);
	}
	return;
}
static void InputPlayerInfo(PlayerInfo *PlayerInfo, char team, char loc, char playernumber)
{
	fgets(PlayerInfo->name, NAMEMAX, stdin);
	if( '\n' == PlayerInfo->name[strlen(PlayerInfo->name) - 1] )
		PlayerInfo->name[strlen(PlayerInfo->name) - 1] = '\0';
	PlayerInfo->team = team;
	PlayerInfo->Location = loc;
	PlayerInfo->OpponentLeft = playernumber;
	PlayerInfo->OpponentStatus = (1 << playernumber) - 1;
	return;
}
static void ObtainOpponent(PlayerInfo *a, PlayerInfo *b, char *a_name, char *b_name, int max)
{
	
	return;
}
static void	ObtainOpponent_loc(PlayerInfo *a, PlayerInfo *b, int a_loc, int b_loc, int max)
{
#if 1
	int i = 0;
	if( -1 != a_loc ) {
		for( b_loc = 0; (1 << b_loc) != a[a_loc].OpponentStatus; ++b_loc)
			NULL;
		a[a_loc].ignore = 1;
		b[b_loc].ignore = 1;
		for( i = 0; i < max; ++i )
			if( a[i].OpponentLeft > 1 && (a[i].OpponentStatus & ~(1 << b_loc)) > 0 && 0 == a[i].ignore )
				DeleteOpponent(a, b, a[i].name, b[b_loc].name, max);
		for( i = 0; i < max; ++i )
			if( b[i].OpponentLeft > 1 && (b[i].OpponentStatus & ~(1 << a_loc)) > 0 && 0 == b[i].ignore )
				DeleteOpponent(a, b, a[a_loc].name, b[i].name, max);
	}
	else if( -1 != b_loc ) {
		for( a_loc = 0; (1 << a_loc) != b[b_loc].OpponentStatus; ++a_loc)
			NULL;
		a[a_loc].ignore = 1;
		b[b_loc].ignore = 1;
		for( i = 0; i < max; ++i )
			if( a[i].OpponentLeft > 1 && (a[i].OpponentStatus & ~(1 << b_loc)) > 0 && 0 == a[i].ignore )
				DeleteOpponent(a, b, a[i].name, b[b_loc].name, max);
		for( i = 0; i < max; ++i )
			if( b[i].OpponentLeft > 1 && (b[i].OpponentStatus & ~(1 << a_loc)) > 0 && 0 == b[i].ignore )
				DeleteOpponent(a, b, a[a_loc].name, b[i].name, max);
	}
	else
		printf("ObtainOpponent wrong!\n");
#endif
	return;
}
