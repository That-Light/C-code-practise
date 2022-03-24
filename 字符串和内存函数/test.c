#define _CRT_SECURE_NO_WARNINGS



#include <memory.h>
int main()
{
	int arr[10] = { 0 };

	memset(arr, 1, 10);

	return 0;
}


//#include <memory.h>
//int main()
//{
//	char arr[5] = "";
//
//	memset(arr, 'w', 5);
//
//	return 0;
//}


//#include <stdio.h>
//#include <memory.h>
//int main()
//{
//	int arr1[] = { 1,2,3 };
//	int arr2[] = { 1,2,4 };
//
//	int ret1 = memcmp(arr1, arr2, 8);
//	printf("%d\n", ret1); // 打印 0
//
//	int ret2 = memcmp(arr1, arr2, 9);
//	printf("%d\n", ret2); // 打印 -1
//
//	return 0;
//}


//#include <assert.h>
//#include <stdio.h>
//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	void* ret = dest;
//
//	if (dest < src || dest>(void*)((char*)src + num))
//		// 对于 (void*)((char*)src + num) ，
//		// src 原来是 void*类型 要 强制类型转换成 (char*) 才能 +num ，
//		// 完成 ((char*)src + num) 后仍为 char*类型 需要再 强制类型转换成 (void*) 再进行比较，
//		// 否则会报 类型不兼容 警告。
//	{
//		// 从前往后 拷贝
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			++(char*)dest;
//			++(char*)src;
//		}
//	}
//	else
//	{
//		// 从后往前 拷贝
//		while (num--)
//		{
//			*((char*)dest + num) = *((char*)src + num);
//		}
//	}
//
//	return ret;
//}
//
//#include <memory.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	my_memmove(arr + 2, arr, 20);
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	// 打印 1 2 1 2 3 4 5 8 9 10
//
//	return 0;
//}



//#include <assert.h>
//#include <stdio.h>
//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	void* ret = dest;
//
//	if (dest < src) // 地址 就算 类型不同 也可以 直接 比较大小 ，只不过 类型不同 时会报 类型不兼容 的警告，
//		            // 高地址 则大，低地址 则小，
//					// 这里 dest 是 void*类型 ，虽然 src 是 const void*类型 ，但也算 void*类型 ，不会报 类型不兼容 的警告，
//					// 
//					// 只不过 解引用 或者 加减操作 时才与 类型 有关系。
//	{
//		// 从前往后 拷贝
//		while (num--) // num-- ，后置减减 ，先使用 再减减，
//			          // 即 先 判断 能否满足条件 进入 while()循环 ，
//					  // 然后 执行自减操作 ，
//					  // 自减完成后，若能进入 while()循环 ，再带着 自减后 num 的 值 进入 while()循环 。
//		{
//			*(char*)dest = *(char*)src;
//			++(char*)dest;
//			++(char*)src;
//		}
//	}
//	else
//	{
//		// 从后往前 拷贝
//		while (num--) // 同理 num-- ，后置减减 ，先使用 再减减
//			// 这里设置得很巧妙 ，
//			// 因为 从后往前 拷贝，需要找到 dest 和 src 的 最后一个字节 ，
//			// 而 dest 和 src 的 最后一个字节 并不是 (dest + num) 或 (src + num) ，
//			// 而是 (dest + num - 1) 或 (src + num - 1)
//			// 
//			// 这里 while (num--) 因为 num 自减后 再进入 while()循环 刚好满足了 (num - 1) ,
//			// 如此循环，
//			// 当 (num == 1) 时 ，先判定 能进入 while()循环 ，然后自减成 (num == 0) 再进入 while()循环 ，
//			// 刚好满足 从后往前 拷贝的要求
//		{
//			*((char*)dest + num) = *((char*)src + num); // num 在 while(num--) 中已经 减1 ，无需再 减1
//		}
//	}
//
//	return ret;
//}
//
//#include <memory.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	my_memmove(arr + 2, arr, 20);
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	// 打印 1 2 1 2 3 4 5 8 9 10
//
//	return 0;
//}


