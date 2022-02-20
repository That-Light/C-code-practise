#define _CRT_SECURE_NO_WARNINGS


////实现一个函数，判断一个数是不是素数。
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
//	printf("请输入一个数：");
//	scanf("%d", &input);
//
//	int reb = think(input);
//
//	if (reb == 1)
//	{
//		printf("为素数\n");
//	}
//	else
//	{
//		printf("非素数\n");
//	}
//
//	return 0;
//}


////创建一个数组，
////实现函数init（）初始化数组、
////实现empty（）清空数组、
////实现reverse（）函数完成数组元素的逆置。
////要求：自己设计函数的参数，返回值。
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
//	printf("***             1. init() 初始化数组           ***\n");
//	printf("***             2. empty() 清空数组            ***\n");
//	printf("***        3. reverse()函数完成数组元素的逆置  ***\n");
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
//		printf("请选择：");
//		scanf("%d", &input);
//
//		if (input == 1)
//		{
//			printf("初始化元素个数(1~20)：");
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
//			printf("退出程序\n");
//			break;
//		}
//	}
//
//	return 0;
//}


////实现一个函数判断year是不是闰年
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
//	printf("请输入年份：");
//	scanf("%d", &input);
//
//	int reb = full_year(input);
//
//	if (reb == 1)
//	{
//		printf("是闰年\n");
//	}
//	else
//	{
//		printf("非闰年\n");
//	}
//
//		return 0;
//}



////使用函数实现两个数的交换。
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



////实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
////输入9，输出9 * 9口诀表，输入12，输出12 * 12的乘法口诀表。
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
//	printf("请输入：");
//	scanf("%d", &input);
//
//	nine_mul(input);
//
//	return 0;
//}