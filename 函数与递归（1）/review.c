#define _CRT_SECURE_NO_WARNINGS


////��ŵ������
//#include <stdio.h>
//int count(int k)
//{
//	if (k > 1)
//	{
//		return 1 + 2 * count(k - 1);
//	}
//	return 1;
//}
//
//int main()
//{
//	int input = 0;
//
//	printf("�����룺");
//	scanf("%d", &input);
//
//	int num = count(input);
//
//	printf("������Ҫ�ƶ� %d ��\n",num);
//
//	return 0;
//}



////������̨��
////һֻ���ܣ�һ������ 1�� ���� 2�� ̨�ף��������� ��n��̨�� �� ����������
//#include <stdio.h>
//int jump1(int n)
//{
//	if (n > 2)
//	{
//		return jump1(n - 1) + jump1(n - 2);
//	}
//	else if (n == 2)
//		return 2;
//	else if (n == 1)
//	{
//		return 1;
//	}
//	return 0;
//}
//
//int jump2(int n)
//{
//	int a = 0;
//	int b = 1;
//	int c = 0;
//	while (n >= 1)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//
//int main()
//{
//	int input = 0;
//
//	printf("������̨������");
//	scanf("%d", &input);
//
//	//int num1 = jump1(input);
//	//
//	//printf("�� %d ������\n", num1);
//
//	int num2 = jump2(input);
//
//	printf("�� %d ������\n", num2);
//
//	return 0;
//}


////��ŵ������
//#include <stdio.h>
//int hnt(int t)
//{
//	if (t > 1)
//	{
//		return 1 + 2*hnt(t - 1);
//	}
//	return 1;
//}
//
//int main()
//{
//	int input = 0;
//
//	printf("���ٲ㺺ŵ����-��");
//	scanf("%d", &input);
//
//	int reb = hnt(input);
//
//	printf("������Ҫ���� %d ��\n", reb);
//
//	return 0;
//}



////쳲��������У�1  1  2  3  5  8  13  21  34  55  89 ����
////���� ǰ�������� �� �� ����Ȼ��Ҫ������һ�ڶ������� 1  1
////��� n �� 쳲�������
//#include <stdio.h>
//int fbnq2(int x)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	
//	int i = 0;
//
//	while (x > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		x--;
//	}
//	return c;
//
//}
//
//int fbnq1(int x)
//{
//	int x1 = 1;
//	int x2 = 2;
//
//	if (x <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return fbnq1(x - 1) + fbnq1(x - 2);
//	}
//}
//
//int main()
//{
//	int input = 0;
//
//	printf("��ڼ���쳲���������-��");
//	scanf("%d", &input);
//
//	//int reb1 = fbnq1(input);
//
//	//printf("reback1 = %d\n", reb1);
//
//	int reb2 = fbnq2(input);
//
//	printf("reback2 = %d\n", reb2);
//
//	return 0;
//}



////n�Ľ׳�
//#include <stdio.h>
//int n_mul(int x)
//{
//	int i = 0;
//	int reb = 1;
//
//	for (i = 1; i <= x; i++)
//	{
//		reb *= i;
//	}
//	return reb;
//}
//
//int main()
//{
//	int input = 0;
//
//	printf("�����룺");
//	scanf("%d", &input);
//
//	int reb = n_mul(input);
//
//	printf("%d", reb);
//
//	return 0;
//}



////ģ��ʵ��һ�� ���� ���ַ�������
//#include <stdio.h>
//int my_strlen(char* str)
//{
//
//	if (*str != '\0')
//	{
//		return 1 + my_strlen(str + 1);
//	}
//		return 0;
//}
//
//int main()
//{
//	char arr[] = "happy!";
//
//	int len = my_strlen(arr);
//
//	printf("len = %d", len);
//
//	return 0;
//}



////����1234�����1 2 3 4
//#include <stdio.h>
//void print(int x)
//{
//	if (x >9)
//	{
//		print(x / 10);
//	}
//	printf("%d ", x % 10);
//
//}
//
//int main()
//{
//	int input = 0;
//
//	printf("�����룺");
//	scanf("%d", &input);
//
//	print(input);
//
//	return 0;
//}


