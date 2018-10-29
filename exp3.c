#include <stdio.h>
#include <math.h>

int main()
{
    int number;
    scanf("%d", &number);
    /*
    求出正整数位数
    */
    int digits = 1;
    while (number / 10 != 0)
    {
        digits++;
        number /= 10;
    }
    printf("%d\n", digits);

    /*
    输出每一位
    */
    for (int i = 0; i < digits; i++)
    {
        // printf("%d", number % (int)pow(10, digits - i - 1));
    }
    // print_reverse(number);
    return 0;
}