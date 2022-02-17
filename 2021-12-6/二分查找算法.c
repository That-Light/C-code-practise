#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };   //需要查找的数组
//
//	int k = 7;   //需要查找的值
//
//	int left = 0;   //左下标
//
//	int sz = sizeof(arr) / sizeof(arr[0]);   //求出数组中有多少个数
//	int right = sz - 1;   //右下标
//
//	   //二分查找法
//	while (left <= right)   //当找不到k时，因为 right-1 、 left + 1 ，最终 left 和 right 会交叉
//	{
//		int mid = (left + right) / 2;   //中间下标
//
//		if (arr[mid] > k)   //当 arr[mid] 比 k 大时，证明 k 在 arr[mid] 左边 ，应修改 right
//		{
//			right = mid - 1;   //为什么 -1 ，因为 arr[mid] 已经比 k 大了 ，只需从 arr[mid-1] 开始比较
//		}
//		else if (arr[mid] < k)   //当 arr[mid] 比 k 小时，证明 k 在 arr[mid] 右边 ，应修改 left
//		{
//			left = mid + 1;   //为什么 +1 ，因为 arr[mid] 已经比 k 小了 ，只需从 arr[mid+1] 开始比较
//		}
//		else   //如果写成 else (arr[mid] == k); 记得有一个“;”
//		{
//			printf("找到了，下标为 %d", mid);
//			break;   //找到了要跳出循环，否则继续循环会影响下面判断→输出“没有找到”
//		}
//	}
//
//	if (left > right)   //当找不到k时，因为 right-1 、 left + 1 ，最终 left 和 right 会交叉
//	{
//		printf("没有找到");
//	}
//
//	return 0;
//}