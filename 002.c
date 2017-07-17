#include <stdio.h>
#define RANK2 (100000 / 10)
#define RANK3 (RANK2 + 100000 * 75 / 1000)
#define RANK4 (RANK3 + 200000 * 5 / 100)
#define RANK5 (RANK4 + 200000 * 3 / 100)
#define RANK6 (RANK5 + 400000 * 15 / 1000)
int main(void)
{
	float bonus = 0, finalbonus = 0;
	scanf("%f", &bonus);
	if( bonus > 1000000 )
		finalbonus = (bonus - 1000000) / 100 + RANK6;
	else if( bonus > 600000	)
		finalbonus = (bonus - 600000) * 15 / 1000 + RANK5;
	else if( bonus > 400000 )
		finalbonus = (bonus - 400000) * 3 / 100 + RANK4;
	else if( bonus > 200000 )
		finalbonus = (bonus - 200000) * 5 / 100 + RANK3;
	else if( bonus > 100000 )
		finalbonus = (bonus - 100000) * 75 / 1000 + RANK2;
	else
		finalbonus = bonus / 10;
	printf("congradulation! your finalbonus = %f\n", finalbonus);
	return 0;
}
