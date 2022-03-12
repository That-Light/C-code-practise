#define _CRT_SECURE_NO_WARNINGS

//模拟实现 qsort()库函数
#include <stdio.h>

int cmp_int(void* e1, void* e2) //比较函数
// 使用 Bubble_qsort函数 的程序员，一定知道自己排序的是什么数据，
// 就一定知道如何 比较数组中的元素 ，所以 使用的程序员 可以自己写出 比较函数
{
	return *((int*)e1) - *((int*)e2);
}

void Swap(char* buf1, char* buf2, int width)//传过来的是 相邻元素 的 地址
{
	int i = 0;
	char tmp; //中间变量

	for (i = 0; i < width; i++)
	{
		tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
		// 此时的 buf1 和 buf2 是 相邻元素 的 地址 ，
		// 逐个字节 进行 更换，更换 width 次，就能完成对 两个 任何类型的元素 的交换
		// 
		// 如 
		// 00000001 00000011 00000111 00001111 - num1
		// 和
		// 00000002 00000022 00000222 00002222 - num2
		// 交换
		// 
		// 先交换第一个字节
		// 00000002 00000011 00000111 00001111 - num1
		// 00000001 00000022 00000222 00002222 - num2
		// 再交换第二个字节
		// 00000002 00000022 00000111 00001111 - num1
		// 00000001 00000011 00000222 00002222 - num2
		// ......如此往复 width 次，就能完成对 两个 任何类型的元素 的交换
		// 00000002 00000022 00000222 00002222 - num1
		// 00000001 00000011 00000111 00001111 - num2
		//
	}
}

void Bubble_qsort(void* base, int sz, int width, int (*cmp)(void* e1, void* e2))
// 第一个参数：为了能够 排序 不同类型的数组， 函数 在接收 数组 时 不能用 固定的类型，
//             所以 得用 void*类型 接收， void*类型 可以接收 任何类型的地址
// 
// 第二个参数：排序需要知道有多少个元素需要排序，所以要用一个 int类型 接收 数组元素的个数
// 
// 第三个参数：因为不知道数组中每个元素是什么类型，所以得用一个方法获得数组中每个元素的类型，
//             方法就是 用一个 int类型 接收 该元素类型 占多少个字节 ，
//                      使用时 访问多少个字节 就相当于访问了 对应字节数的类型
// 
// 第四个参数： 实现 Bubble_qsort函数 的程序员，并不知道 待比较的两个元素 的 类型，
//             所以要用 void*类型 接收 待比较的两个元素 的 地址
// 
//             同时 不知道 待比较的两个元素 的 类型，也必然 不知道 比较的方法，
//             所以要 使用 Bubble_qsort函数 的程序员，自己写一个 比较函数 给 Bubble_qsort函数 调用，
//             然后 返回int类型 ，返回 小于0 的 值，说明 e1 < e2 ,
//                                返回 0 ，说明 e1 = e2 ，
//                                返回 大于0 的 值，说明 e1 > e2 。
{
	//类似冒泡排序
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++) //趟数
	{
		for (j = 0; j < sz - 1 - i; j++) //每一趟比较的 对数
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			// 因为 使用 Bubble_qsort函数 的程序员，知道自己排序的元素是什么类型，
			// 所以在 比较函数 中 直接将 每个元素的地址 强制转换成 自己排序的元素类型 并 解引用 进行比较即可。
			// 
			// 然而 实现 Bubble_qsort函数 的程序员，并不知道排序的元素是什么类型，
			// 但是现在要传 每个元素的地址 给 比较函数 ，如何在 不知道元素类型 的情况下，找到每个元素的地址呢？
			// 已知的是 base数组首元素地址 ，我们可以把 base首元素地址 强制类型转换 成 char* ，
			// 这样 (char*)base  加 减 整数，跳过的步长 都是 1个字节，
			// 而且已知 width每个元素所占字节数 ，可以通过 + width 跳到下一个元素的地址。
			// 则 (char*)base + j * width, (char*)base + (j + 1) * width 就是 跳转到 每个相邻元素 的 地址
			// 
			// 比较完后 返回一个int类型的值 ，告诉 Bubble_qsort函数 相邻元素 的大小，前面元素大 则进行 交换
			{
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width); //交换函数
			}
		}
	}
}

int main()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	Bubble_qsort(arr, sz, sizeof(arr[0]), cmp_int); //模拟实现 qsort()库函数 的 函数

	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]); //打印 0 1 2 3 4 5 6 7 8 9
	}

	return 0;
}

////冒泡排序
//#include <stdio.h>
//#include <stdlib.h>
//void Bubble_Sort(int arr[], int sz)
//{
//	int i = 0;
//	int j = 0;
//	int tmp = 0;
//
//	for (i = 0; i < sz - 1; i++) // 趟数 
//	{
//		for (j = 0; j < sz - 1 - i; j++) //每一趟对比的 对数
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	Bubble_Sort(arr, sz);
//
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//struct Stu //创建一个结构体类型
//{
//	char name[10];
//	int age;
//};
//
//int cmp_Stu_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);// 用 -> 访问结构体的成员
//	// 比较名字 就是 比较字符串，
//	// 而 字符串的比较 不能 直接使用 ><= 来比较，应该用 strcmp()库函数 来比较，
//	// 使用 strcmp()库函数 需要引用 <string.h>头文件
//	// 
//	// strcmp()库函数 比较字符串大小 的方法是：
//	// 从左到右，依次对 字符 的 ASCII码 的 大小 进行比较，遇到 不一样的字符 或 '\0' 结束 ，
//	// 遇到 不一样的字符 ，若此时 左边字符串中的字符ASCII码 > 右边字符串中的字符ASCII码 ,则返回 大于0 的值 ，
//	//                     若此时 左边字符串中的字符ASCII码 < 右边字符串中的字符ASCII码 ,则返回 小于0 的值 ，
//	//             至于 返回的值 ，有的编译器直接返回 1 或 -1 ，有的编译器则返回 两者ASCII码的差值
//	// 比较 两个字符串 同时遇到 '\0' ，说明 两个字符串 完全一样 ，返回 0 。
//	// 
//	// 这里 比较函数的返回值 刚好跟 strcmp()的返回值 匹配，直接 return  strcmp()的返回值 即可。
//	//
//}
//
//int main()
//{
//	struct Stu s[4] = { {"zhangsan",20},{"lisi",10},{"wangwu",40},{"laoliu",30} }; //按照 结构体类型 创建 一个 结构体变量 的 数组
//	int sz = sizeof(s) / sizeof(s[0]);
//
//	//按 名字 排序
//	qsort(s, sz, sizeof(s[0]), cmp_Stu_by_name);
//}

