#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6328)

#include <stdio.h>
int main()
{
	int a, b, c;
	
	a = 5;
	
	c = ++a; // 前置++ 优先级 高于 =等号 ，即
	         // 先 a++ 即 a = 6
	         // 再 c = ++a 即 c = 6
	         //算到这里 a = 6 ， b 未初始化 ， c = 6
	 
	b = ++c, c++, ++a, a++; // =等号 优先级 高于 ,逗号表达式 ，即
	                        // 先算 b = ++c ,因为 前置++ 优先级 高于 =等号 ，则 c = 7 , b = 7
	                        // 再算 c++ ，则 c = 8 ，
							// 再算 ++a ，则 a = 7 ，
							// 最后算 a++ ，则 a = 8 。
	                        //算到这里 a = 8 ， b = 7 ， c = 8

	b += a++ + c; // +加号 优先级 高于 +=加等号 ， 后置++ 先使用 后++
	              // 先算 b += a++ + c ，即 b = b + a + c ，则 b = 23
	              // 再算 a++ ，则 a = 9
				  //算到这里 a = 9 ， b = 23 ， c = 8
	
	printf("a = %d , b = %d , c = %d\n", a, b, c);
	//打印 a = 9 , b = 23 , c = 8
	return 0;
}

//#include <stdio.h>
//
//int i; // 全局变量 不进行 初始化 ，默认是 0
//
//int main()
//{
//	i--;
//	if (i > sizeof(i))
//	{
//		printf(">\n");
//	}
//	else
//	{
//		printf("<\n");
//	}
//	
//	//打印 >
//	//为什么呢？ i-- 变成 -1 不是应该比 sizeof(i) 的值 4 小吗？
//	// 因为
//	// sizeof() 是计算 变量或类型 所占 内存 的 大小 ，是 恒大于等于0 的，
//	// 则规定 sizeof() 计算得出来的 值 是 无符号数 ，
//	// 当 一个整型 和 一个无符号数 进行 比较 时，会先把 这个整型 转换为 无符号数 ，
//	// 所以
//	// -1 的 最高位 不再是 符号位 ，而是 有效位 ，所以变成一个超级大的数 ，
//	// 10000000 00000000 00000000 00000001       -1的原码
//	// 11111111 11111111 11111111 11111110       -1的反码
//	// 11111111 11111111 11111111 11111111       -1的补码
//	// 转换后 最高位 不再是 符号位 ，而是 有效位 ，则
//	// 11111111 11111111 11111111 11111111       补码 = 反码 = 原码
//	// 因为没有了 符号位 ，恒为 正 ，而 正数 三码相同 ，这是一个超级大的数
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	char c = 1;
//
//	// %u 无符号十进制数
//
//	printf("%u\n", sizeof(c)); // 没有进行 运算 就不会进行 整型提升
//
//	printf("%u\n", sizeof(+c)); //进行 运算 就会 进行 整型提升
//
//	printf("%u\n", sizeof(!c)); // 单独对自己操作不算运算 ， 运算得是几个数之间
//
//	//打印   1    4    1
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	// 0x 是 十六进制的前缀
//	char a = 0xb6; // 因为 进制转换(《数组第1节》) 中 ， 4个二进制位 相当于 1个十六进制位 ，
//	               //放进 char类型 1个字节 中
//	               //所以        0x      b      6
//	               //即补码为           1011   0110
//
//	short b = 0xb600; // 因为 进制转换(《数组第1节》) 中 ， 4个二进制位 相当于 1个十六进制位 ，
//					  //放进 short类型 2个字节 中
//	                  //所以        0x      b      6      0      0
//	                  //即补码为           1011   0110   0000   0000
//
//	int c = 0xb6000000; // 因为 进制转换(《数组第1节》) 中 ， 4个二进制位 相当于 1个十六进制位 ，
//						//放进 int类型 4个字节 中
//	                    //所以        0x      b      6      0      0      0      0      0      0
//	                    //即补码为           1011   0110   0000   0000   0000   0000   0000   0000
//	
//	if (a == 0xb6)        // ==对比 也是一种运算 ，要进行 整型提升 ，
//		                  //                            10110110
//		                  // 11111111 11111111 11111111 10110110   (整型提升)
//		                  // 提升后不相等，a不打印
//		printf("a\n");
//	
//	if (b == 0xb600)      // ==对比 也是一种运算 ，要进行 整型提升 ，
//		                  //                   10110110 00000000
//		                  // 11111111 11111111 10110110 00000000   (整型提升)
//		                  // 提升后不相等，b不打印
//		printf("b\n");
//	
//	if (c == 0xb6000000)  // ==对比 也是一种运算 ，要进行 整型提升 ，
//		                  // 10110110 00000000 00000000 00000000
//		                  // 因为已经是 int类型 4个字节，所以不用整型提升
//		                  // c == 0xb6000000 成立 ，打印c
//		printf("c\n");
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	char a = 3;
//	// 3 是一个 整数类型 ，应该占 4个字节 ，其补码 有32位，即
//	//00000000 00000000 00000000 00000011   (正数 三码 相同)
//	//而 char类型 只能放下 1个字节 ，所以要进行 截断 ，
//	//( 截断 原则：存放 最低位、最小的 一个字节 的 内容)即，
//	//00000011
//
//	char b = 127;
//	//同理， b 也要进行截断
//	//01111111
//
//	char c = a + b;
//	//因为 计算机运算 只能是对 4个字节(32个比特位) 的 补码(二进制) 进行运算，
//	//低于 4个字节 的 类型 将会进行 整型提升 ，
//	//( 整型提升 原则：按照 变量 的 数据类型 的 符号位 进行提升。负数为1，全填1；正数为0，全填0)
//	// 则，
//	// a - 00000011 ，整型提升为
//	// 00000000 00000000 00000000 00000011
//	// b - 01111111 ，整型提升为
//	// 00000000 00000000 00000000 01111111
//	//
//	// a + b =
//	// 00000000 00000000 00000000 10000010
//	//
//	// 此时 a + b 的 值 仍为 整型 ，放进 char类型 中要进行 截断 ，
//	// 所以 c 为
//	// 10000010
//
//	printf("%d\n", c);
//	// %d 打印的是 整型(4字节) ，而此时 c 为 char类型(1字节) ，需要进行 整型提升 ，
//	// c - 10000010 ，整型提升为
//	// 11111111 11111111 11111111 10000010   (补码)
//	// 
//	// printf()打印的是 原码
//	// 11111111 11111111 11111111 10000001   (反码)
//	// 10000000 00000000 00000000 01111110   (原码)
//    // -           126
//	//所以打印 -126
//
//	return 0;
//}

