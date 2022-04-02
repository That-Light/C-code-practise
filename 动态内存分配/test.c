#define _CRT_SECURE_NO_WARNINGS



#include <stdio.h>
#include <malloc.h>
struct S
{
	int* arr;
	int i;
};

int main()
{
	// struct S* ps = (struct S*)malloc(sizeof(struct S));
	// ps->arr = (int*)malloc(5 * sizeof(int));
	//
	// 其实对于使用 结构体成员 中的 指针类型 指向一个 开辟的动态内存空间 的方式，
	// 可以不用 开辟两次内存，
	// 
	// 上面代码 开辟一个动态内存 来存放这个结构体（存放在堆区） 是多余的，
	// 可以直接创建一个 结构体变量 （存放在栈区），
	// 然后只用开辟一次内存，用 结构体成员 中的 指针类型 接收 这个开辟内存空间的地址 即可。

	struct S s = { NULL,100 };

	s.arr= (int*)malloc(5 * sizeof(int));

	if (s.arr == NULL)
		return 0;

	int i = 0;
	for (i = 0; i < 5; i++)
	{
		s.arr[i] = i;
	}

	for (i = 0; i < 5; i++)
	{
		printf("%d ", s.arr[i] = i); // 打印 0 1 2 3 4
	}

	free(s.arr);
	s.arr = NULL;

	return 0;
}

//#include <stdio.h>
//#include <malloc.h>
//struct S
//{
//	int* arr;
//	int i;
//};
//
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S));
//
//	ps->arr = (int*)malloc(5 * sizeof(int));
//
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;
//	}
//
//	// 调整内存
//	int* ptr = realloc(ps->arr, 10 * sizeof(int));
//
//	if (ptr != NULL)
//	{
//		ps->arr = ptr;
//	}
//
//	for (i = 5; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//
//	// 释放内存
//	free(ps->arr); // 先释放
//	ps->arr = NULL;
//
//	free(ps); // 后释放
//	ps = NULL;
//
//	// 注意释放内存的 先后问题，
//	// 因为 若先释放 ps ，就不可以通过 ps 找到 在动态内存中存放的 结构体，
//	// 也就 无法访问结构体成员 arr ，
//	// 所以 无法再释放 arr 开辟的内存。
//
//	ptr = NULL;
//
//	return 0;
//}


//#include <stdio.h>
//#include <malloc.h>
//struct S
//{
//	int* arr;
//	int i;
//};
//
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S));
//
//	ps->arr = (int*)malloc(5 * sizeof(int));
//	// 用 结构体成员 中的 arr(为 int*类型 ，即 指针 ) ，指向一个 动态开辟的内存，
//	// 
//	// 其中 动态开辟内存大小 为 5 个 int类型 的大小，
//	// 且因为 arr 为 int*类型 ，只能接收 int*类型 的指针，
//	// 所以 malloc() 的返回类型 要 强制类型转换 成 (int*)类型 。
//
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;
//	}
//
//	return 0;
//}



//#include <stdio.h>
//#include <malloc.h>
//struct S
//{
//	int* arr; // 这种方式开辟动态内存，不用像 柔性数组 那样必须放在最后。
//	int i;
//};
//
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S));
//	// 用 动态内存开辟的方式 来创建，且使用 该结构体指针 来接收。
//	// 
//	// 使用 动态内存开辟的方式 来创建，其中
//	// 动态内存的大小 sizeof(struct S) 包含了 int*类型 和 int类型 的大小。
//	// 
//	// 因为 malloc 返回类型是 void*类型 ，而我们需要用 结构体指针访问 ，所以需要 强制类型转换 成 (struct S*) 。
//	// 
//	// 注意：这种方式 开辟的空间 存放在 堆区 。
//
//	ps->arr = (int*)malloc(5 * sizeof(int));
//	// 用 结构体成员 中的 arr(为 int*类型 ，即 指针 ) ，指向一个 动态开辟的内存，
//	// 
//	// 其中 动态开辟内存大小 为 5 个 int类型 的大小，
//	// 且因为 arr 为 int*类型 ，只能接收 int*类型 的指针，
//	// 所以 malloc() 的返回类型 要 强制类型转换 成 (int*)类型 。
//
//	return 0;
//}