//#include <assert.h>
//#include <stdio.h>
//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//	void* ret = dest;
//
//	if ((char*)dest - (char*)src > 0)
//	{
//		(char*)dest = (char*)dest + num-1;
//		(char*)src = (char*)src + num-1;
//		while (num--)
//		{
//
//			*(char*)dest = *(char*)src;
//			--(char*)dest;
//			--(char*)src;
//		}
//	}
//	else
//	{
//		while (num--)
//		{
//			*(char*)dest = *(char*)src;
//			++(char*)dest;
//			++(char*)src;
//		}
//	}
//
//	return ret;
//}
//
//#include <memory.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	my_memmove(arr + 2, arr, 20);
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//#include <assert.h>
//#include <stdio.h>
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//
//	void* ret = dest;
//
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		++(char*)dest;
//		++(char*)src;
//	}
//
//	return ret;
//}
//
//#include <memory.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	memcpy(arr + 2, arr, 20);
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//#include <assert.h>
//#include <stdio.h>
//void* my_memcpy(void* dest, const void* src, size_t num)
//{
//	assert(dest && src);
//
//	void* ret = dest;
//
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		++(char*)dest;
//		++(char*)src;
//	}
//
//	return ret;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	my_memcpy(arr + 2, arr, 20);
//	// (arr + 2) 是 源头 的 地址
//	// arr 是 目的地 的 地址
//	// 20 是拷贝 5 * 4(int类型) = 20 个字节
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//#include <assert.h>
//void* my_memcpy(void* dest, const void* src, size_t num)
//// void*类型 确保能接收任何类型的 指针
//{
//	assert(dest && src);
//
//	void* ret = dest; // 保存一份 dest 的 起始地址，以便最后返回
//
//	while (num--) // num-- ，后置减减 ，先使用 再减减，即 先进入 while()循环 ，当循环结束一次 再执行自减操作
//	{
//		*(char*)dest = *(char*)src;
//		++(char*)dest; // 前置加加 ，先使用 再加加，即 先 强制类型转换 成 (char*)类型 ，再执行自增操作
//		++(char*)src; // 前置加加 ，先使用 再加加，即 先 强制类型转换 成 (char*)类型 ，再执行自增操作
//	}
//
//	return ret;
//}
//
//int main()
//{
//	int arr1[] = {1,2,3};
//	int arr2[3] = { 0 };
//
//	my_memcpy(arr2, arr1, sizeof(arr1));
//
//	return 0;
//}



//#include <string.h>
//int main()
//{
//	int arr1[] = {1,2,3};
//	int arr2[3] = { 0 };
//
//	strcpy(arr2, arr1);
//
//	return 0;
//}


//#include <stdio.h>
//#include <ctype.h>
//int main()
//{
//	char arr[] = "I Am A Student";
//
//	int i = 0;
//
//	for (arr[i]; arr[i]; i++)
//		// 因为开始时 i 为 0 ，
//		// 
//		// 初始条件为 arr[i] ，即 arr[0] ，相当于从 字符数组arr 的 第一个字符 开始，
//		// 
//		// 随着调整条件 i++ ，不断 取出 字符数组arr 的每一个字符 作为 判断条件，
//		// 而 字符 作为 判断条件 ，判断的是 该字符对应的ASCII码值 ，
//		// 除了 '\0' 的 ASCII码值 为 0 ，
//		// 其他字符 的 ASCII码值 都不为 0 ，则为 真 ，进入循环执行语句，
//		// 
//		// 直到 取出 字符数组arr 最后一个字符 ，即 '\0' ,
//		// 而 '\0' 的 ASCII码值 为 0 ，此时 判断条件 arr[i] == 0 为 假 ，跳出循环
//	{
//		if (islower(arr[i]))
//			// 判断是否为小写字母
//			// 是小写字母，则 islower() 返回 非零值，即为 真 ，进入 if执行语句
//		{
//			arr[i] = toupper(arr[i]); // 小写字母转大写
//		}
//		else // 不是 小写字母(包括空格' ')，则 islower() 返回 0 ，即为 假 ，进入 else执行语句
//		{
//			arr[i] = tolower(arr[i]); // 大写字母转小写，
//			                          // 空格不发生变化，将被保留
//		}
//
//		putchar(arr[i]);
//		// 最终输出 i aM a sTUDENT
//	}
//
//}


