#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void Change(int arr1[],int arr2[],int sz)
{
	int k = 0;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		k = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = k;
	}
}

void Print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr1[5] = { 1,2,3,4,5 };
	int arr2[5] = { 5,4,3,2,1 };

	int sz = sizeof(arr1) / sizeof(arr1[0]);

	Change(arr1, arr2, sz);

	Print(arr1, sz);
	Print(arr2, sz);

	return 0;
}

//#include <stdio.h>
//void Print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void Reverse(int arr[], int sz)
//{
//	int k = 0;
//	int i = 0;
//	for (i = 0; i < sz / 2; i++)
//	{
//		k = arr[i];
//		arr[i] = arr[9 - i];
//		arr[9 - i] = k;
//	}
//}
//
//int main()
//{
//
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	Print(arr, sz);
//
//	Reverse(arr, sz);
//
//	Print(arr, sz);
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//
//	int* arr[3] = { &a,&b,&c }; // int* arr[3] 为 指针数组 ，包含 3个元素
//
//	printf("%d\n", *(arr[1])); //可以使用 *解引用操作符 对 指针数组 进行解引用操作，
//	                           //得到 指针数组 中 某个 元素 存放的 内容(即 地址) 所指向的 值
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//
//	int** ppa = &pa; //二级指针(重点理解)
//
//	int*** pppa = &ppa; //三级指针
//	                    //按此递推可以得到 N级指针
//
//	**ppa = 20;               //二级指针的使用： 取了几次地址 就 解几次引用
//	printf("%d\n", **ppa);    //打印 20
//
//	return 0;
//}

//#define N_VALUES 5 //定义一个叫 N_VALUES 的 常变量 ，其值为 5
//int main()
//{
//	float values[N_VALUES];
//	float* vp;
//
//	for (vp = &values[N_VALUES - 1]; vp >= &values[0]; vp--)// vp = &values[N_VALUES - 1] 相当于是对 vp这个指针 指向的位置 进行修改(即 初始化)
//												            //
//														    // vp >= &values[0] 是 指针的关系运算(即 比较大小)
//	{
//		*vp = 0;
//	}
//
//
//	return 0;
//}

//#define N_VALUES 5 //定义一个叫 N_VALUES 的 常变量 ，其值为 5
//int main()
//{
//	float values[N_VALUES];
//	float* vp;
//
//	for (vp = &values[N_VALUES]; vp > &values[0];) // vp = &values[N_VALUES] 相当于是对 vp这个指针 指向的位置 进行修改(即 初始化)
//												   //
//												   // vp > &values[0] 是 指针的关系运算(即 比较大小)
//												   // 
//												   // 其中 调整阶段 为 空 ，vp 全由下面的 --vp 控制
//	{
//		*--vp = 0; // 其中 --操作符 的 优先级 高于 *解引用操作符 ，
//				   // 而且 是个 前置-- ，相当于 先 --vp 再 使用*vp
//				   //即 先 vp--;
//				   //   再 *vp = 0; (此时 vp 已经 -1)
//	}
//
//	return 0;
//}

//#include <stdio.h>
////用指针的方式模拟strlen()
//int my_strlen(char* str)
//{
//	char* start = str; //创建 指针变量 并 初始化
//	char* end = str; //创建 指针变量 并 初始化
//	
//	while (*end != '\0') //这里要知道 end指针变量 对应了什么值，所以要进行 解引用操作
//	{
//		end++;
//	}
//	return end - start; //这里 指针 相减 得到的是 数组元素的个数 ，不用解引用操作
//}
//
//int main()
//{
//	char arr[] = "happy"; // 在 内存中 存放了 h a p p y '\0'
//	
//	int len = my_strlen(arr);
//
//	printf("len = %d\n", len);
//	
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	printf("%d\n", &arr[9] - &arr[0]); //打印  9 ，大地址 减 小地址 为 正数
//
//	printf("%d\n", &arr[0] - &arr[9]); //打印 -9 ，小地址 减 大地址 为 负数
//
//	return 0;
//}
////地址-地址 的绝对值是 数组元素 的 个数 ，小地址减大地址是

