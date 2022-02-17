#define _CRT_SECURE_NO_WARNINGS

////密码登录
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr1[] = { "123456" };
//	char password[20] = {0};
//	int i = 0;
//
//	for (i = 1; i <= 3; i++)
//	{
//		printf("请输入密码：");
//		scanf("%s", password);
//		if (strcmp(password, arr1) == 0)
//		{
//			printf("登录成功\n");
//			break;
//		}
//		else
//		{
//			printf("密码错误，还有%d次机会\n", 3 - i);
//		}
//	}
//
//	if (i > 3)
//	{
//		printf("三次密码均错误，退出程序\n");
//	}
//
//	return 0;
//}





////EOF
////#include <stdio.h>   // 仅识别0~9的数字并重复打印一次，并能使用ctrl+z结束
////int main()
////{
////	int sr;
////	while ((sr = getchar()) != EOF)
////	{
////		if (sr > '0' && sr < '9')
////		{
////			putchar(sr);
////			printf("%3c\n", sr);
////		}
////		//else
////		//{
////		//	continue;
////		//}
////	}
////
////	return 0;
////}
//
//
//
////#include <stdio.h>   // EOF 的作用
////int main()
////{
////	int sr;
////	
////	while ((sr = getchar()) != EOF)
////	{
////		putchar(sr);
////		printf("%2c", sr);
////	}
////	
////
////	return 0;
////}





////打印显示
//#include <stdio.h>
//#include <string.h>
//#include <Windows.h>
//int main()
//{
//	char arr1[] = { "******************************************"};
//	char arr2[] = { "*****ni shi shui ? ?  wo shi shui ? ?*****"};
//
//	int left = 0;
//
//	int right = sizeof(arr1) / sizeof(arr1[0]) - 2;
//	//int right = strlen(arr1) / strlen(arr1[0]) - 1;
//
//	while (left <= right)
//	{
//		arr1[left] = arr2[left];
//		arr1[right] = arr2[right];
//
//		left++;
//		right--;
//
//		printf("%s\n", arr1);
//
//		Sleep(1000);
//
//		system("cls");
//
//	}
//
//	return 0;
//}





////寻找最大公约数
//#include <stdio.h>
//int main()
//{
//	int a = 0, b = 0;
//	int c = 0;
//
//	//换位置
//
//
//	printf("请输入两个整数：");
//	scanf("%d%d", &a, &b);
//
//	while (a % b != 0)
//	{
//		c = a;
//		
//		a = b;
//		b = c % b;
//	}
//
//	printf("最大公约数为：%d", b);
//
//	return 0;
//}





////二分查找法
//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,8,8,9,10 };
//
//	int k = 7;
//
//	int left = 0;
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int right = sz - 1;
//	
//	int mid = 0;
//
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//
//		if (k > arr[mid])
//		{
//			left = mid+1;
//		}
//		else if (k < arr[mid])
//		{
//			right = mid-1;
//		}
//		else
//		{
//			printf("找到了，下标为：%d", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("没有找到");
//	}
//	return 0;
//}





////寻找最大公约数
//#include <stdio.h>
//int main()
//{
//	int a, b, c;
//
//	printf("请输入两个数：");
//	scanf("%d%d", &a, &b);
//
//	//较大的数放a，较小的数放b
//	if (a < b)
//	{
//		c = a;
//		a = b;
//		b = c;
//	}
//
//	//最大公约数
//	while (a % b != 0)
//	{
//		c = a;
//		a = b;
//		b = c % b;
//	}
//
//	printf("最大公约数为%d", b);
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
//	int k = 71;
//
//	int left = 0;
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
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
//		else if(arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("找到了，下标为%d", mid);
//			break;
//		}
//	}
//
//	if (left > right)
//	{
//		printf("未找到");
//	}
//
//	return 0;
//}