//#include <stdio.h>
//#include <ctype.h>
//int main()
//{
//	// 注意：
//	// 是 字符函数 不是 字符串函数 ，
//	// 所以 字符 得用 ' ' ，而字符串是 " "
//
//	// 方式一：字符变量
//	char ch1 = 'Q'; 
//	ch1 = tolower(ch1); //将 大写Q 转 小写q
//	printf("%c\n", ch1); // 打印 q
//    // 字符使用 %c 打印
//
//	// 方式二：字符本身
//	char ch2 = toupper('Q'); // 大写Q 转大写，还是 大写Q
//	putchar(ch2); // 打印 Q
//	// 字符可以使用 putchar() 输出
//
//	// 方法三：字符对应ASCII码值
//	char ch3 = toupper(113); // ASCII码值113 对应 字符Q ，大写Q 转大写，还是 大写Q
//	putchar(ch3); // 打印 Q
//
//    // 非字母字符
//	char ch4 = toupper('2'); // 非字母字符(或 非字母字符的ASCII码值) ，则 给什么字符 直接 输出什么字符
//	putchar(ch4); // 打印 2
//
//	return 0;
//}


//#include <stdio.h>
//#include <ctype.h>
//int main()
//{
//	// 注意：
//	// 是 字符函数 不是 字符串函数 ，
//	// 所以 字符 得用 ' ' ，而字符串是 " "
//
//	// 方式一
//	char ch1 = 'w'; 
//	int ret1 = isdigit(ch1);
//	printf("ret1 = %d\n", ret1); // 打印 ret1 = 0
//
//	// 方式二
//	int ret2 = isdigit('1');
//	printf("ret2 = %d\n", ret2); // 打印 ret2 = 4
//
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("test.txt", "r");
//	// fopen()函数 的作用是 打开文件。
//	// 
//	// 有两个参数：第一个是 文件的名字，
//	//               第二个是 打开的方式 ，这里 "r" 是 只读 的意思。
//	// 
//	// 返回类型是 FILE*类型
//	// 
//	// 文件 需要存放在 本项目 的 存放路径 底下，
//	// 否则不能成功打开
//
//	if (pf == NULL) 
//		// 返回一个 NULL空指针 说明文件打开失败，
//		// 而失败的原因有很多，如文件不存在、访问权限不够 等等，
//		// 需要用 strerror() 查看具体失败的原因。
//	{
//		printf("%s\n", strerror(errno));
//		// 其中 errno 是 全局错误码的变量 ，
//		// 当 C语言 的 库函数 在执行过程中，发生了错误，就会把对应的错误码，赋值到 errno 中，
//		// 通过 strerror(errno) 就能查到 对应错误码的信息 。
//	}
//	else
//	{
//		printf("open file success\n");
//	}
//
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	int i = 0;
//
//	for (i = 0; i < 5; i++)
//	{
//		char* str = strerror(i);
//
//		printf("%d -> %s\n", i, str);
//		//打印 错误码0~4 对应的错误信息
//	}
//
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr[] = "123.123@.@123";
//	char* p = "@.";
//
//	//临时拷贝
//	char buf[20] = { 0 };
//	strcpy(buf, arr);
//
//	//切割字符串
//	char* ret = NULL;
//
//	for (ret = strtok(arr, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr[] = "1124590960@qq.com";
//	char* p = "@.";
//	 
//	//临时拷贝
//	char buf[20] = { 0 };
//	strcpy(buf, arr);
//
//	//切割字符串
//	char* ret = NULL;
//
//	for (ret = strtok(arr, p); ret != NULL; ret = strtok(NULL, p))
//		// 运用 for循环 巧妙在于，
//		// for循环 的 初始化 只会执行一次，刚好用来执行 strtok(arr, p) ，
//		// 
//		// 而当 strtok(arr, p) 返回的不是 NULL空指针 时 ， for循环 条件判断 为 真 ，
//		// 进入 for循环执行语句 ，
//		// 
//		// 每次执行完后，都只执行 for循环 调整部分 的 strtok(NULL, p) ，
//		// 而不是 for循环 初始化 的 strtok(arr, p) ，
//		// 刚好满足 strtok()库函数 的使用要求，
//		// 
//		// 直到 在字符串中找不到更多的标记 ，strtok() 则返回NULL ，
//		// 此时 for循环 条件判断 为 假 ，跳出循环
//	{
//		printf("%s\n", ret);
//	}
//
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr[] = "1124590960@qq.com";
//	char* p = "@.";
//
//	//临时拷贝
//	char buf[20] = { 0 };
//	strcpy(buf, arr);
//
//	//切割字符串
//	char* ret = strtok(arr, p);
//	printf("%s\n", ret);
//
//	ret = strtok(NULL, p);
//	printf("%s\n", ret);
//
//	char* ret1 = strtok(NULL, p);
//	printf("%s\n", ret1);
//
//	ret1 = strtok(NULL, p);
//	printf("%s\n", ret1);
//
//	return 0;
//}