//#include <stdio.h>
//#include <malloc.h>
//struct S
//{
//	int i;
//	int arr[];
//};
//
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//
//	ps->i = 100;
//
//	int i = 0;
//
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;
//	}
//
//	// 调整内存
//	struct S* ptr = realloc(ps, 44);
//	// realloc()库函数 可以不用 强制类型转换 ，会自动把 返回的地址 强制类型转换 成 与所要调整内存的指针 相同的类型，
//	// 即自动转换成与 ps 相同的类型。
//	// 
//	// 这里 44 包含了 结构体中 int类型成员 4 个字节的大小，
//	//         还有 (44 调整内存大小 - 4 给int类型成员大小) / 4 柔性数组成员类型 = 10 个 柔性数组成员的大小。 
//
//	if (ptr != NULL)
//	{
//		ps = ptr;
//	}
//
//	for (i = 5; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//
//
//	// 释放内存
//	free(ps);
//	ps = NULL;
//
//	ptr = NULL;
//	// 因为 ps 和 ptr 都指向 同一块动态内存空间，
//	// 上面 free(ps); 已经将 该动态内存空间释放，就不用再使用 ptr 释放。
//	// 
//	// 而因为 ptr 同样能找到 该动态内存空间，
//	// 所以释放 该动态内存空间 后，不仅 ps 要置为 NULL空指针 ，同样 ptr 也要置为 NULL空指针 。
//
//	return 0;
//}

//#include <stdio.h>
//#include <malloc.h>
//struct S
//{
//	int i;
//	int arr[];
//};
//
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//
//	ps->i = 100;
//
//	int i = 0;
//
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i]=i;
//	}
//
//	return 0;
//}


//#include <stdio.h>
//#include <malloc.h>
//struct S
//{
//	int i; 
//	int arr[];
//};
//
//int main()
//{
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//	// 带有 柔性数组成员的结构体 要用 动态内存开辟的方式 来创建，
//	// 且使用 该结构体指针 来接收。
//	// 
//	// 使用 动态内存开辟的方式 来创建，其中
//	// sizeof(struct S) 因为 结构体的大小 不包含 柔性数组成员的大小，
//	//                  所以 这里开辟空间 相当于是给 除了 柔性数组成员 以外的成员 开辟空间；
//	// 5 * sizeof(char) 这里才是给 最后的 柔性数组成员 开辟空间，
//	//                   其大小需根据 柔性数组的类型 确定，这里是开辟 5 个 int类型 大小的空间，即 50 个字节。
//	// 
//	// 因为 malloc 返回类型是 void*类型 ，而我们需要用 结构体指针访问 ，所以需要 强制类型转换 成 (struct S*) 。
//	// 
//	// 注意：这种方式 开辟的空间 存放在 堆区 。
//
//	return 0;
//}


//#include <stdio.h>
//struct S
//{
//	int i; // int类型 占 4 个字节
//	int arr[];
//};
//
//int main()
//{
//	struct S s;
//
//	printf("%d\n", sizeof(s)); // 打印 4
//	// 说明 柔性数组成员的大小 不算进 结构体的大小 中，
//	// 所以包含 柔性数组成员 的 结构体 不能只有 柔性数组 这一个成员。
//
//	return 0;
//}


//struct S1
//{
//	int i;
//	int arr[]; // 柔性数组成员(位置大小)
//};
//
//struct S2
//{
//	int i;
//	int arr[0]; // 柔性数组成员(位置大小)
//};
//
//int main()
//{
//
//	return 0;
//}

//#include <stdio.h>
//#include <malloc.h>
//#include <string.h>
//void Test(void)
//{
//	char* str = (char*)malloc(100);
//
//	if (str != NULL) // 注意判定是否成功开辟空间
//	{
//		strcpy(str, "hello");
//	}
//
//	free(str);
//	str = NULL;
//
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//
//		printf(str); // (不执行)
//	}
//
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}

//#include <stdio.h>
//#include <malloc.h>
//#include <string.h>
//void Test(void)
//{
//	char* str = (char*)malloc(100);
//
//	strcpy(str, "hello");
//
//	free(str);
//
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//
//		printf(str); // 打印 world
//	}
//
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}



//#include <stdio.h>
//#include <malloc.h>
//#include <string.h>
//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//
//	GetMemory(&str, 100);
//
//	if (str != NULL) // 判断 GetMemory函数 是否成功开辟空间 并 返回给str
//	{
//		strcpy(str, "hello");
//
//		printf(str); // 打印 hello
//	}
//
//	// 释放内存
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}