//#include <stdio.h>
//#include <stdlib.h>
//int cmp_int(const void* e1, const void* e2) //比较函数
//{
//	// 因为 计算机 不清楚 需要比较的两样东西 是什么类型 ，且 该怎么比较 ，
//	// 所以 要写出这要一个 比较函数 告诉 计算机 ，这两样东西 是这样比较的 ，
//	// 而且 为了满足 比较函数 能 比较 不同类型 的 两样东西，即 传参 给 比较函数 时 能够 传不同类型的参数，
//	// qsort() 的 第四个参数 ，即 比较函数的指针 ，规定了 参数为 void*类型的指针 ，这样便能 比较函数 就能 接收 不同类型的 参数。
//
//	return *(int*)e1 - *(int*)e2;
//	// 我们在写这个 比较函数 的时候，是知道这两样东西 是什么类型 ，该怎么比较的
//	// 
//	// 比如 这里我们知道 这两样东西 是 整型 ，且知道 如何比较大小 ，
//	// 因为 传进来的指针 是 void*类型 ，我们可以将 传进来的指针 强制类型转换成 int*类型 ，
//	// 再进行 解引用操作 就得到 原来的两个整型 ，
//	// 
//	// 进行比较后 按照 当 e1 < e2 时，返回 小于0 的 值
//    //                 当 e1 = e2 时，返回 0
//	//                 当 e1 > e2 时，返回 大于0 的 值 
//	//            即可。
//	// 
//	// 这里 两个整型 相减的值 刚好满足 比较后的返回条件 ，直接 return 返回 相减的值 即可。
//}
//
//int main()
//{
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	qsort(arr, sz, sizeof(arr[0]), cmp_int); // qsort()库函数 需引用 <stdlib.h>头文件
//	// 第一个参数：需要排序的数组 的 起始地址 
//	//             arr数组名 是 首元素地址 ，也是 数组 的 起始地址
//	// 
//	// 第二个参数：需要排序的数组 有几个元素
//	// 
//	// 第三个参数：需要排序的数组 中的元素 占多少个字节 
//	// 
//	// 第四个参数：需自己写一个 比较函数 ， qsort() 通过 指针 调用 该比较函数；
//
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]); //打印 0 1 2 3 4 5 6 7 8 9
//	}
//
//	return 0;
//}

////对于 void*类型 的 指针
//int main()
//{
//	int a = 10;
//	char b = 'w';
//
//	void* p = &a;
//	p = &b; // void* 类型的指针 可以接收任意类型的地址
//
//	*p = 10;//(报错)
//	// void* 类型的指针 不能进行解引用操作
//	// 
//	// 因为 指针类型 决定了 *解引用操作时，能访问多少个字节，
//	// 而 void* 没有具体的类型，不知道解引用操作时能访问多少个字节。
//
//	p++;//(报错)
//	// void* 类型的指针 不能进行 + - 整数的操作
//	// 
//	// 因为 指针类型 决定了 指针 + - 整数时 走过的 步长，
//	// 而 void* 没有具体的类型，不知道 指针 + - 整数时 能走过多长的 步长。
//}

//// qsort()库函数 的 定义
//void qsort(void* base, // 需要排序的数组 的 起始地址
//	                   // void*类型的指针 可以接收 任意类型的地址
//	        
//	       size_t num, // 需要排序的数组 有几个元素
//	                   // num 为 int类型
//	       
//	       size_t width, // 需要排序的数组 中的元素 占多少个字节 
//	                     // width 为 int类型
//	       
//	       int (*cmp)(const void* e1, const void* e2) // 比较函数：需自己写一个比较函数， qsort() 通过指针调用该比较函数；
//	                                                  // 比较函数 需要仿照 qsort() 第四个参数 int (*cmp)(const void* e1, const void* e2) 的格式来写；
//	                                                  // 比较函数 里面是 比较的方法 ，相当于告诉计算机这两样东西怎么比较；
//													  // 
//													  // (const void* e1, const void* e2) 是 需要比较的两个元素 的 地址
//													  // void*类型的指针 可以接收 任意类型的地址
//													  // 
//													  // 当 e1 < e2 时，返回 小于0 的 值
//													  // 当 e1 = e2 时，返回 0
//													  // 当 e1 > e2 时，返回 大于0 的 值          );
//// qsort()库函数 有 4 个参数

//冒泡排序
//#include <stdio.h>
//#include <stdlib.h>
//void Bubble_Sort(int arr[], int sz)
//{
//	int i = 0;
//	int j = 0;
//	int tmp = 0;
//	
//	for ( i = 0; i < sz-1; i++)
//	{
//		for (j = 0; j < sz-1-i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j+1] = ret;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	Bubble_Sort(arr,sz);
//
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	
//	return 0;
//}

////回调函数
//#include <stdio.h>
//void print(char* str) //相当于 char* str = "hehe\n"; 是一个 常量字符串
//{
//	printf("%s", str);
//}
//
//void test(void(*pf)(char*)) //传参 传了 一个函数
//                            //所以要用 函数指针 接收
//{
//	printf("test:");
//	pf("hehe\n"); //在 函数中 通过 函数指针 调用 其他函数 ，称为 回调函数
//}
//
//int main()
//{
//	test(print); //打印 test:hehe
//
//	return 0;
//}