//#include <stdio.h>
//#include <assert.h>
//char* my_strstr(const char* p1, const char* p2)
//{
//	assert(p1 != NULL);
//	assert(p2 != NULL);
//
//	char* s1 = NULL;
//	char* s2 = NULL;
//
//	char* cur = (char*)p1;
//
//	//查找的字符串 为 空 ，直接返回 被查找字符串 的 首字符 地址
//	if (!*p2)
//		// !号 为 逻辑非 运算符，即 真变假 ， 假变真 。
//		// 
//		// 若 *p2 == '\0' 即 *p2 == 0 ，条件为假 ，而 !*p2 则 为真   进入 if执行语句 ，
//		// 若 *p2 != '\0' 即 *p2 != 0 ，条件为真 ，而 !*p2 则 为假 不进入 if执行语句 。
//		// 
//		// 原本为 if(*p2 == '\0') 。
//	{
//		return (char*)p1;
//	}
//
//
//	while (*cur)
//	{
//		s1 = cur;
//
//		s2 = (char*)p2;
//
//		// 对比是否为子串
//		while ((*s1 != '\0') && (*s1 == *s2))
//			// 不需要判断 (*s1 != '\0') 和 (*s2 != '\0') 其中一个 也可以(假设不要 (*s2 != '\0') )，
//			// 因为若 *s1 和 *s2 都为 '\0' ，则 (*s1 != '\0') 会跳出 while循环 ；
//			//     若 *s1 为 '\0' ，而 *s2 不为 '\0' ，则 (*s1 != '\0') 会跳出 while循环 ；
//			//     若 *s1 不为 '\0' ，而 *s2 为 '\0' ，则 (*s1 == *s2) 会跳出 while循环 ；
//			//     若 *s1 不为 '\0' ，且 *s2 不为 '\0' ，则 (*s1 == *s2) 会加以判断。
//			// 
//			// 原本为while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2)) ，
//			// 
//			// 
//			// 可以再优化为 while ((!*s1) && !(*s1-*s2)) ，其中 (!*s1) 与上面的优化类似，
//			// !(*s1-*s2) 
//			// 若 *s1 == *s2 ，则 *s1 - *s2 == 0 ，条件为假 ，而 !(*s1-*s2) 则 为真   进入 while循环 ，
//			// 若 *s1 != *s2 ，则 *s1 - *s2 != 0 ，条件为真 ，而 !(*s1-*s2) 则 为假 不进入 while循环 。
//		{
//			s1++;
//			s2++;
//		}
//
//		if (!*s2)
//			// !号 为 逻辑非 运算符，即 真变假 ， 假变真 。
//		    // 
//		    // 若 *s2 == '\0' 即 *s2 == 0 ，条件为假 ，而 !*s2 则 为真   进入 if执行语句
//		    // 若 *s2 != '\0' 即 *s2 != 0 ，条件为真 ，而 !*s2 则 为假 不进入 if执行语句
//			// 
//			// 原本为 if(*s2 == '\0')
//		{
//			return cur;
//		}
//
//		cur++;
//	}
//
//	return NULL;
//
//}
//
//int main()
//{
//	const char* str1 = "abbbcdef";
//	const char* str2 = "bbc";
//
//	char* ret = my_strstr(str1, str2);
//
//	if (ret == NULL)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//	//打印 bbcdef
//
//	return 0;
//}


