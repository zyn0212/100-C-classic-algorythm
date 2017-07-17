#include <stdio.h>
int main(void)
{
	int leap = 0, year = 0, month = 0, day = 0, total = 0;
	printf("input the year,month,day:");
	scanf("%d,%d,%d", &year, &month, &day);
	if( month < 1 || month > 12 || day < 1 || day > 31 )
	{
		printf("Invalid input!\n");
		return 1;
	}
	leap = 0 == year % 400 || 0 == (year & 3) && 0 != year % 100 ? 1 : 0;
	switch( month )
	{
		case 12:
			total += 30;
		case 11:	
			total += 31;	
		case 10:
			total += 30;	
		case 9:
			total += 31;	
		case 8:
			total += 31;	
		case 7:
			total += 30;	
		case 6:
			total += 31;	
		case 5:
			total += 30;	
		case 4:
			total += 31;	
		case 3:
			total += 28 + leap;	
		case 2:
			total += 31;	
		case 1:
			total += day;
			break;
		default:
			break;
	}
	printf("It's the %dth day in %d year!\n", total, year);
}
