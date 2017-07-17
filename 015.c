#include <stdio.h>
int main(void)
{
	int score = 0;
	scanf("%d", &score);
	printf("Your rank is %c\n", score >= 90 ? 'A' : score >= 80 ? 'B' : score >= 70 ? 'C' : score >= 60 ? 'D' : 'E');
	return 0;
}
