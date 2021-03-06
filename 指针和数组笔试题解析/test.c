#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main()
{
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	// 这句代码说明将 "ENTER","NEW","POINT","FIRST" 这 4 个 常量字符串 的 首字符地址 存入 数组a 中，
	// 即存了 "ENTER"字符中首字符'E'的地址 ， "NEW"字符中首字符'N'的地址 ，"POINT"字符中首字符'P'的地址 ， "FIRST"字符中首字符'F'的地址 。

	char** cp[] = { c + 3,c + 2,c + 1,c };
	// c 是 数组名 ，即 数组的首元素地址 ，
	// 而 数组c 的 每个元素 都是 char*类型 ，
	// 想在 cp 中存入 char*类型的地址 ， cp 的类型需为 char** ，即 二级指针 ，
	// 
	// char** cp[] = { c + 3,c + 2,c + 1,c };
	// 这里的 cp 是一个 一维数组 ，这句代码的意思相当于把 数组c的元素 倒过来排序之后 的 地址 存入 数组cp 中 。
	// 即 数组cp 中，
	//    第一个元素 是 "FIRST"字符中首字符'F'的地址 的地址 ，
	//    第二个元素 是 "POINT"字符中首字符'P'的地址 的地址 ，
	//    第三个元素 是 "NEW"字符中首字符'N'的地址   的地址 ，
	//    第四个元素 是 "ENTER"字符中首字符'E'的地址 的地址 ，

	char*** cpp = cp;
	// cp 是 数组名 ，即 数组的首元素地址 ，
	// 而 数组cp 的 每个元素 都是 char**类型 ，
	// 想在 cpp 中存入 char**类型的地址 ， cpp 的类型需为 char** ，即 三级级指针 。
	// 
	// 此时 cpp 存了 数组cp 的 首元素 的地址，即 "FIRST"字符中首字符'F'的地址 的地址 的地址。


	printf("%s\n", **++cpp); // 打印 POINT
	// ++cpp 先 自增1 ，即 数组cp 的 第二个元素地址 ，也就是 "POINT"字符中首字符'P'的地址 的地址 的地址，
	// *++cpp 取出 数组cp 的 第二个元素 ，即 "POINT"字符中首字符'P'的地址 的地址，
	// **++cpp 取出 "POINT"字符中首字符'P'的地址。
	// 
	// 然后使用 %s 打印，输出为 POINT 。
	// 
	// 此时 cpp 已经 自增1 ，所以不再是 数组cp的首元素地址，而是 数组cp的第二个元素地址。

	printf("%s\n", *-- * ++cpp + 3);// 打印 ER
	// ++cpp 先 自增1 ，即 数组cp 的 第三个元素地址 ，也就是 "NEW"字符中首字符'N'的地址 的地址 的地址，
	// * ++cpp 取出 "NEW"字符中首字符'N'的地址 的地址，
	// -- * ++cpp 是 "ENTER"字符中首字符'E'的地址 的地址，
	// *-- * ++cpp 取出 "ENTER"字符中首字符'E'的地址，
	// *-- * ++cpp + 3 是 "ENTER"字符中首字符'E'(后一个'E')的地址，
	// 
	// 然后使用 %s 打印，输出为 ER 。
	// 
	// 此时 cpp 又已经 自增1 ，所以不再是 数组cp的第二个元素地址，而是 数组cp的第三个元素地址。

	printf("%s\n", *cpp[-2] + 3);// 打印 ST
	// cpp[-2] == *(cpp - 2) ，即 ++cpp 先 自减2 ，即 数组cp 的 第一个元素地址 ，也就是 "FIRST"字符中首字符'F'的地址 的地址 的地址，
	//                                  再 *解引用 取出 "FIRST"字符中首字符'F'的地址 的地址，
	// *cpp[-2] == **(cpp - 2) 取出 "FIRST"字符中首字符'F'的地址，
	// *cpp[-2] + 3 == **(cpp - 2) + 3 取出 "FIRST"字符中首字符'S'的地址，
	// 
	// 然后使用 %s 打印，输出为 ST 。
	// 
	// cpp[-2] == *(cpp - 2) ，不是 cpp = cpp -2 ，所以 cpp 没有改变 ，还是 数组cp的第三个元素地址。

	printf("%s\n", cpp[-1][-1] + 1);// 打印 EW
	// 对于 cpp[-1][-1] ，
	// cpp 先与 左边的[-1] 结合，有 cpp[-1] == *(cpp - 1) ，即 ++cpp 先 自减1 即 数组cp 的 第二个元素地址 ，也就是 "POINT"字符中首字符'P'的地址 的地址 的地址，
	//                                                               再 *解引用 取出 "POINT"字符中首字符'P'的地址 的地址，
	//     再与 右边的[-1] 结合，有 cpp[-1][-1] == *(*(cpp - 1) - 1) ,即 先跳到 "NEW"字符中首字符'N'的地址 的地址，
	//                                                                   再取出 "NEW"字符中首字符'N'的地址，
	// cpp[-1][-1] + 1 取出 "NEW"字符中首字符'E'的地址，
	// 
	// 然后使用 %s 打印，输出为 EW 。
	// 
	// cpp[-1][-1] == *(*(cpp - 1) - 1) ， cpp 并没有 被 重新赋值，还是 数组cp的第三个元素地址。


	// 注意：sizeof(表达式) 中的 表达式 不会 真正进行 运算 ，
	// 
	//       printf(表达式) 中的 表达式   会 真正进行 运算 。
	// 
	//                      但对于此题 要分清 哪些代码进行了 赋值操作 ，哪些没有，
	//                      如 cpp++; 或 cpp = cpp + 1; 就是进行了 赋值操作 ，改变了 cpp 的值，
	//                      而 cpp[2] ，相当于 *(cpp + 2) ，只是对 cpp 进行 解引用操作 ，并没有进行 赋值操作 ，所以 cpp 的值 不会改变。
	//

	return 0;
}


//#include <stdio.h>
//int main()
//{
//	char* a[] = { "work","at","school" };
//	// char* a = "abcdef"; 
//	// 这句代码说明 "abcdef" 是一个 常量字符串 ，
//	// 把 常量字符串 中 首字符'a' 的 地址 存入 指针p(char*类型) ，
//	// 内存中存了 'a' , 'b' , 'c' , 'd' , 'e' , 'f' , '\0' 一共 7 个字符。
//	// 
//	// 对于此题，
//	// char* a[] = { "work","at","school" };
//	// 这句代码说明将 "work","at","school" 这 3 个 常量字符串 的 首字符地址 存入 数组a 中，
//	// 即存了 "work"字符中首字符'w'的地址 ， "at"字符中首字符'a'的地址 ，"school"字符中首字符's'的地址 。
//
//	char** pa = a;
//	// a 是 数组名 ，即 数组的首元素地址 ，
//	// 而 数组a 的 每个元素 都是 char*类型 ，
//	// 想在 pa 中存入 char*类型的地址 ， pa 的类型需为 char** ，即 二级指针 ，
//	// 
//	// 这里的 pa 是 数组a的首元素地址 ，即 "work"字符 中 首字符'w' 的地址 的地址
//
//	pa++;
//	// 这里的 pa 是 a数组的首元素地址 ，
//	// pa++ == pa + 1 ，即跳过 1 个 char*类型 的 步长 ，
//	// 其中 char** 中 右边的* 说明是一个 指针 ， 左边的char* 说明是一个 char*类型的指针 ，
//	// 所以是跳过  1 个 char*类型 的 步长 ，即 数组a的第二个元素地址 
//
//	printf("%s\n", *pa);// 打印 at
//	// *pa 是对 数组a的第二个元素地址 进行解引用操作 ，即得到 "at"字符中首字符'a'的地址 ，
//	// 使用 %s 打印 字符串 ，需要对应放入 字符串的地址 ，且 打印遇到 '\0' 停止，
//	// 所以打印 at 。
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//    int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//
//    int* ptr1 = (int*)(&aa + 1);
//
//    int* ptr2 = (int*)(*(aa + 1));
//
//    printf("%d，%d\n", *(ptr1 - 1), *(ptr2 - 1)); // 打印 10，5
//    // 对于 *(ptr1 - 1) ，
//    // int* ptr1 = (int*)(&aa + 1); 中 &aa 取出的是 整个二维数组的地址 ，
//    // &aa + 1 跳过 1 个 整个二维数组类型 的 步长，即 二维数组末尾的地址 ，
//    // 因为 &aa 是 数组指针 ，同样 &aa + 1 还是 数组指针 ，要想存入 int* ptr1 中需要强制类型转换 (int*) 。
//    // *(ptr1 - 1) 中，
//    // ptr1 - 1 是从 二维数组末尾的地址 开始，往回跳 1 个 int*类型 的 步长，即 往回跳 4 个字节，相当于来到 二维数组aa[2][4]的地址 ，
//    // *(ptr1 - 1) 相当于对 二维数组aa[2][4]的地址 进行解引用操作 ，
//    // 所以输出结果为 10 。
//    // 
//    // 
//    // 对于 *(ptr2 - 1) ，
//    // int* ptr2 = (int*)(*(aa + 1)); 中 aa 是 二维数组的首元素地址 ，
//    // 即把 二维数组想象成一维数组之后 的 第一个元素地址，就是 二维数组 中 第一行 这个 一维数组 的 地址 ，
//    // aa + 1 是 二维数组的第二个元素地址 ，即 二维数组第二行的地址 ，
//    // *(aa + 1) 就是对 二维数组第二行的地址 进行 解引用操作 ，取出 二维数组第二行 这个 一维数组 ，
//    // 
//    // 因为 aa 是 二维数组首元素地址 ，这个地址 指向一个 一维数组 ，同样 &aa + 1 这个地址还是指向一个 一维数组 ，
//    // *(aa + 1) 相当于取出 二维数组第二行 这个 一维数组 ，
//    // 对于 二维数组而言有 *(aa + 1) == aa[1] ，而 aa[1] 相当于 第二行 这个一维数组 的 数组名 ，
//    // 除了 sizeof(数组名) 和 &数组名 以外，数组名 都是 数组 首元素地址 ，
//    // 对于此题 *(aa + 1) 本来就是 int*类型，
//    // 所以 (int*)(*(aa + 1)) 这个 强制类型转换(int*) 不起作用，有没有都可以。
//    // 
//    // *(ptr2 - 1) 中，
//    // ptr2 - 1 是从 二维数组第二行的地址 开始，往回跳 1 个 int*类型 的 步长，即 往回跳 4 个字节，相当于来到 二维数组aa[1][4]的地址 ，
//    // *(ptr2 - 1) 相当于对 二维数组aa[1][4]的地址 进行解引用操作 ，
//    // 所以输出结果为 5 。
//
//    return 0;
//}


