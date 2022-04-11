#define _CRT_SECURE_NO_WARNINGS 1

//// 在 X86(32位平台) ，有如下程序
//
//#include <stdio.h>
//int main()
//{
//	union S
//	{
//		short k;
//		char arr[2];
//	};
//
//	union S s;
//
//	union S* ps = &s;
//
//	ps->arr[0] = 0x39;
//	ps->arr[1] = 0x38;
//
//	printf("%x\n", s.k); // 打印 3839
//
//	return 0;
//}


//#include <stdio.h>
//#include <memory.h>
//int main()
//{
//	char arr[4];
//
//	struct S
//	{
//		char c1;
//		char c2 : 1;
//		char c3 : 2;
//		char c4 : 3;
//	};
//
//	struct S* ps;
//
//	ps = (struct S*)arr;
//
//	memset(arr, 0, 4);
//
//	ps->c1 = 2;
//	ps->c2 = 3;
//	ps->c3 = 4;
//	ps->c4 = 5;
//
//	printf("%02x %02x %02x %02x\n", arr[0], arr[1], arr[2], arr[3]);
//	// %02x ，其中
//	// x 代表以 十六进制 形式输出；
//	// 02 代表：留 2 个位置输出，不足两位，前面补 0 输出，如果超过两位，则以实际输出。
//	// 
//	// 本题输出：02 29 00 00
//	// 
//	// 
//	// %2x ，其中
//	// x 代表以 十六进制 形式输出；
//	// 2 代表：留 2 个位置输出，不足两位，前面不会额外补 0 ，如果超过两位，则以实际输出。
//	// 
//	// 本题输出： 2 29  0  0 (位置留了 2 个，但不会补 0 )
//
//	return 0;
//}


//
//#include <stdio.h>
//
//#define OFFSETOF(struct_name,member_name) (int)&(((struct_name*)0)->member_name)
//// 在 32位平台 强制类型转换成 int类型(4个字节) ，因为 32位平台 的 地址 是 32 个比特位， 即 4 个字节，
//// 在 64位平台 强制类型转换成 long long类型(8个字节) ，因为 64位平台 的 地址 是 64 个比特位， 即 8 个字节，
//// 若 强制类型转换成 放不下 地址长度 的 类型 ，则会报 截断警告 ，
////    但是不影响本题求解，因为本题的偏移值很小，截断不会影响这个值。
//
//struct S
//{
//	char c;
//	int i;
//	double d;
//};
//
//int main()
//{
//	printf("%d\n", OFFSETOF(struct S, c)); // 打印 0
//
//	printf("%d\n", OFFSETOF(struct S, i)); // 打印 4
//	
//	printf("%d\n", OFFSETOF(struct S, d)); // 打印 8
//
//	return 0;
//}



//#include <stdio.h>
//
//struct S
//{
//	char c1;
//	int i;
//	char c2;
//};
//
//#define OFSETOF(STRUCT_NAME,MAMBER) (short)&(((STRUCT_NAME*)0)->MAMBER)
//
//int main()
//{
//	printf("%d\n", OFSETOF(struct S, c2));
//
//	return 0;
//}

//int main()
//{
//
//#if defined(OS_UNIX)
//
//    #ifdef OPTION1
//	    // unix_version_option1();
//    #endif
//
//    #ifdef OPTION2
//	    // unix_version_option2();
//    #endif
//
//#elif defined(OS_MSDOS)
//
//    #ifdef OPTION2
//	    // msdos_version_option2();
//    #endif
//
//#endif
//
//	return 0;
//}




//#include <stdio.h>
//int main()
//{
//	int i = 0;
//
//	int arr[10] = { 0 };
//
//	int __DEBUG__ = 0;
//
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//
//#ifdef __DEBUG__
//		printf("%d ", arr[i]); // 为了观察数组是否赋值成功。需要观察才编译，不需要则不编译。
//#endif
//		// 若定义过 __DEBUG__ 则编译，否则不编译
//
//	}
//	return 0;
//}
//
//#define __DEBUG__