////指向 函数指针数组 的 指针
//#include <stdio.h>
//int main()
//{
//	int (*pf)(int, int); //定义一个 函数指针
//	//(前面已经学习)
//	// (*pf) 表示 pf 先与 *号 结合，说明 pf 是一个 指针 ，其中 pf 是 指针的名字 ；
//	// (*pf)(int, int) 说明 该指针 指向 一个函数 ，即 pf 是一个 函数指针 ，
//	//                      该指针 指向的 函数 有 两个参数 ，且都是 int类型 ；
//	// 
//	// 对于 函数指针 而言，去掉 (*pf)指针表示 和 (int, int)函数参数 ，剩下的是 该指针指向函数的返回类型 ，
//	// 即 int ，
//	// 所以 该指针指向函数的返回类型 为 int类型 ；
//	// 
//	// 故 int (*pf)(int, int) 表示 一个叫 pf 的指针 指向一个 函数 ，该函数有 两个参数 ，都是 int类型 
//	//                                                           且该函数返回 int类型 。
//	//
//
//
//	int(*pArr)[5]; //定义一个 数组指针
//	//(前面已经学习)
//	// (*pArr) 表示 pArr 先与 *号 结合，说明 pArr 是一个 指针 ，其中 pArr 是 指针的名字 ；
//	// (*pArr)[5] 说明 该指针 指向一个 数组 ，即 pArr 是一个 数组指针 ，
//	//                 该指针 指向的 数组 有 5 个元素；
//	// 
//	// 对于 数组指针 而言，去掉 (*pArr)指针表示 和 [5]元素个数，剩下的是 该指针指向数组的元素类型 ，
//	// 即 int ，
//	// 所以 该指针指向数组的元素类型 为 int类型 ；
//	// 
//	// 故 int(*pArr)[5] 说明 一个叫 pArr 的指针 指向一个 数组 ，该数组有 5 个元素，每个元素都是 int类型 。
//
//
//	int (*pfArr[5])(int, int); //定义一个 函数指针数组
//	//(前面已经学习)
//	// [] 的优先级高于 *号 ， pfArr 先与 [5] 结合，说明 pfArr 是一个 数组 ，该数组有 5 个元素；
//	// 
//	// 对于 数组 而言，去掉 pfArr数组名 和 [5]元素个数 ，剩下的是 该数组中元素的类型 ，
//	// 即 int (* )(int, int) ，
//	// 所以 该数组中元素的类型 为 int (* )(int, int)类型 ，其中
//	// (* ) 说明这是一个 指针 ，
//	// (* )(int, int) 说明 该指针 指向 一个函数 ，是一个 函数指针 ，该函数 有 两个参数 ，都是 int类型 ，
//	// int (* )(int, int) 说明 该指针 指向的 函数 返回 int类型 。
//	// 
//	// 故 int (*pfArr[5])(int, int) 说明 一个叫 pfArr 的 数组 ，该数组有 5 个元素，每个元素都是 int (* )(int, int)类型 。
//	// 即 该数组中 每个元素 都是 一个函数指针 ，所以说 pfArr 是一个 函数指针的数组 ，即 函数指针数组 。
//
//
//
//	int (*(*ppfArr)[5])(int, int); //定义一个 函数指针数组的指针
//	// (*ppfArr) 表示 ppfArr 先与 *号 结合，说明 ppfArr 是一个 指针 ，其中 ppfArr 是 指针的名字 ；
//	// 
//	// [] 的优先级高于 *号 ， (*ppfArr) 先与 [5] 结合，说明 该指针 指向一个 数组 ，即 ppfArr 是一个 数组指针 ，
//	//                                                      该指针 指向的 数组 有 5 个元素；
//	// 
//	// 对于 数组指针 而言 ，去掉 (*ppfArr)指针表示 和 [5]元素个数 ，剩下的是 该指针指向数组的元素类型 ，
//	// 即 int (* )(int, int) ，
//	// 所以 该数组中元素的类型 为 int (* )(int, int)类型，其中
//	// (* ) 说明这是一个 指针 ，
//	// (* )(int, int) 说明 该指针 指向 一个函数 ，是一个 函数指针 ，该函数 有 两个参数 ，都是 int类型 ，
//	// int (* )(int, int) 说明 该指针 指向的 函数 返回 int类型 。
//	// 
//	// 故 int (*(*ppfArr)[5])(int, int) 说明 一个叫 ppfArr 的 指针 指向一个 数组 ，该数组有 5 个元素，每个元素都是 int (* )(int, int)类型 ，
//	// 即 每个元素 都是 函数指针 ，各自指向一个 函数 ，指向的 函数 有 两个参数 ，都是 int类型 ，且 指向的 函数 返回 int类型 。
//
//	return 0;
//}

////使用 回调函数 进行化简
//#include <stdio.h>
//void menu()
//{
//	printf("*************************\n");
//	printf("*****     1.Add     *****\n");
//	printf("*****     2.Sub     *****\n");
//	printf("*****     3.Mul     *****\n");
//	printf("*****     4.Div     *****\n");
//	printf("*****     0.Exit    *****\n");
//	printf("*************************\n");
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//void Calc(int (*pFun)(int, int)) //因为 函数传参 传的是 函数的地址 ，
//                                 //所以需要一个 函数指针 来接收
//{
//	int x = 0;
//	int y = 0;
//
//	printf("请输入两个操作数：");
//	scanf("%d%d", &x, &y);
//	printf("%d\n", pFun(x, y)); // 回调函数 就是在 函数中 调用函数 
//}
//
//int main()
//{
//	int input = 0;
//
//	do
//	{
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 1:
//			Calc(Add); //函数传参 传的是 函数的地址
//			break;
//		case 2:
//			Calc(Sub); //函数传参 传的是 函数的地址
//			break;
//		case 3:
//			Calc(Mul); //函数传参 传的是 函数的地址
//			break;
//		case 4:
//			Calc(Div); //函数传参 传的是 函数的地址
//			break;
//		case 0:
//			printf("退出程序\n");
//			break;
//		default:
//			printf("选择错误，请重新选择\n");
//			break;
//		}
//
//	} while (input);
//
//
//	return 0;
//}

////使用 函数指针数组 进行简化
//#include <stdio.h>
//void menu()
//{
//	printf("*************************\n");
//	printf("*****     1.Add     *****\n");
//	printf("*****     2.Sub     *****\n");
//	printf("*****     3.Mul     *****\n");
//	printf("*****     4.Div     *****\n");
//	printf("*****     0.Exit    *****\n");
//	printf("*************************\n");
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//
//	int (*pArr[5])(int, int) = { 0,Add,Sub,Mul,Div };
//	//使用 函数指针数组 进行简化
//	//为什么填写 5 个元素？
//	// 因为 数组首元素 下标为 0 ，令 首元素 为 0无关项 ，
//	// pArr[input] 刚好与 menu()菜单 中的 功能选项 匹配，
//	// 而无需额外把 input 减1 。
//
//	do
//	{
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//
//		if (input >= 1 && input <= 4)
//		{
//			printf("请输入两个操作数：");
//			scanf("%d%d", &x, &y);
//
//			printf("%d\n", pArr[input](x, y));//函数指针数组的调用
//
//		}
//		else if (input == 0)
//		{
//			printf("退出程序\n");
//		}
//		else
//		{
//			printf("选择错误，请重新选择\n");
//		}
//
//	} while (input);
//
//
//	return 0;
//}

////常规写法
//#include <stdio.h>
//void menu()
//{
//	printf("*************************\n");
//	printf("*****     1.Add     *****\n");
//	printf("*****     2.Sub     *****\n");
//	printf("*****     3.Mul     *****\n");
//	printf("*****     4.Div     *****\n");
//	printf("*****     0.Exit    *****\n");
//	printf("*************************\n");
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//
//	do
//	{
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 1:
//			printf("请输入两个操作数：");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Add(x, y));
//			break;
//		case 2:
//			printf("请输入两个操作数：");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Sub(x, y));
//			break;
//		case 3:
//			printf("请输入两个操作数：");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Mul(x, y));
//			break;
//		case 4:
//			printf("请输入两个操作数：");
//			scanf("%d%d", &x, &y);
//			printf("%d\n", Div(x, y));
//			break;
//		case 0:
//			printf("退出程序\n");
//			break;
//		default:
//			printf("选择错误，请重新选择\n");
//			break;
//		}
//
//	} while (input);
//
//
//	return 0;
//}