//#include <stdio.h>
//int main()
//{
//    int a[5][5];
//
//    int(*p)[4];
//
//    p = a;
//    // p 和 a 都是 指针 ，即 一个地址 ，只是 指针 指向的 类型不同 ，
//    // 所以 a二维数组首元素地址 可以赋给 数组指针p ，
//    // 
//    // a 是 二维数组首元素地址 ，把二维数组看成一个一维数组，则 a 是一个 一维数组指针类型 ，即 int(* )[5] ，
//    // p 是 数组指针类型 ，即 int(* )[4] ，
//    // 所以会报警告。
//
//    printf("%d，%p\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]); // 32位平台打印 -4， FFFFFFFC
//                                                                  // 64位平台打印 -4， FFFFFFFF FFFFFFFC
//
//    // 对于 &a[4][2] ，
//    // 就是取出 二维数组a 中 第四行 第二列 元素 的 地址 。
//    // 
//    // 对于 &p[4][2] ，
//    // 首先， p 是 数组指针类型 ，则 *p 取出的是一个 数组 ，是 数组 就可以 *(*p) 取出 数组中的元素 ，
//    // 接着，我们知道 p[4][2] == *(*(p + 4) + 2) ,
//    // 而 *(*(p + 4) + 2) 中 p 存放了 二维数组a 的 首元素地址 ，且 p 的类型为  int(* )[4] ，
//    // 所以 p + 4 是指 从二维数组a的首元素地址 开始，跳过 4 个 int(* )[4]类型 的 步长，即跳过 4 * 4(int类型为4字节) = 16 个字节，
//    // (相当于来到 二维数组a[3][2] 的 地址)，
//    //    *(p + 4) 因为 p 是 数组指针int(* )[4]类型 ，则 *p 取出的是一个 4个元素的数组 ，
//    //             故 *(p + 4) 即从 该地址(相当于 二维数组a[3][2] 的地址) 向后取出 4个int类型的元素 作为 一个数组arr ，
//    //    *(p + 4) + 2 是指 数组arr 中 第三个元素 的 地址 ，(相当于 二维数组a[3][4] 的地址)，
//    //    *(*(p + 4) + 2) 则是 取出 数组arr 中 第三个元素 ，(相当于 取出 二维数组a[3][4] 的元素)，
//    // 最后，我们知道 &p[4][2] == &(*(*(p + 4) + 2)) ,相当于 取出 数组arr 中 第三个元素 的 地址 ，(相当于 二维数组a[3][4] 的地址)。
//    // 
//    // 
//    // 从之前的学习可知， 高地址 - 底地址 = 两个地址间元素的个数(整型) ，
//    // 
//    // 因为 地址&p[4][2] 比 地址&a[4][2] 低，且 两个地址之间 有 4 个元素 ，
//    // 所以， &p[4][2] - &a[4][2] = -4 ，
//    // 
//    // 使用 %d 打印的是整型十进制的值，即 -4 ，
//    // 
//    // 使用 %p 打印的是地址十六进制的值，打印用的是 内存中的补码 ，
//    // 这里 &p[4][2] - &a[4][2] = -4 ，
//    //    ( 32位平台为例 )
//    //       1000 0000 0000 0000 0000 0000 0000 0100   -   -4的原码
//    //       1111 1111 1111 1111 1111 1111 1111 1011   -   -4的反码
//    //       1111 1111 1111 1111 1111 1111 1111 1100   -   -4的补码
//    // 使用 %p 打印 用的是 内存中的补码 ，且输出 十六进制 ，
//    // 即 0x  F    F    F    F    F    F    F    C
//
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int a[3][2] = { (0, 1), (2, 3), (4, 5) };
//    // 这里是个坑，
//    // 正常的初始化应该是 { {0, 1}, {2, 3}, {4, 5} } ，
//    // 而这里初始化用的是 { (0, 1), (2, 3), (4, 5) } ，
//    // 这个一个 逗号表达式 ， 逗号表达式的结果 是 最后一个表达式的结果 ，
//    // 
//    // 所以这里初始化了 { 1, 3, 5 } ，即 { {1, 3}, {5, 0}, {0, 0} } 。
//
//    int* p;
//
//    p = a[0]; 
//    // 把 二维数组 想象成 一维数组 ，
//    // 即把 第一行 的 一维数组 的 地址 赋给 指针变量p 。
//
//    printf("%d\n", p[0]); // 打印 1
//    // 即 打印 二维数组中 第一行 第一列 的 值 。
//
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//    //此题 只能在 32位平台 运行
//    int a[4] = { 1, 2, 3, 4 };
//
//    int* ptr1 = (int*)(&a + 1);
//
//    int* ptr2 = (int*)((int)a + 1);
//
//    printf("%x，%x\n", ptr1[-1], *ptr2); // 只能在32位平台打印 4，2000000 ，64位平台报错
//    // %x 即输出 十六进制数
//    // 
//    // 对于 ptr1[-1] ,
//    // int* ptr1 = (int*)(&a + 1); 中 &a 取出 整个数组的地址 ，
//    // &a + 1 是指 跳过 1 个 整个数组类型 的 步长，即 数组末尾的地址 ，
//    // 因为 &a 是 数组指针 ，同样 &a + 1 还是 数组指针 ，要想存入 int* ptr1 中需要强制类型转换 (int*) 。
//    // 
//    // 则 ptr1 是 数组a末尾的地址 ，且是个 int*类型 的 指针 ，
//    // 所以 ptr - 1 是指 往后跳过 1 个 int类型 的 步长，即 数组中第四个元素的地址 ，
//    // *(ptr1 - 1) 是对 数组中第四个元素的地址 进行 解引用操作 ，取出 数组中第四个元素 ，即 4(十进制) 。
//    // 所以使用 十六进制打印 的是 4 。
//    //
//    // 
//    // 对于 *ptr2 ，
//    // int* ptr2 = (int*)((int)a + 1); 中 a 是 数组首元素的地址 ，是一个 数组指针 ，
//    // (int)a 将 首元素地址 强制类型转换成 int类型 ，即 将地址的 十六进制的值 转换成 十进制的值 ，
//    // (int)a + 1 将 转换成的 十进制的值 加1 ，
//    // (int*)((int)a + 1) 将 加1后的十进制的值 ，强制类型转换成 int*类型 ，即 将加1后的十进制的值 转换成 十六进制的值 ，表示成一个地址，
//    // 然后存放在 ptr2 中，
//    // 
//    // *ptr2 是对 加1后的十进制的值 转换成 十六进制的值 进行 解引用操作 ，
//    // 因为 该指针 是个 int*类型 的指针，解引用操作能 访问4个字节 ，
//    // 取出的值为 十六进制0x02000000 传换成 十进制的值 ，
//    // 所以使用 十六进制打印 的是 0x02000000 ，即 2000000
//
//    return 0;
//}

