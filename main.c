#include "main.h"

int main()
{
	// ��ʼ��������ֵ
	STUDENT_SUM = 0;
	progress_rate = 20;
	final_rate = 80;

	char i;
	for (;;)
	// ѭ��ִ�й��ܲ˵�
	{
		system("cls");
		menu();

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
				break;
			case 'c':
				sort();
				break;
			case 'd':
				search();
				break;
			case 'e':
				change_rate();
				break;
			case 'f':
				Delete();
				break;
			case 'g':
				save();
				break;
			}
		printf("\n\n\n\n* * ���س����˳� * *\n");
		while (getchar() != '\n')
			;
		getchar();
	}
	return 0;
}