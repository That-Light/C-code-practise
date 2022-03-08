#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//int main()
//{
//	int a = 10;
//
//	int b = 20
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	const int num = 10;
//	int* p = &num;
//
//	int n = 30;
//
//	num = 20; //报错，不能把 num 修改成 20
//
//	*p = 40; //正常，能把 num 修改成 40
//
//	p = &n; //正常，能把 p 修改成 n的地址
//
//	printf("num = %d", num);
//
//	return 0;
//}

//#include <stdio.h>
//#include <assert.h>
//void my_strcmp(char* dest, const char* src) // char* src 被 const 修饰 具有了 常属性
//{
//	assert(dest != NULL); 
//	assert(src != NULL);  
//	                     
//	while (*src++ = *dest++) // 当 char* src 具有了 常属性 ，就不能被修改，
//		                     // 可以有效防止代码写反的情况，
//		                     // 正确应该是 *dest++ = *src++
//	{
//		;
//	}
//}
//
//int main()
//{
//	char arr1[] = "#########";
//	char arr2[] = "hello";
//
//	my_strcmp(arr1, NULL);
//
//	printf("%s\n", arr1);
//
//	return 0;
//}



//#include <stdio.h>
//int main()
//{
//    int i = 0;
//    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//
//    printf("%p\n", &i);
//    printf("%p\n", arr);
// 
//    //for (i = 0; i <= 11; i++)
//    //{
//    //    arr[i] = 0;
//    //     printf("hehe\n");
//    //}
//    return 0;
//}



















//#include <stdio.h>
//void test3()
//{
//	printf("hehe\n");
//}
//void test2()
//{
//	test3();
//}
//void test1()
//{
//	test2();
//}
//int main()
//{
//	test1();
//	return 0;
//}

//#include <stdlib.h>
//int main()
//{
//	int i = 0;
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n", i);
//	}
//
//	for (i = 10; i < 20; i++)
//	{
//		printf("%d\n", i);
//	}
//
//	system("pause");
//
//}