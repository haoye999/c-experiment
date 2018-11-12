#include <stdio.h>
#include <time.h>

int main()
{
    int a, b, c;
    int *p1, *p2;
    p1 = &c;
    p2 = p1 + 3;
    a = p2 - p1;
    b = (char *)p2 - (char *)p1;
    printf("%d, %d\n", a, b);
    return 0;
}