//#include <stdio.h>
//#include <assert.h>
//char* my_strstr(const char* p1, const char* p2)
//{
//	assert(p1 != NULL);
//	assert(p2 != NULL);
//
//	char* s1 = NULL; // 逐个字符对比时，用 s1 记录指针在 字符串str1 的位置
//	char* s2 = NULL; // 逐个字符对比时，用 s2 记录指针在 字符串str2 的位置
//
//	char* cur = (char*)p1; // 记录从 字符串str1 的 哪个字符 开始对比，
//						   // 因为 找到了子串 要返回 开始对比 的 那个字符 的 地址 ，而 s1 和 s2 一直在变化，
//					       // 所以需要 cur 记录从 字符串str1 的 哪个字符 开始对比，以便 return返回 。
//						   // 
//						   // 因为 p1 的类型是 const char* ，需 强制类型转换 成 (char*) 才能存入 cur 中。
//
//	//查找的字符串 为 空 ，直接返回 被查找字符串 的 首字符 地址
//	if (*p2 == '\0')
//	{
//		return (char*)p1; // 因为 p1 的类型是 const char* ，而 函数返回类型 是 char* ，所以需要 强制类型转换 成 (char*)
//	}
//
//
//	while (*cur)
//		// 当 (*cur == '\0') 即 (*cur == 0) 时，条件 为0 为假 ，跳出 while循环 ，
//		// 说明 被查找的字符串str1 已经对比到最后一个字符串 还是没能找到 子串，
//	{
//		s1 = cur;
//		// 每次 s1 需要 重置 成 字符串str1 的 开始对比 的 字符 的 地址 ，
//		// 因为 s1 在 对比是否为子串 的环节 可能发生改变，
//		// 若不重置，可能会导致本来有子串，但却没找到的情况。
//
//		s2 = (char*)p2; // 每次都是从 str2 的 首字符 开始对比
//		         //
//		         // 因为 p2 的类型是 const char* ，需 强制类型转换 成 (char*) 才能存入 s2 中。
//
//		// 对比是否为子串
//		while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))
//			// 只有当 (*s1 != '\0') && (*s2 != '\0') ，才对比 (*s1 == *s2) ，若成立，
//			// 说明 被查找的字符串str1 和 查找的字符串str2 有字符 相同 ，可以继续往下比较。
//			// 
//			// 当 *s1 == '\0' 时说明 被查找的字符串str1 比 查找的字符串str2 短，不可能找到子串；
//			// 
//			// 当 *s2 == '\0' 时说明 查找的字符串str2 对比完成，在 被查找的字符串str1 找到子串。
//		{
//			s1++;
//			s2++;
//		}
//
//		if (*s2 == '\0')
//			// 当 s2 找到 '\0' 时，
//			// 说明在 被查找的字符串str1 中有 查找的字符串str2 的子串 ，
//			// 则返回 cur 的值，即 字符串str1 的 开始对比 的 字符 的 地址 。
//		{
//			return cur;
//		}
//
//		cur++; //跳到 被查找的字符串str1 的 下一个字符 再进行对比
//	}
//
//	return NULL; // 当 (*cur == '\0') 时跳出 while循环 ，
//				 // 说明 被查找的字符串str1 已经对比到最后一个字符串 还是没能找到 子串，
//				 // 即 被查找的字符串str1 中没有 查找的字符串str2 的子串，
//				 // 所以返回 NULL空指针 。
//
//}
//
//int main()
//{
//	const char* str1 = "abbbcdef";
//	const char* str2 = "bbc";
//
//	char* ret = my_strstr(str1, str2);
//
//	if (ret == NULL)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//	//打印 bbcdef
//
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	const char* p1 = "abcdefabcdef";
//	const char* p2 = "def";
//
//	char* ret = strstr(p1, p2);
//
//	printf("%s\n", ret); // 打印 defabcdef
//	// 由此可见，
//	// 返回的是 查找的字符串 在 被查找的字符串 第一次出现 的 地址 ，
//	// 即 "abcdefabcdef" 中 def abcdef 的 地址 。
//
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	const char* p1 = "abcdef"; // 因为只是 比较 字符串，不需要 修改 字符串，
//	const char* p2 = "abcghi"; // 可使用 const 将 字符串 保护起来，以免不小心修改
//
//	int ret1 = strncmp(p1, p2, 3);
//	// strncmp()库函数 第三个参数 的 值 为 num ，就 比较 前num 个字符。
//	printf("ret1 = %d\n", ret1); // 打印 ret1 = 0
//
//	int ret2 = strncmp(p1, p2, 4);
//	printf("ret2 = %d\n", ret2); // 打印 ret2 = -1
//
//	int ret3 = strncmp(p1, p2, 15);
//	// 若 strncmp()库函数 第三个参数 的 值 很大，比 字符串 本身都大，
//	// 就等于 没有对 比较哪几个字符 进行限制，相当于 直接使用 strcmp()库函数 进行比较。
//	printf("ret3 = %d\n", ret3); // 打印 ret3 = -1
//
//	const char* p3 = "abcdef";
//
//	int ret4 = strncmp(p1, p3, 15);
//	printf("ret4 = %d\n", ret4); // 打印 ret4 = 0
//
//	return 0;
//}



