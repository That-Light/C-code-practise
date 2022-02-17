#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//
//int main()
//{
//	int a = 10;
//
//	int* p = &a;
//	
//	printf("十六进制地址：%p\n",p);
//
//	printf("利用指针寻找a的值：%d\n", *p);
//
//	*p = 20;
//
//	printf("利用指针将a的值改为20：%d\n", *p);
//
//	printf("指针变量大小：%d\n", sizeof(int*));   //无论int*,char*...64位系统值为8，32位系统值为4，指针变量大小只与内存每一格空间有关
//
//	return 0;
//}