#include <stdio.h>
#include <math.h>

int get_height(double x, double y)
{
    x = fabs(x) - 2;
    y = fabs(y) - 2;
    return sqrt(pow(x, 2) + pow(y, 2)) > 1 ? 0 : 10;
}

int main()
{
    double pos_x, pos_y;
    int height;
    printf("������Ҫ�����жϵ����꣨��','���������磺1, 2) ��");
    scanf("%lf, %lf", &pos_x, &pos_y);
    height = get_height(pos_x, pos_y);
    printf("(%.2lf, %.2lf)��Ľ����߶��ǣ�%dm\n", pos_x, pos_y, height);
    return 0;
}