//#include <string.h>
//int main()
//{
//	char arr1[15] = "#\0##########";
//	char arr2[] = "abc";
//
//	strncat(arr1, arr2, 6);
//
//
//	return 0;
//}



//#include <string.h>
//int main()
//{
//	char arr1[10] = "########";
//	char arr2[] = "abc";
//
//	strncpy(arr1, arr2, 5);
//
//	return 0;
//}



//#include <stdio.h>
//#include <assert.h>
//int my_strcmp(const char* str1,const char* str2)
//{
//	assert(str1 && str2);
//
//	//比较
//
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0') // 两个参数的字符串 相等
//			// while循环 时已经确定 *str1 == *str2 ，
//			// 这里判断 *str1 == '\0' 就相当于也判断了 *str2 == '\0' 。
//		{
//			return 0; 
//		}
//
//		str1++;
//		str2++;
//	}
//
//	if (*str1 > *str2)
//	{
//		return 1; //第一个参数的字符串 大于 第二个参数的字符串
//	}
//	else
//	{
//		return -1; //第一个参数的字符串 小于 第二个参数的字符串
//	}
//	// 这是模拟 VS编译器 的 返回值，
//	// 
//	// 若模拟其他编译器，如 GCC编译器 返回的是 两字符ASCII码值之差，
//	// 可直接写成：
//	// return *str1 - *str2;
//
//
//}
//
//int main()
//{
//	char* p1 = "abc";
//	char* p2 = "def";
//
//	int ret = my_strcmp(p1, p2);
//
//	printf("ret = %d\n", ret);
//
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char* arr1 = "abc";
//	char* arr2 = "def";
//
//	if (strcmp(arr1, arr2) > 0)
//	{
//		printf("arr1 > arr2\n");
//	}
//	else if (strcmp(arr1, arr2) == 0)
//	{
//		printf("arr1 = arr2\n");
//	}
//	else if (strcmp(arr1, arr2) < 0)
//	{
//		printf("arr1 < arr2\n");
//	}
//
//	return 0;
//}



//#include <string.h>
//int main()
//{
//	strcat();
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src); // NULL空指针 相当于 0 ，而 0 为假 。
//	// 即 dest 和 src 都不为 NULL 才为 真 ，
//	// 这一句相当于 
//	// assert(dest != NULL);
//	// assert(src != NULL);
//	// 或者
//	// assert(dest);
//	// assert(src);
//
//	char* ret = dest;
//	// 因为 dest 会随着 下面代码中 dest++ 而改变，
//	// 若最后想返回 原来dest 中的 地址，
//	// 可先用 ret 保存 ，最后再返回 ret 保存的地址 即可。
//
//	//1、找到 目标字符串 的 '\0'
//	while (*dest != '\0')
//	{
//		dest++; // 使 dest 指向 '\0' 的位置
//	}
//
//
//	//2、追加字符串
//	// 相当于拷贝把 追加的字符串 拷贝到 目标函数后面(因为现在 dest 指向 '\0' 的位置)
//	while (*dest++ = *src++)
//	{
//		;
//	}
//
//	return dest;
//
//}
//
//int main()
//{
//	char arr1[15] = "hello";
//	char arr2[] = "world";
//
//	my_strcat(arr1, arr2);
//
//	printf("%s\n", arr1);
//	//打印 helloworld
//
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr1[15] = "hello\0xxxxxxxx";
//	// strcat()库函数 原理：
//	// 先找到 目标字符串 的 '\0' ,
//	// 然后把 追加字符串 的 第一个字符 替换掉 目标字符串 的 '\0' ，
//	// 逐个往后 如此往复 把 追加字符串 的 每个字符 追加到 目标字符串 的 '\0' 之后的字符，
//	// 直到 追加到 追加字符串 的 '\0' ,
//	// 把 追加字符串 的 '\0' 追加到 目标字符串 之后 才停止。
//
//	char arr2[] = "world";
//
//	strcat(arr1, arr2);
//
//	return 0;
//}



