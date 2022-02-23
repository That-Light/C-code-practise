//#define _CRT_SECURE_NO_WARNINGS

////二维数组地址的打印
//#include <stdio.h>
//int main()
//{
//	int arr[3][4] = { {1,2,3},{4,5} };   
//
//	int i = 0;   
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;   
//		for (j = 0; j < 4; j++)
//		{
//			printf("&arr[%d][%d] = %p\n", i, j, &arr[i][j]);   //打印每一行中的元素的地址
//		}
//		printf("\n");   //打印完一行之后换行
//	}
//
//	return 0;
//}

////二维数组的打印
//#include <stdio.h>
//int main()
//{
//	int arr[3][4] = { {1,2,3},{4,5} };   //定义二维数组
//
//	int i = 0;   //循环打印的行
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;   //循环打印的列
//		for (j = 0; j < 4; j++)
//		{
//			printf("%d ", arr[i][j]);   //打印每一行中的元素
//		}
//		printf("\n");   //打印完一行之后换行
//	}
//
//	return 0;
//}



//#include <stdio.h>
//int main()
//{
//	int arr1[] = { 1,2,3,4 };
//	char arr2[] = "1234";
//	return 0;
//}



////一维数组的存储
//#include <stdio.h>
//int main()
//{
//    int arr[10] = { 0 };
//    int i = 0;
//    int sz = sizeof(arr) / sizeof(arr[0]);
//
//    for (i = 0; i < sz; ++i)
//    {
//        printf("&arr[%d] = %p\n", i, &arr[i]);
//    }
//    return 0;
//}