//#include <stdio.h>
////struct 用于创建一个 结构体类型 ，而 stu 是创建的 结构体类型名字
//// struct stu 整体是一个叫 stu 的结构体类型 ，它跟 int 、 char 一样是一种 类型 ，
////                                        而 类型 是用来创建 变量 的。
//struct stu
//{
//	//描述一个 结构体 所需要的 成员变量
//	char name[20];
//	int age;
//	char id[10];
//};
//
//int main()
//{
//	struct stu s1 = { "张三",20,"20220213" };
//	// s1 是使用 struct stu 这个 结构体类型 创建的一个 结构体(对象)(变量) ，并进行了初始化
//
//	printf("%s\n", s1.name); //访问一个结构的成员一种方式：( 结构体 . 成员名 )
//
//	struct stu* ps = &s1; //既然 s1 是 类型 创建出来的 变量 ，那它肯定有一个 地址 ，
//						  //可以使用 &取地址操作符 获取它的 地址 ，
//						  // 存放在名为 ps 的 指针变量 中 ，
//						  // 而 存放地址 的 类型 是 (类型)* , s1 的 类型 是 struct stu ，
//						  // 所以是 struct stu* 
//
//	printf("%s\n", (*ps).name);
//
//	printf("%s\n", ps->name); //这里的 ps-> 跟上面的 (*ps). 没有任何区别
//	                          //这是访问结构的成员的另一种方式：( 结构体指针 -> 成员名 )
//
//	return 0;
//}


