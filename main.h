#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ѧ��������
#define student_max 100

// ����ѧ�������ṹ��
struct Student
{
	int id;
	char name[15];
	int progress_score;
	int final_score;
	double overall_rating;
};

struct Student student[student_max];
// ѧ��ʵ������
int STUDENT_SUM;

// ��������
void input();
void sort();
void display();
void search();