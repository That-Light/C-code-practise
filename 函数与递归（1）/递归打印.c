#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//void print(int a)
//{
//	int b = 0;
//
//	if (a % 10 == a)
//	{
//		printf("%d ", a);
//	}
//	else
//	{
//		b = a / 10;
//		print(b);
//		printf("%d ", a % 10);
//	}
//}
//
//int main()
//{
//
//	unsigned int a = 0;
//	printf("请输入：");
//	scanf("%d", &a);//1234
//
//	print(a);
//
//	return 0;
//}

//int my_strlen(char* str)
//{
//
//	if (*str != '\0')
//	{
//		return 1 + my_strlen(str+1);
//	}
//	return 0;
//}
//
//
//#include <stdio.h>
//int main()
//{
//
//	char arr[] = "happy";
//
//	int len = my_strlen(arr);
//
//	printf("len = %d\n", len);
//
//	return 0;
//}


////接受一个整型值（无符号），按照顺序打印它的每一位。
////例如：
////输入：1234，输出 1 2 3 4.
//
////解题思路：
////print(1234)
////print(123) 4
////print(12) 3 4
////print(1) 2 3 4
//// 1 2 3 4
//
//#include <stdio.h>
//void print(int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//
//int main()
//{
//	unsigned int num = 0;
//
//	printf("请输入：");
//	scanf("%d", &num);
//
//	print(num);
//
//	return 0;
//}


//编写函数 不允许创建 临时变量 ，求字符串的长度。（即：模拟实现一个 函数 求字符串长度）

//解题思路：识别 '\0'
//str:↓
//arr: h a p p y \0
// ( str + 1 )
//str:  ↓
//arr: h a p p y \0
// ( str + 1 )
//str:    ↓
//arr: h a p p y \0
// ( str + 1 )
//str:      ↓
//arr: h a p p y \0
// ( str + 1 )
//str:        ↓
//arr: h a p p y \0
// ( str + 1 )
//str:           ↓
//arr: h a p p y \0
// ( str + 1 )

//return 的值：
//my_strln("happy\0")
// 1 +my_strln("appy\0")
//1+ 1 +my_strln("ppy\0")
//1+1+ 1 +my_strln("py\0")
//1+1+1+ 1 +my_strln("y\0")
//1+1+1+1+ 1 +my_strln("\0")
//1+1+1+1+1+ 0

//#include <stdio.h>
//
//int my_strlen(char* str)                           //因为传进来的是 数组 的 第一个元素的 地址 ，所以用 数组类型(char)的指针(char*) 来储存
//{
//	if (*str != '\0')                         // 字符串结束标志 是 '\0'   不是'\n'，'\n'是换行操作符
//	{
//		return 1 + my_strlen(str + 1);
//	}
//		return 0;
//}
//
//int main()
//{
//	char arr[] = "happy";   //字符串类型(char) 数组 ：不用{}，直接""，即 char arr[] = "happy";
//	                        //整型类型(int) 数组 ：要{}和""同时使用，即 int arr[] ={"0"};
//
//	int len = my_strlen(arr);   //arr 是 数组 ， 数组传参 ，传过去的不是整个数组，而是数组中第一个元素的地址
//
//	printf("len = %d\n", len);
//
//	return 0;
//}