//#include <stdio.h>
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//int main()
//{
//	int (*pa)(int, int) = Add;
//	//此时 pa 是一个 函数指针 ，存放了 Add函数 的 地址 ，
//	//同理，
//	// Sub函数 、 Mul函数 、 Div函数 与 pa 所指向的 函数 的 参数个数及类型 、 返回类型 相同 ，
//	// 所以 pa 也可以存放 Sub函数 、 Mul函数 、 Div函数 的 地址 ，如
//	// int (*pa)(int, int) = Sub;
//	// int (*pa)(int, int) = Mul;
//	// int (*pa)(int, int) = Div;
//	// 
//	// 我们可以把 参数个数及类型 、 返回类型 都相同 的 函数 的 地址 存到一个数组中，那这个 数组 就叫 函数指针数组 。
//	// 如何定义 函数指针数组：
//
//	int (*parr[4])(int, int) = { Add,Sub,Mul,Div };
//	// parr 先于 [4] 结合，说明 parr 是一个 数组 ，
//	// 
//	// 对于 数组 而言，去掉 parr函数名 和 [4]元素个数 ，剩下的是 该数组中元素的类型 ，
//	// 即 int (* )(int, int) ，其中
//	// (* ) 说明这是一个 指针 ，
//	// (* )(int, int) 说明 该指针 指向 一个函数 ，是一个 函数指针 ，该函数 有 两个参数 ，都是 int类型 ，
//	// int (* )(int, int) 说明 该指针 指向的 函数 返回 int类型 。
//	// 
//	// 故 parr 是一个 数组 ，该数组中 每个元素 都是 一个函数指针 ，所以说 parr 是一个 函数指针的数组 ，即 函数指针数组 。
//
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d ", parr[i](2, 3));//打印 5 -1 6 0
//		// 类似 数组 的使用，
//		// 因为 函数 有 参数 ，所以要使用 () 并附上 实参 。
//		// 
//		// 且对于 函数指针 解引用 的 *号 是 没有实际意义的，写 与 不写 都是 一样的，
//		// 也可以写成 (*parr)[i](2, 3) ，
//		// 若 写上*号 ，需用 ()括号 括住 *parr ，即 (*parr) ，
//		// 不然 *号 优先级低于 [] ，则 parr 先于 [i] 结合再 *解引用 ，造成错误。
//	}
//
//	return 0;
//}

//#include <stdio.h>
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int (*pAdd)(int, int) = Add;
//
//	printf("%d\n", pAdd(2, 3));
//	printf("%d\n", (*pAdd)(2, 3));
//	printf("%d\n", (**pAdd)(2, 3));
//	printf("%d\n", (***pAdd)(2, 3));
//	//都打印 5
//	// 
//	// 
//	// 由此可见，
//	// 对于 函数指针 解引用 的 *号 是 没有实际意义的，写 与 不写 都是 一样的，
//	// 一般 不写 或者 写一颗* ，写多了容易造成误会。
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//
//	typedef unsigned int u_int;
//	// typedef 的作用是 对 函数 进行 重命名 ，
//	// 这里将 unisgned int 重命名为 u_int 。
//
//	void (*signal(int, void(*)(int)))(int);
//	//我们可以将 void(*)(int) 重命名为 pfun_t ，
//	// 
//	//然而
//	// typedef void(*)(int) pfun_t; 这样的写法是错误的，
//	// 
//	//对于 函数指针 ，要把 新名字 放在 *号 后面，即
//	typedef void(*pfun_t)(int); //这样才是正确的写法
//
//	//化简
//	pfun_t signal(int, pfun_t);
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	void (*signal(int, void(*)(int)))(int);
//	// signal() 说明这是一个 函数 ；
//	// signal(int, void(*)(int)) 说明这个函数有 两个参数 ，
//	//          第一个参数 是 int类型 ，是个 整型 ，
//	//          第二个参数 是 void(*)(int)类型，是个 函数指针 ，
//	//                     该 函数指针 指向的函数 有 一个参数 ，为 int类型 ，
//	//                     该 函数指针 指向的函数 无返回类型 ；
//	// 
//	// 我们知道 signal 是 一个函数 ，
//	// 也知道，如 void test(int, int); ，去掉 test函数名 和 (int, int)函数参数 后，剩下的 void 就是 函数 的 返回类型 。
//	// 同理，
//	// void (*signal(int, void(*)(int)))(int);
//	// 去掉 signal函数名 和 (int, void(*)(int))函数参数 后，剩下的 void (* )(int) 就是 该函数 的 返回类型 ，
//	// 即 返回一个 函数指针类型 ，该 函数指针 指向的函数 有 一个参数 为 int类型 ，且  无返回类型 。
//	// 
//	// 这段代码的意思是：
//	// 定义一个 函数 ，不是定义 函数指针 或者 其他东西 ，
//	// 该函数 有 两个参数 ，分别是 int整型类型 和 void(*)(int)函数指针类型 ，
//	// 且返回 void(*)(int)函数指针类型 。
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	(*(void (*)())0)();
//	// (*) 说明这是一个 指针类型；
//	// (*)() 说明 这个指针类型 指向一个 函数 ，即 函数指针 ，且这个函数 无参数 ；
//	// void (*)() 说明 这个指针类型 指向的 函数 无返回类型 ；
//	// 将 一个类型 放在 ()括号 中，是 强制类型转换 的意思， (void (*)())0 的意思是将 0 强制类型转换 成 void (*)()类型 的 函数指针 ；
//	// (*(void (*)())0) 的意思是 对 强制类型转换 成 void (*)()类型 的 0 进行 解引用操作 ，即 调用这个函数 ；
//	// 函数调用 需要 传参 ，从 函数指针void (*)() 中可知，这个函数 无参数，所以写成 (*(void (*)())0)(); 。
//	// 
//	// 应用场景：
//	// 当计算机启动时，硬件将调用首地址为0位置的函数。
//	// 为了模拟开机启动时的情形，必须设计出一个C语句，以显示调用该函数。
//
//	return 0;
//}

//#include <stdio.h>
//void Print(char* str)
//{
//	printf("%s\n", str);
//}
//
//int main()
//{
//	void (*pPrint)(char*) = Print;
//	// pPrint 是 指针变量 的 名字 ；
//	// (*pPrint) 表示 这是一个 指针变量 ，其中 pPrint 要用 ()括号 括起来，
//	//                                因为 ()括号 的优先级高于 *星号 ，不括起来 pPrint 先于后面的 (char*) 结合；
//	// (char*) 说明 该指针 指向的 函数 有 一个参数 ，为 char*类型 。写成 (char* str) 也是可以的；
//	//最前面的 void 说明 该指针 指向的 函数 无返回类型。
//
//	(*pPrint)("hello world"); //打印 hello world
//	// 函数的形参 是 char* str ，传过去的是 "hello world" ，
//	// 即 char* str = "hello world"; 这表示的是 常量字符串 ，
//	// 意思是把 "hello world" 中 h的地址 赋给 str 。
//	// 
//	// 使用 %s 打印 字符串 ，规定了 %s 要对应的类型 是 char*类型 ，
//    // 这里的 str 存了 "hello world" 中 h的地址 ，相当于是 该字符串首元素地址 ，
//	// 
//	// 该 字符串"hello world" ，包含了 'h'，'e'，'l'，'l'，'o'，' '，'w'，'o'，'r'，'l'，'d'，'\0'
//	// printf() 打印 字符串 ，只有识别到 '\0'字符串结束标志 才会停止打印
//
//	return 0;
//}

