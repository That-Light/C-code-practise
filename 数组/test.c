//#define _CRT_SECURE_NO_WARNINGS

////��ά�����ַ�Ĵ�ӡ
//#include <stdio.h>
//int main()
//{
//	int arr[3][4] = { {1,2,3},{4,5} };   
//
//	int i = 0;   
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;   
//		for (j = 0; j < 4; j++)
//		{
//			printf("&arr[%d][%d] = %p\n", i, j, &arr[i][j]);   //��ӡÿһ���е�Ԫ�صĵ�ַ
//		}
//		printf("\n");   //��ӡ��һ��֮����
//	}
//
//	return 0;
//}

////��ά����Ĵ�ӡ
//#include <stdio.h>
//int main()
//{
//	int arr[3][4] = { {1,2,3},{4,5} };   //�����ά����
//
//	int i = 0;   //ѭ����ӡ����
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;   //ѭ����ӡ����
//		for (j = 0; j < 4; j++)
//		{
//			printf("%d ", arr[i][j]);   //��ӡÿһ���е�Ԫ��
//		}
//		printf("\n");   //��ӡ��һ��֮����
//	}
//
//	return 0;
//}



//#include <stdio.h>
//int main()
//{
//	int arr1[] = { 1,2,3,4 };
//	char arr2[] = "1234";
//	return 0;
//}



////һά����Ĵ洢
//#include <stdio.h>
//int main()
//{
//    int arr[10] = { 0 };
//    int i = 0;
//    int sz = sizeof(arr) / sizeof(arr[0]);
//
//    for (i = 0; i < sz; ++i)
//    {
//        printf("&arr[%d] = %p\n", i, &arr[i]);
//    }
//    return 0;
//}
