#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int Add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}

int main()
{
	int a = 10;
	int b = 20;
	int ret = 0;

	ret = Add(a, b);

	return 0;
}

//#include <stdio.h>
//
//typedef struct Stu
//{
//	char name[20];
//	int age;
//}STU;
//
//void print1(struct Stu tmp) //Ҳ���� void peint1(STU tmp)
//{
//	printf("%s\n", tmp.name);
//	printf("%d\n", tmp.age);
//	//��ӡ   ����
//	//       40
//}
//
//void print2(STU* tmp) //Ҳ���� void peint1(struct Stu* tmp)
//{
//	printf("%s\n", tmp->name);
//	printf("%d\n", (*tmp).age);
//	//��ӡ   ����
//	//       40
//}
//
//int main()
//{
//	STU s = { "����",40 };
//
//	print1(s); //�� �ṹ��
//	print2(&s); //�� ��ַ
//
//	return 0;
//}

//#include <stdio.h>
//
//struct S
//{
//	int a;
//	char c;
//	char arr[20];
//	double d;
//};
//
//struct T
//{
//	char ch[10];
//
//	struct S s; // �ṹ���� ���԰��� �����ṹ���Ա
//	
//	char* pc;
//};
//
//int main()
//{
//	char arr[] = "hello earth\n";
//	
//	struct T t = { "hehe",{100,'w',"hello world",3.14},arr };
//
//	printf("%s\n", t.ch);
//	printf("%s\n", t.s.arr); //���� ��� ���� �ṹ���� �� �����ṹ���Ա
//	printf("%lf\n", t.s.d); // ��ӡ double���� ʹ�� %lf
//	printf("%s\n", t.pc);
//	//��ӡ  hehe 
//	//      hello world
//	//	    3.140000
//	//	    hello earth
//
//	return 0;
//}


//////���� �ṹ�����
////struct Stu // struct �� �ṹ��ؼ��� �� Stu �� �ṹ���ǩ �� struct Stu �� �ṹ������ ��
////{
////	//��Ա����
////	char name[20]; //����
////	int age; //����
////	char sex[5]; //�Ա�
////	char id[20]; //ѧ��
////}s1, s2, s3; //������ s1 , s2 , s3 ���� ȫ�ֽṹ����� �������Բ���������Ӧ��������ʹ��ȫ�ֱ���
////             //�ֺŲ��ܶ�
//
//typedef struct Stu // typedef �������Ǹ� һ������ ������ ��
//                   //���ｫ  struct Stu  ��� �ṹ������ ������Ϊ STU
//{
//	char name[20];
//	int age;
//	char sex[5];
//	char id[20];
//}STU; // ����� STU ���� ȫ�ֽṹ����� ������ʹ�� typedef ��������� ����
//
//
//int main()
//{
//	struct Stu s; //һ�㷽������ �ṹ����� 
//
//	STU s; //ʹ�� typedf �������󴴽� �ṹ�����
//
//	return 0;
//}