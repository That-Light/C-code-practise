#define _CRT_SECURE_NO_WARNINGS


////n的阶乘
//#include <stdio.h>
//
//int dmul(int x)
//{
//	//int ret = 1;
//	//while (1)
//	//{
//	//	if (x != 0)
//	//	{
//	//		ret = ret * x;
//	//		x--;
//	//	}
//	//	else
//	//	{
//	//		return ret;
//	//	}
//	//}
//
//
//	if (x <= 1)
//	{
//		return 1;
//	}
//	return x*dmul(x - 1);
//}
//
//int main()
//{
//	int input = 0;
//
//	printf("n = ");
//	scanf("%d", &input);
//
//	int reb = dmul(input);
//
//	printf("n! = %d\n", reb);
//
//	return 0;
//


//斐波那契数列：1  1  2  3  5  8  13  21  34  55  89 ……
//就是 前两个数 的 和 等于 后一个数 ，当然，要先给定第一个和第二个数： 1  1

//求 第n个 斐波那契数

#include <stdio.h>

//递归的方式：（程序占用内存大，运行速度慢，如：求第50个斐波那契数时要很长时间）
//解题原理：
//         已知 斐波那契数列 就是 第一个和第二个数 都为 1 ，然后 前两个数 的 和 等于 后一个数 ，则
//         可以通过 递归 ，每次返回 前两个数 的 和 ，直到返回 第一个和第二个数(即 1) ，
//
//劣势：(程序占用内存大)
//     如：求第50个斐波那契数，
//     得求 第49个 与 第48个 斐波那契数，
//     而又得求 第48个 与 第47个 斐波那契数 还有 第47个 与 第46个 斐波那契数，
//     ……
//     即：      50
//              ↙↘
//           49      48
//          ↙↘    ↙↘
//         48  47  47  46
//              ……
//     有许多数需要重复计算，所以 递归的方式 求 第n个 斐波那契数 效率极低
int fib1(int n)
{
	if (n <= 2)
		return 1;
	else
		return fib1(n - 1) + fib1(n - 2);
}

//迭代的方式：（程序占用内存小，运行速度快）
// 一开始令 a = 1 ; b = 1 ; c = 1
// 每次迭代 令 c = a + b ; a = b ; b = c
// 返回 c 的值
// 
// 解题原理：
//1  1  2  3  5  8  13  21  34  55  89 ……
//a  b  c
//(迭代一次)
//1  1  2  3  5  8  13  21  34  55  89 ……
//   a  b  c
//(迭代一次)
//1  1  2  3  5  8  13  21  34  55  89 ……
//      a  b  c
//……
int fib2(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;   //这里令 c = 1 很关键，因为 斐波那契数列 第一个和第二个 值 都为 1 ，
	             //若 n < 2 (输出 第1个或第2个 斐波那契数) 直接就可以返回 c = 1 的值，与题目相匹配

	while (n > 2)
	{
		c = a + b;   //这里 先 c = a + b ，后面又是 b = c ，不会使 c 和 b 冲突吗？
		a = b;       //解：是 不会冲突 的，因为我们只是 输出 c 的 值 ，
		b = c;       //    这里的 a = b , b = c 只是为 下一轮迭代中 的 c = a + b 赋值作准备，
		             //    意思就是： c的值 是 本轮迭代中 的 c的值 ，
		             //               而 a 和 b 的值 已经是 下一轮迭代中的值

		n--;   //为什么是 n-- ? 因为 n > 2 才需要进行迭代处理，
		       //                   每迭代完一次 n-- ，直到 n < 2 (第一个和第二个 斐波那契数 不用通过迭代 求得)结束，
		       //                   即用 n > 2 作为 循环判断 ， n-- 作为 调整 ，刚好满足题目要求。
	}
	return c;
}

//主函数
int main()
{
	int input = 0;

	printf("求第几个斐波那契数？—》：");
	scanf("%d", &input);

	//递归的方式
	int ret1 = fib1(input);
	printf("递归的方式结果为：%d\n", ret1);

	//迭代的方式
	int ret2 = fib2(input);
	printf("迭代的方式结果为：%d\n", ret2);

	return 0;
}