#include <stdio.h>

int inNumber()
{
    int out = 0;
    printf("Please input a positive number:\n");
    scanf("%d", &out);
    while (out <= 0)
    {
        printf("Please input again:\n");
        scanf("%d", &out);
    }
    return out;
}

int f(int x, int y)
{
    /*
    辗转相除法
    */
    return y == 0 ? x : f(y, x % y);
}

int g(int x, int y)
{
    /*   
    最小公倍数 * 最大公约数 = x * y
    */
    return x * y / f(x, y);
}

int main()
{
    int a, b, c, d;
    a = inNumber();
    b = inNumber();
    c = f(a, b);
    d = g(a, b);
    printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);
    return 0;
}