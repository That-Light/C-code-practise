#define _CRT_SECURE_NO_WARNINGS


////乘法口诀表
////在屏幕上输出9*9乘法口诀表
//#include <stdio.h>
//int main()
//{
//	int i = 0, j = 0;
//	
//	for (i = 1; i <= 9; i++)
//	{
//
//		for (j = 1; j <= i; j++)
//		{
//
//				printf("%d*%d=%-2d ", i, j, i * j);
//
//		}
//
//		printf("\n");
//	}
//
//
//	return 0;
//}





////求最大值
////求10个整数中的最大值
//#include <stdio.h>
//int main()
//{
//	int arr[10]={0};
//	int max = arr[0];
//	int i;
//	printf("请输入10个整数：");
//	scanf("%d%d%d%d%d%d%d%d%d%d",&arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6], &arr[7], &arr[8], &arr[9]);
//	
//	for (i = 0; i <= 9; i++)
//	{
//		if (max < arr[i])
//			max = arr[i];
//	}
//	printf("最大的整数为：%d", max);
//	return 0;
//}





////分数求和
////计算1/1-1/2+1/3-1/4+1/5……+1/99-1/100的值，打印出结果
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	float a = 0;
//	float sum = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 == 1)
//		{
//			a = 1.000000 / i;
//		}
//		else if (i % 2 == 0)
//		{
//			a = -1.000000 / i;
//		}
//
//		sum = sum + a;
//	}
//	printf("sum = %f", sum);
//
//	return 0;
//}





////数1~100中，9的个数
////编写程序数一下1~100的所有整数中出现多少个数字9
//#include <stdio.h>
//int main()
//{
//	int a, gw, sw;
//	int sl = 0;
//
//	for (a = 1; a <= 100; a++)
//	{
//		gw = a % 10;
//		sw = a / 10;
//		if (gw == 9)
//		{
//			sl++;
//		}
//		if (sw == 9)
//		{
//			sl++;
//		}
//	}
//	printf("数字9的数量为：%d", sl);
//
//	return 0;
//}





////打印100~200之间的素数
////素数：即质数，除了1和它本身没有其他因数的自然数
////①试除法---逐个数试
//#include <stdio.h>
//int main()
//{
//	int i;
//	int a;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		for (a = 2; a < i; a++)
//		{
//			if (i % a == 0)
//			{
//				break;
//			}
//			else if (a == i-1)
//			{
//				printf("素数：%d\n", i);
//				count++;
//			}
//		}
//
//	}
//	printf("素数个数为：%d", count);
//
//	return 0;
//}

////②优化------如果一个数不是素数，一定能找到这个数的一个 因子 小于等于 这个数的开平方
////开平方库函数 sqrt() ，需引用头文件 <math.h>
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int i;
//	int a;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		for (a = 2; a < sqrt(i); a++)   //更改
//		{
//			if (i % a == 0)
//			{
//				break;
//			}
//
//		}
//		if (a > sqrt(i))   //更改---这个判断 不能 放在上面一个 for循环 中，因为 a > sqrt(i) 就 不 进入 for循环 中了，我们也不好捕捉 a 与 sqrt(i) 的准确关系
//		{
//			printf("素数：%d\n", i);
//			count++;
//		}
//
//	}
//	printf("素数个数为：%d", count);
//
//	return 0;
//}

//③优化------如果一个数不是素数，一定能找到这个数的一个 因子 小于等于 这个数的开平方
//开平方库函数 sqrt() ，需引用头文件 <math.h>
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int i;
//	int a;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		for (a = 2; a < sqrt(i); a++)   //更改
//		{
//			if (i % a == 0)
//			{
//				break;
//			}
//			else if (a > sqrt(i)-1)   //更改---把这个判断放回上面的 for循环 里面，因为 a > sqrt(i) 就不再进行循环，那极限一点 -1 就能大概确认最后一个 a 。
//				                      但这种方法不好，因为 i开平方带小数 ，谁知道 sqrt(i)-1 就一定比最后一个 a 小呢？！
//				                      还是推荐上面②的写法；如果是①的写法，因为 i 是整数，怎么放都能肯定地判断。
//			{
//				printf("素数：%d\n", i);
//				count++;
//			}
//		}
//
//	}
//	printf("素数个数为：%d", count);
//
//	return 0;
//}