//#include <stdio.h>
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p; // 这里创建一个 结构体指针p
//
////假设p 的值为0x100000。 如下表表达式的值分别为多少？
////已知，结构体Test类型的变量大小是20个字节
//int main()
//{
//	p = (struct Test*)0x100000;		
//	// 给 p 附上假设的值，
//	// 因为 p 是一个 结构体类型指针 ，所以赋值时要把 整型十六进制数 强制类型转换成 (struct Test*)类型 。
//
//	printf("%p\n", p + 0x1); // 0x100014 ，即 32位平台打印 00100014 ，64位平台打印 00000000 00100014
//	// 加上一个 十六进制数 ，就等于 加上一个 该十六进制 对应的 十进制数 ，
//	// 即 0x1(十六进制) == 1(十进制) ，所以 p + 0x1 == p + 1 。
//	// 
//	// p 是一个 结构体指针 ，存了一个 地址 ，
//	// p + 0x1 == p + 1 是指 跳过 1 个 结构体Test类型 的 步长，即 跳过 20 个字节 之后的 地址 ，
//	// 而 20(十进制) == 14(十六进制) ，
//	// 所以 0x100000 + 20(十进制) == 0x100000 + 14(十六进制)  == 0x100014
//
//	printf("%p\n", (unsigned long)p + 0x1); // 0x100001 ，即 32位平台打印 00100001 ，64位平台打印 00000000 00100001
//	// p 中存了 0x100000 ，
//	// (unsigned long)p 将 十六进制100000 转换成 十进制长整型1048576 ，
//	// (unsigned long)p + 0x1 == (unsigned long)p + 1 对 十进制长整型1048576 加1 即值为 1048577 ，
//	// 使用 %p 打印 输出的是 十六进制 会把 十进制长整型1048577 转换成 十六进制0x100001 ，
//	// 所以为 0x100001
//
//	printf("%p\n", (unsigned int*)p + 0x1); // 0x100004 ，即 32位平台打印 00100004 ，64位平台打印 00000000 00100004
//	// p 是一个 结构体指针 ，存了一个 地址 ，
//	// 原本 p + 0x1 == p + 1 是 跳过 1 个 结构体Test类型 的 步长，即 跳过 20 个字节 之后的 地址 ，
//	// 
//	// 然而现在 p 被强制类型转换成 (unsigned int*)类型，
//	// 所以此时的 p + 0x1 == p + 1 是 跳过 1 个 (unsigned int*)类型 的 步长，即 跳过 4 个字节 之后的 地址 ，
//	// 
//	// (unsigned int*) 中的 * 说明这是一个 指针类型 ，
//	// 除去这个说明 指针类型 的 * ，剩下的 (unsigned int) 就是 该指针 指向的 类型 ，即 无符号整型的指针，
//	// 所以 跳过 1 个 (unsigned int*)类型 的 步长，就是跳过 unsigned int 的 4 个字节，( C语言规定 int类型长度为 4 个字节 )，
//	// 
//	// 而 4(十进制) == 4(十六进制) ，
//	// 所以 0x100000 + 4(十进制) == 0x100000 + 4(十六进制)  == 0x100004
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int a[5] = { 1, 2, 3, 4, 5 };
//
//    int* ptr = (int*)(&a + 1);
//
//    printf("%d，%d\n", *(a + 1), *(ptr - 1)); // 打印 2，5
//    // 对于 *(a + 1) ：
//    // 这里的 a 是指 数组中首元素 的 地址 ，
//    // a + 1 是指 跳过 1 个 数组中元素类型 的 步长，即 数组中第二个元素的地址 ，
//    // *(a + 1) 是对 数组中第二个元素的地址 进行 解引用操作 ，取出 数组中第二个元素 ，即 2 。
//    // 所以打印的是 2 。
//    // 
//    // 
//    // 对于 *(ptr - 1) ：
//    // int* ptr = (int*)(&a + 1); 中 &a 取出的是 整个数组的地址 ，
//    // &a + 1 是指 跳过 1 个 整个数组类型 的 步长，即 数组a末尾的地址 ，
//    // 因为 &a 是 数组指针 ，同样 &a + 1 还是 数组指针 ，要想存入 int* ptr 中需要强制类型转换 (int*) 。
//    // 
//    // 则 ptr 是 数组a末尾的地址 ，且是个 int*类型 的 指针 ，
//    // 所以 ptr - 1 是指 往后跳过 1 个 int类型 的 步长，即 数组中第五个元素的地址 ，
//    // *(ptr - 1) 是对 数组中第五个元素的地址 进行 解引用操作 ，取出 数组中第五个元素 ，即 5 。
//    // 所以打印的是 5 。
//
//    return 0;
//}