//#include <stdio.h>
//#include <assert.h>
//char* my_strcpy(char* dest, const char* src)
//// 与之前不同的是：
//// 我们这里返回类型是 char* ，
//// strcpy()库函数 的 返回类型 也是 char* ，目的是返回 拷贝目的地 的 地址。
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//
//	char* ret = dest;
//	// 因为 dest 会随着 下面代码中 dest++ 而改变，
//	// 若最后想返回 原来dest 中的 地址，
//	// 可先用 ret 保存 ，最后再返回 ret 保存的地址 即可。
//
//	while (*dest++ = *src++)
//	{
//		;
//	}
//
//	return ret;
//
//}
//	
//int main()
//{
//	char arr1[] = "abcdefghi";
//	char arr2[] = "hello";
//
//	my_strcpy(arr1, arr2);
//	// 虽然 my_strcpy() 返回了一个 char*类型 的 值 ，
//	// 但是可以 不拿东西 接收 这个值，
//	// 就好比
//	// 3;
//	// 在语法中也是支持的。
//	// 
//	// 而本题
//	// my_strcpy(arr1, arr2);
//	// 在函数中改变了 arr1 的内容，
//	// 但在主函数中 arr1首字符的地址 没变， 
//	// printf("%s\n", arr1);
//	// 打印 改变后 arr1 的内容，即 hello 。
//	// 
//	// my_strcpy() 返回了一个 char*类型 的 值 可能是 想用来赋给 其他字符指针 ，
//	// 如
//	// char* arr3 = my_strcpy(arr1, arr2);
//	// printf("%s\n", arr3);
//	// 照样能打印 hello 。
//
//	printf("%s\n", arr1); //打印 hello
//
//	return 0;
//}


//#include <string.h>
//int main()
//{
//	char arr1[] = {"abcdefg"};
//	char arr2[] = {"hello"};
//
//	strcpy(arr1, arr2);
//	// strcpy()库函数 的作用是 字符串拷贝 ，
//	// 有两个参数：第一个是 拷贝目的地 的 地址，
//	//             第二个是 被拷贝的内容 的 地址，
//	// 这里是将 arr2 的内容拷贝到 arr1 中去，
//
//	return 0;
//}


//#include <stdio.h>
//#include <assert.h>
//int my_strlen(const char* str)
//{
//	assert(str != NULL);
//
//	int count = 0;
//
//	while (*str) 
//	{
//		count++;
//		str++;
//	}
//
//	return count;
//
//}
//
//int main()
//{
//
//	if (my_strlen("abc") - my_strlen("abcdef") > 0)
//	{
//		printf("haha\n");
//	}
//	else
//	{
//		printf("gaga\n");
//	}
//	// 打印 gaga
//
//	return 0;
//}


//#include <stdio.h>
//size_t // 需引用 <stdio.h>头文件
//
//// 以32为平台为例：
//// 00000000 00000000 00000000 00000011   -> 3的补码(正数三码相同)
//// 00000000 00000000 00000000 00000110   -> 6的补码(正数三码相同)
//// 
//// 计算机使用补码进行运算：6 - 3 = -3
//// 11111111 11111111 11111111 11111101   -> -3的补码
//// 
//// 因为 strlen()库函数 返回的是 unsighed int ，所以
//// 11111111 11111111 11111111 11111101 最高位 不再是 符号位 ， 而是 有效位 ，
//// 这是一个 大于0 且非常大的数 。


//#include <stdio.h>
//#include <string.h>
//int main()
//{
//
//	if (strlen("abc") - strlen("abcdef") > 0)
//	{
//		printf("haha\n");
//	}
//	else
//	{
//		printf("gaga\n");
//	}
//	// 打印 haha
//	
//	return 0;
//}


