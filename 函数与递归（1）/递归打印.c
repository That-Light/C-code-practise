#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//void print(int a)
//{
//	int b = 0;
//
//	if (a % 10 == a)
//	{
//		printf("%d ", a);
//	}
//	else
//	{
//		b = a / 10;
//		print(b);
//		printf("%d ", a % 10);
//	}
//}
//
//int main()
//{
//
//	unsigned int a = 0;
//	printf("�����룺");
//	scanf("%d", &a);//1234
//
//	print(a);
//
//	return 0;
//}

//int my_strlen(char* str)
//{
//
//	if (*str != '\0')
//	{
//		return 1 + my_strlen(str+1);
//	}
//	return 0;
//}
//
//
//#include <stdio.h>
//int main()
//{
//
//	char arr[] = "happy";
//
//	int len = my_strlen(arr);
//
//	printf("len = %d\n", len);
//
//	return 0;
//}


////����һ������ֵ���޷��ţ�������˳���ӡ����ÿһλ��
////���磺
////���룺1234����� 1 2 3 4.
//
////����˼·��
////print(1234)
////print(123) 4
////print(12) 3 4
////print(1) 2 3 4
//// 1 2 3 4
//
//#include <stdio.h>
//void print(int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//
//int main()
//{
//	unsigned int num = 0;
//
//	printf("�����룺");
//	scanf("%d", &num);
//
//	print(num);
//
//	return 0;
//}


//��д���� �������� ��ʱ���� �����ַ����ĳ��ȡ�������ģ��ʵ��һ�� ���� ���ַ������ȣ�

//����˼·��ʶ�� '\0'
//str:��
//arr: h a p p y \0
// ( str + 1 )
//str:  ��
//arr: h a p p y \0
// ( str + 1 )
//str:    ��
//arr: h a p p y \0
// ( str + 1 )
//str:      ��
//arr: h a p p y \0
// ( str + 1 )
//str:        ��
//arr: h a p p y \0
// ( str + 1 )
//str:           ��
//arr: h a p p y \0
// ( str + 1 )

//return ��ֵ��
//my_strln("happy\0")
// 1 +my_strln("appy\0")
//1+ 1 +my_strln("ppy\0")
//1+1+ 1 +my_strln("py\0")
//1+1+1+ 1 +my_strln("y\0")
//1+1+1+1+ 1 +my_strln("\0")
//1+1+1+1+1+ 0

//#include <stdio.h>
//
//int my_strlen(char* str)                           //��Ϊ���������� ���� �� ��һ��Ԫ�ص� ��ַ �������� ��������(char)��ָ��(char*) ������
//{
//	if (*str != '\0')                         // �ַ���������־ �� '\0'   ����'\n'��'\n'�ǻ��в�����
//	{
//		return 1 + my_strlen(str + 1);
//	}
//		return 0;
//}
//
//int main()
//{
//	char arr[] = "happy";   //�ַ�������(char) ���� ������{}��ֱ��""���� char arr[] = "happy";
//	                        //��������(int) ���� ��Ҫ{}��""ͬʱʹ�ã��� int arr[] ={"0"};
//
//	int len = my_strlen(arr);   //arr �� ���� �� ���鴫�� ������ȥ�Ĳ����������飬���������е�һ��Ԫ�صĵ�ַ
//
//	printf("len = %d\n", len);
//
//	return 0;
//}