#define _CRT_SECURE_NO_WARNINGS

//ѧ��ʹ�� ��ֵ���� �� ��ַ����

////дһ��������ÿ����һ������������ͻὫnum��ֵ����1
//#include <stdio.h>
//void Num(int* pc)
//{
//	*pc = *pc + 1;
//}
//int main()
//{
//	int input = 0;
//	int i = 0;
//	int num = 0;
//	while (1)
//	{
//		printf("��������ü���Num����������һ�Σ�numֵ��һ��������0ֹͣ��-��");
//		scanf("%d", &input);
//
//		if (input == 0)
//		{
//			printf("����ֹͣ\n");
//			break;
//		}
//		else
//		{
//			for (i = 1; i <= input; i++)
//			{
//				Num(&num);
//			}
//			printf("num = %d\n", num);
//		}
//
//	}
//
//	return 0;
//}


////дһ��������ʵ��һ��������������ö��ֲ���
//#include <stdio.h>
//
//int Num(int a)
//{
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0]) - 1;
//	int mid = 0;
//
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//
//		if (arr[mid] > a)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < a)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	if (left > right)
//	{
//		return -1;
//	}
//}
//
//int main()
//{
//	int input = 0;
//
//	printf("������1~10����ҪѰ�ҵ�����");
//	scanf("%d", &input);
//
//	int reb = Num(input);
//
//	if (reb == -1)
//	{
//		printf("δ�ҵ�\n");
//	}
//	else
//	{
//		printf("�ҵ��ˣ��±�Ϊ��%d", reb);
//	}
//
//	return 0;
//}



////дһ�������ж�һ���ǲ�������
//#include <stdio.h>
//
//int Num(int a)
//{
//	if (a % 400 == 0)
//	{
//		return 1;
//	}
//	else if (a % 100 != 0 && a % 4 == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	int input = 0;
//
//	printf("������һ����ݣ�");
//	scanf("%d", &input);
//
//	int pd = Num(input);
//	if (pd == 1)
//	{
//		printf("������\n");
//	}
//	else
//	{
//		printf("��������\n");
//	}
//
//	return 0;
//}



////дһ�����������ж�һ�����ǲ�������
//#include <stdio.h>
//int Num(int a)
//{
//	int i = 1;
//	for (i = 2; i < a; i++)
//	{
//		if (a % i == 0)
//		{
//			return 0;
//			break;
//		}
//	}
//	if (i == a)
//	{
//		return 1;
//	}
//}
//
//int main()
//{
//	int input = 0;
//
//	printf("������һ������");
//	scanf("%d", &input);
//
//	int pd = Num(input);
//
//	if (pd == 1)
//	{
//		printf("������\n");
//	}
//	else
//	{
//		printf("��������\n");
//	}
//
//	return 0;
//}