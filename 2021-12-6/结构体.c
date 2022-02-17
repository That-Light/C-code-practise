#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//#include <string.h>
//
////创建结构体类型
//struct book
//{
//	char name[20];
//	short price;
//};
//
//
////利用结构体类型，创建一个该类型的变量
//int main()
//{
//	//创建结构体变量
//	struct book b1 = { "咕咕",20 };
//	printf("书名：%s\n", b1.name);
//	printf("价格：%d元\n", b1.price);
//
//	//修改参数
//	b1.price = 15;
//	printf("修改后价格：%d元\n", b1.price);
//
//	strcpy(b1.name, "哈哈");
//	printf("修改后书名：%s\n", b1.name);
//
//	//指针
//	struct book* pb = &b1;
//	printf("‘.’指针指示的书名：%s\n",(*pb).name);
//	
//	printf("'->'指针知识的书名：%s\n", pb->name);
//
//
//	return 0;
//}