//#include <stdio.h>
//int get_max(int a, int b) //这里的 () 不是函数调用操作符，只是语法格式要求
//{
//	return (a > b ? a : b);
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	int max = get_max(a, b); // () 为函数调用操作符
//	                         //此代码有 函数名get_max 和 参数a、参数b 三个操作数
//
//	printf("max = %d\n", max);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int i = 0;
//    int a = 0, b = 2, c = 3;
//    i = a++ && ++b && c++;
//
//    printf("a = %d ， b = %d ， c = %d\n", a, b, c);
//    //打印 a = 1 ， b = 2 ， c = 3
//    //
//    // 为什么不是 a = 1 ， b = 3 ， c = 4 呢？
//    //
//    // 因为 &&逻辑与 ，算到 0(假) 就直接可以判定 为假 了，后面就不再进行运算，
//    // 即 i = a++ && ++b && c++;
//    //        a++ 先计算，后++ ，
//    //        运算 &&逻辑与 时 a 为 0 ，则 i = a++ && ++b && c++; 可以直接判定 为假(i = 0) ，
//    //                                           后面的 ++b 和 c++ 就不再进行运算算
//    // 所以 ++b 和 c++ 其实并没有运算 ，只有 a++ 运算了
//
//    return 0;
//}
//
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int a = 1, b = 2, c = 3;
//	i = a++ || ++b || c++;
//
//	printf("a = %d ， b = %d ， c = %d\n", a, b, c);
//	//打印 a = 2 ， b = 2 ， c = 3
//	// 为什么不是 a = 2 ， b = 3 ， c = 4 呢？
//	// 
//	// (与上面的 &&逻辑与 同理)
//	// 
//	// 因为 ||逻辑或 ，算到 1(真) 就直接可以判定 为真 了，后面就不再进行运算，
//	// 即 i = a++ || ++b || c++;
//	//        a++ 先计算，后++ ，
//	//        运算 ||逻辑或 时 a 为 1 ，则 i = a++ || ++b || c++; 可以直接判定 为真(i = 1) ，
//	//                                           后面的 ++b 和 c++ 就不再进行运算算
//	// 所以 ++b 和 c++ 其实并没有运算 ，只有 a++ 运算了
//
//	return 0;
//}

