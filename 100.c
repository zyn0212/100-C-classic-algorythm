#include <stdio.h>
#include <string.h>
#define NAMEMAX 20
#define STUDENTMAX 3
typedef struct StudentInfomation {
	int stu_number;
	char stu_name[NAMEMAX];
	int stu_chinese;
	int stu_math;
	int stu_english;
	float stu_aver;
} stuinf;
static void GetStudentInformation(stuinf *sp);
static void SaveStudentInformation(stuinf *sp, int MAX, FILE *fp);
int main(int argc, char *argv[])
{
	if( 2 != argc ) {
		printf("no output file or to many output file!\n");
		return 1;
	}
	FILE *fp = NULL;
	if( NULL == (fp = fopen(argv[1], "w")) ) {
		printf("open file %s failed!\n", argv[1]);
		return 2;
	}
	stuinf db[STUDENTMAX];
	memset(db, 0, sizeof db);
	int i = 0;
	for( i = 0; i < STUDENTMAX; ++i )
		GetStudentInformation(db + i);
	SaveStudentInformation(db, STUDENTMAX, fp);
	fclose(fp);
	fp = NULL;
	return 0;
}
static void GetStudentInformation(stuinf *sp)
{
	printf("input student number:\n");
	while( 1 != scanf("%d", &sp->stu_number) ) {
		while( '\n' != getchar() )
			continue;
		printf("wrong input to student number, retry, or input 0 for end:\n");
	}
	while( '\n' != getchar() )
		continue;
	if( 0 == sp->stu_number ) {
		memset(sp, 0, sizeof(stuinf));
		printf("clear one student information cause number is zero!\n");
		return;
	}
	printf("input student name:\n");
	while( NULL == fgets(sp->stu_name, NAMEMAX, stdin) || 0 == strcmp("r\n", sp->stu_name) ) {
		memset(sp->stu_name, 0, sizeof(char) * NAMEMAX);
		printf("wrong input to student name, press r and enter to retry, or input enter for end:\n");
	}
	if( 1 == strlen(sp->stu_name) && '\n' == *sp->stu_name ) {
		memset(sp, 0, sizeof(stuinf));
		printf("clear one student information cause name is NULL!\n");
		return;
	}
	else if( '\n' == sp->stu_name[strlen(sp->stu_name) - 1] )
		sp->stu_name[strlen(sp->stu_name) - 1] = '\0';
	else
		while( '\n' != getchar() )
			continue;
	printf("input chinese, math, english score:\n");
	while( 3 != scanf("%d,%d,%d", &sp->stu_chinese, &sp->stu_math, &sp->stu_english) ) {
		sp->stu_chinese = 0, sp->stu_math = 0, sp->stu_english = 0;
		printf("wrong input to student score, press enter to retry, other for zero score each class:\n");
		if( '\n' == getchar() )
			continue;
		else
			break;
	}
	while( '\n' != getchar() )
		continue;
	sp->stu_chinese = sp->stu_chinese < 0 || sp->stu_chinese > 100 ? 0 : sp->stu_chinese;
	sp->stu_math = sp->stu_math < 0 || sp->stu_math > 100 ? 0 : sp->stu_math;
	sp->stu_english = sp->stu_english < 0 || sp->stu_english > 100 ? 0 : sp->stu_english;
	return;
}
static void SaveStudentInformation(stuinf *sp, int MAX, FILE *fp)
{
	fprintf(fp, "the student information:\n");
	fprintf(fp, "%8s\t%*s\t%8s\t%8s\t%8s\t%8s\n", "number", NAMEMAX, "name", "chinese", "math", "english", "average");
	int i = 0;
	for( i = 0; i < MAX; ++i, ++sp )
		fprintf(fp, "%8d\t%*s\t%8d\t%8d\t%8d\t%8.2f\n", sp->stu_number, NAMEMAX, sp->stu_name, sp->stu_chinese, sp->stu_math, sp->stu_english,
			(sp->stu_chinese + sp->stu_math + sp->stu_english) / 3.0);
	return;
}
