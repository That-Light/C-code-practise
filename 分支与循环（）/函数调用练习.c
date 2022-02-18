#define _CRT_SECURE_NO_WARNINGS

//学会使用 传值调用 和 传址调用

////写一个函数，每调用一次这个函数，就会将num的值增加1
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
//		printf("请输入调用几次Num函数（调用一次，num值加一），输入0停止：-》");
//		scanf("%d", &input);
//
//		if (input == 0)
//		{
//			printf("程序停止\n");
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


////写一个函数，实现一个整型有序数组得二分查找
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
//	printf("请输入1~10内需要寻找的数：");
//	scanf("%d", &input);
//
//	int reb = Num(input);
//
//	if (reb == -1)
//	{
//		printf("未找到\n");
//	}
//	else
//	{
//		printf("找到了，下标为：%d", reb);
//	}
//
//	return 0;
//}



////写一个函数判断一年是不是闰年
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
//	printf("请输入一个年份：");
//	scanf("%d", &input);
//
//	int pd = Num(input);
//	if (pd == 1)
//	{
//		printf("是闰年\n");
//	}
//	else
//	{
//		printf("不是闰年\n");
//	}
//
//	return 0;
//}



////写一个函数可以判断一个数是不是素数
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
//	printf("请输入一个数：");
//	scanf("%d", &input);
//
//	int pd = Num(input);
//
//	if (pd == 1)
//	{
//		printf("是素数\n");
//	}
//	else
//	{
//		printf("不是素数\n");
//	}
//
//	return 0;
//}