#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int STUDENT_SUM;
// 成绩比重
int progress_rate;
int final_rate;

// 函数声明
void input();
void sort();
void display();
void search();
void compute_overall();
void do_sort();
void display_by_pro();
void display_by_final();
void display_by_overall();
void change_rate();
void show_all_info();
void Delete();
void delete_stu(int);
void save();
void menu();
void input_file();
void input_hand();
int search_by_id(int);