#define _CRT_SECURE_NO_WARNINGS

////��дһ�����򣬿���һֱ���ռ����ַ���
////�����Сд�ַ��������Ӧ�Ĵ�д�ַ���
////������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ���
////��������ֲ������
//#include <stdio.h>
//int main()
//{
//	int input = 0;
//
//	while (1)
//	{
//		printf("����:");
//
//		input = getchar();
//		//printf("%d\n", input);
//
//		if (input != -1)
//		{
//			while (getchar() != '\n')
//			{
//				printf("����\n");
//			}
//		}
//
//		if (input >= 65 && input <= 90)
//		{
//			printf("���:%c\n", (input + 32));
//		}
//		else if (input >= 92 && input <= 122)
//		{
//			printf("���:");
//			putchar(input - 32);
//			printf("\n");
//		}
//		else if (input == EOF)
//		{
//			printf("�������\n");
//			break;
//		}
//		else
//		{
//			printf("\n");
//		}
//	}
//	return 0;
//}



////��д����ģ��������������ĳ�����
////����������������룬������ȷ����ʾ����¼�ɹ���, �������
////�����������룬����������Ρ����ξ�������ʾ�˳�����
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr[10] = { "123456"};
//
//	int i = 0;
//
//	char password[20] = { 0 };
//
//	for (i = 1; i <= 3; i++)
//	{
//		printf("���������룺");
//
//		//password = getchar();
//		scanf("%s", password);
//
//		if (strcmp(password, arr) == 0)
//		{
//			printf("��½�ɹ�\n");
//			break;
//		}
//	}
//	if (i == 4)
//	{
//		printf("��������������˳�����");
//	}
//
//	return 0;
//}



////д����������������������в�����Ҫ�����֣�
////�ҵ��˷����±꣬�Ҳ������� - 1.���۰���ң�
//#include <stdio.h>
//
//int half_find(int arr[], int k, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	int k = 7;
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	int ret = half_find(arr, k, sz);
//
//	printf("%d", ret);
//
//	return 0;
//}



////��ɲ�������Ϸ
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//void menu()
//{
//	printf("*******************************\n");
//	printf("*****   1.play   0.exit   *****\n");
//	printf("*******************************\n");
//}
//
//void game()
//{
//	printf("��������Ϸ\n");
//
//	int ret = rand() % 100 + 1;
//
//	int guess = 0;
//
//	int left = 1;
//	int right = 100;
//
//	printf("%d", ret);
//
//	while (1)
//	{
//		printf("��£�");
//		scanf("%d", &guess);
//
//		if (guess <= right && guess >= left)
//		{
//			if (ret > guess)
//			{
//				printf("��С��\n");
//				left = guess + 1;
//			}
//			else if (ret < guess)
//			{
//				printf("�´���\n");
//				right = guess - 1;
//			}
//			else
//			{
//				printf("�¶���\n");
//				break;
//			}
//		}
//		else
//		{
//			printf("�������\n");
//		}
//		printf("��� %d ~ %d �ڲ²�\n", left, right);
//	}
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//
//	do
//	{
//		menu();
//		printf("��ѡ��");
//		scanf("%d", &input);
//		
//		switch (input)
//		{
//		case 1:
//			printf("��������ʼ��Ϸ������\n");
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("ѡ�����������ѡ��\n");
//			break;
//		}
//	} while (input);
//
//
//	return 0;
//}