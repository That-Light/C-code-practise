#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  //���� C�����ڲ��� �� <>
#include "add.h"   //���� �Զ���� �� ""

int main()
{
	int a = 10;
	int b = 20;
	int sum = 0;

	//��������
	sum = Add(a, b);
	printf("sum = %d", sum);

	return 0;
}