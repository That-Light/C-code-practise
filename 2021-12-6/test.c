#define _CRT_SECURE_NO_WARNINGS


////�˷��ھ���
////����Ļ�����9*9�˷��ھ���
//#include <stdio.h>
//int main()
//{
//	int i = 0, j = 0;
//	
//	for (i = 1; i <= 9; i++)
//	{
//
//		for (j = 1; j <= i; j++)
//		{
//
//				printf("%d*%d=%-2d ", i, j, i * j);
//
//		}
//
//		printf("\n");
//	}
//
//
//	return 0;
//}





////�����ֵ
////��10�������е����ֵ
//#include <stdio.h>
//int main()
//{
//	int arr[10]={0};
//	int max = arr[0];
//	int i;
//	printf("������10��������");
//	scanf("%d%d%d%d%d%d%d%d%d%d",&arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6], &arr[7], &arr[8], &arr[9]);
//	
//	for (i = 0; i <= 9; i++)
//	{
//		if (max < arr[i])
//			max = arr[i];
//	}
//	printf("��������Ϊ��%d", max);
//	return 0;
//}





////�������
////����1/1-1/2+1/3-1/4+1/5����+1/99-1/100��ֵ����ӡ�����
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	float a = 0;
//	float sum = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 == 1)
//		{
//			a = 1.000000 / i;
//		}
//		else if (i % 2 == 0)
//		{
//			a = -1.000000 / i;
//		}
//
//		sum = sum + a;
//	}
//	printf("sum = %f", sum);
//
//	return 0;
//}





////��1~100�У�9�ĸ���
////��д������һ��1~100�����������г��ֶ��ٸ�����9
//#include <stdio.h>
//int main()
//{
//	int a, gw, sw;
//	int sl = 0;
//
//	for (a = 1; a <= 100; a++)
//	{
//		gw = a % 10;
//		sw = a / 10;
//		if (gw == 9)
//		{
//			sl++;
//		}
//		if (sw == 9)
//		{
//			sl++;
//		}
//	}
//	printf("����9������Ϊ��%d", sl);
//
//	return 0;
//}





////��ӡ100~200֮�������
////������������������1��������û��������������Ȼ��
////���Գ���---�������
//#include <stdio.h>
//int main()
//{
//	int i;
//	int a;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		for (a = 2; a < i; a++)
//		{
//			if (i % a == 0)
//			{
//				break;
//			}
//			else if (a == i-1)
//			{
//				printf("������%d\n", i);
//				count++;
//			}
//		}
//
//	}
//	printf("��������Ϊ��%d", count);
//
//	return 0;
//}

////���Ż�------���һ��������������һ�����ҵ��������һ�� ���� С�ڵ��� ������Ŀ�ƽ��
////��ƽ���⺯�� sqrt() ��������ͷ�ļ� <math.h>
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int i;
//	int a;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		for (a = 2; a < sqrt(i); a++)   //����
//		{
//			if (i % a == 0)
//			{
//				break;
//			}
//
//		}
//		if (a > sqrt(i))   //����---����ж� ���� ��������һ�� forѭ�� �У���Ϊ a > sqrt(i) �� �� ���� forѭ�� ���ˣ�����Ҳ���ò�׽ a �� sqrt(i) ��׼ȷ��ϵ
//		{
//			printf("������%d\n", i);
//			count++;
//		}
//
//	}
//	printf("��������Ϊ��%d", count);
//
//	return 0;
//}

//���Ż�------���һ��������������һ�����ҵ��������һ�� ���� С�ڵ��� ������Ŀ�ƽ��
//��ƽ���⺯�� sqrt() ��������ͷ�ļ� <math.h>
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int i;
//	int a;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		for (a = 2; a < sqrt(i); a++)   //����
//		{
//			if (i % a == 0)
//			{
//				break;
//			}
//			else if (a > sqrt(i)-1)   //����---������жϷŻ������ forѭ�� ���棬��Ϊ a > sqrt(i) �Ͳ��ٽ���ѭ�����Ǽ���һ�� -1 ���ܴ��ȷ�����һ�� a ��
//				                      �����ַ������ã���Ϊ i��ƽ����С�� ��˭֪�� sqrt(i)-1 ��һ�������һ�� a С�أ���
//				                      �����Ƽ�����ڵ�д��������Ǣٵ�д������Ϊ i ����������ô�Ŷ��ܿ϶����жϡ�
//			{
//				printf("������%d\n", i);
//				count++;
//			}
//		}
//
//	}
//	printf("��������Ϊ��%d", count);
//
//	return 0;
//}