//#define N_VALUES 5 //定义一个叫 N_VALUES 的 常变量 ，其值为 5
//int main()
//{
//	float values[N_VALUES]; //创建一个 float类型 的 数组 ，名字叫 values ，里面有 N_VALUES 个元素，即 5 个元素
//
//	float* vp; //创建一个叫 vp 的 float类型 的 指针变量 ，
//			   // 这里为什么 不是 局部变量未初始化 ，产生 野指针 ？
//			   // 因为 野指针 是指对 位置不可知的地址 进行了 操作 ，
//			   //     而 没有操作时 它还是正常的指针，只是这个 指针 指向的位置 不可知(随机的)，
//			   //     当我们后面对 这个指针 指向的位置 进行修改(即 初始化)，注意不是 对这个指针 指向的位置 的值 进行修改(这样就是 野指针)，
//			   //     才可以  对这个指针 指向的位置 的值 进行修改。
//
//	for (vp = &values[0]; vp < &values[N_VALUES];) // vp = &values[0] 相当于是对 vp这个指针 指向的位置 进行修改(即 初始化)
//												   //
//												   // vp < &values[N_VALUES] 是 指针的关系运算(即 比较大小)
//												   // 
//												   // 其中 调整阶段 为 空 ，vp 全由下面的 vp++ 控制
//
//	{
//		*vp++ = 0; // 其中 ++操作符 的 优先级 高于 *解引用操作符 ，
//				   // 但是 是个 后置++ ，相当于 先使用 *vp 然后 vp 再 ++
//				   //即 先 *vp = 0 ;
//				   //   再 vp++;
//	}
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	
//	int* p1 = arr; // 数组名 是 首元素地址 ，本来就是 地址 ，不用 &取地址操作符
//	
//	int* p2 = &arr[9]; // 取 arr数组中 下标为9 的 元素 的 地址 ，即 arr数组中 的 10 的 地址
//
//	int i = 0;
//	for (i = 0; i < 5; i++) //注意下面 p1 每次循环 +2 ，所以 i < 5 即可，如果设置 i < 10 会产生 野指针
//	{
//		printf("%d ", *p1); //打印 1 3 5 7 9
//		p1 += 2;
//	}
//	printf("\n");
//	for (i = 0; i < 5; i++) //注意下面 p2 每次循环 -2 ，所以 i < 5 即可，如果设置 i < 10 会产生 野指针
//	{
//		printf("%d ", *p2); //打印 10 8 6 4 2
//		p2 -= 2;
//	}
//
//	return 0;
//}

//#include <stdio.h>
//int* test()
//{
//	int a = 10;
//	return &a;
//}
//int main()
//{
//	int* p = test();
//
//	*p = 20; // 指针指向的空间已经释放，无法找到该地址
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int arr[10] = { 0 };
//    int* p = arr;
//    int i = 0;
//    for (i = 0; i <= 11; i++)
//    {
//        p++; //当指针指向的范围超出数组arr的范围时，p就是野指针
//    }
//    return 0;
//}


//#include <stdio.h>
//int main()
//{
//    int* p; //局部变量指针未初始化，默认为随机值
//    *p = 20;
//    return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr; // 数组名 是 首元素地址
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = 1;
//	}
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 0x11223344;
//
//	int* pa = &a;
//	char* pc = &a;
//
//	printf("%p\n", pa);
//	printf("%p\n", pa+1);
//
//	printf("%p\n", pc);
//	printf("%p\n", pc+1);
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 0x11223344;
//
//	char* pa = &a;
//
//	*pa = 0;
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 0x11223344; // 0x 表示十六进制，其中 十六进制的1位 需要用 4位二进制表示，
//	                    //即 0x11223344 需要 32位二进制表示 ，
//	                    //即便是 32位操作系统 也能完整装下
//
//	int* pa = &a; 
//	char* pc = &a;
//
//	printf("%p\n", pa);
//	printf("%p\n", pc);
//
//	return 0;
//}