//int* test()
//{
//	int* ptr;
//
//	*ptr = 10;
//	// 这里也存在 非法访问内存 的问题，
//	// 因为上面 int* ptr; 未初始化 ，是一个 随机的地址，
//	// 对一个 随机的地址 进行 解引用操作 是 非法访问内存。
//	//
//	// 无法编译
//
//	return ptr;
//}
//
//int main()
//{
//	int* p = test();
//
//	return 0;
//}

//#include <stdio.h>
//char* GetMemory(void)
//{
//	static char p[] = "hello world";
//
//	return p;
//}
//
//void Test(void)
//{
//	char* str = NULL;
//
//	str = GetMemory();
//
//	printf(str); // 输出 hello world
//}
//
//int main()
//{
//	Test();
//	return 0;
//}


//#include <malloc.h>
//#include <string.h>
//#include <stdio.h>
//char* GetMemory(char* p) // 注意 返回类型 改为 char*
//{
//	p = (char*)malloc(100);
//	return p;
//}
//
//void Test(void)
//{
//	char* str = NULL;
//
//	str = GetMemory(str);
//
//	if (str != NULL) // 判断 GetMemory()函数 是否返回 开辟动态内存的地址
//	{
//		strcpy(str, "hello world");
//
//		printf(str);// 打印 hello world
//	}
//
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}



//#include <malloc.h>
//#include <string.h>
//#include <stdio.h>
//void GetMemory(char** p) // 传进来 指针的地址 ，所以需要 二级指针 接收
//{
//	char* ptr = (char*)malloc(100);
//
//	if (ptr != NULL) // 判断是否成功开辟动态内存
//	{
//		*p = ptr; // *p 才是真正找到 Test()函数 中的 str
//	}
//}
//
//void Test(void)
//{
//	char* str = NULL;
//
//	GetMemory(&str); // 传址传参 才能真正改变 str 的值
//
//	if (str != NULL) // 判断 GetMemory()函数 是否真正改变 str 的值
//	{
//		strcpy(str, "hello world");
//
//		printf(str); // 打印 hello world
//	}
//
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}


//#include <malloc.h>
//#include <string.h>
//#include <stdio.h>
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//
//	GetMemory(str);
//
//	strcpy(str, "hello world");
//
//	printf(str);
//
//}
//
//int main()
//{
//	Test();
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%s\n", arr);
//
//	printf(arr);
//
//	printf("abcdef");
//
//	return 0;
//}


//#include <malloc.h>
//#include <string.h>
//#include <stdio.h>
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//
//	GetMemory(str);
//
//	strcpy(str, "hello world");
//
//	printf(str);
//
//}
//
//int main()
//{
//	test();
//	return 0;
//}


//#include <malloc.h>
//int main()
//{
//	while (1)
//	{
//		malloc(1);
//	}
//	// 相当于 无限开辟内存 但是 不进行释放
//
//	return 0;
//}


//#include <malloc.h>
//int main()
//{
//	int* p = (int*)malloc(100);
//
//	if (p != NULL)
//	{
//		return 0;
//	}
//
//	free(p);
//
//	p = NULL;
//	free(p);
//	// 将 p 置为 NULL空指针 后，
//	// 下面的 free() 将对 NULL空指针进行释放，相当于什么也没发生，
//	// 从而避免多次释放同一块内存而造成程序崩溃。
//
//	return 0;
//}

//#include <malloc.h>
//int main()
//{
//	int* p = (int*)malloc(40);
//
//	p++; // p 不再指向 动态内存 的 起始位置
//
//	free(p);
//	// 而 free() 只能从 动态开辟内存 的 起始位置 开始释放，
//	// 若不是从 动态开辟内存 的 起始位置 开始释放，会导致程序崩溃。
//
//	p = NULL;
//
//	return 0;
//}


//#include <malloc.h>
//int main()
//{
//	int a = 10;
//	int* p = &a;
//
//	free(p);
//	// 对 非动态开辟的内存 使用 free()库函数 释放，
//	// 会造成程序崩溃
//
//	p = NULL;
//
//	return 0;
//}


//#include <malloc.h>
//int main()
//{
//	int* p = (int*)malloc(5 * sizeof(int));
//
//	if (p != NULL)
//	{
//		return 0; // 相当于直接结束 main()主函数
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		// malloc()库函数 开辟了 5 个 int类型 的空间，
//		// 而 for循环 的内容 却要访问 10  个 int类型 的空间。
//		//
//		// 越界访问 会造成 程序崩溃、死循环或者卡死
//	}
//
//	free(p);
//	p = NULL;
//
//	return 0;
//}