////1000~2000��֮�������
////���꣺���ܱ�4���������ܱ�100�����������ꣻ���ܱ�400������������
//#include <stdio.h>
//int main()
//{
//	int year;
//	int count = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (year % 4 == 0)
//		{
//			if (year%400 ==0)
//			{
//				printf("���꣺%d\n", year);
//				count++;
//			}
//			else if (year % 100 == 0)
//			{
//				;
//			}
//			else
//			{
//				printf("���꣺%d\n", year);
//				count++;
//			}
//		
//		}
//	}
//	printf("���������%d", count);
//
//	return 0;
//}





////���Լ��------շת�����
//#include <stdio.h>
//int main()
//{
//	int a, b, c;
//
//	printf("��������������");
//	scanf("%d%d", &a, &b);
//
//	//�ϴ����Ϊ����������С����Ϊ����
//	if (a < b)
//	{
//		c = a;
//		a = b;
//		b = c;
//	}
// 
//	//շת�����
//	while (a % b != 0)
//	{
//		c = a;
//		a = b;
//		b = c % b;
//	}
//
//	printf("���Լ��Ϊ��%d",  b);     //��������ʽ���У�������Ϊ���Լ��
//
//	return 0;
//}





////��ҵ����ӡ1~100֮��3�ı���
//#include <stdio.h>
//int main()
//{
//	int i;
//
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0)
//		{
//			printf("%d\n", i);
//		}
//	}
//	return 0;
//}





////��ҵ��3�������Ӵ�С���
//#include <stdio.h>
//int main()
//{
//
//	int a, b, c;
//	printf("������������");
//	scanf("%d%d%d", &a, &b, &c);
//
//	int arr[3] = { 0 };
//	if (a > b && a > c)
//	{
//		arr[0] = a;
//		if (b > c)
//		{
//			arr[1] = b;
//			arr[2] = c;
//		}
//		else
//		{
//			arr[2] = b;
//			arr[1] = c;
//		}
//	}
//	else if (a > b && a < c)
//	{
//		arr[1] = a;
//		arr[0] = c;
//		arr[2] = b;
//	}
//	else if (a > c && a < b)
//	{
//		arr[1] = a;
//		arr[0] = b;
//		arr[2] = c;
//	}
//	else
//	{
//		arr[2] = a;
//		if (b > c)
//		{
//			arr[0] = b;
//			arr[1] = c;
//		}
//		else
//		{
//			arr[1] = b;
//			arr[0] = c;
//		}
//	}
//
//	printf("%d %d %d", arr[0], arr[1],arr[2]);
//
//	return 0;
//}





////��¼����
//#include<stdio.h>
//int main()
//{
//	char password[20] = {0};
//	int i = 0;
//
//	while (i < 3)
//	{
//		printf("���������룺");
//		scanf("%s", password);
//
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("��¼�ɹ�\n");
//			break;
//		}
//		else
//		{
//			if (i < 2)
//			{
//				printf("��¼ʧ�ܣ�����%d�λ���\n", 2 - i);
//			}
//			i++;
//		}
//	}
//
//	if (i == 3)
//	{
//		printf("������������������˳�����\n");
//	}
//
//	return 0;
//}





////�ַ��滻*��
//#include <stdio.h>
//#include <string.h>
//#include <Windows.h>
//#include <stdlib.h>
//int main()
//{
//
//	char arr1[] = "welcome to my home !!!!";
//	char arr2[] = "***********************";
//
//	int left = 0;
//
//	int right = strlen(arr1) - 1;
//	//�� int right = sizeof(arr1) / sizeof(arr[0]) - 2;
//
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		left++;
//		right--;
//
//		Sleep(1000);
//
//		system("cls");
//	}
//
//	return 0;
//}






////���ַ�����
//#include <stdio.h>
//int main()
//{
//
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	int k = 7;
//
//	int left = 0;
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int right = sz - 1;
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("�ҵ��ˣ��±�Ϊ��%d", mid);
//			break;
//		}
//	}
//
//	if (left > right)
//	{
//		printf("�Ҳ���");
//	}
//
//	return 0;
//}