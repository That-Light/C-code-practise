#define _CRT_SECURE_NO_WARNINGS

////  Ч����
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
////ʵ��ԭ�������ַ������� ���� �ַ�����ͨ���±�ķ�ʽ��Ѱ�Ҳ����� # �ַ�����Ӧ�ַ�
//#include <stdio.h>
//#include <string.h>
//#include <windows.h>
//int main()
//{
//	char arr1[] = { "welcome to my school !!!!" };   // ���� �ַ���
//	char arr2[] = { "#########################" };   //  #   �ַ���
//
//	int left = 0;   //���±�
//
//	int right = sizeof(arr1) / sizeof(arr1[0]) - 2;   //���±�ΪʲôҪ -2 �� ��Ϊ�����ַ�����1��2��3���������ˡ�1��2��3��'\n'�� �����ֻ -1 ���Ӧ '\n'
//	//�� int right = strlen(arr1) - 1; ����Ϊʲôֻ -1 �� ��Ϊ srtlen ֻ�����ַ�����Ԫ�ظ������������ַ���������־'\n'   ��strlen() Ҫ���ÿ⺯��<string.h>
//
//	while (left <= right)   //�� left ���� right ʱ��֤�� ���� �� # �Ѿ�ȫ���滻
//	{
//		arr2[left] = arr1[left];   //��߿�ʼ�� ���� �滻 #
//		arr2[right] = arr1[right];   //�ұ߿�ʼ�� ���� �滻 #
//
//		printf("%s\n", arr2);   //��ӡ�ַ����� %s
//
//		left++;   //���±� +1 �����м俿£
//		right--;   //���±� -1 �����м俿£
//
//		Sleep(1000);//ͣ�� 1000 ���� = 1 ��   ��Sleep() Ҫ���ÿ⺯��<windows.h>   ��Sleep() ����ĸ�����д
//	}
//
//	return 0;
//}