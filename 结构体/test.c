#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int Add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}

int main()
{
	int a = 10;
	int b = 20;
	int ret = 0;

	ret = Add(a, b);

	return 0;
}

//#include <stdio.h>
//
//typedef struct Stu
//{
//	char name[20];
//	int age;
//}STU;
//
//void print1(struct Stu tmp) //也可以 void peint1(STU tmp)
//{
//	printf("%s\n", tmp.name);
//	printf("%d\n", tmp.age);
//	//打印   张三
//	//       40
//}
//
//void print2(STU* tmp) //也可以 void peint1(struct Stu* tmp)
//{
//	printf("%s\n", tmp->name);
//	printf("%d\n", (*tmp).age);
//	//打印   张三
//	//       40
//}
//
//int main()
//{
//	STU s = { "张三",40 };
//
//	print1(s); //传 结构体
//	print2(&s); //传 地址
//
//	return 0;
//}

//#include <stdio.h>
//
//struct S
//{
//	int a;
//	char c;
//	char arr[20];
//	double d;
//};
//
//struct T
//{
//	char ch[10];
//
//	struct S s; // 结构体中 可以包含 其他结构体成员
//	
//	char* pc;
//};
//
//int main()
//{
//	char arr[] = "hello earth\n";
//	
//	struct T t = { "hehe",{100,'w',"hello world",3.14},arr };
//
//	printf("%s\n", t.ch);
//	printf("%s\n", t.s.arr); //可以 逐层 访问 结构体中 的 其他结构体成员
//	printf("%lf\n", t.s.d); // 打印 double类型 使用 %lf
//	printf("%s\n", t.pc);
//	//打印  hehe 
//	//      hello world
//	//	    3.140000
//	//	    hello earth
//
//	return 0;
//}


//////定义 结构体变量
////struct Stu // struct 是 结构体关键字 ； Stu 是 结构体标签 ； struct Stu 是 结构体类型 。
////{
////	//成员变量
////	char name[20]; //名字
////	int age; //年龄
////	char sex[5]; //性别
////	char id[20]; //学号
////}s1, s2, s3; //创建了 s1 , s2 , s3 三个 全局结构体变量 ，但可以不创建，且应尽量减少使用全局变量
////             //分号不能丢
//
//typedef struct Stu // typedef 的作用是给 一个类型 重命名 ，
//                   //这里将  struct Stu  这个 结构体类型 重命名为 STU
//{
//	char name[20];
//	int age;
//	char sex[5];
//	char id[20];
//}STU; // 这里的 STU 不是 全局结构体变量 ，而是使用 typedef 重命名后的 名字
//
//
//int main()
//{
//	struct Stu s; //一般方法创建 结构体变量 
//
//	STU s; //使用 typedf 重命名后创建 结构体变量
//
//	return 0;
//}