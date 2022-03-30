#define _CRT_SECURE_NO_WARNINGS

#include "contect.h"

void menu()
{
	printf("**********************************\n");
	printf("*****          1.Add         *****\n");
	printf("*****          2.Del         *****\n");
	printf("*****          3.Search      *****\n");
	printf("*****          4.Modify      *****\n");
	printf("*****          5.Sort        *****\n");
	printf("*****          6.Show        *****\n");
	printf("*****          0.Exit        *****\n");
	printf("**********************************\n");

}

int main()
{
	int input = 0;

	//����ͨѶ¼
	struct Contest con;

	//��ʼ��ͨѶ¼
	InitContest(&con);


	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);

		switch (input)
		{
		case ADD:
			AddContest(&con);
			break;

		case DEL:
			DelContest(&con);
			break;

		case SEARCH:
			SearchContest(&con);
			break;

		case MODIFY:
			ModifyContest(&con);
			break;

		case SORT:
			SortContest(&con);
			break;

		case SHOW:
			ShowContest(&con);
			break;

		case EXIT:
			printf("�˳�ͨѶ¼\n");
			break;

		default:
			printf("ѡ�����������ѡ��\n");
			break;

		}

	} while (input);

	return 0;
}