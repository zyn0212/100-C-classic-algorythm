#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct studentinfo {
	int number;
	char name[15];
	float Chinese;
	float Maths;
	float Chemistry;
	float Physics;
	float total;
} Student;
static int input(Student *list, int n);
static int output(Student *list, int n);
int main(void)
{
	srand(time(NULL));
	int n = 0;
	scanf("%d", &n);
	Student * const studentlist = calloc(n, sizeof(Student));
	if( NULL == studentlist )
		return 1;
	input(studentlist, n);
	output(studentlist, n);
	free(studentlist);
	return 0;
}
static int input(Student *list, int n)
{
	int i = 0, j = 0;
	for( i = 0; i < n; ++i )
	{
		list[i].number = i + 1;
		list[i].total += list[i].Chinese = (rand() % 10000 + 1) / 100.0;
		list[i].total += list[i].Maths = (rand() % 10000 + 1) / 100.0;
		list[i].total += list[i].Chemistry = (rand() % 10000 + 1) / 100.0;
		list[i].total += list[i].Physics = (rand() % 10000 + 1) / 100.0;
		for( j = 0; j < 14; ++j )
			list[i].name[j] = (rand() & 1) + 1 > 1 ? rand() % 26 + 'a' : rand() % 26 + 'A';
		list->name[j] = '\0';
	}
	return i;
}
static int output(Student *list, int n)
{
	int i = 0;
	for( i = 0; i < n; ++i )
		printf("Number\t= %d\nName\t= %s\nChinese\t= %.2f\nMaths\t= %.2f\n"
				"Chemis\t= %.2f\nPhysics\t= %.2f\nTotal\t= %.2f\n-----------------------------------\n",
				list[i].number, list[i].name, list[i].Chinese, list[i].Maths, list[i].Chemistry, list[i].Physics,
				list[i].total);
	return i;
}
