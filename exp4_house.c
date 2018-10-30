#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <time.h>

int main()
{
    clock_t starttime, endtime;
    starttime = clock();

    endtime = clock();
    printf("%ldms", (endtime - starttime));
    return 0;
}