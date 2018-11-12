#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define rMAX 5
#define cMAX 5
#define nMAX 100

int a[rMAX][cMAX] = {};

void get_random(int a[rMAX][cMAX])
{
    for (int i = 0; i < rMAX; i++)
    {
        for (int j = 0; j < cMAX; j++)
        {
            a[i][j] = rand() % nMAX + 1;
        }
    }
}

void show_random(int a[rMAX][cMAX])
{
    for (int i = 0; i < rMAX; i++)
    {
        for (int j = 0; j < cMAX; j++)
        {
            printf("%2d\t", a[i][j]);
        }
        printf("\n");
    }
}

void exchange_row(int a[rMAX][cMAX], int x, int y)
{
    int temp[cMAX] = {};
    int length = sizeof(int) * cMAX;
    memcpy(temp, a[x], length);
    memcpy(a[x], a[y], length);
    memcpy(a[y], temp, length);
}

void show_max(int a[rMAX][cMAX])
{
    for (int i = 0; i < rMAX; i++)
    {
        int nmax = 0;
        int colnum_max = 0;
        for (int j = 0; j < cMAX; j++)
        {
            if (a[i][j] > nmax)
            {
                nmax = a[i][j];
                colnum_max = j;
            }
        }
        printf("The max number of this row %d is %d in col %d\n", i + 1, nmax, colnum_max + 1);
    }
}

int main(void)
{
    system("clear");
    srand((unsigned int)time(NULL));
    get_random(a);
    printf("Random array:\n");
    show_random(a);
    exchange_row(a, 0, 4);
    printf("Exchange row 1 with row 5. \nRandom array:\n");
    show_random(a);
    show_max(a);
    return 0;
}