//#include <stdio.h>
//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//
//int main()
//{
//	int (*pAdd)(int, int) = Add;
//	// pAdd 是 指针变量 的 名字 ；
//	// (*pAdd) 表示 这是一个 指针变量 ，其中 pAdd 要用 ()括号 括起来，
//	//                                因为 ()括号 的优先级高于 *星号 ，不括起来 pAdd 先于后面的 (int, int) 结合；
//	// (int, int) 说明 该指针 指向的 函数 有 两个参数 ，且两个都是 int类型 。写成 (int x, int y) 也是可以的；
//	//最前面的 int 说明 该指针 指向的 函数 的 返回类型 是 int类型 。
//
//	printf("%d\n", (*pAdd)(2, 3));//打印 5
//	//其中 *pAdd 要用 ()括号 括起来，
//	//因为 ()括号 的优先级高于 *星号 ，不括起来 pAdd 先于后面的 (2, 3) 结合
//
//	return 0;
//}

//#include <stdio.h>
//int Add(int x, int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//
//int main()
//{
//	printf("%p\n", &Add);
//	printf("%p\n", Add);
//
//	return 0;
//}

////二级指针传参
//void test(int** ptr)// 二级指针 传参 只能用 二级指针 接收
//{}
//
//int main()
//{
//	int n = 10;
//	int* pn = &n;
//	test(&pn);// 函数形参 是 二级指针 ，实参传参 可以传 一级指针的地址
//
//	int** ppn = &pn;
//	test(ppn);// 函数形参 是 二级指针 ，实参传参 可以传 二级指针
//
//	int* arr[10];
//	test(arr);// 函数形参 是 二级指针 ，实参传参 可以传 指针数组
//
//	return 0;
//}

////一级指针传参
//#include <stdio.h>
//void test(int* p) // 一级指针 传参 只能用 一级指针 接收
//{}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr; //一级指针
//
//	test(p); //一级指针传参
//
//	return 0;
//}

////二维数组
//#include <stdio.h>
//// 形参 可以写成 二维数组的形式
//void test(int arr[3][5]) 
//{}
//
//void test(int arr[][5])
//{}
//
//void test(int arr[3][])//错误
//{}
//
//void test(int arr[][])//错误
//{}
//// 二维数组 传参 ，函数形参 的设计 只能 省略 第一个[]的数字 ，即 可以 省略 行数 ， 不可以 省略 列数 ，
////因为对 二维数组 而言，可以不知道有多少 行 ，但是必须知道 一行有多少个元素 ，这样才方便运算。
//
//// 形参 可以写成 数组指针的形式
//void test(int(*arr)[5]) //对于 二维数组 来说， 数组传参 传的也是 首元素地址 ，
//{}                      //要把 二维数组 想象成 一维数组 ，
//                        //即 二维数组 的 每一行 表示成 一个元素 ，二维数组的首元素 就是 第一行 ，
//						//而 每一行 是一个 数组 ，则 首元素的地址 就是 第一行这个数组的地址 ，
//						// 数组的地址 要用 数组指针 来存放，所以  形参 可以写成 数组指针的形式
//						// 
//						//其中 int(*arr)[5] 中 数组指针 指向的数组 所包含的 元素个数 ，即 [5] ,
//						//代表了 二维数组 有多少列 ，所以要与 二维数组 中的 列数 保持一致，
//						//写错 或者 不写 都会 报错 。 
//
//int main()
//{
//	int arr[3][5] = { 0 };
//
//	test(arr);
//
//	return 0;
//}

////指针数组
//#include <stdio.h>
//void test2(int* arr[]) //形参 可以写成 数组的形式
//{}                     //同理， 数组 的 元素个数 不起任何实质性的作用，
//                       // 元素的个数 写，不写，写错都不影响，但一般不要写错。
//
//void test2(int**arr) //形参 可以写成 指针的形式
//{}                   //因为 数组传参 传的是 首元素的地址 ，
//                     // arr2 是一个 数组指针
//                     // 首元素 是个 指针 ，即 int*类型 ，是 一个地址
//                     //则 首元素的地址 是 一个地址的地址 ，应该用二级指针接收，
//                     //所以 首元素的地址 用 int** 接收。
//
//int main()
//{
//	int* arr2[20] = { 0 };
//
//	test2(arr2);
//
//	return 0;
//}

////一般的数组，如 整型数组
//#include <stdio.h>
//void test1(int arr[]) // 形参 可以写成 数组的形式
//{}                    //其中 数组 的 元素个数 不起任何实质性的作用，
//                      //要不就不写，
//
//void test1(int arr[10]) //写就写对，与传过来的 实参 所含 元素个数 相同 ，
//{}
//
//void test1(int arr[5]) //虽然写错也没有关系，但会造成误解，日后维护困难。
//{}
//
//void test1(int* arr) // 形参 也可以写成 指针的形式
//{}                   //因为 数组传参 传的是 首元素的地址 ，
//                     // 首元素 是个 int类型 ，
//                     //则 首元素的地址 用 int* 接收。
//
//int main()
//{
//	int arr1[10] = { 0 };
//
//	test1(arr1);
//
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//void cmp(char* e1, char* e2, int weight)
//{
//	int i = 0;
//	int ret = 0;
//	for (i = 0; i < weight; i++)
//	{
//		ret = *(e1 + i);
//		*(e1 + i) = *(e2 + i);
//		*(e2 + i) = ret;
//	}
//}
//
//void my_sort(void* arr, int sz, int weight, int (*pf)(const void* p1, const void* p2))
//{
//	int i = 0;
//	int j = 0;
//
//	for (i = 0; i < sz - 1; i++)
//	{
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (pf((char*)arr + j * weight, (char*)arr + (j + 1) * weight) > 0)
//				cmp((char*)arr + j * weight, (char*)arr + (j + 1) * weight, weight);
//		}
//	}
//}
//
//int line(const void* p1, const void* p2)
//{
//	return *((int*)p1) - *((int*)p2);
//}
//
//struct Stu
//{
//	char name[10];
//	int age;
//};
//
//int line1_age(const void* p1, const void* p2)
//{
//	return ((struct Stu*)p1)->age - ((struct Stu*)p2)->age;
//}
//
//int line1_name(const void* p1, const void* p2)
//{
//	return strcmp(((struct Stu*)p1)->name, ((struct Stu*)p2)->name);
//}
//
//int main()
//{
//	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	my_sort(arr, sz, sizeof(arr[0]), line);
//	//int i = 0;
//	//for (i = 0; i < sz; i++)
//	//{
//	//	printf("%d ", arr[i]);
//	//}
//
//	struct Stu s[4] = { {"zhangsan",20} ,{"lisi",10},{"wangwu",40},{"wangwei",30} };
//	int sz1 = sizeof(s) / sizeof(s[0]);
//
//	my_sort(s, sz1, sizeof(s[0]), line1_age);
//
//	my_sort(s, sz1, sizeof(s[0]), line1_name);
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//int s_age(const void* p1, const void* p2)
//{
//	return ((struct Stu*)p1)->age - ((struct Stu*)p2)->age;
//}
//
//int s_name(const void* p1, const void* p2)
//{
//	return strcmp(((char*)p1), ((char*)p2));
//}
//
//int main()
//{
//	struct Stu s[4] = { {"zhangsan",20} ,{"lisi",10},{"wangwu",40},{"wangwei",30} };
//	int sz = sizeof(s) / sizeof(s[0]);
//
//	qsort(s, sz, sizeof(s[0]), s_age);
//
//	qsort(s, sz, sizeof(s[0]), s_name);
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//int int_cmp(const void* p1, const void* p2)
//{
//    return (*(int*)p1 - *(int*)p2);
//}
//int main()
//{
//    int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
//    int i = 0;
//
//    qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
//    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//int line(const void* x,const void* y)
//{
//	return (*(int*))x - (*(int*))y;
//}
//
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	qsort(arr, sz, sizeof(arr[0]), line);
//
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]); 
//	}
//
//	return 0;
//}

