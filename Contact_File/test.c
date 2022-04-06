#define _CRT_SECURE_NO_WARNINGS

#include "contact.h"

void menu()
{
	printf("*************************************\n");
	printf("******          1.Add          ******\n");
	printf("******          2.Del          ******\n");
	printf("******          3.Search       ******\n");
	printf("******          4.Modify       ******\n");
	printf("******          5.Sort         ******\n");
	printf("******          6.Show         ******\n");
	printf("******          7.Save         ******\n");
	printf("******          0.Exit         ******\n");
	printf("*************************************\n");

}

int main()
{
	int input = 0;

	// ����ͨѶ¼
	struct Contest con;

	// ��ʼ��ͨѶ¼
	InitContest(&con);

	if (con.data != NULL) // �ж� ��ʼ��ͨѶ¼ �Ƿ�ɹ�
	{
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

			case SAVE:
				SaveContact(&con);
				printf("SaveContact successfully\n");
				break;

			case EXIT:
				// �˳�ͨѶ¼ǰ����ͨѶ¼�������ļ�
				SaveContact(&con);

				// ����ͨѶ¼���ͷŶ�̬���ٵ��ڴ�
				DestroyContact(&con);
				printf("Auto To SaveContact successfully\n");
				printf("�˳�ͨѶ¼\n");
				break;

			default:
				printf("�����������������\n");
				break;
			}

		} while (input);
	}

	return 0;
}