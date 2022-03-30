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

	//创建通讯录
	struct Contest con;

	//初始化通讯录
	InitContest(&con);


	do
	{
		menu();
		printf("请选择：>");
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
			printf("退出通讯录\n");
			break;

		default:
			printf("选择错误，请重新选择\n");
			break;

		}

	} while (input);

	return 0;
}