//#include <stdio.h>
//#include <assert.h>
//int my_strlen(const char* str) 
//{
//	assert(str != NULL); 
//
//	int count = 0; 
//
//	while (*str) // while (*str != '\0') 可以改成 while (*str) ，
//		         // 因为 '\0' 在运算中 使用的是 ASCII码值 ，即 0 ，
//				 // *str != '\0 即 *str != 0 ，而 while()循环 非0为真 则进入循环， 0为假 则不进入循环，
//				 // *str 刚好满足 while()循环 的判断条件，
//				 // 所以可以写成 while(*str) 。
//	{
//		count++; 
//		str++; 
//	}
//
//	return count; 
//
//}
//
//int main()
//{
//	int len = my_strlen("abcdef");
//
//	printf("%d\n", len); //打印 6
//
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>
//int my_strlen(const char* str) // 传过来的是 字符串"abcdef" 的 首字符 的 地址，所以用 char*字符指针 接收
//                               // char* str 被 const 修饰 具有了 常属性
//{
//	assert(str != NULL); // assert()库函数 即 断言 ，需要引用 <assert.h>头文件
//	                     // assert() 括号内 表达式 为真 则无事发生， 为假 则报错。
//
//	int count = 0; // 计数器，用来计算字符串中 '\0' 之前有多少个字符
//
//	while (*str != '\0') // 本题 不需要修改 str指针 指向字符 的 内容，
//		                 // 注意 不是 指向字符串 的 内容 ， str 是 字符串首字符的地址 ， *str 只能访问 一个字符，
//		                 // 当 char* str 具有了 常属性 ，就不能被修改，
//		                 // 可以有效防止 str指针 指向字符 的 内容 被修改。
//	{
//		count++; // 该字符不是 '\0' ，则计数器加一。
//		str++; // 指针指向下一个字符
//	}
//	
//	return count; // while()循环 结束后，说明 计算字符长度 结束，返回 计数器的值
//
//}
//
//int main()
//{
//	int len = my_strlen("abcdef");
//
//	printf("%d\n", len); //打印 6
//
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	// strlen()库函数 计算字符串中 '\0' 之前有多少个字符，其中 '\0' 不计算在内。
//
//	char arr2[] = { 'a','b','c','d','e','f' }; // 内存中存了 'a','b','c','d','e','f'
//	
//	char arr3[] = { "abc def" }; // 内存中存了 'a','b','c',' ','d','e','f'
//
//	int len1 = strlen("abcdef"); // 内存中存了 'a','b','c','d','e','f','\0'
//	printf("len1 = %d\n", len1); // 输出 len1 = 6
//	// 字符串 '\0' 之前有 6 个字符
//
//	int len2 = strlen(arr2);
//	printf("len2 = %d\n", len2); // 输出 len1 = 33(随机值)
//	// 字符串没有 '\0' ，而 strlen()库函数 会越界访问，直到找到 '\0' 为止，但什么时候找到 '\0' 是未知的，所以 输出随机值。
//
//	int len3 = strlen(arr3);
//	printf("len3 = %d\n", len3); // 输出 len1 = 7
//	// 字符串 '\0' 之前有 6 个字符 ，
//	// 可见 strlen()库函数 会把 ' '空格 作为一个字符，而不是找到 ' '空格 就停止计算， strlen()库函数 只有遇到 '\0' 才停止计算。
//
//	return 0;
//}



//#include <stdio.h>
//int my_strlen(char* arr)
//{
//	if (*arr == '\0')
//	{
//		return 0;
//	}
//	else
//	{
//		return 1 + my_strlen(arr + 1);
//	}
//}
//
//int main()
//{
//	int len = my_strlen("a b c d e f");
//
//	printf("%d\n", len);
//
//	return 0;
//}



//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	if (strlen("abc") - strlen("abcdef") > 0)
//	{
//		printf("hehe\n");
//	}
//	else
//	{
//		printf("haha\n");
//	}
//
//	return 0;
//}



//#include <stdio.h>
//int my_strlen(char* arr)
//{
//	int count = 0;
//
//	while (*arr)
//	{
//		count++;
//		arr++;
//	}
//
//	return count;
//}
//
//int main()
//{
//	int len = my_strlen("a b c d e f");
//
//	printf("%d\n", len);
//
//	return 0;
//}