//#include <stdio.h>
//void menu()
//{
//	printf("***************************\n");
//	printf("*****      1.Add      *****\n");
//	printf("*****      2.Sub      *****\n");
//	printf("*****      3.Mul      *****\n");
//	printf("*****      4.Div      *****\n");
//	printf("*****      0.Exit     *****\n");
//	printf("***************************\n");
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//void Calc(int (*pf)(int,int))
//{
//	int x = 0;
//	int y = 0;
//	printf("请输入两个操作数：");
//	scanf("%d%d", &x, &y);
//	printf("result = %d\n", pf(x, y));
//}
//
//int main()
//{
//	int input = 0;
//
//	do
//	{
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 1:
//			Calc(Add);
//			break;
//		case 2:
//			Calc(Sub);
//			break;
//		case 3:
//			Calc(Mul);
//			break;
//		case 4:
//			Calc(Div);
//			break;
//		case 0:
//			printf("退出程序\n");
//			break;
//		default:
//			printf("输入错误，请重新输入\n");
//			break;
//		}
//
//	} while (input);
//
//	return 0;
//}

//#include <stdio.h>
//void menu()
//{
//	printf("***************************\n");
//	printf("*****      1.Add      *****\n");
//	printf("*****      2.Sub      *****\n");
//	printf("*****      3.Mul      *****\n");
//	printf("*****      4.Div      *****\n");
//	printf("*****      0.Exit     *****\n");
//	printf("***************************\n");
//}
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Sub(int x, int y)
//{
//	return x - y;
//}
//
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int Div(int x, int y)
//{
//	return x / y;
//}
//
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	
//	do
//	{
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//
//		if (input >= 1 && input <= 4)
//		{
//			int (*parr[5])(int, int) = { 0,Add,Sub,Mul,Div };
//			printf("请输入两个操作数：");
//			scanf("%d%d", &x, &y);
//			int ret = parr[input](x, y);
//			printf("result = %d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("退出程序\n");
//		}
//		else
//		{
//			printf("输入错误，请重新输入\n");
//		}
//	} while (input);
//
//	return 0;
//}

//int main()
//{
//	int arr[5];
//	// arr 是一个 数组 ，该数组 有 10个元素 ，每个元素是 int类型(整型) 。
//
//	int* parr1[10];
//	// parr1 先与 [] 结合，所以
//	// parr1 是一个 数组 ，该数组 有 10个元素 ，每个元素是 int*类型(指针) 。
//
//	int(*parr2)[10];
//	// parr2 被 ()括号 括住，先与 * 结合，所以
//	// parr2 是一个 指针 ，该指针 指向了一个 数组 ，该数组有 10个元素 ，每个元素是 int类型(整型) ，
//	// parr2 是一个 数组指针 。
//
//
//	int(*parr3[10])[5];
//	// parr3 先与 [] 结合，所以
//	// parr3 是一个 数组 ，该数组 有 10个元素 ，每个元素是 int(* )[5]类型 。
//	//
//	//注意：
//	//   如 int arr[5]; 去掉 数组名arr 和 元素个数[5] ，剩下的 int 是 数组中 元素的类型 ，
//	// 同理 int(*parr3[10])[5]; 去掉 数组名parr3 和 元素个数[10] ，剩下的 int(* )[5] 是 数组中 元素的类型 。
//	//
//	// 而 int(* )[5]类型 被 ()括号 括住，先与 * 结合，所以
//	// 数组parr3[10] 中 每个元素 是一个 指针 ，该指针 指向了一个 数组 ，该数组有 5个元素 ，每个元素是 int类型(整型) ，
//	// 数组parr3[10] 中 每个元素 是一个 数组指针
//	//
//	//综上所述：
//	// parr3 是一个 数组 ，该数组 有 10个元素 ，每个元素是一个 数组指针 ，
//	// 该数组指针 指向的 数组 有 5个元素 ，每个元素是 int类型 。
//
//	return 0;
//}

