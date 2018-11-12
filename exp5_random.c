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
    printf("Random array:\n");
    for (int i = 0; i < rMAX; i++)
    {
        for (int j = 0; j < cMAX; j++)
        {
            printf("%d\t", a[i][j]);
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

int main(void)
{
    system("clear");
    srand((unsigned int)time(NULL));
    get_random(a);
    show_random(a);
    exchange_row(a, 0, 4);
    show_random(a);

    return 0;
}