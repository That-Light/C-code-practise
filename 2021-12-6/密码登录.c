#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码：");
//		scanf("%s", password);
//
//		//   if (password == "123456")   是错误的写法，因为 “==” 不能用来比较两个字符串是否相等，应该使用库函数 strcmp()
//
//		if (strcmp(password, "123456") == 0)   //※使用 strcmp() 需要引用头文件 <string.h>
//		//strcmp(char1,char2) 将比较 char1 与 char2 ↓↓↓
//		//如果 ①两者相等则返回值0； ② char1 大于 char2 则返回大于0的值； ③ char1 小于 char2 则返回小于0的值
//		{
//			printf("登陆成功\n");
//			break;
//		}
//		else
//		{
//			printf("密码错误\n");
//		}
//	}
//
//	if (i == 3)
//	{
//		printf("三次密码均错误，退出程序\n");
//	}
//
//	return 0;
//}