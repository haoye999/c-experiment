#include <stdio.h>
#include <stdlib.h>

int find(char *str, char xch, int *position)
{
    int count = 0;
    for (int i = 1; *str != '\0'; i++)
    {
        if (xch == *(str++))
        {
            position[count++] = i;
        }
    }
    return count;
}

int main()
{
    /*
    清屏
    windows环境下用system("cls")  
    */
    system("clear");
    while(1){
        char xch;
        char str[100];
        int position[100], count;

        printf("Please input a string:\n");
        scanf("%s", str);

        while((getchar()) != '\n');

        printf("Please input a character finding:\n");
        scanf("%c", &xch);
        count = find(str, xch, position);
        if (count != 0)
        {
            printf("The number of times '%c' appears in '%s' is %d.\n", xch, str, count);
            printf("The positions '%c' appears is: ", xch);
            for (int i = 0; i < count; i++)
            {
                printf("%d ", position[i]);
            }
            printf("\n");
        }
        else
        {
            printf("There is no '%c' found in '%s'\n", xch, str);
        }
        while((getchar()) != '\n');
        printf("continue?(input 'n' to stop!)\n");
        if(getchar()=='n') break;
    }
    return 0;
}