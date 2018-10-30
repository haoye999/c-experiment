#include <stdio.h>
#include <math.h>

int number, digits;

int get_digits(int number)
{
    /*
    get digits of number
    */
    int number_s = number;
    int digits = 1;
    while (number / 10 != 0)
    {
        digits++;
        number /= 10;
    }
    printf("%d��λ����%d\n", number_s, digits);
    return digits;
}

void print_every_digit(int number)
{
    /*
    �г�ÿһλ
    */
    printf("�г�ÿһλ��");
    for (int i = 0; i < digits; i++)
    {
        /* + 0.5 ����Ϊ����(int)ǿ��ת��ʱ��ֱ��Ĩ��С��λ�����˹��������롣*/
        int digit = number / (int)(pow(10, digits - i - 1) + 0.5);
        printf("%d ", digit);
        number -= digit * (int)(pow(10, digits - i - 1) + 0.5);
        if (i == digits - 1)
            printf("\n");
    }
}

void print_reverse(int number)
{
    /*
    �������ÿһλ
    */
    printf("�������ÿһλ��");
    for (int i = 0; i < digits; i++)
    {
        int digit_reverse = number % 10;
        printf("%d", digit_reverse);
        number /= 10;
        if (i == digits - 1)
            printf("\n");
    }
}

int main()
{
    printf("������Ҫ�����жϵ�����");
    scanf("%d", &number);
    digits = get_digits(number);
    print_every_digit(number);
    print_reverse(number);
    return 0;
}