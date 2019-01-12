#include "main.h"
// 录入信息

void input()
{
	system("cls");
	printf("\t\t\t*            * Input *            *\n\n");
	printf("\t\t\t* * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t*             输入方式             *\n");
	printf("\t\t\t*         * a. 读取文件 *          *\n");
	printf("\t\t\t*         * b. 手工输入 *          *\n");
	printf("\t\t\t*         * q. 退出    *           *\n");
	printf("\t\t\t* * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t          选择输入方式： ");
	while (getchar() != '\n')
		;
	char i = getchar();
	if (i != 'g')
		switch (i)
		{
		case 'a':
			input_file();
			break;
		case 'b':
			input_hand();
			break;
		default:
			printf("\t\t\t输入有误，请重新选择输入方式（y）：");
			while (getchar() != '\n')
				;
			char ii = getchar();
			if (ii == 'y' || ii == 'Y')
			{
				input();
			}
		}
	// 计算总成绩
	compute_overall();
}
void input_file()
{
	FILE *fp;
	struct Student temp_student;
	if ((fp = fopen("score.txt", "r")) == NULL)
	{
		printf("\t\t\t* 文件不存在!!! *\n");
	}
	else
	{
		while (1)
		{
			int r = fscanf(fp, "%d %s %d %d", &temp_student.id, temp_student.name, &temp_student.progress_score, &temp_student.final_score);
			// int r = fscanf(fp, "%d %s %d %d", &student[STUDENT_SUM].id, student[STUDENT_SUM].name, &student[STUDENT_SUM].progress_score, &student[STUDENT_SUM].final_score);

			if (r == EOF)
				break;
			if (search_by_id(temp_student.id) == -1)
			{
				student[STUDENT_SUM] = temp_student;
				STUDENT_SUM++;
			}
		}
		printf("\t\t\t* 读入成功!!! *\n");
	}
	fclose(fp);
}

void input_hand()
{
	system("cls");
	struct Student temp_student;
	char goon = 0;
	printf("\t\t\t*           * Input *           *\n");
	while (1)
	{
		printf("请输入第%d个学生成绩信息（学号、姓名、平时成绩、期末成绩）\n", STUDENT_SUM + 1);
		printf("（请用空格/TAB/回车分隔）\n");
		while (getchar() != '\n')
			;
		scanf("%d %s %d %d", &temp_student.id, temp_student.name, &temp_student.progress_score, &temp_student.final_score);
		// 计算总成绩
		// student[STUDENT_SUM].overall_rating = student[STUDENT_SUM].progress_score * 0.2 + student[STUDENT_SUM].final_score * 0.8;
		// printf("%d %s %d %d\n", student[STUDENT_SUM].id, student[STUDENT_SUM].name, student[STUDENT_SUM].progress_score,\
			student[STUDENT_SUM].final_score);
		// STUDENT_SUM++;
		if (search_by_id(temp_student.id) == -1)
		{
			student[STUDENT_SUM] = temp_student;
			STUDENT_SUM++;
			// 继续输入?
			printf("输入成功，是否继续输入？（输入q退出）\n");
		}
		else
			printf("学号%d的学生已存在，是否继续输入？（输入q退出）\n", temp_student.id);

		while (getchar() != '\n')
			;
		goon = getchar();
		if (goon == 'q')
		{
			break;
		}
	}
}

// 计算总成绩
void compute_overall()
{
	for (int i = 0; i < STUDENT_SUM; i++)
	{
		student[i].overall_rating = student[i].progress_score * progress_rate / 100.0 + student[i].final_score * final_rate / 100.0;
	}
}

void menu()
{
	printf("\n");
	printf("\t\t\t* * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t*              Menu             *\n");
	printf("\t\t\t*         * a. Input *          *\n");
	printf("\t\t\t*         * b. Display *        *\n");
	printf("\t\t\t*         * c. Sort *           *\n");
	printf("\t\t\t*         * d. Find *           *\n");
	printf("\t\t\t*         * e. Modify *         *\n");
	printf("\t\t\t*         * f. Delete *         *\n");
	printf("\t\t\t*         * g. Save to file *   *\n");
	printf("\t\t\t*         * q. Exit *           *\n");
	printf("\t\t\t* * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t   Please select a to q :");
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
	system("cls");
	do_sort();
	show_all_info();
}

void show_all_info()
{
	printf("\n\t\t\t*             * Sort By Overall rating *             *\n\n");
	printf("\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t学号\t    姓名\t\t平时成绩（%d%%）\t期末成绩（%d%%）\t总评成绩\n", progress_rate, final_rate);
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

void change_rate()
{
	system("cls");
	printf("\t\t\t*            * Change rate *          *\n\n");
	printf("\t\t\t* * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t请输入平时成绩与期末成绩之比(例如：\"30,40\"): ");
	scanf("%d,%d", &progress_rate, &final_rate);
	if (progress_rate + final_rate == 100)
	{
		compute_overall();
		do_sort();
		show_all_info();
	}
	else
	{
		printf("\n\t\t\t输入有误，重新输入(y)?");
		char ii;
		while (getchar() != '\n')
			;
		ii = getchar();
		if (ii == 'y' || ii == 'Y')
		{
			change_rate();
		}
	}
}

int search_by_id(int id)
{
	for (int i = 0; i < STUDENT_SUM; i++)
	{
		if (student[i].id == id)
		{
			return i;
		}
	}
	return -1;
}

void Delete()
{
	int del_id, num;
	system("cls");
	show_all_info();

	printf("\t\t\t* * * * * * * * * * * * * * * * * * * *\n");
	printf("\t\t\t请输入要删除学生的学号: ");
	scanf("%d", &del_id);
	if ((num = search_by_id(del_id)) != -1)
	{
		delete_stu(num);
	}
	else
	{
		printf("\t\t\t输入有误, 请重新输入（y）/退出（q）");
		while (getchar() != '\n')
			;
		char i = getchar();
		// 重新输入
		if (i == 'y' || i == 'Y')
		{
			Delete();
		}
	}
}

void delete_stu(int num)
{
	STUDENT_SUM--;
	for (int i = num; i < STUDENT_SUM; i++)
	{
		student[i] = student[i + 1];
	}
}

void save()
{
	FILE *fp;
	if ((fp = fopen("score.txt", "w")) == NULL)
	{
		printf("\t\t\t* 文件不存在!!! *\n");
	}
	else
	{
		for (int i = 0; i < STUDENT_SUM; i++)
		{
			int r = fprintf(fp, "%d %s %d %d\n", student[i].id, student[i].name, student[i].progress_score, student[i].final_score);
		}
		printf("\t\t\t* 保存成功!!! *\n");
	}
	fclose(fp);
}