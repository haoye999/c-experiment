#include "main.h"
// 录入信息
#define file

void input()
{
#ifdef file
	int r, line = 0, found = 0;
	FILE *fp = fopen("score.txt", "r");
	while (1)
	{
		r = fscanf(fp, "%d %s %d %d", &student[student_sum].id, student[student_sum].name, &student[student_sum].progress_score, &student[student_sum].final_score);
		if (r == EOF)
			break;
		// 计算总成绩
		student[student_sum].overall_rating = student[student_sum].progress_score * 0.2 + student[student_sum].final_score * 0.8;
		student_sum++;
	}
#else
	char goon = 0;
	printf("\t\t\t*           * Input *           *\n");
	while (1)
	{
		printf("请输入第%d个学生成绩信息（学号、姓名、平时成绩、期末成绩）\n", student_sum + 1);
		printf("（请用空格/TAB/回车分隔）\n");
		scanf("%d %s %d %d", &student[student_sum].id, student[student_sum].name, &student[student_sum].progress_score, &student[student_sum].final_score);
		// 计算总成绩
		student[student_sum].overall_rating = student[student_sum].progress_score * 0.2 + student[student_sum].final_score * 0.8;
		// printf("%d %s %d %d\n", student[student_sum].id, student[student_sum].name, student[student_sum].progress_score,\
			student[student_sum].final_score);
		student_sum++;
		// 继续输入模块
		printf("输入成功，是否继续输入？（输入q退出）\n");
		while (getchar() != '\n')
			;
		goon = getchar();
		if (goon == 'q')
		{
			break;
		}
	}
#endif
}

void sort()
{
	for (int i = 0; i < student_sum - 1; i++)
	{
		for (int j = 0; j <= student_sum - 1 - i; j++)
		{
			if (student[j].overall_rating < student[j + 1].overall_rating)
			{
				struct Student temp = student[j];
				student[j] = student[j + 1];
				student[j + 1] = temp;
			}
		}
	}
	system("clear");
	printf("\n\t\t\t*           * Sort *           *\n\n");
	printf("\t\t\t* * * * * * * * * * * * * * * * * *\n");
	printf("\t\t学号\t姓名\t平时成绩（20%%）\t期末成绩（80%%）\t总评成绩\n");
	for (int i = 0; i < student_sum; i++)
	{
		printf("\t\t%d\t%s\t%3d\t\t%3d\t\t%3.2f\n", student[i].id, student[i].name, student[i].progress_score, student[i].final_score, student[i].overall_rating);
	}
}

void display()
{
	system("clear");
	printf("\t\t\t*           * Display *           *\n\n");
	printf("\t\t\t* * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t*             统计方式             *\n");
	printf("\t\t\t*         * a. 平时成绩 *          *\n");
	printf("\t\t\t*         * b. 期末成绩 *          *\n");
	printf("\t\t\t*         * c. 总评成绩 *          *\n");
	printf("\t\t\t*         * q. 退出    *           *\n");
	printf("\t\t\t* * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t*         选择统计方式： ");

	while (getchar() != '\n')
		;
	char i = getchar();
	printf("hhh\n");
	if (i != 'g')
		switch (i)
		{
		case 'a':
			system("clear");
			printf("\t\t\t*           * Display *           *\n\n");
			printf("\t\t\t* * * * * * * * * * * * * * * * * *\n");
			printf("\t\t\t平时成绩\t人数\t所占比重\n");
			for (int i = 0; i < student_sum; i++)
			{
				// printf("\t\t\t%d\t%s\t%d\t%d\t%.2f\n", student[i].id, student[i].name, student[i].progress_score, student[i].final_score, student[i].overall_rating);
				printf("\t\t\t%d %d\n", student[i].progress_score, student[i].final_score);
			}
			break;
		case 'b':
			break;
		case 'c':
			// 调用排序函数;
			break;
		}
}