////二维数组
//#include <stdio.h>
//int main()
//{
//	int a[3][4] = { 0 };
//
//	printf("%d\n", sizeof(a)); //打印 48
//	// sizeof(a) ，即 sizeof(数组名) ，这里的 数组名 表示 整个数组 的 地址 ，
//	// 这里 sizeof() 计算的是 整个数组的大小 ，为 48 字节。
//	// 
//	// 整个数组的大小 = 二维数组中元素个数 * 元素的类型 ，即 48 = (3 * 4) * 4 。
//
//	printf("%d\n", sizeof(a[0][0])); //打印 4
//	// a[0][0] 即取出 二维数组中 第一行 第一列 的 元素，
//	// 而 二维数组中每个元素是 int类型 ，
//	// 这里 sizeof() 计算的是 二维数组中 第一行 第一列 的元素的大小 ，为 4 字节 。
//
//	printf("%d\n", sizeof(a[0])); //打印 16
//	// 我们知道 对于二维数组 a[i][j] ，就是取出二维数组中 第i行 第j列 的元素，
//	// 则 a[i] 就是取出 二维数组的每一行 ，
//	// 
//	// 把 二维数组 想象成一个 一维数组 ，
//	// 即 这个想象出来的一维数组的每一个元素 是 原来二维数组的每一行，
//	// 也就是 这个想象出来的一维数组的每一个元素 还是 一个一维数组，
//	// 
//	// 所以说 二维数组的每一行 又是一个 一维数组， a[i][j] 就是取出 对应一维数组 中的 第j个 元素，
//	// 我们可以把 a[i][j] 中的 a[i] 理解为 这个对应一维数组的 数组名，
//	// 
//	// sizeof(a[0]) ，即 sizeof(数组名) ，这里的 数组名 表示 整个数组 的 地址 ，
//	// 这里 sizeof() 计算的是 第一行这个对应一维数组的大小 ，为 16 字节。
//	// 
//	// 第一行这个对应一维数组的大小 = 二维数组中第一行的元素个数 * 元素的类型 ，即 16 = (1 * 4) * 4 。
//
//	printf("%d\n", sizeof(a[0] + 1)); //打印 4\8
//	// 从上一段代码的解析可知，可以把 a[i][j] 中的 a[i] 理解为 这个对应一维数组的 数组名，
//	// 
//	// 除 sizeof(数组名) 和 &数组名 之外，所有的数组名都表示 首元素的地址 ，
//	// sizeof(a[0] + 1) 中 a[0] 是 这个对应一维数组的 首元素地址 ， 地址 + - 整数 相当于跳过 该类型大小 的 步长 ，
//	// ( 地址 指向的 类型 是什么，就跳过 该类型大小 的 步长。如：指向 整个数组 的类型，就跳过 整个数组 ；指向 数组中元素 的类型，就跳过 数组中一个元素 )
//	// 此题 a[0] + 1 跳过 1 个 数组中元素类型(即 int类型) 的 步长 ，即 二维数组中 第一行 第二列 的元素的 地址 ，
//	// 这里 sizeof() 计算的是 地址的大小 ，为  4\8 字节 。
//
//	printf("%d\n", sizeof(*(a[0] + 1))); //打印 4
//	// 从上上一段代码的解析可知，可以把 a[i][j] 中的 a[i] 理解为 这个对应一维数组的 数组名，
//	// 
//	// 除 sizeof(数组名) 和 &数组名 之外，所有的数组名都表示 首元素的地址 ，
//	// sizeof(a[0] + 1) 中 a[0] 是 这个对应一维数组的 首元素地址 ， 地址 + - 整数 相当于跳过 该类型大小 的 步长 ，
//	// ( 地址 指向的 类型 是什么，就跳过 该类型大小 的 步长。如：指向 整个数组 的类型，就跳过 整个数组 ；指向 数组中元素 的类型，就跳过 数组中一个元素 )
//	// 此题 a[0] + 1 跳过 1 个 数组中元素类型(即 int类型) 的 步长 ，即 二维数组中 第一行 第二列 的元素的 地址 ，
//	// 
//	// *(a[0] + 1) 即对 二维数组中 第一行 第二列 的元素的地址 进行 解引用操作 ，取出 二维数组中 第一行 第二列 的元素，
//	// 而 数组中每个元素是 int类型 ，
//	// 这里 sizeof() 计算的是 数组中第一个元素类型的大小 ，为 4 字节 。
//
//	printf("%d\n", sizeof(a + 1)); //打印 4\8
//	// 除 sizeof(数组名) 和 &数组名 之外，所有的数组名都表示 首元素的地址 ，
//	// sizeof(a + 1) 中 a 是 这个二维数组的 首元素地址 ， 地址 + - 整数 相当于跳过 该类型大小 的 步长 ，
//	// ( 地址 指向的 类型 是什么，就跳过 该类型大小 的 步长。如：指向 整个数组 的类型，就跳过 整个数组 ；指向 数组中元素 的类型，就跳过 数组中一个元素 )
//	// 
//	// 把 二维数组 想象成一个 一维数组 ，
//	// 即 这个想象出来的一维数组的每一个元素 是 原来二维数组的每一行，
//	// 也就是 这个想象出来的一维数组的每一个元素 还是 一个一维数组，
//	// 
//	// 此题 a + 1 跳过 1 个 这个想象出来的一维数组元素类型(即 一维数组类型) 的 步长 ，即 二维数组中 第二行 的元素的 地址 ，
//	// 这里 sizeof() 计算的是 地址的大小 ，为  4\8 字节 。
//
//	printf("%d\n", sizeof(*(a + 1))); //打印 16
//	// 从上一段代码的解析可知，a + 1 就是 二维数组中 第二行 的元素的 地址 ，
//	// 
//	// *(a + 1) 即对 二维数组中 第二行 的地址 进行 解引用操作 ，取出 二维数组中整个第二行 ，是一个一维数组，
//	// 这里 sizeof() 计算的是 二维数组中整个第二行 的大小 ，为 16 字节。
//	// 
//	// 二维数组中整个第二行 = 二维数组中第二行的元素个数 * 元素的类型 ，即 16 = (1 * 4) * 4 。
//	//
//	// *(a + 1) == a[1]
//
//	printf("%d\n", sizeof(&a[0] + 1)); //打印 4\8
//	// 由上面代码的解析可知，可以把 a[i][j] 中的 a[i] 理解为 这个对应一维数组的 数组名，
//	// 
//	// &a[i] 就相当于 &数组名 ，取出的是 这个对应一维数组 整个数组的地址 ，
//	// 
//	// 地址 + - 整数 相当于跳过 该类型大小 的 步长 ，
//	// ( 地址 指向的 类型 是什么，就跳过 该类型大小 的 步长。如：指向 整个数组 的类型，就跳过 整个数组 ；指向 数组中元素 的类型，就跳过 数组中一个元素 )
//	// 此题 &a[0] + 1 跳过 1 个 一维数组类型(即 跳过整个数组) 的 步长 ，即 二维数组中 第二行 地址 ，
//	// 这里 sizeof() 计算的是 地址的大小 ，为  4\8 字节 。
//
//	printf("%d\n", sizeof(*(&a[0] + 1))); //打印 16
//	// 从上一段代码的解析可知， &a[0] + 1 就是 二维数组中 第二行 地址 ，
//	// 
//	// *(&a[0] + 1) 即对 二维数组中 第二行 的地址 进行 解引用操作 ，取出 二维数组中整个第二行 ，是一个一维数组，
//	// 这里 sizeof() 计算的是 二维数组中整个第二行 的大小 ，为 16 字节。
//	// 
//	// 二维数组中整个第二行 = 二维数组中第二行的元素个数 * 元素的类型 ，即 16 = (1 * 4) * 4 。
//
//	printf("%d\n", sizeof(*a)); //打印 16
//	// *a == *(a + 0) ，跟上面 *(a + 1) 的解析类似，
//	//
//	// 除 sizeof(数组名) 和 &数组名 之外，所有的数组名都表示 首元素的地址 ，
//	// sizeof(*a) 中 a 是 这个二维数组的 首元素地址 ，
//	// 
//	// 把 二维数组 想象成一个 一维数组 ，
//	// 即 这个想象出来的一维数组的每一个元素 是 原来二维数组的每一行，
//	// 也就是 这个想象出来的一维数组的每一个元素 还是 一个一维数组，
//	// 
//	// *a == *(a + 0) 即对 二维数组中 第一行 的地址 进行 解引用操作 ，取出 二维数组中整个第一行 ，是一个一维数组，
//	// 这里 sizeof() 计算的是 二维数组中整个第一行 的大小 ，为 16 字节。
//	// 
//	// 二维数组中整个第一行 = 二维数组中第一行的元素个数 * 元素的类型 ，即 16 = (1 * 4) * 4 。
//
//	printf("%d\n", sizeof(a[3])); //打印 16
//	// 这段代码是正确的
//	//
//	// sizeof()函数 括号中的 表达式 是不会真正进行计算的，
//	// 
//	// 所以这里的 sizeof(a[3]) 是不会真正去访问 该二维数组的第四行，
//	// 只是 根据类型计算大小 ，
//	// 
//	// 这里 sizeof() 计算的是 二维数组的一行 对应一维数组类型 的大小 ，为 16 字节。
//	// 
//	// 二维数组的一行 对应一维数组类型 = 二维数组中一行的元素个数 * 元素的类型 ，即 16 = (1 * 4) * 4 。
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	char* p = "abcdef";
//	// 这段代码的意思是 "abcdef" 是 常量字符串 ，
//	// 把 常量字符串"abcdef" 第一个字符 的 地址 存到 p 中。
//	// 所以 p 是一个为 char类型 的 指针变量 。
//	//
//	// 是 字符串 就有 '\0'字符串结束标志 ，
//	// 所以内存中存了 'a','b','c','d','e','f','\0' 一共 7 个字符 
//
//	printf("%d\n", strlen(p)); //打印 6
//	// 这里的 p 存了 第一个字符的地址 ，
//	// strlen(p) 即从 这个常量字符串 的 第一个字符'a' 开始往后计算，
//	// 
//	// strlen()库函数 求 字符串 长度 ，需要找到 '\0'字符串结束标志 才停止计算，其中 '\0' 不算进长度里，
//	// 而此处的 常量字符串 中 存在 '\0' ，计算机 找到 '\0' 停止，而 '\0' 之前有 6 个字符，
//	// 即该 字符串长度 为 6 个字节，所以输出的是 6 。
//	
//	printf("%d\n", strlen(p + 1)); //打印 5
//	// p 存了 第一个字符的地址 ，地址 + - 整数 相当于跳过 该类型大小 的 步长 ，
//	// 此题 p + 1 跳过 1 个 字符类型类型(即 char类型) 的 步长 ，即 'b'第二个字符的地址 ，
//	// strlen(p) 即从 这个常量字符串 的 第二个字符'b' 开始往后计算，
//	// 
//	// strlen()库函数 求 字符串 长度 ，需要找到 '\0'字符串结束标志 才停止计算，其中 '\0' 不算进长度里，
//	// 而此处的 常量字符串 中 存在 '\0' ，现在要从 这个常量字符串 的 第二个字符'b' 开始往后计算，计算机 找到 '\0' 停止，
//	// 则 '\0' 之前有 6-1 个字符，所以输出的是 5 。
//	
//	printf("%d\n", strlen(*p)); //(报错) 
//	// 这里的 p 存了 第一个字符的地址 ， *p 即对 第一个字符的地址 进行 解引用操作 ，找到 第一个字符 即 'a' ，
//	// 即把 'a'字符 当作参数 传给 strlen()库函数 ，而 'a'字符 的 ASCII码值 为 97 ，
//	// 
//	// 相当于给 strlen()库函数 传了一个 97的值 ，而 strlen()库函数 的 参数 要求填入一个 地址 ，
//	// strlen()库函数 会把 97这个值 当作一个地址 ，然后从这个 错误的地址 开始向后计算，
//	// 
//	// 这是非法访问内存，而这也是一种错误的写法，会引起程序崩溃。
//	
//	printf("%d\n", strlen(p[0])); //(报错)
//	//// 数组名arr[i] == *(数组名arr + i) == *(该指针p + i) == 该指针p[i]
//	// 推广到： *(指针p + i) == 指针p[i]
//	// p[0] == *(p + 0) == *p ，即取出 常量字符串 中 第一个字符 即 'a' ，
//	// 
//	// 即把 'a'字符 当作参数 传给 strlen()库函数 ，而 'a'字符 的 ASCII码值 为 97 ，
//	// 
//	// 相当于给 strlen()库函数 传了一个 97的值 ，而 strlen()库函数 的 参数 要求填入一个 地址 ，
//	// strlen()库函数 会把 97这个值 当作一个地址 ，然后从这个 错误的地址 开始向后计算，
//	// 
//	// 这是非法访问内存，而这也是一种错误的写法，会引起程序崩溃。
//	
//	printf("%d\n", strlen(&p)); //打印 随机值
//	// 这里的 p 存了 第一个字符的地址 ，
//	// &p 即 第一个字符的地址 的 地址 ，是一个 二级指针 ，
//	// 所以相当于从 第一个字符的地址 的 地址 开始往后计算，
//    //
//	// strlen()库函数 求 字符串 长度 ，需要找到 '\0'字符串结束标志 才停止计算，其中 '\0' 不算进长度里，
//	// 而对于从 第一个字符的地址 的 地址 开始往后计算了 多少个字符长度 以后 才找到 '\0' ，这个是未知的，
//	// 所以输出的是 随机值 。
//	
//	printf("%d\n", strlen(&p + 1)); //打印 随机值
//	// 这里的 p 存了 第一个字符的地址 ，
//	// &p 即 第一个字符的地址 的 地址 ，是一个 二级指针 ，
//	// 
//	// 地址 + - 整数 相当于跳过 该类型大小 的 步长 ，
//	// 此题 &p + 1 跳过 1 个 二级指针类型(即 char**类型) 的 步长 ，
//	// 即 跳过这个二级指针 以后的 地址 ，
//	// 值得注意的是 char**类型 是个 指针 ，跳过 1 个 char**类型 的 步长 ，即跳过 4\8 个字节，
//	//
//	// strlen()库函数 求 字符串 长度 ，需要找到 '\0'字符串结束标志 才停止计算，其中 '\0' 不算进长度里，
//	// 而对于从 跳过这个二级指针 以后的 地址 开始往后计算了 多少个字符长度 以后 才找到 '\0' ，这个是未知的，
//	// 所以输出的是 随机值 。
//	//
//	// 对于此题：
//	// strlen(&p) 和 strlen(&p + 1) 由这两个产生的 随机值 没有明确的数量关系，
//	// 可以理解为 strlen() 是 逐个字符 计算的，即 一次访问 1 个字节 ，
//	// 而 &p 和 &p + 1 都是 地址 ，即 是一个 指针 ，为 4\8 个字节，即 &p 与 &p + 1 之间 相差 4或8 个字节，
//	// 若 &p 与 &p + 1 之间 有 '\0' ，
//	// 则 strlen(&p) 计算到这个 '\0' 就停止了 ，而 strlen(&p + 1) 计算到哪停止，要看 &p + 1 以后的 '\0' 在哪，
//	// 若 &p 与 &p + 1 之间 没有有 '\0' ，
//	// 则 &p 与 &p + 1 都是计算到  &p + 1 以后的 '\0' 停止，
//	//    但 strlen(&p) 比 strlen(&p + 1) 多计算 &p 与 &p + 1 之间 相差 4或8 个字节 ,即多计算 4或8 个字符，
//	//    这样的情况下，strlen(&p)的随机值 = strlen(&p + 1)的随机值 + 4或8
//	
//	printf("%d\n", strlen(&p[0] + 1)); //打印 5
//	// [] 的优先级高于 & ，所以 arr 先与 [0] 结合，即取出 常量字符串 中 第一个字符 即 'a' ，
//	// 然后再与 & 结合 ，即 取出 第一个字符 的 地址 ，
//	// 而 地址 + - 整数 相当于跳过 该类型大小 的 步长 ，
//	// 此题 &p[0] + 1 跳过 1 个 字符类型类型(即 char类型) 的 步长 ，即 'b'第二个字符的地址 ，
//	// strlen(p) 即从 这个常量字符串 的 第二个字符'b' 开始往后计算，
//	// 
//	// strlen()库函数 求 字符串 长度 ，需要找到 '\0'字符串结束标志 才停止计算，其中 '\0' 不算进长度里，
//	// 而此处的 常量字符串 中 存在 '\0' ，现在要从 这个常量字符串 的 第二个字符'b' 开始往后计算，计算机 找到 '\0' 停止，
//	// 则 '\0' 之前有 6-1 个字符，所以输出的是 5 。
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	char* p = "abcdef";
//	// 这段代码的意思是 "abcdef" 是 常量字符串 ，
//	// 把 常量字符串"abcdef" 第一个字符 的 地址 存到 p 中。
//	// 所以 p 是一个为 char类型 的 指针变量 。
//	//
//	// 是 字符串 就有 '\0'字符串结束标志 ，
//	// 所以内存中存了 'a','b','c','d','e','f','\0' 一共 7 个字符 
//
//	printf("%d\n", sizeof(p)); //打印 4\8
//	// p 存了 第一个字符的地址 ，是一个 指针变量 ，
//	// 这里 sizeof() 计算的是 指针变量(即地址)的大小 ，为 4\8 字节 。
//
//	printf("%d\n", sizeof(p + 1)); //打印 4\8
//    // p 存了 第一个字符的地址 ，地址 + - 整数 相当于跳过 该类型大小 的 步长 ，
//	// 此题 p + 1 跳过 1 个 字符类型类型(即 char类型) 的 步长 ，即 'b'第二个字符的地址 ，
//	// 这里 sizeof() 计算的是 指针变量(即地址)的大小 ，为 4\8 字节 。
//
//	printf("%d\n", sizeof(*p)); //打印 1
//	// 这里的 p 存了 第一个字符的地址 ， 
//	// *p 即对 第一个字符的地址 进行 解引用操作 ，找到 第一个字符 即 'a' ，
//	// 而 常量字符串 中 每个字符 为 char类型 ，
//	// 这里 sizeof() 计算的是 第一个字符的大小 ，即计算 char类型的大小 ，为 1 字节 。
//
//	printf("%d\n", sizeof(p[0])); //打印 1
//	// 数组名arr[i] == *(数组名arr + i) == *(该指针p + i) == 该指针p[i]
//	// 推广到： *(指针p + i) == 指针p[i]
//	//
//	// p[0] == *(p + 0) == *p ，即取出 常量字符串 中 第一个字符 即 'a' ，
//	// 而 常量字符串 中 每个字符 为 char类型 ，
//	// 这里 sizeof() 计算的是 第一个字符的大小 ，即计算 char类型的大小 ，为 1 字节 。 
//
//	printf("%d\n", sizeof(&p)); //打印 4\8
//	// 这里的 p 存了 第一个字符的地址 ，
//	// &p 即 第一个字符的地址 的 地址 ，是一个 二级指针 ，
//	// 这里 sizeof() 计算的是 二级 指针(即地址)的大小 ，为 4\8 字节 。
//
//	printf("%d\n", sizeof(&p + 1)); //打印 4\8
//	// 这里的 p 存了 第一个字符的地址 ，
//	// &p 即 第一个字符的地址 的 地址 ，是一个 二级指针 ，
//	// 
//	// 地址 + - 整数 相当于跳过 该类型大小 的 步长 ，
//	// 此题 &p + 1 跳过 1 个 二级指针类型(即 char**类型) 的 步长 ，
//	// 即 跳过这个二级指针 以后的 地址 ，
//	// 值得注意的是 char**类型 是个 指针 ，跳过 1 个 char**类型 的 步长 ，即跳过 4\8 个字节，
//	// 
//	// 这里 sizeof() 计算的是 二级 指针(即地址)的大小 ，为 4\8 字节 。
//
//	printf("%d\n", sizeof(&p[0] + 1)); //打印 4\8
//	// [] 的优先级高于 & ，所以 arr 先与 [0] 结合，即取出 常量字符串 中 第一个字符 即 'a' ，
//	// 然后再与 & 结合 ，即 取出 第一个字符 的 地址 ，
//	// 而 地址 + - 整数 相当于跳过 该类型大小 的 步长 ，
//	// 此题 &p[0] + 1 跳过 1 个 字符类型类型(即 char类型) 的 步长 ，即 'b'第二个字符的地址 ，
//	// 这里 sizeof() 计算的是 指针变量(即地址)的大小 ，为 4\8 字节 。
//
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr[] = "abcdef";
//	// 这是 字符串 ，不是 字符数组 ，
//	// 
//	// 字符串 ，即 char arr[] = "abcdef" ，没有输入 '\0' ，但是自带 '\0'字符串结束标志 ，
//	// 在内存中存储了 'a','b','c','d','e','f','\0' ，一共 7 个元素。
//	// 
//	// 字符数组 ，如 char arr[] = { 'a','b','c','d','e','f' } ，不自带 '\0' ，需要的时候要自己加上，
//	// 在内存中存储了 'a','b','c','d','e','f' ，一共 6 个元素。
//
//	printf("%d\n", strlen(arr)); //打印 6
//	// 这里的 arr 是 数组首元素地址 ，即从 这个数组的首元素 开始往后计算，
//	// 
//	// strlen()库函数 求 字符串 长度 ，需要找到 '\0'字符串结束标志 才停止计算，其中 '\0' 不算进长度里，
//	// 而此处的 arr字符数组 中 存在 '\0' ，计算机 找到 '\0' 停止，而 '\0' 之前有 6 个元素，
//	// 即该 字符串长度 为 6 个字节，所以输出的是 6 。
//
//	printf("%d\n", strlen(arr + 0)); //打印 6
//	// 这里的 arr 是 数组首元素地址 ，即从 这个数组的首元素 开始往后计算，
//	// 
//	// strlen()库函数 求 字符串 长度 ，需要找到 '\0'字符串结束标志 才停止计算，其中 '\0' 不算进长度里，
//	// 而此处的 arr字符数组 中 存在 '\0' ，计算机 找到 '\0' 停止，而 '\0' 之前有 6 个元素，
//	// 即该 字符串长度 为 6 个字节，所以输出的是 6 。
//
//	printf("%d\n", strlen(*arr)); //(报错)
//	// 这里的 arr 是 数组首元素地址 ， *arr 为取出 数组中第一个元素'a' ，
//	// 即把 'a'字符 当作参数 传给 strlen()库函数 ，而 'a'字符 的 ASCII码值 为 97 ，
//	// 
//	// 相当于给 strlen()库函数 传了一个 97的值 ，而 strlen()库函数 的 参数 要求填入一个 地址 ，
//	// strlen()库函数 会把 97这个值 当作一个地址 ，然后从这个 错误的地址 开始向后计算，
//	// 
//	// 这是非法访问内存，而这也是一种错误的写法，会引起程序崩溃。
//
//	printf("%d\n", strlen(arr[1])); //(报错)
//	// a[1] 即 取出 第二个元素 即 'b'
//	// 即把 'b'字符 当作参数 传给 strlen()库函数 ，而 'b'字符 的 ASCII码值 为 98 ，
//	// 
//	// 相当于给 strlen()库函数 传了一个 98的值 ，而 strlen()库函数 的 参数 要求填入一个 地址 ，
//	// strlen()库函数 会把 98这个值 当作一个地址 ，然后从这个 错误的地址 开始向后计算，
//	// 
//	// 这是非法访问内存，而这也是一种错误的写法，会引起程序崩溃。
//
//	printf("%d\n", strlen(&arr)); //打印 6
//	// &arr ，即 &数组名 ，这里的 数组名 表示 整个数组 的 地址 ，
//	// 整个数组的地址 跟 首元素的地址 是 一样的 ，只是性质不同，
//	// 所以相当于从 这个数组的首元素 开始往后计算，
//	// 
//	// strlen()库函数 求 字符串 长度 ，需要找到 '\0'字符串结束标志 才停止计算，其中 '\0' 不算进长度里，
//	// 而此处的 arr字符数组 中 存在 '\0' ，计算机 找到 '\0' 停止，而 '\0' 之前有 6 个元素，
//	// 即该 字符串长度 为 6 个字节，所以输出的是 6 。
//	//
//	// 虽然值是 6 ，但是会有一些警报出现，
//	// 因为 &arr ，即 &数组名 ，这里的 数组名 表示 整个数组的地址 ，数组的地址 存放在 数组指针中，
//	// 即用 int (* )[7]类型 存放，
//	// 而 strlen()库函数 的 参数 要求填入一个 地址 ，这个地址 是一个 字符地址 ，
//	// 即用 const char* 存放，
//	// 因为 这两个地址 的 值 是 一样的 ，strlen()库函数 在使用这个地址时 将 int (* )[7] 转换为 const char* 照样能用，
//	// 只不过会报 类型不同 的警告。
//
//	printf("%d\n", strlen(&arr + 1)); //打印 随机值
//	// &arr ，即 &数组名 ，这里的 数组名 表示 整个数组 的 地址 ，
//	// 而 地址 + - 整数 相当于跳过 该类型大小 的 步长 ，
//	// 此题 &arr + 1 跳过 1 个 数组类型大小 的 步长 ，即 跳过这个数组 以后的 地址 ，
//	// 所以相当于从 跳过这个数组以后的地址 开始往后计算，
//	//
//	// strlen()库函数 求 字符串 长度 ，需要找到 '\0'字符串结束标志 才停止计算，其中 '\0' 不算进长度里，
//	// 虽然 此处的 arr字符数组 中 存在 '\0' ，但却是从 跳过这个数组以后的地址 开始往后计算，
//	// 而对于 该数组 往后 计算了 多少个字符长度 以后 才找到 '\0' ，这个是未知的，
//	// 所以输出的是 随机值 。
//
//	printf("%d\n", strlen(&arr[0] + 1)); //打印 5
//	// [] 的优先级高于 & ，所以 arr 先与 [0] 结合，即 取出 第一个元素 即 'a' ，
//	// 然后再与 & 结合 ，即 取出 第一个元素 的 地址 ，
//	// 而 地址 + - 整数 相当于跳过 该类型大小 的 步长 ，
//	// 此题 &arr + 1 跳过 1 个 数组中元素类型(即 char类型) 的 步长 ，即 数组中第二个元素的地址 ，
//	// 所以相当于从 数组中第二个元素的地址 开始往后计算，
//	// 
//	// strlen()库函数 求 字符串 长度 ，需要找到 '\0'字符串结束标志 才停止计算，其中 '\0' 不算进长度里，
//	// 而此处的 arr字符数组 中 存在 '\0' ，现在要从 数组中第二个元素的地址 开始往后计算，计算机 找到 '\0' 停止，
//	// 则 '\0' 之前有 6-1 个元素，所以输出的是 5 。
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	char arr[] = "abcdef";
//	// 这是 字符串 ，不是 字符数组 ，
//	// 
//	// 字符串 ，即 char arr[] = "abcdef" ，没有输入 '\0' ，但是自带 '\0'字符串结束标志 ，
//	// 在内存中存储了 'a','b','c','d','e','f','\0' ，一共 7 个元素。
//	// 
//	// 字符数组 ，如 char arr[] = { 'a','b','c','d','e','f' } ，不自带 '\0' ，需要的时候要自己加上，
//	// 在内存中存储了 'a','b','c','d','e','f' ，一共 6 个元素。
//
//	printf("%d\n", sizeof(arr)); //打印 7
//	// sizeof(arr) ，即 sizeof(数组名) ，这里的 数组名 表示 整个数组 的 地址 ，
//	// 这里 sizeof() 计算的是 整个数组的大小 ，为 7 字节 ，
//	// 
//	// 有 'a','b','c','d','e','f','\0' 一共 7 个元素，
//	// 整个数组的大小 = 数组中元素个数 * 元素类型的大小 ，即 7 = 7 * 1 。
//
//	printf("%d\n", sizeof(arr + 0)); //打印 4\8
//	// 除 sizeof(数组名) 和 &数组名 之外，所有的数组名都表示 首元素的地址 ，
//	// sizeof(arr + 0) 中 arr 是 数组首元素地址 ， 地址 + - 整数 相当于跳过 该类型大小 的 步长 ，
//	// 此题 arr + 0 跳过 0 个 数组中元素类型(即 char类型) 的 步长 ，还是 首元素的地址 ，
//	// 这里 sizeof() 计算的是 地址的大小 ，为  4\8 字节 。
//
//	printf("%d\n", sizeof(*arr)); //打印 1
//	// 这里的 arr 是 数组首元素地址 ， 
//	// *arr 即对 数组首元素地址 进行 解引用操作 ，取出 第一个元素 即 'a' ，
//	// 而 数组中每个元素是 char类型 ，
//	// 这里 sizeof() 计算的是 数组中第一个元素类型的大小 ，为 1 字节 。
//
//	printf("%d\n", sizeof(arr[1])); //打印 1
//	// a[1] 即 取出 第二个元素 即 'b' ，
//	// 而 数组中每个元素是 char类型 ，
//	// 这里 sizeof() 计算的是 数组中第二个元素类型的大小 ，为 1 字节 。
//	//
//	// arr[1] == *(arr + 1)
//
//	printf("%d\n", sizeof(&arr)); //打印 4\8
//	// &arr ，即 &数组名 ，这里的 数组名 表示 整个数组 的 地址 ，
//	// 这里 sizeof() 计算的是 地址的大小 ，为  4\8 字节 。
//	
//	printf("%d\n", sizeof(&arr + 1)); //打印 4\8
//	// &arr ，即 &数组名 ，这里的 数组名 表示 整个数组 的 地址 ，
//	// 而 地址 + - 整数 相当于跳过 该类型大小 的 步长 ，
//	// 此题 &arr + 1 跳过 1 个 数组类型大小 的 步长 ，即 跳过这个数组 以后的 地址 ，
//	// 这里 sizeof() 计算的是 地址的大小 ，为  4\8 字节 。
//	
//	printf("%d\n", sizeof(&arr[0] + 1)); //打印 4\8
//	// [] 的优先级高于 & ，所以 arr 先与 [0] 结合，即 取出 第一个元素 即 'a' ，
//	// 然后再与 & 结合 ，即 取出 第一个元素 的 地址 ，
//	// 而 地址 + - 整数 相当于跳过 该类型大小 的 步长 ，
//	// 此题 &arr + 1 跳过 1 个 数组中元素类型(即 char类型) 的 步长 ，即 数组中第二个元素的地址 ，
//	// 这里 sizeof() 计算的是 地址的大小 ，为  4\8 字节 。
//
//	return 0;
//}

