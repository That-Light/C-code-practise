//#define _CRT_SECURE_NO_WARNINGS

////冒泡排序
//#include <stdio.h>
//void bubble_sort(int arr[], int sz)   // int arr[] 的本质其实是 int* arr ，
//                                      //可以直接用 int arr[] ，则 函数传参 时要传 arr ， 函数中 数组的使用 也可以直接用 arr[i] ,
//	                                  //也可以用 int* arr ，则 函数传参 时要传 &arr ， 函数中 数组的使用 也可以直接用 arr[i] 。
//{
//	int i = 0;   //冒泡排序的趟数
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;   //每趟冒泡排序内的交换次数
//		for (j = 0; j < sz - i - 1; j++)   //循环判定中的 j < sz - i - 1 ，
//			                               //其中 sz - i 是 第几趟排序 ，即 只剩几个数 需要排序，
//			                               //        - 1 是 剩下需要排序的数 中，只需要对比 剩下需要排序的数的个数 - 1 次
//			                               
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 8,9,7,6,5,4,3,2,1 };   //待排序的数组
//
//	int sz = sizeof(arr) / sizeof(arr[0]);   //不能在 函数 内用这种方法求 数组元素的个数，
//	                                         //因为 数组传参 传过去的是 首元素的地址 ，并不是整个数组，
//	                                         //所以只能在 主函数 中先求得，然后再把 求得的数据 传进 函数。
//	
//	int i = 0;   //打印数组 得用 循环打印 的方式
//
//	bubble_sort(arr, sz);
//
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}



////冒泡排序(改进)
//#include <stdio.h>
//void bubble_sort(int arr[], int sz)   
//{
//	int i = 0;
//
//	int flag = 1;   //判定开关，排列的数据 已为 升序 则为 1 ，否则为 0
//
//	for (i = 0; i < sz - 1; i++)
//	{
//
//		flag = 1;   //假设，注意是 假设 ，假设 本层(即 i 层) 排列的数据已为升序 ，
//		            //每次进入 某层排序 flag 都会先置 1 ，
//		            //若 本层(即 i 层) 排序 不为 升序，则  会 进入 对比 ，会使 flag 置 0 ，
//		            //若 本层(即 i 层) 排序   为 升序，则不会 进入 对比 ， flag 仍为 1 。
//		 
//		int j = 0;   
//		for (j = 0; j < sz - i - 1; j++)   
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//
//				flag = 0;   // flag 置 0 ，说明 本层(即 i 层) 排序 不为 升序 ，后面 if判断 不会 跳出 循环，
//				            //将进入 下一层(即 i+1 层) 排序，进入 下一层(即 i+1 层) 时， flag 会重新置 1 。
//			}
//		}
//
//		if (flag == 1)   //若 flag == 1 ，即 排序已为升序 ，不必再进行下一层排序，可跳出循环
//		{
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,9,8 };   
//
//	int sz = sizeof(arr) / sizeof(arr[0]);   
//
//	int i = 0;
//
//	bubble_sort(arr, sz);
//
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}