//#include <stdio.h>
//
////#define __DEBUG__
//
//int main()
//{
//#if !defined(__DEBUG__)
//	printf("hehe\n");
//#endif 
//
//#ifndef __DEBUG__
//	printf("hehe\n");
//#endif
//
//	return 0;
//}


//#include <stdio.h>
//
//#define __DEBUG__
//
//int main()
//{
//#if defined(__DEBUG__)
//	printf("hehe\n");
//#endif 
//
//#ifdef __DEBUG__
//	printf("hehe\n");
//#endif
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//
//#if 1==2
//	printf("123\n");
//
//#elif 1==3
//	printf("456\n");
//
//#else
//	printf("789\n");
//
//#endif
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int i = 0;
//
//	int arr[10] = { 0 };
//
//	int __DEBUG__ = 0;
//
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//
//#if 1-1
//		printf("%d ", arr[i]);
//#endif
//
//	}
//	return 0;
//}

//#include <stdio.h>
//
////#define __DEBUG__
//
//int main()
//{
//	int i = 0;
//
//	int arr[10] = { 0 };
//
//	int __DEBUG__ = 0;
//
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//
//#ifdef __DEBUG__
//		printf("%d ", arr[i]); // 为了观察数组是否赋值成功。需要观察才编译，不需要则不编译。
//#endif
//		// 若定义过 __DEBUG__ 则编译，否则不编译
//
//	}
//	return 0;
//}



//// 在 Linux系统 的 gcc编译器 下运行
//
//#include <stdio.h>
//int main()
//{
//	int arr[SZ] = { 0 };
//
//	int i = 0;
//
//	for (i = 0; i < SZ; i++)
//	{
//		arr[i] = i;
//	}
//
//	for (i = 0; i < SZ; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}


//#include <stdio.h>
//
//#define MAX 100
//
//int main()
//{
//	printf("%d\n", MAX);
//
//#undef MAX
//
//	printf("%d\n", MAX);
//
//	return 0;
//}

//#include <malloc.h>
//
//#define MALLOC(num,type) (type*)malloc(num*sizeof(type))
//// 使用 宏 则使得代码更好理解，即
//// 开辟 (num) 个 (type)类型 的动态内存空间
//
//int main()
//{
//	int* p = MALLOC(10, int);
//	// 相当于 int* p = (int*)malloc(10 * sizeof(int));
//
//	return 0;
//}

//#include <stdio.h>
//
//#define SIZEOF(type) sizeof(type)
//
//int main()
//{
//	int size = SIZEOF(int);
//	printf("%d\n", size);
//
//	return 0;
//}


//#include <stdio.h>
//
//// 宏
//#define MAX(X,Y) (X)>(Y)?(X):(Y)
//
//// 函数
//int Max(int x, int y)
//{
//	return (x > y ? x : y);
//}
//
//int main()
//{
//	float a = 5.1f;
//	float b = 10.2f;
//
//	// 宏
//	float max1 = MAX(a, b);
//	printf("%lf\n", max1);
//
//	// 函数 
//	float max2 = Max(a, b);
//	printf("%lf\n", max2);
//
//	return 0;
//}



//#include <stdio.h>
//
//// 宏
//#define MAX(X,Y) (X)>(Y)?(X):(Y)
//
//// 函数
//int Max(int x, int y)
//{
//	return (x > y ? x : y);
//}
//
//int main()
//{
//	int a = 5;
//	int b = 10;
//
//	// 宏
//	int max1 = MAX(a, b);
//	printf("%d\n", max1);
//
//	// 函数
//	int max2 = Max(a, b);
//	printf("%d\n", max2);
//
//	return 0;
//}


//#include <stdio.h>
//int Max(int x, int y)
//{
//	return (x > y ? x : y);
//}
//
//int main()
//{
//	int  a = 5;
//	int b = 10;
//
//	int max = Max(a++, b++);
//
//	printf("a = %d\n", a);
//	printf("b = %d\n", b);
//	printf("max = %d\n", max);
//
//	return 0;
//}