////�ú���ģ�� strlen()
//#include <stdio.h>
//int my_strlen(char* x)
//{
//	if (*x != '\0')
//	{
//		return 1 + my_strlen(x+1);
//	}
//	return 0;
//
//}
//
//int main()
//{
//	char arr[] = "happy new year!!!";
//
//	int num = my_strlen(arr);
//
//	printf("strlen = %d", num);
//
//	return 0;
//}

////����1234�����1 2 3 4
//#include <stdio.h>
//
//void print(int x)
//{
//	if (x > 9)
//	{
//		print(x / 10);
//	}
//		printf("%d ", x%10);
//}
//
//int main()
//{
//	int input = 0;
//
//	printf("�����룺");
//	scanf("%d", &input);
//
//	print(input);
//
//	return 0;
//}



//#include <stdio.h>
//#include "add.h"
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	
//	//int sum = add(a, b);
//
//	printf("sum = %d\n", add(a, b));
//
//	return 0;
//}

//#include <stdio.h>
//
//void swap(int* x, int* y);
//
//int main()
//{
//
//	int a = 10;
//	int b = 20;
//	printf("a = %d , b = %d \n", a, b);
//
//	swap(&a, &b);
//	printf("a = %d , b = %d \n", a, b);
//	return 0;
//}
//
//void swap(int* x, int* y)
//{
//	int ret = 0;
//	ret = *x;
//	*x = *y;
//	*y = ret;
//}



////����д��
//#include <stdio.h>
//int binary_search(int arr[], int k)
//{
//	int left = 0;
//
//	int sz = sizeof(arr) / sizeof(arr[0]);   //�٣��� ���� ͨ�� ���� �ķ�ʽ���� ���� ��ʱ�����������ַ�����Ԫ�ظ���
//	                                         //�ڣ� ���� ��һ�� �����Ŀռ� �� ���� �� ���� ��ʱ�򣬲��Ǵ��������飬��������ȥ ���� ��һ��Ԫ�� �� ��ַ ��
//	                                         //    ���� �����Ĳ��� int arr[] ���� ���� ������һ�� ָ�� ��
//	                                         //     ָ�� �� 32λ����ϵͳ ���� 4 �� �ֽ� ���� 64λ����ϵͳ ���� 8 �� �ֽ� ��
//	                                         //    arr[0] �� ���� �� 4 �� �ֽ� ����������� sz Ϊ 2
//	int right = sz - 1;
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//
//	int ret = binary_search(arr, k);// arr ���ݹ�ȥ���� ����arr �� ��һ��Ԫ�� �� ��ַ
//
//	if (ret == -1)
//	{
//		printf("�Ҳ���ָ������\n");
//	}
//	else
//	{
//		printf("�ҵ��ˣ��±��ǣ�%d\n", ret);
//	}
//
//	return 0;
//}

////��ȷд��
//#include <stdio.h>
//int binary_search(int arr[], int k,int sz)
//{
//	int left = 0;
//
//	int right = sz - 1;
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//
//	int sz = sizeof(arr) / sizeof(arr[0]);   //�� ���� �ⲿ���� ������ ���棩��
//	                                         //����� ����arr �� Ԫ�صĸ��� ��
//	                                         //��ͨ�� ���� �ķ�ʽ�����Ѿ��ó��� ����Ԫ�ظ��� ���� ���� ��
//
//	int ret = binary_search(arr, k, sz);
//
//	if (ret == -1)
//	{
//		printf("�Ҳ���ָ������\n");
//	}
//	else
//	{
//		printf("�ҵ��ˣ��±��ǣ�%d\n", ret);
//	}
//
//	return 0;
//}



//#include <stdio.h>
//
////��������
//����int Add(int x, int y);
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int sum = 0;
//
//	//��������
//	sum = Add(a, b);
//	
//	printf("sum = %d\n", sum);
//	return 0;
//}
//
////��������
//int Add(int x, int y)
//{
//	int z = x + y;
//	return z;
//}