////1000~2000年之间的闰年
////闰年：①能被4整除；②能被100整除不是闰年；③能被400整除才是闰年
//#include <stdio.h>
//int main()
//{
//	int year;
//	int count = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (year % 4 == 0)
//		{
//			if (year%400 ==0)
//			{
//				printf("闰年：%d\n", year);
//				count++;
//			}
//			else if (year % 100 == 0)
//			{
//				;
//			}
//			else
//			{
//				printf("闰年：%d\n", year);
//				count++;
//			}
//		
//		}
//	}
//	printf("闰年个数：%d", count);
//
//	return 0;
//}





////最大公约数------辗转相除法
//#include <stdio.h>
//int main()
//{
//	int a, b, c;
//
//	printf("请输入两个数：");
//	scanf("%d%d", &a, &b);
//
//	//较大的数为被除数，较小的数为除数
//	if (a < b)
//	{
//		c = a;
//		a = b;
//		b = c;
//	}
// 
//	//辗转相除法
//	while (a % b != 0)
//	{
//		c = a;
//		a = b;
//		b = c % b;
//	}
//
//	printf("最大公约数为：%d",  b);     //能整除的式子中，除数即为最大公约数
//
//	return 0;
//}





////作业：打印1~100之间3的倍数
//#include <stdio.h>
//int main()
//{
//	int i;
//
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0)
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}





////作业：3个数，从大到小输出
//#include <stdio.h>
//int main()
//{
//
//	int a, b, c;
//	printf("输入三个数：");
//	scanf("%d%d%d", &a, &b, &c);
//
//	int arr[3] = { 0 };
//	if (a > b && a > c)
//	{
//		arr[0] = a;
//		if (b > c)
//		{
//			arr[1] = b;
//			arr[2] = c;
//		}
//		else
//		{
//			arr[2] = b;
//			arr[1] = c;
//		}
//	}
//	else if (a > b && a < c)
//	{
//		arr[1] = a;
//		arr[0] = c;
//		arr[2] = b;
//	}
//	else if (a > c && a < b)
//	{
//		arr[1] = a;
//		arr[0] = b;
//		arr[2] = c;
//	}
//	else
//	{
//		arr[2] = a;
//		if (b > c)
//		{
//			arr[0] = b;
//			arr[1] = c;
//		}
//		else
//		{
//			arr[1] = b;
//			arr[0] = c;
//		}
//	}
//
//	printf("%d %d %d", arr[0], arr[1],arr[2]);
//
//	return 0;
//}





////登录秘密
//#include<stdio.h>
//int main()
//{
//	char password[20] = {0};
//	int i = 0;
//
//	while (i < 3)
//	{
//		printf("请输入密码：");
//		scanf("%s", password);
//
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("登录成功\n");
//			break;
//		}
//		else
//		{
//			if (i < 2)
//			{
//				printf("登录失败，还有%d次机会\n", 2 - i);
//			}
//			i++;
//		}
//	}
//
//	if (i == 3)
//	{
//		printf("输入三次密码均错误，退出程序\n");
//	}
//
//	return 0;
//}





////字符替换*号
//#include <stdio.h>
//#include <string.h>
//#include <Windows.h>
//#include <stdlib.h>
//int main()
//{
//
//	char arr1[] = "welcome to my home !!!!";
//	char arr2[] = "***********************";
//
//	int left = 0;
//
//	int right = strlen(arr1) - 1;
//	//或 int right = sizeof(arr1) / sizeof(arr[0]) - 2;
//
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		left++;
//		right--;
//
//		Sleep(1000);
//
//		system("cls");
//	}
//
//	return 0;
//}






////二分法查找
//#include <stdio.h>
//int main()
//{
//
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	int k = 7;
//
//	int left = 0;
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int right = sz - 1;
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
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
//			printf("找到了，下标为：%d", mid);
//			break;
//		}
//	}
//
//	if (left > right)
//	{
//		printf("找不到");
//	}
//
//	return 0;
//}