//#define MAX(X,Y) (X)>(Y)?(X):(Y)
//
//int main()
//{
//	int a = 5;
//	int b = 10;
//
//	int max = MAX(a++, b++);
//
//	printf("a = %d\n", a);
//	printf("b = %d\n", b);
//	printf("max = %d\n", max);
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int a = 10;
//	int b = 0;
//
//	b = a + 1;
//	printf("a = %d ; b = %d\n", a, b);
//
//	b = ++a;
//	printf("a = %d ; b = %d\n", a, b);
//
//	return 0;
//}



//#include <stdio.h>
//int MAX(int x, int y)
//{
//	return (x > y ? x : y);
//}
//int main()
//{
//	int a = 10;
//	int b = 11;
//
//	int Max = MAX(a++, b++);
//
//	printf("%d\n", Max);
//	printf("%d\n", a);
//	printf("%d\n", b);
//
//	return 0;
//}


//#include <stdio.h>
//
//#define CAT(X,Y) X##Y
//
//int main()
//{
//	int room10 = 2022;
//
//	printf("%d\n", CAT(room, 10));
//	// 在预编译时，会被替换成
//	// printf("%d\n", room##10 );
//	// 
//	// 而在 宏 中， ## 可以把位于它两边的符号合成一个符号，
//	// 即变成
//	// printf("%d\n", room10 );
//	// 
//	// 所以打印 2022
//
//	return 0;
//}

//#include <stdio.h>
//
//#define PRINT(X) printf("the value of "#X" is %d\n",X)
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	PRINT(a);
//
//	PRINT(b);
//
//	return 0;
//}

//#include <stdio.h>
//void PRINT(int x, char c)
//{
//	printf("the value of %c is %d\n", c, x);
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	PRINT(a, 'a');
//
//	PRINT(b, 'b');
//
//	return 0;
//}



//#include <stdio.h>
//void PRINT(int x)
//{
//	printf("the value of a is %d\n", x);
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	PRINT(a);
//
//	PRINT(b);
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	printf("hello world\n");
//
//	printf("hello ""world\n");
//
//	printf("he""llo ""wo""rld\n");
//
//	char* hw = "hello ""world";
//
//	printf("%s\n", hw);
//
//	return 0;
//}

//#define DOUBLE(X) ((X)+(X))
//
//#include <stdio.h>
//int main()
//{
//	int a = 5;
//
//	int ret = 10 * DOUBLE(a);
//
//	printf("%d\n", ret);
//
//	return 0;
//}


//#define DOUBLE(X) X+X
//
//#include <stdio.h>
//int main()
//{
//	int a = 5;
//
//	int ret = 10 * DOUBLE(a);
//
//	printf("%d\n", ret);
//
//	return 0;
//}



//#define SQUARE(X) (X)*(X)
//
//#include <stdio.h>
//int main()
//{
//	int ret = SQUARE(5 + 1);
//
//	printf("%d\n", ret);
//
//	return 0;
//}




//#define SQUARE(X) X*X
//
//#include <stdio.h>
//int main()
//{
//	int ret = SQUARE((5 + 1));
//
//	printf("%d\n", ret);
//
//	return 0;
//}



//#define SQUARE(X) X*X
//
//#include <stdio.h>
//int main()
//{
//	int ret = SQUARE(5 + 1);
//
//	printf("%d\n", ret);
//
//	return 0;
//}




//#define MAX 100;
//
//#include <stdio.h>
//int main()
//{
//	int max = MAX;
//	// 这段代码运行 没有问题，
//	// 但值得注意的是，
//	// 这段代码相当于 int max = 100;;
//	// 即 int max = 100;
//	//    ;
//	// 两句代码
//
//	printf("%d\n", MAX);
//	// 这段代码 有问题，无法编译，
//	// 但是 单从 语法格式 上是看不出问题的，
//	// 因为是替换之后才有问题，即 printf("%d\n",100;); ， 前一个 ;分号 错误
//
//	return 0;
//}

