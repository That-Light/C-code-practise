#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//int main()
//{
//	int input1 = 0;
//	int input2 = 0;
//	printf("请输入两个数：");
//	scanf("%d%d", &input1, &input2);
//
//	int count = 0;
//
//	int ret = input1 ^ input2;
//
//	while (ret)
//	{
//		count++;
//		ret = ret & (ret - 1);
//	}
//
//	printf("输出：%d\n", count);
//	return 0;
//}

//#include <stdio.h>
//int n_mul(int n)
//{
//	if (n == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return n * n_mul(n - 1);
//	}
//}
//
//int main()
//{
//	int input = 0;
//	printf("请输入：");
//	scanf("%d", &input);
//
//	int ret = n_mul(input);
//	printf("ret = %d\n", ret);
//
//	return 0;
//}

//#include <stdio.h>
//int DigitSum(int n)
//{
//	if (n > 9)
//	{
//		return n % 10 + DigitSum(n / 10);
//	}
//	else
//	{
//		return n;
//	}
//}
//
//int main()
//{
//	int input = 0;
//
//	printf("请输入：");
//	scanf("%d", &input);
//
//	int digitsum = DigitSum(input);
//	printf("digitsum = %d", digitsum);
//	return 0;
//}

//#include <stdio.h>
//void reverse_string1(char* string,int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//
//	char ret = '0';
//
//	while (left < right)
//	{
//		ret = *(string + left);
//		*(string + left) = *(string + right);
//		*(string + right) = ret;
//
//		left++;
//		right--;
//	}
//
//}
//
//int main()
//{
//	char arr[] = "happy";
//
//	int sz = sizeof(arr) / sizeof(arr[0]) - 1;
//
//	printf("%s\n", arr);
//
//	reverse_string1(arr, sz);
//
//	printf("%s\n", arr);
//
//	return 0;
//}

//#include <stdio.h>
//void my_mul(int n)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%2d*%2d=%3d  ", i, j, i * j);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int input = 0;
//	printf("请输入：");
//	scanf("%d", &input);
//
//	my_mul(input);
//
//	return 0;
//}

//#include <stdio.h>
//void print(int n)
//{
//	//int arr1[16] = { 0 };
//	//int arr2[16] = { 0 };
//
//	int i = 0;
//
//	printf("奇数位：");
//	for (i = 30; i >=0; i-=2)
//	{
//			printf("%d ", (n>>i) & 1);
//	}
//
//	printf("\n");
//
//	printf("偶数位：");
//	for (i = 31; i >= 0; i -= 2)
//	{
//		printf("%d ", (n >> i) & 1);
//	}
//
//}
//
//int main()
//{
//	int input = 0;
//
//	printf("请输入一个数：");
//	scanf("%d", &input);
//
//	print(input);
//
//	return 0;
//}

//#include <stdio.h>
//int count(int x, int y)
//{
//	int a = 0;
//	int count = 0;
//	a = x ^ y;
//	////101   5
//	////111   7
//	////010
//	//printf("%d", a);
//	while (a)
//	{
//		count++;
//		a = a & (a - 1);
//	}
//	return count;
//}
//
//int main()
//{
//	int x = 0;
//	int y = 0;
//	
//	int ret = 0;
//
//	printf("请输入两个整数：");
//	scanf("%d%d", &x, &y);
//
//	ret = count(x, y);
//
//	printf("不同的位数有：%d\n",ret);
//
//	return 0;
//}

//#include <stdio.h>
//int count(int x)
//{
//	int count = 0;
//
//	while (x)
//	{
//		if ((x & 1) == 1)
//		{
//			count++;
//		}
//		x = (x >> 1);
//	}
//
//	//int i = 0;
//	//for (i = 0; i < 32; i++)
//	//{
//	//	if ((x & 1) == 1)
//	//	{
//	//		count++;
//	//	}
//	//	x = x >> 1;
//	//}
//
//	//while (x)
//	//{
//	//	if (x % 2 == 1)
//	//	{
//	//		count++;
//	//	}
//	//	x = x / 2;
//	//}
//
//	return count;
//}
//
//int main()
//{
//	int input = 0;
//	int ret = 0;
//
//	printf("请输入一个数：");
//	scanf("%d", &input);
//
//	ret = count(input);
//
//	printf("二进制中 1 的个数为：%d\n", ret);
//
//	return 0;
//}