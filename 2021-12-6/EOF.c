#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

////仅输出0~9的数字，并能使用CTRL+Z退出代码运行
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch >'9')
//			continue;
//		putchar(ch);
//	}
//
//	return 0;
//}


////对比一下三段代码
//int main()
//{
//	////③
//	//int ret = 0;
//	//char password[20] = { 0 };
//
//	//printf("请输入密码：");
//	//scanf("%s", &password);
//
//	////一直清除'\n'
//	//while (getchar() != '\n')
//	//{
//	//	;
//	//}
//
//	//printf("请确认（Y/N）：");
//	//ret = getchar();
//	//if (ret == 'Y')
//	//{
//	//	printf("确认成功");
//	//}
//	//else
//	//{
//	//	printf("放弃确认");
//	//}
//
//
//
//	////②
//	//int ret = 0;
//	//char password[20] = { 0 };
//
//	//printf("请输入密码：");
//	//scanf("%s", &password);
//
//	////清除'\n'
//	//getchar();
//
//	//printf("请确认（Y/N）：");
//	//ret = getchar();
//	//if (ret == 'Y')
//	//{
//	//	printf("确认成功");
//	//}
//	//else
//	//{
//	//	printf("放弃确认");
//	//}
//
//
//	////①
//	//int ret = 0;
//	//char password[20] = { 0 };
//
//	//printf("请输入密码：");
//	//scanf("%s", &password);
//
//	//printf("请确认（Y/N）：");
//	//ret = getchar();
//	//if (ret == 'Y')
//	//{
//	//	printf("确认成功");
//	//}
//	//else
//	//{
//	//	printf("放弃确认");
//	//}
//
//
//	return 0;
//}





////   CTRL+Z 输出 EOF-文件结束标志
//int main()
//{
//
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		putchar(ch);
//		printf("%c", ch);
//	}
//
//
//	return 0;
//}