//// 如果定义的 stuff 过长，可以分成几行写，除了最后一行外，每行的后面都加一个反斜杠(续行符)。
//#define DEBUG_PRINT printf("file:%s\tline:%d\t\
//date:%s\ttime:%s\n" ,\
//__FILE__,__LINE__ ,\
//__DATE__,__TIME__ )  
//
//#include <stdio.h>
//int main()
//{
//    DEBUG_PRINT;
//    // 打印 file:D:\virtual studio\C_Language_learn\预处理\test.c   line:14 date:Apr  8 2022        time:20:44:47
//
//
//    return 0;
//}

//#define CASE break;case  //在写 case语句 的时候自动把 break 写上。
//
//#include <stdio.h>
//int main()
//{
//	int input = 0;
//	scanf("%d", &input);
//
//	switch (input)
//	{
//	case 1:
//		break;
//
//	case 2:
//		break;
//
//		// 以上写法容易忘记加上 break;
//		// 而使用 #define 定义的 CASE 则可以避免这种问题
//
//		CASE 3:
//		// 相当于
//		//     break;
//		// case 3:
//
//		CASE 4:
//		// 相当于
//    	//     break;
//	    // case 4:
//
//		CASE 5:
//		// 相当于
//		//     break;
//		// case 5:
//		break; // 但是 最后这个 break; 仍需要自己写上
//
//	}
//}




//#define  do_forever for(;;)    // 符号对应内容 是 函数
//
//#include <stdio.h>
//int main()
//{
//	do_forever
//
//	return 0;
//	
//	// 没有 ;分号 则 不会死循环，
//	// 这段代码 相当于
//	// for(;;)
//	// {
//	//     return 0;
//	// }
//	// 
//	// 因为缺少 ;分号 ，所以这里应该把 return 0; 联系起来看
//}

//#define UNI unsigned           // 符号对应内容 是 关键字
//#define  do_forever for(;;)    // 符号对应内容 是 函数
//
//#include <stdio.h>
//int main()
//{
//	UNI int i = 10;
//	// 相当于 unsigned int i = 10;
//
//	do_forever;
//	// 相当于 
//	// for(;;)
//	// {
//	//     ;
//	// }
//	// 这段代码是 死循环 且 什么也没干
//
//	return 0;
//}


//#define MAX 100       // 符号对应内容 是 整数
//#define STR "hehe"    // 符号对应内容 是 字符串
//
//#include <stdio.h>
//int main()
//{
//	printf("%d\n", MAX); // 打印 100
//
//	printf("%s\n", STR); // 打印 hehe
//
//	return 0;
//}


//#include <stdio.h>
//
//#define MAX 100 // 我们自己使用 #define 定义的符号，不是 预定义符号
//
//int main()
//{
//	// 预定义符号
//
//	printf("%s\n", __FILE__);
//	// 打印 D:\virtual studio\C_Language_learn\预处理\test.c
//	//
//	// 即 这段代码所在 源文件 保存的 绝对路径 ，使用 %s 打印
//
//	printf("%d\n", __LINE__); 
//	// 打印 15
//	//
//	// 即 这段代码 在哪一行 ，使用 %d 打印
//
//	printf("%s\n", __DATE__);
//	// 打印 Apr  8 2022
//	//
//	// 即 这段代码 运行时的日期 ，使用 %s 打印
//
//	printf("%s\n", __TIME__);
//	// 打印 18:27:16
//	//
//	// 即 这段代码 运行时的时间 ，使用 %s 打印
//
//	printf("%s\n", __FUNCTION__);
//	// 打印 main
//	//
//	// 即 这段代码 运行时所在函数的 函数名 ，使用 %s 打印
//
//	return 0;
//}


//extern ADD(int x, int y); // extern 用于 声明外部函数
//
//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//
//	int i = 0;
//
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//	}
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	int a = 10;
//	int b = 20;
//
//	int c = ADD(a, b);
//
//	printf("%d\n", c);
//
//	return 0;
//}