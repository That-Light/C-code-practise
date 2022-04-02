#define _CRT_SECURE_NO_WARNINGS

#include "contest.h"

void menu()
{
	printf("*************************************\n");
	printf("******          1.Add          ******\n");
	printf("******          2.Del          ******\n");
	printf("******          3.Search       ******\n");
	printf("******          4.Modify       ******\n");
	printf("******          5.Sort         ******\n");
	printf("******          6.Show         ******\n");
	printf("******          0.Exit         ******\n");
	printf("*************************************\n");

}

int main()
{
	int input = 0;

	// 创建通讯录
	struct Contest con;

	// 初始化通讯录
	InitContest(&con);

	if (con.data != NULL) // 判断 初始化通讯录 是否成功
	{
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
				// 销毁通讯录，释放动态开辟的内存
				DestroyContact(&con);

				printf("输入错误，请重新输入\n");
				break;
			}

		} while (input);
	}

	return 0;
}