#define _CRT_SECURE_NO_WARNINGS

//����һ���ǿ��������飬
//����ĳ��Ԫ��ֻ����һ�����⣬
//����ÿ��Ԫ�ؾ��������Σ�
//�ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�

//������
//int arr[] = { 1,2,3,4,5,1,2,3,4} ��
//��������ֻ�� 5 ������ һ�� ��
//�������� �������� ���� ��
//Ҫ�ҳ����� 5 ��

#include <stdio.h>
int main()
{
	int arr[] = { 1,2,3,4,5,1,2,3,4 };

	//��λ���ķ���
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	
	int ret = 0;   //��Ž��

	for (i = 0; i < sz; i++)
	{
		ret = ret ^ arr[i];
	}
	printf("ֻ����һ�ε�����%d\n", ret);

	return 0;
}


//#include <stdio.h>
//int main()
//{
//	int arr[] = { 1,2,3,4,5,1,2,3,4 };
//
//	//������
//	int i = 0;
//	int j = 0;
//	int count = 0;   //������
//
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	for (i = 0; i < sz; i++)
//	{
//		count = 0;   //ÿ�����ü�����
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
//			printf("ֻ����һ�ε�����%d\n", arr[i]);
//			break;
//		}
//	}
//
//	return 0;
//}