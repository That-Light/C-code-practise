#define _CRT_SECURE_NO_WARNINGS

////编写一个程序，可以一直接收键盘字符，
////如果是小写字符就输出对应的大写字符，
////如果接收的是大写字符，就输出对应的小写字符，
////如果是数字不输出。
//#include <stdio.h>
//int main()
//{
//	int input = 0;
//
//	while (1)
//	{
//		printf("输入:");
//
//		input = getchar();
//		//printf("%d\n", input);
//
//		if (input != -1)
//		{
//			while (getchar() != '\n')
//			{
//				printf("清障\n");
//			}
//		}
//
//		if (input >= 65 && input <= 90)
//		{
//			printf("输出:%c\n", (input + 32));
//		}
//		else if (input >= 92 && input <= 122)
//		{
//			printf("输出:");
//			putchar(input - 32);
//			printf("\n");
//		}
//		else if (input == EOF)
//		{
//			printf("程序结束\n");
//			break;
//		}
//		else
//		{
//			printf("\n");
//		}
//	}
//	return 0;
//}



////编写代码模拟三次密码输入的场景。
////最多能输入三次密码，密码正确，提示“登录成功”, 密码错误，
////可以重新输入，最多输入三次。三次均错，则提示退出程序。
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
//		printf("请输入密码：");
//
//		//password = getchar();
//		scanf("%s", password);
//
//		if (strcmp(password, arr) == 0)
//		{
//			printf("登陆成功\n");
//			break;
//		}
//	}
//	if (i == 4)
//	{
//		printf("三次密码均错误，退出程序");
//	}
//
//	return 0;
//}



////写代码可以在整型有序数组中查找想要的数字，
////找到了返回下标，找不到返回 - 1.（折半查找）
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



////完成猜数字游戏
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
//	printf("猜数字游戏\n");
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
//		printf("你猜：");
//		scanf("%d", &guess);
//
//		if (guess <= right && guess >= left)
//		{
//			if (ret > guess)
//			{
//				printf("猜小了\n");
//				left = guess + 1;
//			}
//			else if (ret < guess)
//			{
//				printf("猜大了\n");
//				right = guess - 1;
//			}
//			else
//			{
//				printf("猜对了\n");
//				break;
//			}
//		}
//		else
//		{
//			printf("输入错误\n");
//		}
//		printf("请从 %d ~ %d 内猜测\n", left, right);
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
//		printf("请选择：");
//		scanf("%d", &input);
//		
//		switch (input)
//		{
//		case 1:
//			printf("《《《开始游戏》》》\n");
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误，请重新选择！\n");
//			break;
//		}
//	} while (input);
//
//
//	return 0;
//}