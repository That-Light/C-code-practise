#define _CRT_SECURE_NO_WARNINGS

////��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
////���磺2 + 22 + 222 + 2222 + 22222
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int input = 0;
//	int i = 0;
//	int sum = 0;
//	int num = 0;
//
//	printf("������һ����λ����");
//	scanf("%d", &input);
//
//	//����ÿ����
//	for (i = 0; i < 5; i++)
//	{
//		num = num + input * pow(10, i);
//		sum = sum + num;
//	}
//	printf("sum = %d", sum);
//}


////���0��999֮������С�ˮ�ɻ����������
////��ˮ�ɻ�������ָһ����λ�������λ���ֵ�������ȷ�õ��ڸ��������磻153��1��5��3?����153��һ����ˮ�ɻ�����
//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int i = 0;
//	int sum = 0;
//
//	for (i = 100; i <= 999; i++)
//	{
//		sum = pow(i/100,3)+pow((i/10)%10, 3)+pow(i%10,3);
//		if (i == sum)
//		{
//			printf("%d\n", i);
//		}
//	}
//
//
//	return 0;
//}



////��ӡͼ��
//#include <stdio.h>
//int main()
//{
//	char arr1[] = { "*************" };
//	char arr2[] = { "             " };
//	char arr3[] = { "             " };
//
//	int left = 0;
//
//	int sz = sizeof(arr2) / sizeof(arr2[0]);
//	int right = sz - 2;
//
//	int mid = (left + right) / 2;
//
//	left = mid;
//	right = mid;
//
//	while (right != 13)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		left--;
//		right++;
//	}
//
//	left = 0;
//	right = sz - 2;
//
//	while (left <= right)
//	{
//		arr1[left] = arr3[left];
//		arr1[right] = arr3[right];
//		printf("%s\n", arr1);
//		left++;
//		right--;
//	}
//
//	return 0;
//}