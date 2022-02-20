#define _CRT_SECURE_NO_WARNINGS


////汉诺塔问题
//#include <stdio.h>
//int count(int k)
//{
//	if (k > 1)
//	{
//		return 1 + 2 * count(k - 1);
//	}
//	return 1;
//}
//
//int main()
//{
//	int input = 0;
//
//	printf("请输入：");
//	scanf("%d", &input);
//
//	int num = count(input);
//
//	printf("最少需要移动 %d 次\n",num);
//
//	return 0;
//}



////青蛙跳台阶
////一只青蛙，一次能跳 1层 或者 2层 台阶，试问跳到 第n层台阶 有 多少种跳法
//#include <stdio.h>
//int jump1(int n)
//{
//	if (n > 2)
//	{
//		return jump1(n - 1) + jump1(n - 2);
//	}
//	else if (n == 2)
//		return 2;
//	else if (n == 1)
//	{
//		return 1;
//	}
//	return 0;
//}
//
//int jump2(int n)
//{
//	int a = 0;
//	int b = 1;
//	int c = 0;
//	while (n >= 1)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//
//int main()
//{
//	int input = 0;
//
//	printf("请输入台阶数：");
//	scanf("%d", &input);
//
//	//int num1 = jump1(input);
//	//
//	//printf("有 %d 种跳法\n", num1);
//
//	int num2 = jump2(input);
//
//	printf("有 %d 种跳法\n", num2);
//
//	return 0;
//}


////汉诺塔问题
//#include <stdio.h>
//int hnt(int t)
//{
//	if (t > 1)
//	{
//		return 1 + 2*hnt(t - 1);
//	}
//	return 1;
//}
//
//int main()
//{
//	int input = 0;
//
//	printf("多少层汉诺塔？-》");
//	scanf("%d", &input);
//
//	int reb = hnt(input);
//
//	printf("最少需要搬运 %d 次\n", reb);
//
//	return 0;
//}



////斐波那契数列：1  1  2  3  5  8  13  21  34  55  89 ……
////就是 前两个数字 的 和 ，当然，要给定第一第二个数字 1  1
////求第 n 个 斐波那契数
//#include <stdio.h>
//int fbnq2(int x)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	
//	int i = 0;
//
//	while (x > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		x--;
//	}
//	return c;
//
//}
//
//int fbnq1(int x)
//{
//	int x1 = 1;
//	int x2 = 2;
//
//	if (x <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return fbnq1(x - 1) + fbnq1(x - 2);
//	}
//}
//
//int main()
//{
//	int input = 0;
//
//	printf("求第几个斐波那契数？-》");
//	scanf("%d", &input);
//
//	//int reb1 = fbnq1(input);
//
//	//printf("reback1 = %d\n", reb1);
//
//	int reb2 = fbnq2(input);
//
//	printf("reback2 = %d\n", reb2);
//
//	return 0;
//}



////n的阶乘
//#include <stdio.h>
//int n_mul(int x)
//{
//	int i = 0;
//	int reb = 1;
//
//	for (i = 1; i <= x; i++)
//	{
//		reb *= i;
//	}
//	return reb;
//}
//
//int main()
//{
//	int input = 0;
//
//	printf("请输入：");
//	scanf("%d", &input);
//
//	int reb = n_mul(input);
//
//	printf("%d", reb);
//
//	return 0;
//}



////模拟实现一个 函数 求字符串长度
//#include <stdio.h>
//int my_strlen(char* str)
//{
//
//	if (*str != '\0')
//	{
//		return 1 + my_strlen(str + 1);
//	}
//		return 0;
//}
//
//int main()
//{
//	char arr[] = "happy!";
//
//	int len = my_strlen(arr);
//
//	printf("len = %d", len);
//
//	return 0;
//}



////输入1234，输出1 2 3 4
//#include <stdio.h>
//void print(int x)
//{
//	if (x >9)
//	{
//		print(x / 10);
//	}
//	printf("%d ", x % 10);
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
//	print(input);
//
//	return 0;
//}


////用函数模拟 strlen()
//#include <stdio.h>
//int my_strlen(char* x)
//{
//	if (*x != '\0')
//	{
//		return 1 + my_strlen(x+1);
//	}
//	return 0;
//
//}
//
//int main()
//{
//	char arr[] = "happy new year!!!";
//
//	int num = my_strlen(arr);
//
//	printf("strlen = %d", num);
//
//	return 0;
//}

////输入1234，输出1 2 3 4
//#include <stdio.h>
//
//void print(int x)
//{
//	if (x > 9)
//	{
//		print(x / 10);
//	}
//		printf("%d ", x%10);
//}
//
//int main()
//{
//	int input = 0;
//
//	printf("请输入：");
//	scanf("%d", &input);
//
//	print(input);
//
//	return 0;
//}



//#include <stdio.h>
//#include "add.h"
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	
//	//int sum = add(a, b);
//
//	printf("sum = %d\n", add(a, b));
//
//	return 0;
//}

//#include <stdio.h>
//
//void swap(int* x, int* y);
//
//int main()
//{
//
//	int a = 10;
//	int b = 20;
//	printf("a = %d , b = %d \n", a, b);
//
//	swap(&a, &b);
//	printf("a = %d , b = %d \n", a, b);
//	return 0;
//}
//
//void swap(int* x, int* y)
//{
//	int ret = 0;
//	ret = *x;
//	*x = *y;
//	*y = ret;
//}



////错误写法
//#include <stdio.h>
//int binary_search(int arr[], int k)
//{
//	int left = 0;
//
//	int sz = sizeof(arr) / sizeof(arr[0]);   //①：当 数组 通过 传参 的方式传到 函数 中时，不能用这种方法求元素个数
//	                                         //②： 数组 是一个 连续的空间 ， 数组 在 传参 的时候，不是传整个数组，仅仅传过去 数组 第一个元素 的 地址 ，
//	                                         //    所以 函数的参数 int arr[] 不是 数组 ，而是一个 指针 ，
//	                                         //     指针 在 32位操作系统 中是 4 个 字节 ，在 64位操作系统 中是 8 个 字节 ，
//	                                         //    arr[0] 是 整型 是 4 个 字节 ，所以这里的 sz 为 2
//	int right = sz - 1;
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
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
//	int k = 7;
//
//	int ret = binary_search(arr, k);// arr 传递过去的是 数组arr 中 第一个元素 的 地址
//
//	if (ret == -1)
//	{
//		printf("找不到指定数字\n");
//	}
//	else
//	{
//		printf("找到了，下标是：%d\n", ret);
//	}
//
//	return 0;
//}

////正确写法
//#include <stdio.h>
//int binary_search(int arr[], int k,int sz)
//{
//	int left = 0;
//
//	int right = sz - 1;
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
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
//	int k = 7;
//
//	int sz = sizeof(arr) / sizeof(arr[0]);   //在 函数 外部（即 主函数 里面），
//	                                         //先求出 数组arr 中 元素的个数 ，
//	                                         //再通过 传参 的方式，将已经得出的 具体元素个数 传进 函数 内
//
//	int ret = binary_search(arr, k, sz);
//
//	if (ret == -1)
//	{
//		printf("找不到指定数字\n");
//	}
//	else
//	{
//		printf("找到了，下标是：%d\n", ret);
//	}
//
//	return 0;
//}



//#include <stdio.h>
//
////函数声明
//、、int Add(int x, int y);
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int sum = 0;
//
//	//函数调用
//	sum = Add(a, b);
//	
//	printf("sum = %d\n", sum);
//	return 0;
//}
//
////函数定义
//int Add(int x, int y)
//{
//	int z = x + y;
//	return z;
//}