//#include <stdio.h>
//void print(int(*p)[5])
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			printf("%2d ", p[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			printf("%2d ", *(p[i] + j));
//		}
//		printf("\n");
//	}
//	printf("\n");
//
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			printf("%2d ", *(*(p + i) + j)); //通常写法
//		}
//		printf("\n");
//	}
//	printf("\n");
//
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			printf("%2d ", (*(p + i))[j]);
//			//注意这里要把 *(p + i) 先用 ()括号 括起来 ，因为 [] 优先级高于 () 
//		}
//		printf("\n");
//	}
//
//	//以上都打印：
//	// 1  2  3  4  5
//	// 6  7  8  9 10
//	//11 12 13 14 15
//}
//
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
//
//	print(arr);
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//
//	int* p = arr; //注意这里不是 &arr ，
//				  //虽然 &arr 和 arr 都是传了 同样的地址 过去，
//				  //但是含义不一样， &arr 是 整个数组的开头的地址 ，而 arr 是 数组的首元素地址 。
//				  // 
//				  // 此时的 p 和 arr 都是 arr数组 的 首元素地址
//
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr[i]); //通常的写法
//	}
//	printf("\n");
//
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", p[i]); //此时的 p 和 arr 都是 arr数组 的 首元素地址 ，两者完全等价
//	}
//	printf("\n");
//
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", *(p + i)); //使用地址的方式打印数组
//	}
//	printf("\n");
//
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", *(arr + i)); //此时的 p 和 arr 都是 arr数组 的 首元素地址 ，两者完全等价
//	}
//	printf("\n");
//
//	//以上都打印 1 2 3 4 5
//
//	return 0;
//}

//#include <stdio.h>
//void print1(int arr1[3][5]) 
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			printf("%2d ", arr1[i][j]);//通常的方法
//		}
//		printf("\n");
//	}
//}
//
//void print2(int arr2[3][5])
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			printf("%2d ", *(*(arr2 + i) + j));
//			// 数组传参 传的是 首元素地址 ，二维数组也不例外，
//			// 我们要把 二维数组 想象为一个 一维数组 ，
//			// 即 二维数组 中的 每一行 为 这个 所想象的一维数组 的 每个元素 ，这 每个元素 又是一个 一维数组 ，
//			//    二维数组 中的 列数 为 每个元素所代表的一维数组中 元素的个数
//			// 
//			// 如本题：int arr[3][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
//			//        把 arr 想象成一个 一维数组 ，
//			//        因为 二维数组arr 有 3 行 ，所以 想象的一维数组 包含 3 个元素，
//			//        每个元素 又是一个 一维数组 ，即 {1,2,3,4,5}   {6,7,8,9,10}   {11,12,13,14,15} ，
//			//        二维数组arr 有 5 列，所以 上方 每个元素代表的一维数组 中 都有 5 个元素 。
//			//        
//			// 本题中： arr2 是 二维数组arr首元素地址 ，即 一维数组{1,2,3,4,5} 的地址 ，是个 数组指针 。
//			//         (arr2 + i) 是 二维数组每个元素的地址 ，
//			//                    当 i = 1 时，从 首元素地址 往后跳过 一个元素的地址 ，即跳过一个 一维数组 的长度，找到一维数组{6,7,8,9,10} 的地址。
//			//         *(arr2 + i) 是对 二维数组每个元素的地址 进行 解引用操作 ，找到 每个元素 对应的 一维数组 。
//			//         *(arr2 + i) + j 是对 二维数组每个元素的地址 进行 解引用操作 ，找到 每个元素 对应的 一维数组 ，
//			//                         然后 再找到 这个对应的一维数组 中的 每一元素 。
//			//         *(*(arr2 + i) + j) 是对 二维数组每个元素的地址 进行 解引用操作 ，找到 每个元素 对应的 一维数组 ，
//			//                            然后 再找到 这个对应的一维数组 中的 每一元素 ，
//			//                            最后对 这个对应的一维数组 中的 每一元素 进行 解引用操作 ，找到 对应的值 。
//		}
//		printf("\n");
//	}
//}
//
//void print3(int (*arr3)[5]) // 数组传参 传的是 首元素地址 ，
//                            //而 二维数组的首元素 是一个 一维数组 ，传过来的是 一维数组的地址 ，所以要用 数组指针 进行存放
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			printf("%2d ", *(*(arr3 + i) + j));
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
//
//	print1(arr);
//
//	printf("\n");
//
//	print2(arr);
//
//	printf("\n");
//
//	print3(arr);
//
//	//以上都打印：
//	// 1  2  3  4  5
//	// 6  7  8  9 10
//	//11 12 13 14 15
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	printf("%p\n", p);
//	printf("%p\n", &a);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int i = 0;
//
//	//存放 首元素地址 的方法打印
//	int* p = arr; // 数组名 是 数组首元素的地址 ，这里将 数组首元素的地址 存放到 指针变量p 中。
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", p[i]);
//		//此时的 p 就是 arr ，而 p[i] 就相当于 arr[i]
//	}
//
//	printf("\n");
//
//	//存放 数组指针 的方法打印
//	int(*pa)[10] = &arr;// &数组名 是 整个数组的地址 ，这里将 整个数组的地址 存放到 数组指针pa 中。
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", (*pa)[i]);
//		// 1、记住要用 () 将 *pa 括住，因为 [] 的优先级要高于 *号 的，所以必须加上（）来保证 p 先和 *号 结合。
//		// 
//		// 2、*pa 的意思是对 pa 进行 解引用操作 ,
//		// 
//		//    因为 int* p = &a; 我们可以很明确地知道 p 是 指针 , p 中存了 &a(a的地址) ，即使用 %p 打印 p 和 &a 是同样的十六进制数，
//		//    而 *p 解引用 则是通过 p 中 存放的地址(a的地址) 找到 a(的值) ，即 *p 就是 a(的值) 。
//		// 
//		//    但在 数组中 只有int(*pa)[10] = &arr 才能说明是 数组指针 ，
//		//    即 pa 是 指针变量名 ， (*pa) 的 *号 说明 pa 是一个 指针 ，
//		//    同理 pa 是一个 指针 ，pa 存了 &arr(整个数组的地址) ，即使用 %p 打印 pa 和 &arr 是同样的十六进制数，
//		//    而 *pa 解引用 则是通过 pa 中 存放的地址(整个数组的地址) 找到 arr( 数组名 即 该数组首元素地址 ) ，即 *pa 就是 arr 。
//		// 
//		//    所以我们可以认为 *pa 就是 arr ，
//		//    *pa 的意思是对 &arr 解引用 ，得到 arr ，而 arr 是 数组名 ,即 该数组首元素地址 。
//		//    
//		// (*pa)[i] 就是 arr[i]
//	}
//
//	printf("\n");
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(*pa + i));
//		// 我们已经知道 *pa 就是 arr ，
//		// (*pa + i) 即 (arr + i) ，就是 该数组每个元素的地址 ，
//		// 其中指针'+'或'-' n个整数 ，意思就是 指针 走过 n个 该指针类型大小 的 步长 。
//		// 
//		// *(*pa + i) 则是对 该数组每个元素的地址 进行 解引用操作 ，取得 该数组每个元素的地址 所对应的 值 。 
//		// 
//		// *(*pa + i) 相当于 (*pa)[i]
//	}
//
//	return 0;
//}
//// 2、*pa 的意思不是对 pa 进行 解引用操作 ， *(*pa) 才是对 *pa (不单止是 pa ，而是 *pa ) 进行 解引用操作 ，
//		//    对 数组指针 而言 *pa 是一个整体 ，
//		//    因为 int* p = &a; 我们可以很明确地知道 p 是 指针 , p 中存了 a的地址 ，即使用 %p 打印 p 和 &a 是同样的十六进制数，
//		//    但在 数组中 只有int(*pa)[10] = &arr 才能说明是 数组指针 ，即 pa 不是 指针 ， (*pa) 才是 指针 ，
//		//    同理 (*pa) 才是存了 整个数组的地址 ，即使用 %p 打印 (*pa) 和 &arr 是同样的十六进制数，
//		//    所以我们可以认为 *pa 与 &arr 是同样的东西， *pa 的意思是取 整个arr数组的地址 ，即 *pa 还是个 地址 。