//#include <stdio.h>
//#include  <string.h>
//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	// 这是 字符数组 ，不是 字符串 ，
//	// 
//	// 字符数组 ，如 char arr[] = { 'a','b','c','d','e','f' } ，不自带 '\0' ，需要的时候要自己加上，
//	// 在内存中存储了 'a','b','c','d','e','f' ，一共 6 个元素。
//	// 
//	// 字符串 ，即 char arr[] = "abcdef" ，没有输入 '\0' ，但是自带 '\0'字符串结束标志 ，
//	// 在内存中存储了 'a','b','c','d','e','f','\0' ，一共 7 个元素。
//
//	printf("%d\n", strlen(arr)); //打印 随机值
//	// 这里的 arr 是 数组首元素地址 ，即从 这个数组的首元素 开始往后计算，
//	// 
//	// strlen()库函数 求 字符串 长度 ，需要找到 '\0'字符串结束标志 才停止计算，
//	// 而此处的 arr字符数组 中 没有 '\0' ，计算机 会一直往后计算，直到找到 '\0' 才停止，
//	// 而对于 计算了 多少个字符长度 以后 才找到 '\0' ，这个是未知的，
//	// 所以输出的是 随机值 。
//
//	printf("%d\n", strlen(arr + 0)); //打印 随机值
//	// 这里的 arr 是 数组首元素地址 ，地址 + - 整数 相当于跳过 该类型大小 的 步长 ，
//	// 此题 arr + 0 跳过 0 个 数组中元素类型(即 char类型) 的 步长 ，还是 首元素的地址 ，
//    // 即从 这个数组的首元素 开始往后计算，
//	// 
//	// strlen()库函数 求 字符串 长度 ，需要找到 '\0'字符串结束标志 才停止计算，
//	// 而此处的 arr字符数组 中 没有 '\0' ，计算机 会一直往后计算，直到找到 '\0' 才停止，
//	// 而对于 计算了 多少个字符长度 以后 才找到 '\0' ，这个是未知的，
//	// 所以输出的是 随机值 。
//
//	printf("%d\n", strlen(*arr)); //(报错)
//	// 这里的 arr 是 数组首元素地址 ， *arr 为取出 数组中第一个元素'a' ，
//	// 即把 'a'字符 当作参数 传给 strlen()库函数 ，而 'a'字符 的 ASCII码值 为 97 ，
//	// 
//	// 相当于给 strlen()库函数 传了一个 97的值 ，而 strlen()库函数 的 参数 要求填入一个 地址 ，
//	// strlen()库函数 会把 97这个值 当作一个地址 ，然后从这个 错误的地址 开始向后计算，
//	// 
//	// 这是非法访问内存，而这也是一种错误的写法，会引起程序崩溃。
//
//	printf("%d\n", strlen(arr[1])); //(报错)
//	// a[1] 即 取出 第二个元素 即 'b'
//	// 即把 'b'字符 当作参数 传给 strlen()库函数 ，而 'b'字符 的 ASCII码值 为 98 ，
//	// 
//	// 相当于给 strlen()库函数 传了一个 98的值 ，而 strlen()库函数 的 参数 要求填入一个 地址 ，
//	// strlen()库函数 会把 98这个值 当作一个地址 ，然后从这个 错误的地址 开始向后计算，
//	// 
//	// 这是非法访问内存，而这也是一种错误的写法，会引起程序崩溃。
//
//	printf("%d\n", strlen(&arr)); //打印 随机值
//	// &arr ，即 &数组名 ，这里的 数组名 表示 整个数组 的 地址 ，
//	// 整个数组的地址 跟 首元素的地址 是 一样的 ，只是性质不同，
//	// 所以相当于从 这个数组的首元素 开始往后计算，
//	// 
//	// strlen()库函数 求 字符串 长度 ，需要找到 '\0'字符串结束标志 才停止计算，
//	// 而此处的 arr字符数组 中 没有 '\0' ，计算机 会一直往后计算，直到找到 '\0' 才停止，
//	// 而对于 计算了 多少个字符长度 以后 才找到 '\0' ，这个是未知的，
//	// 所以输出的是 随机值 。
//
//	printf("%d\n", strlen(&arr + 1)); //打印 随机值-6
//	// &arr ，即 &数组名 ，这里的 数组名 表示 整个数组 的 地址 ，
//	// 而 地址 + - 整数 相当于跳过 该类型大小 的 步长 ，
//	// 此题 &arr + 1 跳过 1 个 数组类型大小 的 步长 ，即 跳过这个数组 以后的 地址 ，
//	// 所以相当于从 跳过这个数组以后的地址 开始往后计算，
//	// 
//	// strlen()库函数 求 字符串 长度 ，需要找到 '\0'字符串结束标志 才停止计算，
//	// 而此处的 arr字符数组 中 没有 '\0' ，计算机 会一直往后计算，直到找到 '\0' 才停止，
//	// 而对于 计算了 多少个字符长度 以后 才找到 '\0' ，这个是未知的，会输出一个 随机值 ，
//	// 
//	// 但是我们知道 arr字符数组 中 没有 '\0' ，
//	// 故这个 随机值 的计算中 一定包含了 arr字符数组 中的 6 个元素 ，
//	// 而我们又是从 跳过这个数组以后的地址 开始往后计算，
//	// 所以会比 上面代码中 从 这个数组的首元素 开始往后计算 所产生的 随机值 少 6 (少计算整个数组的6个元素)，
//	// 即输出的是 随机值-6 。
//
//	printf("%d\n", strlen(&arr[0] + 1)); //打印 随机值-1
//	// [] 的优先级高于 & ，所以 arr 先与 [0] 结合，即 取出 第一个元素 即 'a' ，
//	// 然后再与 & 结合 ，即 取出 第一个元素 的 地址 ，
//	// 而 地址 + - 整数 相当于跳过 该类型大小 的 步长 ，
//	// 此题 &arr + 1 跳过 1 个 数组中元素类型(即 char类型) 的 步长 ，即 数组中第二个元素的地址 ，
//	// 所以相当于从 数组中第二个元素的地址 开始往后计算，
//	// 
//	// strlen()库函数 求 字符串 长度 ，需要找到 '\0'字符串结束标志 才停止计算，
//	// 而此处的 arr字符数组 中 没有 '\0' ，计算机 会一直往后计算，直到找到 '\0' 才停止，
//	// 而对于 计算了 多少个字符长度 以后 才找到 '\0' ，这个是未知的，会输出一个 随机值 ，
//	// 
//	// 但是我们知道 arr字符数组 中 没有 '\0' ，
//	// 故这个 随机值 的计算中 一定包含了 arr字符数组 中的 6 个元素 ，
//	// 而我们又是从 数组中第二个元素的地址 开始往后计算，
//	// 所以会比 上面代码中 从 这个数组的首元素 开始往后计算 所产生的 随机值 少 1 (少计算数组的第一个元素)，
//	// 即输出的是 随机值-1 。
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	// 这是 字符数组 ，不是 字符串 ，
//	// 
//	// 字符数组 ，如 char arr[] = { 'a','b','c','d','e','f' } ，不自带 '\0' ，需要的时候要自己加上，
//	// 在内存中存储了 'a','b','c','d','e','f' ，一共 6 个元素。
//	// 
//	// 字符串 ，即 char arr[] = "abcdef" ，没有输入 '\0' ，但是自带 '\0'字符串结束标志 ，
//	// 在内存中存储了 'a','b','c','d','e','f','\0' ，一共 7 个元素。
//
//	printf("%d\n", sizeof(arr)); //打印 6
//	// sizeof(arr) ，即 sizeof(数组名) ，这里的 数组名 表示 整个数组 的 地址 ，
//	// 这里 sizeof() 计算的是 整个数组的大小 ，为 6 字节。
//	// 
//	// 整个数组的大小 = 数组中元素个数 * 元素类型的大小 ，即 6 = 6 * 1 。
//
//	printf("%d\n", sizeof(arr + 0)); //打印 4\8
//	// 除 sizeof(数组名) 和 &数组名 之外，所有的数组名都表示 首元素的地址 ，
//	// sizeof(arr + 0) 中 arr 是 数组首元素地址 ， 地址 + - 整数 相当于跳过 该类型大小 的 步长 ，
//	// 此题 arr + 0 跳过 0 个 数组中元素类型(即 char类型) 的 步长 ，还是 首元素的地址 ，
//	// 这里 sizeof() 计算的是 地址的大小 ，为  4\8 字节 。
//
//	printf("%d\n", sizeof(*arr)); //打印 1
//	// 这里的 arr 是 数组首元素地址 ， 
//	// *arr 即对 数组首元素地址 进行 解引用操作 ，取出 第一个元素 即 'a' ，
//	// 而 数组中每个元素是 char类型 ，
//	// 这里 sizeof() 计算的是 数组中第一个元素类型的大小 ，为 1 字节 。
//	//
//	// *arr == *(arr + 0)
//
//	printf("%d\n", sizeof(arr[1])); //打印 1
//	// a[1] 即 取出 第二个元素 即 'b' ，
//	// 而 数组中每个元素是 char类型 ，
//	// 这里 sizeof() 计算的是 数组中第二个元素类型的大小 ，为 1 字节 。
//	//
//	// arr[1] == *(arr + 1)
//
//	printf("%d\n", sizeof(&arr)); //打印 4\8
//	// &arr ，即 &数组名 ，这里的 数组名 表示 整个数组 的 地址 ，
//	// 这里 sizeof() 计算的是 地址的大小 ，为  4\8 字节 。
//
//	printf("%d\n", sizeof(&arr + 1)); //打印 4\8
//	// &arr ，即 &数组名 ，这里的 数组名 表示 整个数组 的 地址 ，
//	// 而 地址 + - 整数 相当于跳过 该类型大小 的 步长 ，
//	// 此题 &arr + 1 跳过 1 个 数组类型大小 的 步长 ，即 跳过这个数组 以后的 地址 ，
//	// 这里 sizeof() 计算的是 地址的大小 ，为  4\8 字节 。
//
//	printf("%d\n", sizeof(&arr[0] + 1)); //打印 4\8
//	// [] 的优先级高于 & ，所以 arr 先与 [0] 结合，即 取出 第一个元素 即 'a' ，
//	// 然后再与 & 结合 ，即 取出 第一个元素 的 地址 ，
//	// 而 地址 + - 整数 相当于跳过 该类型大小 的 步长 ，
//	// 此题 &arr + 1 跳过 1 个 数组中元素类型(即 char类型) 的 步长 ，即 数组中第二个元素的地址 ，
//	// 这里 sizeof() 计算的是 地址的大小 ，为  4\8 字节 。
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a[] = { 1,2,3,4 };
//
//	printf("%d\n", sizeof(a)); //打印 16
//	// sizeof(a) ，即 sizeof(数组名) ，这里的 数组名 表示 整个数组 的 地址 ，
//	// 这里 sizeof() 计算的是 整个数组的大小 ，为 16 字节。
//	// 
//	// 整个数组的大小 = 数组中元素个数 * 元素的类型 ，即 16 = 4 * 4 。
//
//	printf("%d\n", sizeof(a + 0)); //打印 4\8
//	// 除 sizeof(数组名) 和 &数组名 之外，所有的数组名都表示 首元素的地址 ，
//	// sizeof(a + 0) 中 a 是 数组首元素地址 ， 地址 + - 整数 相当于跳过 该类型大小 的 步长 ，
//	// 此题 a + 0 跳过 0 个 数组中元素类型(即 int类型) 的 步长 ，还是 首元素的地址 ，
//	// 这里 sizeof() 计算的是 地址的大小 ，为  4\8 字节 。
//
//	printf("%d\n", sizeof(*a)); //打印 4
//	// 这里的 a 是 数组首元素地址 ， 
//	// *a 即对 数组首元素地址 进行 解引用操作 ，取出 第一个元素 即 1 ，
//	// 而 数组中每个元素是 int类型 ，
//	// 这里 sizeof() 计算的是 数组中第一个元素类型的大小 ，为 4 字节 。
//	//
//	// *a == *(a + 0)
//
//	printf("%d\n", sizeof(a + 1)); //打印 4\8
//	// 除 sizeof(数组名) 和 &数组名 之外，所有的数组名都表示 首元素的地址 ，
//	// sizeof(a + 1) 中 a 是 数组首元素地址 ， 地址 + - 整数 相当于跳过 该类型大小 的 步长 ，
//	// 此题 a + 1 跳过 1 个 数组中元素类型(即 int类型) 的 步长 ，即 数组中第二个元素的地址 ，
//	// 这里 sizeof() 计算的是 地址的大小 ，为  4\8 字节 。
//
//	printf("%d\n", sizeof(a[1])); //打印 4
//	// a[1] 即 取出 第二个元素 即 2 ，
//	// 而 数组中每个元素是 int类型 ，
//	// 这里 sizeof() 计算的是 数组中第二个元素类型的大小 ，为 4 字节 。
//	//
//	// a[1] == *(a + 1)
//
//	printf("%d\n", sizeof(&a)); //打印 4\8
//	// &a ，即 &数组名 ，这里的 数组名 表示 整个数组 的 地址 ，
//	// 这里 sizeof() 计算的是 地址的大小 ，为  4\8 字节 。
//
//	printf("%d\n", sizeof(*&a)); //打印 16
//	// &a ，即 &数组名 ，这里的 数组名 表示 整个数组 的 地址 ，
//	// *&a ,因为这里的 a数组名 是整个数组的地址 ，所以 *解引用操作 通过地址 找到的是 整个数组 ，
//	// 这里 sizeof() 计算的是 整个数组的大小 ，为 16 字节。
//	// 
//	// 整个数组的大小 = 数组中元素个数 * 元素的类型 ，即 16 = 4 * 4 。
//	// 
//	// 这里的 *解引用操作符 和 &取地址操作符 抵消了，相当于 sizeof(a) 。
//
//	printf("%d\n", sizeof(&a + 1)); //打印 4\8
//	// &a ，即 &数组名 ，这里的 数组名 表示 整个数组 的 地址 ，
//	// 而 地址 + - 整数 相当于跳过 该类型大小 的 步长 ，
//	// 此题 &a + 1 跳过 1 个 数组类型大小 的 步长 ，即 跳过这个数组 以后的 地址 ，
//	// 这里 sizeof() 计算的是 地址的大小 ，为  4\8 字节 。
//
//	printf("%d\n", sizeof(&a[0])); //打印 4\8
//	// [] 的优先级高于 & ，所以 a 先与 [0] 结合，即 取出 第一个元素 即 1 ，
//	// 然后再与 & 结合 ，即 取出 第一个元素 的 地址 ，
//	// 这里 sizeof() 计算的是 地址的大小 ，为  4\8 字节 。
//
//	printf("%d\n", sizeof(&a[0] + 1)); //打印 4\8
//	// [] 的优先级高于 & ，所以 a 先与 [0] 结合，即 取出 第一个元素 即 1 ，
//	// 然后再与 & 结合 ，即 取出 第一个元素 的 地址 ，
//	// 而 地址 + - 整数 相当于跳过 该类型大小 的 步长 ，
//	// 此题 &a + 1 跳过 1 个 数组中元素类型(即 int类型) 的 步长 ，即 数组中第二个元素的地址 ，
//	// 这里 sizeof() 计算的是 地址的大小 ，为  4\8 字节 。
//
//	return 0;
//}