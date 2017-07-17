#include <stdio.h>
#define S ((((((((((((((((0
#define X * 2 + 1)
#define _ * 2 )
unsigned int const character_c[16] = {
S _ _ _ _ _ _ _ X _ X _ _ _ _ _ _,
S _ _ _ _ X _ _ _ _ _ _ _ X _ _ _,
S _ _ X _ _ _ _ _ _ _ _ _ _ _ _ X,
S _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _,
S _ X _ _ _ _ _ _ _ _ _ _ _ _ _ _,
S _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _,
S X _ _ _ _ _ _ _ _ _ _ _ _ _ _ _,
S _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _,
S X _ _ _ _ _ _ _ _ _ _ _ _ _ _ _,
S _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _,
S _ X _ _ _ _ _ _ _ _ _ _ _ _ _ _,
S _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _,
S _ _ X _ _ _ _ _ _ _ _ _ _ _ _ _,
S _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ X,
S _ _ _ _ X _ _ _ _ _ _ _ X _ _ _,
S _ _ _ _ _ _ _ X _ X _ _ _ _ _ _,
};
unsigned int const character_i[16] = {
S _ _ _ _ _ _ X X X _ _ _ _ _ _ _,
S _ _ _ _ _ _ _ X _ _ _ _ _ _ _ _,
S _ _ _ _ _ _ _ X _ _ _ _ _ _ _ _,
S _ _ _ _ _ _ _ X _ _ _ _ _ _ _ _,
S _ _ _ _ _ _ _ X _ _ _ _ _ _ _ _,
S _ _ _ _ _ _ _ X _ _ _ _ _ _ _ _,
S _ _ _ _ _ _ _ X _ _ _ _ _ _ _ _,
S _ _ _ _ _ _ _ X _ _ _ _ _ _ _ _,
S _ _ _ _ _ _ _ X _ _ _ _ _ _ _ _,
S _ _ _ _ _ _ _ X _ _ _ _ _ _ _ _,
S _ _ _ _ _ _ _ X _ _ _ _ _ _ _ _,
S _ _ _ _ _ _ _ X _ _ _ _ _ _ _ _,
S _ _ _ _ _ _ _ X _ _ _ _ _ _ _ _,
S _ _ _ _ _ _ _ X _ _ _ _ _ _ _ _,
S _ _ _ _ _ _ _ X _ _ _ _ _ _ _ _,
S _ _ _ _ _ _ X X X _ _ _ _ _ _ _,
};
unsigned int const character_l[16] = {
S _ _ _ _ X _ X _ _ _ X _ X _ _ _,
S _ _ _ _ _ _ _ X _ X _ _ _ _ _ _,
S _ _ X _ _ _ _ _ _ _ _ _ _ _ X _,
S _ _ _ _ _ _ _ _ X _ _ _ _ _ _ _,
S _ X _ _ _ _ _ _ _ _ _ _ _ _ _ X,
S _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _,
S _ X _ _ _ _ _ _ _ _ _ _ _ _ _ X,
S _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _,
S _ _ X _ _ _ _ _ _ _ _ _ _ _ X _,
S _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _,
S _ _ _ X _ _ _ _ _ _ _ _ _ X _ _,
S _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _,
S _ _ _ _ _ X _ _ _ _ _ X _ _ _ _,
S _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _,
S _ _ _ _ _ _ _ X _ X _ _ _ _ _ _,
S _ _ _ _ _ _ _ _ X _ _ _ _ _ _ _,
};
unsigned int const character_u[16] = {
S _ _ X _ _ _ _ _ _ _ _ _ _ _ X _,
S _ _ X _ _ _ _ _ _ _ _ _ _ _ X _,
S _ _ X _ _ _ _ _ _ _ _ _ _ _ X _,
S _ _ X _ _ _ _ _ _ _ _ _ _ _ X _,
S _ _ X _ _ _ _ _ _ _ _ _ _ _ X _,
S _ _ X _ _ _ _ _ _ _ _ _ _ _ X _,
S _ _ X _ _ _ _ _ _ _ _ _ _ _ X _,
S _ _ X _ _ _ _ _ _ _ _ _ _ _ X _,
S _ _ X _ _ _ _ _ _ _ _ _ _ _ X _,
S _ _ X _ _ _ _ _ _ _ _ _ _ _ X _,
S _ _ X _ _ _ _ _ _ _ _ _ _ _ X _,
S _ _ X _ _ _ _ _ _ _ _ _ _ _ X _,
S _ _ X _ _ _ _ _ _ _ _ _ _ _ X _,
S _ _ _ X _ _ _ _ _ _ _ _ _ X _ _,
S _ _ _ _ _ X _ _ _ _ _ X _ _ _ _,
S _ _ _ _ _ _ _ X _ X _ _ _ _ _ _,
};
void draw(unsigned int const n[16]);
void draw_s(unsigned int n[16], unsigned int o[16], unsigned int p[16]);
int main(void)
{
	draw(character_c);
//	draw_s(character_i, character_l, character_u);
	return 0;
}
static void drawline(unsigned int n, int bitloc);
void draw_s(unsigned int n[16], unsigned int o[16], unsigned int p[16])
{
	int i = 0;
	for( i = 0; i < 16; ++i )
	{
		drawline(*n++, 1);
		printf("\t");
		drawline(*o++, 1);
		printf("\t");
		drawline(*p++, 1);
		printf("\n");
	}
	return;
}
void draw(unsigned const int n[16])
{
	if( NULL == n )
	{
		printf("fatal error!\n");
		return;
	}
	int i = 0;
	for( i = 0; i < 16; ++i )
	{
		drawline(*n++, 1);
		printf("\n");
	}
	return;
}
static void drawline(unsigned int n, int bitloc)
{
	if( bitloc < 16 )
		drawline(n >> 1, bitloc + 1);
	printf("%c ", 1 == (n & 1) ? '*' : ' ');
	return;
}