//#include <stdio.h>
//void test1(int arr[])
//{
//	printf("%d\n", sizeof(arr)); //打印 8
//	                             //数组传参 传的是 首元素地址，
//	                             //此处的 arr 是一个 指针变量 的名字，
//	                             //指针变量 在 32位操作系统占4个字节
//	                             //         在 64位操作系统占8个字节
//}
//
//void test2(char ch[])
//{
//	printf("%d\n", sizeof(ch)); //打印 8
//								//数组传参 传的是 首元素地址，
//								//此处的 arr 是一个 指针变量 的名字，
//							    //指针变量 在 32位操作系统占4个字节
//							    //         在 64位操作系统占8个字节
//
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	char ch[10] = { 0 };
//
//	printf("%d\n", sizeof(arr)); //打印 40
//	                             // arr 是一个 整型数组 ，
//	                             //大小是 数组类型大小 乘 元素个数 ，
//	                             //即          4       *     10    = 40
//
//	printf("%d\n", sizeof(ch)); //打印 10
//							    // arr 是一个 字符串数组 ，
//								//大小是 数组类型大小 乘 元素个数 ，
//								//即          1       *     10    = 10
//
//	test1(arr);
//	test2(ch);
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 11;
//	//即 a 的 在 内存中 为：
//	//00000000 00000000 00000000 00001101
//	//                      我们想要把 ↑ 这个 0 改成 1 ，
//	//即 二进制中 的 某一位 0 改成 1 ，本题是将 第2位 的 0 改成 1 ，
//	//我们可以 或上 一个，( | 或：有 1 则为 1 ，全 0 才是 0)
//	//00000000 00000000 00000000 00000010
//	//就可以得到
//	//00000000 00000000 00000000 00001111 为所求
//	// 
//	//如何获得
//	//00000000 00000000 00000000 00000010 ?
//	//因为是把 二进制中 的 某一位 0 改成 1 ，有具体的位置，
//	//可以用 << 左移操作符，对 1 进行 左移 ，即 对
//	//00000000 00000000 00000000 00000001 进行左移，
//	//本题是 左移 两位
//	a = (a | (1 << 2));
//	printf("%d\n", a); //打印 15
//
//	//现在 a 是 15 ，即
//	//00000000 00000000 00000000 00001111
//	//我们想把 a 变回原来的 11 ,同理 即 将
//	//00000000 00000000 00000000 00001111
//	//                      我们想要把 ↑ 这个 1 改成 0 ，
//	//我们可以 与上 一个 ，( & 与：有 0 则为 0 ，全 1 才是 1)
//	//11111111 11111111 11111111 11111101
//	//就可以得到
//	//00000000 00000000 00000000 00001101 为所求，
//	//
//	//如何获得
//	//11111111 11111111 11111111 11111101 ?
//	//可以对
//	//00000000 00000000 00000000 00000010
//	//使用按位取反获得，( ~ 按位取反：二进制中 0 变 1 ， 1 变 0)
//	//而
//	//00000000 00000000 00000000 00000010
//	//是上面通过 对 1 进行 左移操作 得来的
//	a = (a & (~(1 << 2)));
//	printf("%d\n", a); //打印 11
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	short a = 0;
//	int b = 10;
//
//	printf("%d\n", sizeof(a = b + 5)); //打印 2
//	printf("%d\n", a); //打印 0
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 0;
//	char c = 'r';
//	char* p = &c;
//	int arr[10] = { 0 };
//
//	 sizeof() 计算变量所占内存空间的大小，单位是字节
//
//	printf("%d\n", sizeof a); //打印4      当为 变量 时，可不用 () 括住
//	printf("%d\n", sizeof(int)); //打印4   但为 类型 时，必须用 () 括住
//
//	printf("%d\n", sizeof(c)); //打印1
//	printf("%d\n", sizeof(char)); //打印1
//
//	printf("%d\n", sizeof(p)); //打印4         32为操作系统为 4 ，64位操作系统为 8
//	printf("%d\n", sizeof(char*)); //打印4
//
//	printf("%d\n", sizeof(arr)); //打印40
//	printf("%d\n", sizeof(int[10])); //打印40   对于 数组 来说， 定义 去掉 数组名 就是 数组的类型
//	printf("%d\n", sizeof(int[5])); //打印20    每个 int类型 占 4 个字节，一共有 5 个，则 数组大小 为 20 个字节
//	
//	return 0;
//}

////求一个 整数 存储在内存中的 二进制 中 1 的 个数
//
//#include <stdio.h>
//int main()
//{
//	int input = 0;
//	printf("请输入一个数：");
//	scanf("%d", &input);
//
//	int count = 0; //统计出现 1 的次数
//	int i = 0;
//
//	for (i = 0; i < 32; i++)
//	{
//		if ((1 & (input >> i)) == 1)
//			count++;
//	}
//
//	printf("输出：%d", count);
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int input = 0;
//	printf("请输入一个数：");
//	scanf("%d", &input);
//
//	int count = 0; //统计出现 1 的次数
//
//	while (input)
//	{
//		if (input % 2 == 1)
//		{
//			count++;
//		}
//		input = input / 2;
//	}
//
//	printf("输出：%d",count);
//
//	return 0;
//}