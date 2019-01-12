#include "main.h"

int main()
{
	STUDENT_SUM = 0;
	char i;
	for (;;)
		// 循环执行功能菜单
	{
		system("cls");
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
				printf("\n\n\n\n* * 按回车键退出 * *\n");
				while (getchar() != '\n');
				getchar();
				break;
			case 'd':
				search();
				printf("\n\n\n\n* * 按回车键退出 * *\n");
				while (getchar() != '\n');
				getchar();
				break;
			case 'e':
				// 调用修改函数;
				printf("\n\n\n\n* * 按回车键退出 * *\n");
				while (getchar() != '\n');
				getchar();
				break;
			case 'f':
				// 调用添加函数;
				printf("\n\n\n\n* * 按回车键退出 * *\n");
				while (getchar() != '\n');
				getchar();
				break;
			}
	}
	return 0;
}