#include <stdio.h>
// #include <windows.h>
#include <math.h>
#include <time.h>

void first_while()
{
    clock_t starttime, endtime;
    int ncount = 0;
    starttime = clock();
    int big = 1;
    printf("\t\t*********'WHILE'*********\n");
    while (big < 33)
    {
        int small = 2;
        while (small <= 100 - big)
        {
            int middle = 100 - big - small;
            if (middle >= 1 && small % 2 == 0 && big * 3 + middle * 2 + small / 2 == 100)
            {
                ncount++;
                printf("Big horses %d\t  Middle horses %d\t Small horses %d\n", big, middle, small);
            }
            small += 2;
        }
        big++;
    }
    printf("The number of combination with 'WHILE' is %d\n", ncount);
    endtime = clock();
    printf("'WHILE' cost %5.1fus\n", difftime(endtime, starttime));
}

void second_do_while()
{
    clock_t starttime, endtime;
    int ncount = 0;
    starttime = clock();
    int big = 0;
    printf("\t\t*********'DO WHILE'*********\n");
    do
    {
        int small = 0;
        do
        {
            int middle = 100 - big - small;
            if (small % 2 == 0 && big * 3 + middle * 2 + small / 2 == 100)
            {
                ncount++;
                printf("Big horses %d\t  Middle horses %d\t Small horses %d\n", big, middle, small);
            }
            small += 2;
        } while (small <= 100 - big);
        big++;
    } while (big <= 33);
    printf("The number of combination with 'DO WHILE' is %d\n", ncount);
    endtime = clock();
    printf("'DO WHILE' cost %5.1fus\n", difftime(endtime, starttime));
}

void first_for()
{
    clock_t starttime, endtime;
    int ncount = 0;
    starttime = clock();
    printf("\t\t*********'FOR_FIRST'*********\n");
    for (int big = 1; big < 33; big++)
    {
        for (int small = 2; small <= 100 - big; small += 2)
        {
            int middle = 100 - big - small;
            if (middle >= 1 && small % 2 == 0 && big * 3 + middle * 2 + small / 2 == 100)
            {
                ncount++;
                printf("Big horses %d\t  Middle horses %d\t Small horses %d\n", big, middle, small);
            }
        }
    }
    printf("The number of combination with 'FOR_FIRST' is %d\n", ncount);
    endtime = clock();
    printf("'FOR_FIRST' cost %5.1fus\n", difftime(endtime, starttime));
}

void second_for()
{

    clock_t starttime, endtime;
    int ncount = 0;
    starttime = clock();
    printf("\t\t*********'FOR_SECOND'*********\n");
    for (int big = 0; big < 33; big++)
    {
        for (int small = 0; small <= 100 - big; small += 2)
        {
            int middle = 100 - big - small;
            if (small % 2 == 0 && big * 3 + middle * 2 + small / 2 == 100)
            {
                ncount++;
                printf("Big horses %d\t  Middle horses %d\t Small horses %d\n", big, middle, small);
            }
        }
    }
    printf("The number of combination with 'FOR_SECOND' is %d\n", ncount);
    endtime = clock();
    printf("'FOR_SECOND' cost %5.1fus\n", difftime(endtime, starttime));
}
int main()
{
    first_while();
    second_do_while();
    first_for();
    second_for();
    return 0;
}