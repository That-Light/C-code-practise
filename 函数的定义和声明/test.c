#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  //引用 C语言内部库 用 <>
#include "add.h"   //引用 自定义库 用 ""

int main()
{
	int a = 10;
	int b = 20;
	int sum = 0;

	//函数调用
	sum = Add(a, b);
	printf("sum = %d", sum);

	return 0;
}