#define _CRT_SECURE_NO_WARNINGS

//给定一个非空整型数组，
//除了某个元素只出现一次以外，
//其余每个元素均出现两次，
//找出那个只出现了一次的元素。

//样例：
//int arr[] = { 1,2,3,4,5,1,2,3,4} ，
//该数组中只有 5 出现了 一次 ，
//其他数字 都出现了 两次 ，
//要找出数字 5 。

#include <stdio.h>
int main()
{
	int arr[] = { 1,2,3,4,5,1,2,3,4 };

	//按位异或的方法
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	
	int ret = 0;   //存放结果

	for (i = 0; i < sz; i++)
	{
		ret = ret ^ arr[i];
	}
	printf("只出现一次的数：%d\n", ret);

	return 0;
}


//#include <stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,1,2,3,4 };
//
//	//笨方法
//	int i = 0;
//	int j = 0;
//	int count = 0;   //计数器
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	for (i = 0; i < sz; i++)
//	{
//		count = 0;   //每次重置计数器
//
//		for (j = 0; j < sz; j++)
//		{
//			if (arr[i] == arr[j])
//			{
//				count++;
//			}
//		}
//
//		if (count == 1)
//		{
//			printf("只出现一次的数：%d\n", arr[i]);
//			break;
//		}
//	}
//
//	return 0;
//}