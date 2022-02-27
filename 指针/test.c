#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void Change(int arr1[],int arr2[],int sz)
{
	int k = 0;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		k = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = k;
	}
}

void Print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr1[5] = { 1,2,3,4,5 };
	int arr2[5] = { 5,4,3,2,1 };

	int sz = sizeof(arr1) / sizeof(arr1[0]);

	Change(arr1, arr2, sz);

	Print(arr1, sz);
	Print(arr2, sz);

	return 0;
}

//#include <stdio.h>
//void Print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void Reverse(int arr[], int sz)
//{
//	int k = 0;
//	int i = 0;
//	for (i = 0; i < sz / 2; i++)
//	{
//		k = arr[i];
//		arr[i] = arr[9 - i];
//		arr[9 - i] = k;
//	}
//}
//
//int main()
//{
//
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	Print(arr, sz);
//
//	Reverse(arr, sz);
//
//	Print(arr, sz);
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//
//	int* arr[3] = { &a,&b,&c }; // int* arr[3] Ϊ ָ������ ������ 3��Ԫ��
//
//	printf("%d\n", *(arr[1])); //����ʹ�� *�����ò����� �� ָ������ ���н����ò�����
//	                           //�õ� ָ������ �� ĳ�� Ԫ�� ��ŵ� ����(�� ��ַ) ��ָ��� ֵ
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//
//	int** ppa = &pa; //����ָ��(�ص����)
//
//	int*** pppa = &ppa; //����ָ��
//	                    //���˵��ƿ��Եõ� N��ָ��
//
//	**ppa = 20;               //����ָ���ʹ�ã� ȡ�˼��ε�ַ �� �⼸������
//	printf("%d\n", **ppa);    //��ӡ 20
//
//	return 0;
//}

//#define N_VALUES 5 //����һ���� N_VALUES �� ������ ����ֵΪ 5
//int main()
//{
//	float values[N_VALUES];
//	float* vp;
//
//	for (vp = &values[N_VALUES - 1]; vp >= &values[0]; vp--)// vp = &values[N_VALUES - 1] �൱���Ƕ� vp���ָ�� ָ���λ�� �����޸�(�� ��ʼ��)
//												            //
//														    // vp >= &values[0] �� ָ��Ĺ�ϵ����(�� �Ƚϴ�С)
//	{
//		*vp = 0;
//	}
//
//
//	return 0;
//}

//#define N_VALUES 5 //����һ���� N_VALUES �� ������ ����ֵΪ 5
//int main()
//{
//	float values[N_VALUES];
//	float* vp;
//
//	for (vp = &values[N_VALUES]; vp > &values[0];) // vp = &values[N_VALUES] �൱���Ƕ� vp���ָ�� ָ���λ�� �����޸�(�� ��ʼ��)
//												   //
//												   // vp > &values[0] �� ָ��Ĺ�ϵ����(�� �Ƚϴ�С)
//												   // 
//												   // ���� �����׶� Ϊ �� ��vp ȫ������� --vp ����
//	{
//		*--vp = 0; // ���� --������ �� ���ȼ� ���� *�����ò����� ��
//				   // ���� �Ǹ� ǰ��-- ���൱�� �� --vp �� ʹ��*vp
//				   //�� �� vp--;
//				   //   �� *vp = 0; (��ʱ vp �Ѿ� -1)
//	}
//
//	return 0;
//}

//#include <stdio.h>
////��ָ��ķ�ʽģ��strlen()
//int my_strlen(char* str)
//{
//	char* start = str; //���� ָ����� �� ��ʼ��
//	char* end = str; //���� ָ����� �� ��ʼ��
//	
//	while (*end != '\0') //����Ҫ֪�� endָ����� ��Ӧ��ʲôֵ������Ҫ���� �����ò���
//	{
//		end++;
//	}
//	return end - start; //���� ָ�� ��� �õ����� ����Ԫ�صĸ��� �����ý����ò���
//}
//
//int main()
//{
//	char arr[] = "happy"; // �� �ڴ��� ����� h a p p y '\0'
//	
//	int len = my_strlen(arr);
//
//	printf("len = %d\n", len);
//	
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	printf("%d\n", &arr[9] - &arr[0]); //��ӡ  9 �����ַ �� С��ַ Ϊ ����
//
//	printf("%d\n", &arr[0] - &arr[9]); //��ӡ -9 ��С��ַ �� ���ַ Ϊ ����
//
//	return 0;
//}
////��ַ-��ַ �ľ���ֵ�� ����Ԫ�� �� ���� ��С��ַ�����ַ��

