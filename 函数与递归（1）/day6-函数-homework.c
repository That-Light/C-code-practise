#define _CRT_SECURE_NO_WARNINGS


////ʵ��һ���������ж�һ�����ǲ���������
//#include <stdio.h>
//#include <math.h>
//int think(int x)
//{
//	int i = 0;
//	for (i = 2; i <= sqrt(x); i++)
//	{
//		if (x % i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int main()
//{
//	int input = 0;
//	printf("������һ������");
//	scanf("%d", &input);
//
//	int reb = think(input);
//
//	if (reb == 1)
//	{
//		printf("Ϊ����\n");
//	}
//	else
//	{
//		printf("������\n");
//	}
//
//	return 0;
//}


////����һ�����飬
////ʵ�ֺ���init������ʼ�����顢
////ʵ��empty����������顢
////ʵ��reverse���������������Ԫ�ص����á�
////Ҫ���Լ���ƺ����Ĳ���������ֵ��
//#include <stdio.h>
//
//void init(int arr[], int x)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		arr[i] = i;
//	}
//}
//
//void empty(int arr[], int x)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		arr[i] = 0;
//	}
//}
//
//void reverse(int arr[], int x)
//{
//	int ret = 0;
//	
//	int left = 0;
//	int right = x - 1;
//
//	int mid = (left + right) / 2;
//
//	while (left <= right)
//	{
//		ret = arr[left];
//		arr[left] = arr[right];
//		arr[right] = ret;
//		left++;
//		right--;
//	}
//
//}
//
//void menu()
//{
//	printf("***             1. init() ��ʼ������           ***\n");
//	printf("***             2. empty() �������            ***\n");
//	printf("***        3. reverse()�����������Ԫ�ص�����  ***\n");
//	printf("***                  0. exit                   ***\n");
//}
//
//int main()
//{
//	int arr[20] = {0};
//
//	int choose = 0;
//	int input = 0;
//
//	int num = 20;
//	int k = 0;
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	while (1)
//	{
//		menu();
//
//		printf("��ѡ��");
//		scanf("%d", &input);
//
//		if (input == 1)
//		{
//			printf("��ʼ��Ԫ�ظ���(1~20)��");
//			scanf("%d", &num);
//			init(arr, num);
//
//			for (k = 0; k < num; k++)
//			{
//				printf("%d ", arr[k]);
//			}
//			printf("\n");
//		}
//		else if (input == 2)
//		{
//			empty(arr,sz);
//
//			for (k = 0; k < 20; k++)
//			{
//				printf("%d ", arr[k]);
//			}
//			printf("\n");
//		}
//		else if (input == 3)
//		{
//			reverse(arr, num);
//
//			for (k = 0; k < num; k++)
//			{
//				printf("%d ", arr[k]);
//			}
//			printf("\n");
//		}
//		else
//		{
//			printf("�˳�����\n");
//			break;
//		}
//	}
//
//	return 0;
//}


////ʵ��һ�������ж�year�ǲ�������
//#include <stdio.h>
//
//int full_year(int x)
//{
//	if (x % 4 == 0 && x % 100 != 0)
//	{
//		return 1;
//	}
//	else if (x % 400 == 0)
//	{
//		return 1;
//	}
//	return 0;
//}
//
//int main()
//{
//	int input = 0;
//
//	printf("��������ݣ�");
//	scanf("%d", &input);
//
//	int reb = full_year(input);
//
//	if (reb == 1)
//	{
//		printf("������\n");
//	}
//	else
//	{
//		printf("������\n");
//	}
//
//		return 0;
//}



////ʹ�ú���ʵ���������Ľ�����
//#include <stdio.h>
//
//void change(int* x, int* y)
//{
//	int ret = 0;
//	ret = *x;
//	*x = *y;
//	*y = ret;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	
//	printf(" start: a = %d , b = %d\n", a, b);
//
//	change(&a, &b);
//
//	printf("change: a = %d , b = %d\n", a, b);
//
//	return 0;
//}



////ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
////����9�����9 * 9�ھ�������12�����12 * 12�ĳ˷��ھ���
//#include <stdio.h>
//
//void nine_mul(int x)
//{
//	int h = 0;
//	int l = 0;
//
//	for (h = 1; h <= x; h++)
//	{
//		for (l = 1; l <= h; l++)
//		{
//			printf("%2d*%2d=%-3d ", l, h, l * h);
//		}
//		printf("\n");
//	}
//
//
//}
//
//int main()
//{
//	int input = 0;
//
//	printf("�����룺");
//	scanf("%d", &input);
//
//	nine_mul(input);
//
//	return 0;
//}