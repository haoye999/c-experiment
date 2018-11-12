#include <stdio.h>

#define student_max 5

struct student
{
    long no;
    char name[10];
    char sex;
    int age;
    float score;
};

struct student Student[student_max];
/*sum存储实际人数*/
int sum, sum_tem;
float mean_score;

void input()
{
    printf("Please input the number of students:\n");
    scanf("%d", &sum);
    sum_tem = sum;
    while (sum_tem--)
    {
        int num = sum - sum_tem - 1;
        printf("Please input the NO.%d student's informations:\n", num);
        printf("ID:");
        scanf("%ld", &Student[num].no);
        printf("NAME:");
        scanf("%s", Student[num].name);
        while ((getchar()) != '\n')
            ;
        printf("SEX:");
        scanf("%c", &Student[num].sex);
        printf("AGE:");
        scanf("%d", &Student[num].age);
        printf("SCORE:");
        scanf("%f", &Student[num].score);
    }
}

void show_students()
{
    printf("****************************\n");
    printf("ID\tNAME\tSEX\tAGE\tSCORE\n");
    for (int i = 0; i < sum; i++)
    {
        printf("%ld\t%s\t%c\t%d\t%3.2f\n", Student[i].no, Student[i].name, Student[i].sex, Student[i].age, Student[i].score);
    }
}

void count_sex()
{
    printf("****************************\n");
    int men_num = 0;
    for (int i = 0; i < sum; i++)
    {
        if (Student[i].sex == 'm')
        {
            men_num++;
        }
    }
    printf("men:%d\twomen:%d\n", men_num, sum - men_num);
}

void get_mean_score()
{
    printf("****************************\n");
    float sum_score = 0;
    for (int i = 0; i < sum; i++)
    {
        sum_score += Student[i].score;
    }
    mean_score = sum_score / sum;
    printf("The mean score is %3.2f\n", mean_score);
}

void show_lower_mean()
{
    printf("****************************\n");
    printf("The students who's score is lower than the mean score:\n");
    printf("ID\tNAME\tSEX\tAGE\tSCORE\n");
    for (int i = 0; i < sum; i++)
    {
        if (Student[i].score < mean_score)
        {
            printf("%ld\t%s\t%c\t%d\t%3.2f\n", Student[i].no, Student[i].name, Student[i].sex, Student[i].age, Student[i].score);
        }
    }
}

int main(int argc, char const *argv[])
{
    input();
    show_students();
    count_sex();
    get_mean_score();
    show_lower_mean();
    return 0;
}
