#include "main.h"
// 录入信息
#define USE_FILE

void input()
{
#ifdef USE_FILE
	int r, line = 0, found = 0;
	FILE *fp = fopen("score.txt", "r");
	while (1)
	{
		r = fscanf(fp, "%d %s %d %d", &student[STUDENT_SUM].id, student[STUDENT_SUM].name, &student[STUDENT_SUM].progress_score, &student[STUDENT_SUM].final_score);
		if (r == EOF)
			break;
		// 计算总成绩
		student[STUDENT_SUM].overall_rating = student[STUDENT_SUM].progress_score * 0.2 + student[STUDENT_SUM].final_score * 0.8;
		STUDENT_SUM++;
	}
#else
	char goon = 0;
	printf("\t\t\t*           * Input *           *\n");
	while (1)
	{
		printf("请输入第%d个学生成绩信息（学号、姓名、平时成绩、期末成绩）\n", STUDENT_SUM + 1);
		printf("（请用空格/TAB/回车分隔）\n");
		scanf("%d %s %d %d", &student[STUDENT_SUM].id, student[STUDENT_SUM].name, &student[STUDENT_SUM].progress_score, &student[STUDENT_SUM].final_score);
		// 计算总成绩
		student[STUDENT_SUM].overall_rating = student[STUDENT_SUM].progress_score * 0.2 + student[STUDENT_SUM].final_score * 0.8;
		// printf("%d %s %d %d\n", student[STUDENT_SUM].id, student[STUDENT_SUM].name, student[STUDENT_SUM].progress_score,\
			student[STUDENT_SUM].final_score);
		STUDENT_SUM++;
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

// 冒泡排序
void do_sort()
{
	for (int i = 0; i < STUDENT_SUM - 1; i++)
	{
		for (int j = 0; j <= STUDENT_SUM - 1 - i; j++)
		{
			if (student[j].overall_rating < student[j + 1].overall_rating)
			{
				struct Student temp = student[j];
				student[j] = student[j + 1];
				student[j + 1] = temp;
			}
		}
	}
}
// 排序并显示
void sort()
{
	do_sort();
	system("cls");
	printf("\n\t\t\t*             * Sort By Overall rating *             *\n\n");
	printf("\t\t\t* * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t学号\t    姓名\t\t平时成绩（20%%）\t期末成绩（80%%）\t总评成绩\n");
	for (int i = 0; i < STUDENT_SUM; i++)
	{
		printf("\t\t%d\t%10s\t\t%3d\t\t%3d\t\t%3.2f\n", student[i].id, student[i].name, student[i].progress_score, student[i].final_score, student[i].overall_rating);
	}
}

void display_by_pro()
{
	int l60 = 0, l70 = 0, l80 = 0, l90 = 0, l100 = 0;
	for (int i = 0; i < STUDENT_SUM; i++)
	{
		if (student[i].progress_score < 60)
			l60++;
		else if (student[i].progress_score < 70)
			l70++;
		else if (student[i].progress_score < 80)
			l80++;
		else if (student[i].progress_score < 90)
			l90++;
		else
			l100++;
	}

	system("cls");
	printf("\t\t\t*           * 平时成绩  *           *\n\n");
	printf("\t\t\t* * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t平时成绩        人数      所占比重\n");
	printf("\t\t\t不及格           %d         %.2f%%\n", l60, 100.0 * l60 / STUDENT_SUM);
	printf("\t\t\t60~69            %d         %.2f%%\n", l70, 100.0 * l70 / STUDENT_SUM);
	printf("\t\t\t70~79            %d         %.2f%%\n", l80, 100.0 * l80 / STUDENT_SUM);
	printf("\t\t\t80~89            %d         %.2f%%\n", l90, 100.0 * l90 / STUDENT_SUM);
	printf("\t\t\t90~100           %d         %.2f%%\n", l100, 100.0 * l100 / STUDENT_SUM);
}
void display_by_final()
{
	int l60 = 0, l70 = 0, l80 = 0, l90 = 0, l100 = 0;
	for (int i = 0; i < STUDENT_SUM; i++)
	{
		if (student[i].final_score < 60)
			l60++;
		else if (student[i].final_score < 70)
			l70++;
		else if (student[i].final_score < 80)
			l80++;
		else if (student[i].final_score < 90)
			l90++;
		else
			l100++;
	}

	system("cls");
	printf("\t\t\t*           * 期末成绩  *           *\n\n");
	printf("\t\t\t* * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t期末成绩        人数      所占比重\n");
	printf("\t\t\t不及格           %d         %.2f%%\n", l60, 100.0 * l60 / STUDENT_SUM);
	printf("\t\t\t60~69            %d         %.2f%%\n", l70, 100.0 * l70 / STUDENT_SUM);
	printf("\t\t\t70~79            %d         %.2f%%\n", l80, 100.0 * l80 / STUDENT_SUM);
	printf("\t\t\t80~89            %d         %.2f%%\n", l90, 100.0 * l90 / STUDENT_SUM);
	printf("\t\t\t90~100           %d         %.2f%%\n", l100, 100.0 * l100 / STUDENT_SUM);
}
void display_by_overall()
{
	int l60 = 0, l70 = 0, l80 = 0, l90 = 0, l100 = 0;
	for (int i = 0; i < STUDENT_SUM; i++)
	{
		if (student[i].overall_rating < 60)
			l60++;
		else if (student[i].overall_rating < 70)
			l70++;
		else if (student[i].overall_rating < 80)
			l80++;
		else if (student[i].overall_rating < 90)
			l90++;
		else
			l100++;
	}

	system("cls");
	printf("\t\t\t*           * 总成绩  *           *\n\n");
	printf("\t\t\t* * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t总成绩          人数      所占比重\n");
	printf("\t\t\t不及格           %d         %.2f%%\n", l60, 100.0 * l60 / STUDENT_SUM);
	printf("\t\t\t60~69            %d         %.2f%%\n", l70, 100.0 * l70 / STUDENT_SUM);
	printf("\t\t\t70~79            %d         %.2f%%\n", l80, 100.0 * l80 / STUDENT_SUM);
	printf("\t\t\t80~89            %d         %.2f%%\n", l90, 100.0 * l90 / STUDENT_SUM);
	printf("\t\t\t90~100           %d         %.2f%%\n", l100, 100.0 * l100 / STUDENT_SUM);
}

// display 功能
void display()
{
	system("cls");
	printf("\t\t\t*           * Display *           *\n\n");
	printf("\t\t\t* * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t*             统计方式             *\n");
	printf("\t\t\t*         * a. 平时成绩 *          *\n");
	printf("\t\t\t*         * b. 期末成绩 *          *\n");
	printf("\t\t\t*         * c. 总评成绩 *          *\n");
	printf("\t\t\t*         * q. 退出    *           *\n");
	printf("\t\t\t* * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t          选择统计方式： ");

	while (getchar() != '\n')
		;
	char i = getchar();
	if (i != 'g')
		switch (i)
		{
		case 'a':
			display_by_pro();
			break;
		case 'b':
			display_by_final();
			break;
		case 'c':
			display_by_overall();
			break;
		}
}

void search()
{
	system("cls");
	struct Student search_stu;
	int found = 0;
	int number = 0;
	// 先进行排序，以便确定名次
	do_sort();
	printf("\t\t\t*           * Search *           *\n\n");
	printf("\t\t\t* * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t请输入要查找的学生姓名：");

	while (getchar() != '\n')
		;
	scanf("%s", search_stu.name);
	for (int i = 0; i < STUDENT_SUM; i++)
	{
		if (strcmp(search_stu.name, student[i].name) == 0)
		{
			found = 1;
			search_stu = student[i];
			number = i + 1;
			break;
		}
	}
	if (found == 0)
	{
		printf("\t\t\t没找到学生：%s, 请重新输入（y）/退出（q）", search_stu.name);
		while (getchar() != '\n')
			;
		char i = getchar();
		// 重新输入
		if (i == 'y' || i == 'Y')
		{
			search();
		}
	}
	else
	{
		printf("\t\t学号\t    姓名\t\t平时成绩（20%%）\t期末成绩（80%%）\t总评成绩\t名次\n");
		printf("\t\t%d\t%10s\t\t%3d\t\t%3d\t\t%3.2f\t\t%d\n", search_stu.id, search_stu.name, search_stu.progress_score, search_stu.final_score, search_stu.overall_rating, number);
	}
}