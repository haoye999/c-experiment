#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
// 学生最多个数
#define student_max 100

// 定义学生基本结构体
struct Student
{
	int id;
	char name[15];
	int progress_score;
	int final_score;
	double overall_rating;
};

struct Student student[student_max];
// 学生实际总数
int student_sum;

// 函数声明
void input();
void sort();
void display();