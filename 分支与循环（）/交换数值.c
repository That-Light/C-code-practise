#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//
//// void类型 不返回任何东西 
//void swap1(int x, int y)   // 主函数 中的 a 和 b 与 swap1 中的 x 和 y 分别开辟了不同的 内存 ，
//                           // swap1 仅在 函数 中更换了 参数 x 和 y 的位置，对 主函数 的 a 和 b 无影响
//{
//	int tmp = 0;
//	tmp = x;
//	x = y;
//	y = tmp;
//}
//
//// void类型 不返回任何东西 
//void swap2(int* pa, int* pb)   // int* 为 整型指针类型 ， pa 和 pb 存储 内存地址 的称为 指针变量
//                               // 无返回值函数 更改变量，得通过 内存地址 找到 该地址对应的变量 进行更改
//{
//	int tmp = 0;
//	tmp = *pa;   // *pa 和 *pb 为 解引用操作符 ，即分别为 主函数 中的 a 和 b
//	*pa = *pb;
//	*pb = tmp;
//}
//
//int main()
//{
//	int a = 10, b = 20;
//
//	//不能完成交换任务
//	swap1(a, b);
//	printf("swap1: a = %d   b = %d\n", a, b);
//
//	//可以完成交换任务
//	swap2(&a, &b);   // & 为取 地址操作符
//	printf("swap2: a = %d   b = %d\n", a, b);
//
//	return 0;
//}