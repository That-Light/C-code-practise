#define _CRT_SECURE_NO_WARNINGS

////  效果：
////  w#######################!
////  we#####################!!
////  wel###################!!!
////  welc#################!!!!
////  welco############### !!!!
////  welcom#############l !!!!
////  welcome###########ol !!!!
////  welcome #########ool !!!!
////  welcome t#######hool !!!!
////  welcome to#####chool !!!!
////  welcome to ###school !!!!
////  welcome to m# school !!!!
////  welcome to my school !!!!
//
////实现原理：两组字符串，用 文字 字符串，通过下标的方式，寻找并更改 # 字符串对应字符
//#include <stdio.h>
//#include <string.h>
//#include <windows.h>
//int main()
//{
//	char arr1[] = { "welcome to my school !!!!" };   // 文字 字符串
//	char arr2[] = { "#########################" };   //  #   字符串
//
//	int left = 0;   //左下标
//
//	int right = sizeof(arr1) / sizeof(arr1[0]) - 2;   //右下标为什么要 -2 ？ 因为：如字符串“1，2，3”，包含了“1，2，3，'\n'” ，如果只 -1 则对应 '\n'
//	//或 int right = strlen(arr1) - 1; 这里为什么只 -1 ？ 因为 srtlen 只计算字符串内元素个数，不包括字符串结束标志'\n'   ※strlen() 要引用库函数<string.h>
//
//	while (left <= right)   //当 left 大于 right 时，证明 文字 与 # 已经全部替换
//	{
//		arr2[left] = arr1[left];   //左边开始用 文字 替换 #
//		arr2[right] = arr1[right];   //右边开始用 文字 替换 #
//
//		printf("%s\n", arr2);   //打印字符串用 %s
//
//		left++;   //左下标 +1 ，向中间靠拢
//		right--;   //右下标 -1 ，向中间靠拢
//
//		Sleep(1000);//停顿 1000 毫秒 = 1 秒   ※Sleep() 要引用库函数<windows.h>   ※Sleep() 首字母必须大写
//	}
//
//	return 0;
//}