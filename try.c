#include <stdio.h>
#include <time.h>

void for_pro1()
{
    clock_t start_time, end_time;
    start_time = clock();
    int cnt = 0;
    for(int big = 1; big < 33; big++)
    {
        for(int small = 2; small < 100 - big; small += 2)
        {
            int middle = 100 - big - small;
            if(middle >= 1 && big * 3 + middle * 2 + small / 2 == 100)
            {
                cnt++;
                printf("Big horse:%d\t Middle horse:%d\t Small horse:%d\n", big, middle, small);
            }
        }
    }
    printf("The number of this method is %d\n", cnt);
    end_time = clock();
    printf("'FOR_PRO1' cost %5.1fus\n", difftime(end_time, start_time));
}

int main()
{
    for_pro1();
    return 0;
}