//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	 //定义数组指针
//	int(*p)[10] = &arr; //这里要使用 &取地址操作符 ，
//						//因为 arr 是指 首元素地址 ， &arr 才是指 整个数组的地址 。
//	//上面的 p 就是 数组指针
//	//
//	//解释：
//	// 1、 [] 的优先级要高于 *号 的，若写成 int *p[10] = &arr; 则 p 先与 [] 结合 ，这样是个 指针数组 ，
//	//    所以必须加上（）来保证 p 先和 *号 结合， (*p) 说明这是一个 指针 。
//	// 2、 int(*p)[10] 除去 (*p) 剩下的 int [10] 是 数组的类型 ，
//	//    意思是 (*p) 指向一个 数组 ，该 数组 有 10 个 元素 ，每个 元素 是 int类型
//
//	char* arr1[5];
//	char* (*pa)[5] = &arr1;
//	//解释：
//	// pa 是 指针变量名 ， (*pa) 的 *号 说明 pa 是一个 指针 ，
//	// [5] 说明 pa 指向的 数组 有 5 个 元素 ，
//	// char* 说明 pa 指向的 数组类型 是 char* 。
//	//
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 6,7,8,9,10 };
//	int arr3[] = { 11,12,13,14,15 };
//
//	int* parr[] = { arr1,arr2,arr3 }; //这里不用使用 &取地址操作符 (&arr) ，
//	                                  //因为 数组名 本身就是 地址 。
//	// int* 根据存放 对应数组的类型 而决定
//
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			printf("%2d ", *(parr[i]+j)); // parr[i] 是 parr指针数组 的每个元素 ，即每个 arr整型数组 的 首元素地址 ，
//			                              // parr[i] 本身就是个 地址(即指针变量) 。
//										  // 
//										  // parr[i]+j 是 arr整型数组 中 每个元素的地址 。
//										  // 
//										  // *(parr[i]+j) 是 取出 arr整型数组 中 每个元素的地址 所对应的 值 。
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int d = 40;
//
//	int* arr[4] = { &a,&b,&c,&d };
//
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d\n", *(arr[i]));
//	}
//
//	return 0;
//}	

//#include <stdio.h>
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//
//	char* p1 = "abcdef"; 
//	char* p2 = "abcdef";
//
//	if (arr1 == arr2)
//	{
//		printf("arr is same\n");
//	}
//	else
//	{
//		printf("arr is not same\n");
//	}
//	//打印 arr is not same
//	//因为 arr1 和 arr2 是 两个数组 ，在 内存中 开辟了 两个 不同的 空间 ，
//	//数组名 是 首元素地址 ，既然是 两个不同的空间 ，即使都是存 "abcdef" ，但 首元素地址 肯定不同 ，
//	// 即 arr1 和 arr2 是不同的
//
//	if (p1 == p2)
//	{
//		printf("p is same\n");
//	}
//	else
//	{
//		printf("p is not same\n");
//	}
//	//打印 p is same
//	//因为此处的 "abcdef" 是 常量字符串 ，既然是 常量 ，就不可修改 ，
//	//既然只能拿去用，但不可修改，不会改变，所以在 内存中 就 没有必要 存两份，
//	//即 为了节省内存空间， 常量字符串"abcdef" 只存了一份，
//	// 所以 p1 和 p2 其实 都指向 同一块空间的 位置 ，都存了 同一块空间的 第一个元素的 地址 ，
//	// 即 p1 和 p2 是相同的
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	const char* p = "abcdef"; // 使用 const 修饰 ，可以将代码保护起来
//
//	*p = 'w'; //被 const 修饰 *p 无法修改 ，代码无法编译
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	char* p = "abcdef"; // "abcdef" 是 常量字符串
//
//	*p = 'w'; //报错：segmentation fault 即 段错误 ，一般是 非法访问 时出现
//	//因为"abcdef" 是 常量字符串 ，既然是 常量 ，就不能被随意更改
//	
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	char* p = "abcdef";
//
//	*p = 'w';
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	char* p = "abcdef";
//	//很明显 字符串"abcdef" ，包含了 a , b , c , d , e , f , '\0' 一共 7 个 字符 ，其中每个字符占 1 字节，
//	//而 p 是个 指针 ，在 32位平台 上面只有 4 字节 ，肯定放不下，
//	//
//	//但这种写法是正确的
//	//
//	//这里的 "abcdef" 是一个 常量字符串 ，
//	//
//	//这段代码的意思是 把 a 的 地址 赋给 p 
//
//	printf("%c\n", *p); //打印 a
//
//	printf("%s\n", p);  //打印 abcdef
//	//为什么不是 *p ，
//	//因为 使用 % s 打印 字符串 ，规定了 % s 要对应的类型 是 char*类型 ，
//	//这里的 p 存了 "abcdef" 中 a 的 地址 ，相当于是 该字符串首元素地址
//	// 
//	//且 printf() 打印 字符串 ，只有识别到 '\0'字符串结束标志 才会停止打印
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	char arr[] = "abcdef";
//	// arr数组 中存了 a , b , c , d , e , f , '\0'
//
//	char* pc = arr; //这里没有用 &arr ，即 &取地址操作符 ，
//	                //因为 数组名arr 本身就表示 首元素的地址 ，本身就是一个 地址
//
//	//使用 %s 打印 字符串 ，规定了 %s 要对应的类型 是 char*
//    //且 printf() 打印 字符串 ，只有识别到 '\0'字符串结束标志 才会停止打印
//	printf("%s\n", arr); //打印 abcdef
//
//	printf("%s\n", pc); //打印 abcdef
//	//为什么不是 *pc ？
//	//因为 比如 
//	// int a = 10;
//	// int* pa = &a;
//	// 此时 pa 是 指针变量 ，即存了一个 地址 ， *pa 是通过 pa 存的 地址 ，找到对应的 值 为 10
//	// 
//	// 此题 首先 使用 %s 打印 字符串 ，规定了 %s 要对应的类型 是 char* ，而 pc 本身就是个 char*类型 ，
//	//      其次 我们 不是 解引用 来寻找 pc存的地址下 对应的 值 ，
//	//      而且 通过 char* pc = arr; 可得 pc 与 arr 等价。
//
//	return 0;
//}

//#include <stdio.h>
//void test(int arr[])
//{
//	//数组传参，传的是首元素地址
//	//地址存放在指针变量中，
//	//指针变量的大小是固定的4/8个字节(32位平台/64位平台)
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	// sz =      指针变量的大小      /      数组中一个元素的大小
//	//        (64位平台是 8 字节)      (整型数组，每个元素大小位 4 字节)
//	// sz = 8 / 4 = 2 ，这里打印 2
//	// 
//	// 若是 32位平台 则为 sz = 4 / 4 = 1
//
//	printf("%d\n", sz); //打印 2
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	test(arr);
//
//	return 0;
//}

//#include <stdio.h>
//void print1(int arr[3][5], int x, int y)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%2d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//}
//
//void print2(int(*p)[5], int x, int y)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y; j++)
//		{
//			printf("%2d ", *(*(p + i) + j));
//			printf("%2d ", *(p[i] + j));
//			printf("%2d ", ( * (p + i))[j]);
//			printf("%2d ", p[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
//	print1(arr, 3, 5);
//
//	printf("\n");
//
//	print2(arr, 3, 5);
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	int(*p)[10] = &arr;
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//}
//
//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	int(*p)[10] = &arr;
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(*p + i));
//	}
//
//	return 0;
//}
//
//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	int(*p)[10] = &arr;
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	int(*p)[10] = &arr;
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", (*p)[i]);
//	}
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	char* p = "abcdef";
//	*p = 'w';
//	return 0;
//
//}

//#include <stdio.h>
//void test(int arr[])
//{
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("%d\n", sz);
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//
//	test(arr);
//
//	return 0;
//}