#include "main.h"

int main()
{
	student_sum = 0;
	char i;
	for (;;)
		// 循环执行功能菜单
	{
		system("clear");
		printf("\n");
		printf("\t\t\t* * * * * * * * * * * * * * * * *\n");
		printf("\t\t\t*              Menu             *\n");
		printf("\t\t\t*         * a. Input *          *\n");
		printf("\t\t\t*         * b. Display *        *\n");
		printf("\t\t\t*         * c. Sort *           *\n");
		printf("\t\t\t*         * d. Find *           *\n");
		printf("\t\t\t*         * e. Modify *         *\n");
		printf("\t\t\t*         * f. Add *            *\n");
		printf("\t\t\t*         * q. Exit *           *\n");
		printf("\t\t\t* * * * * * * * * * * * * * * * *\n");
		printf("\t\t\t   Please select a to q :");

		i = getchar();
		printf("\n");
		if (i == 'q')
			break;
		else
			switch (i)
			{
			case 'a':
				input();
				break;
			case 'b':
				display();
				while (getchar() != '\n');
				getchar();
				break;
			case 'c':
				sort();
				while (getchar() != '\n');
				getchar();
				break;
			case 'd':
				// 调用查找函数;
				break;
			case 'e':
				// 调用修改函数;
				break;
			case 'f':
				// 调用添加函数;
				break;
			}
	}
	return 0;
}