//#include <malloc.h>
//int main()
//{
//	int* p = (int*)malloc(_CRT_INT_MAX);
//
//	if (p != NULL)
//	{
//		*p = 0;
//	}
//
//	free(p);
//	p = NULL;
//
//	return 0;
//}


//#include <malloc.h>
//#include <string.h>
//#include <errno.h>
//#include <stdio.h>
//int main()
//{
//	int* p = (int*)malloc(5 * sizeof(int));
//
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 5; i++)
//		{
//			*(p + i) = i;
//		}
//	}
//
//	int* ptr = (int*)realloc(p, 40);
//
//	if (ptr != NULL)
//	{
//		p = ptr;
//	}
//
//	int j = 0;
//	for (j = 0; j < 10; j++)
//	{
//		printf("%d ", *(p + j));
//		// 打印 0 1 2 3 4 -842150451(随机值) -842150451(随机值) -842150451(随机值) -842150451(随机值) -842150451(随机值)
//	}
//
//	return 0;
//}

//#include <malloc.h>
//#include <string.h>
//#include <errno.h>
//#include <stdio.h>
//int main()
//{
//	int* p = (int*)malloc(5 * sizeof(int));
//	// 即 20 个字节
//
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 5; i++)
//		{
//			*(p + i) = i;
//		}
//	}
//	// 以上代码 是在使用 malloc()库函数 开辟的空间
//	// 
//	// 假设到此， 20 个字节已经无法满足要求，我们希望有 40 个字节的空间，
//	// 就要使用 realloc()库函数 来 调整动态开辟内存的空间。
//	int* p1 = (int*)realloc(p, 40);
//
//	int j = 0;
//	for (j = 0; j < 10; j++)
//	{
//		printf("%d ", *(p1 + j));
//		// 打印 0 1 2 3 4 -842150451(随机值) -842150451(随机值) -842150451(随机值) -842150451(随机值) -842150451(随机值)
//	}
//	// 可见 realloc()库函数 成功把 动态开辟内存的空间 调整为 40 个字节，
//	// 
//	// 且原来的数据保持不变，不会因为调整而丢失( 从 大内存 调整为 小内存 除外 )。
//
//	return 0;
//}



//#include <malloc.h>
//int main()
//{
//	// 向 内存 申请 10 个 int类型 的空间
//	int* p = (int*)calloc(10, sizeof(int));
//
//	return 0;
//}



//#include <malloc.h>
//int main()
//{
//	int* p = (int*)malloc(10 * sizeof(int));
//
//	return 0;
//}



//#include <malloc.h>
//#include <string.h>
//#include <errno.h>
//#include <stdio.h>
//int main()
//{
//	int* p = (int*)malloc(10*sizeof(int));
//	if (p == NULL)
//	{
//		// 打印错误原因
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			// 给开辟的内存赋值
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i)); // 打印 0 1 2 3 4 5 6 7 8 9
//		}
//	}
//
//	free(p);
//	p = NULL;
//
//	return 0;
//}



//#include <malloc.h>
//#include <string.h>
//#include <errno.h>
//#include <stdio.h>
//int main()
//{
//	// 在 32位平台 才能成功， 64位平台 可开辟的动态空间太大，试不出来
//
//	int* p = (int*)malloc(_CRT_INT_MAX);
//	// _CRT_INT_MAX最大的int类型 的 值 为 2147483647
//
//	if (p == NULL)
//	{
//		// 打印错误原因
//		printf("%s\n", strerror(errno)); //打印 Not enough space
//		// 其中 strerror()库函数 需引用 <string.h>头文件 ，
//		//      errno全局错误变量 需引用 <errno.h>头文件 。
//
//		printf("%p\n", p); // 打印 00000000 ，即 NULL空指针
//	}
//
//	return 0;
//}

//#include <malloc.h>
//int main()
//{
//	// 向 内存 申请 10 个 int类型 的空间
//	int* p = (int*)malloc(10 * sizeof(int));
//	// 我们申请 int类型 的空间，并希望以 int类型 维护，
//	// 而 malloc()库函数 返回 void*类型，所以需要 强制类型转换 成 int*类型 ，
//	// 并使用 int*类型 的 指针 接收。
//
//	return 0;
//}

//int main()
//{
//	int n = 0;
//
//	scanf("%d", &n);
//
//	int arr[n];
//	// 这种写法在 VS编译器下 是不合法的，
//	// 数组 在创建时 数组元素个数 要为 常量。
//
//	return 0;
//}