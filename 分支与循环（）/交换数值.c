#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//
//// void���� �������κζ��� 
//void swap1(int x, int y)   // ������ �е� a �� b �� swap1 �е� x �� y �ֱ𿪱��˲�ͬ�� �ڴ� ��
//                           // swap1 ���� ���� �и����� ���� x �� y ��λ�ã��� ������ �� a �� b ��Ӱ��
//{
//	int tmp = 0;
//	tmp = x;
//	x = y;
//	y = tmp;
//}
//
//// void���� �������κζ��� 
//void swap2(int* pa, int* pb)   // int* Ϊ ����ָ������ �� pa �� pb �洢 �ڴ��ַ �ĳ�Ϊ ָ�����
//                               // �޷���ֵ���� ���ı�������ͨ�� �ڴ��ַ �ҵ� �õ�ַ��Ӧ�ı��� ���и���
//{
//	int tmp = 0;
//	tmp = *pa;   // *pa �� *pb Ϊ �����ò����� �����ֱ�Ϊ ������ �е� a �� b
//	*pa = *pb;
//	*pb = tmp;
//}
//
//int main()
//{
//	int a = 10, b = 20;
//
//	//������ɽ�������
//	swap1(a, b);
//	printf("swap1: a = %d   b = %d\n", a, b);
//
//	//������ɽ�������
//	swap2(&a, &b);   // & Ϊȡ ��ַ������
//	printf("swap2: a = %d   b = %d\n", a, b);
//
//	return 0;
//}