//#define N_VALUES 5 //����һ���� N_VALUES �� ������ ����ֵΪ 5
//int main()
//{
//	float values[N_VALUES]; //����һ�� float���� �� ���� �����ֽ� values �������� N_VALUES ��Ԫ�أ��� 5 ��Ԫ��
//
//	float* vp; //����һ���� vp �� float���� �� ָ����� ��
//			   // ����Ϊʲô ���� �ֲ�����δ��ʼ�� ������ Ұָ�� ��
//			   // ��Ϊ Ұָ�� ��ָ�� λ�ò���֪�ĵ�ַ ������ ���� ��
//			   //     �� û�в���ʱ ������������ָ�룬ֻ����� ָ�� ָ���λ�� ����֪(�����)��
//			   //     �����Ǻ���� ���ָ�� ָ���λ�� �����޸�(�� ��ʼ��)��ע�ⲻ�� �����ָ�� ָ���λ�� ��ֵ �����޸�(�������� Ұָ��)��
//			   //     �ſ���  �����ָ�� ָ���λ�� ��ֵ �����޸ġ�
//
//	for (vp = &values[0]; vp < &values[N_VALUES];) // vp = &values[0] �൱���Ƕ� vp���ָ�� ָ���λ�� �����޸�(�� ��ʼ��)
//												   //
//												   // vp < &values[N_VALUES] �� ָ��Ĺ�ϵ����(�� �Ƚϴ�С)
//												   // 
//												   // ���� �����׶� Ϊ �� ��vp ȫ������� vp++ ����
//
//	{
//		*vp++ = 0; // ���� ++������ �� ���ȼ� ���� *�����ò����� ��
//				   // ���� �Ǹ� ����++ ���൱�� ��ʹ�� *vp Ȼ�� vp �� ++
//				   //�� �� *vp = 0 ;
//				   //   �� vp++;
//	}
//
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	
//	int* p1 = arr; // ������ �� ��Ԫ�ص�ַ ���������� ��ַ ������ &ȡ��ַ������
//	
//	int* p2 = &arr[9]; // ȡ arr������ �±�Ϊ9 �� Ԫ�� �� ��ַ ���� arr������ �� 10 �� ��ַ
//
//	int i = 0;
//	for (i = 0; i < 5; i++) //ע������ p1 ÿ��ѭ�� +2 ������ i < 5 ���ɣ�������� i < 10 ����� Ұָ��
//	{
//		printf("%d ", *p1); //��ӡ 1 3 5 7 9
//		p1 += 2;
//	}
//	printf("\n");
//	for (i = 0; i < 5; i++) //ע������ p2 ÿ��ѭ�� -2 ������ i < 5 ���ɣ�������� i < 10 ����� Ұָ��
//	{
//		printf("%d ", *p2); //��ӡ 10 8 6 4 2
//		p2 -= 2;
//	}
//
//	return 0;
//}

//#include <stdio.h>
//int* test()
//{
//	int a = 10;
//	return &a;
//}
//int main()
//{
//	int* p = test();
//
//	*p = 20; // ָ��ָ��Ŀռ��Ѿ��ͷţ��޷��ҵ��õ�ַ
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int arr[10] = { 0 };
//    int* p = arr;
//    int i = 0;
//    for (i = 0; i <= 11; i++)
//    {
//        p++; //��ָ��ָ��ķ�Χ��������arr�ķ�Χʱ��p����Ұָ��
//    }
//    return 0;
//}


//#include <stdio.h>
//int main()
//{
//    int* p; //�ֲ�����ָ��δ��ʼ����Ĭ��Ϊ���ֵ
//    *p = 20;
//    return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr; // ������ �� ��Ԫ�ص�ַ
//
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = 1;
//	}
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 0x11223344;
//
//	int* pa = &a;
//	char* pc = &a;
//
//	printf("%p\n", pa);
//	printf("%p\n", pa+1);
//
//	printf("%p\n", pc);
//	printf("%p\n", pc+1);
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 0x11223344;
//
//	char* pa = &a;
//
//	*pa = 0;
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 0x11223344; // 0x ��ʾʮ�����ƣ����� ʮ�����Ƶ�1λ ��Ҫ�� 4λ�����Ʊ�ʾ��
//	                    //�� 0x11223344 ��Ҫ 32λ�����Ʊ�ʾ ��
//	                    //������ 32λ����ϵͳ Ҳ������װ��
//
//	int* pa = &a; 
//	char* pc = &a;
//
//	printf("%p\n", pa);
//	printf("%p\n", pc);
//
//	return 0;
//}