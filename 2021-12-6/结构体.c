#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//#include <string.h>
//
////�����ṹ������
//struct book
//{
//	char name[20];
//	short price;
//};
//
//
////���ýṹ�����ͣ�����һ�������͵ı���
//int main()
//{
//	//�����ṹ�����
//	struct book b1 = { "����",20 };
//	printf("������%s\n", b1.name);
//	printf("�۸�%dԪ\n", b1.price);
//
//	//�޸Ĳ���
//	b1.price = 15;
//	printf("�޸ĺ�۸�%dԪ\n", b1.price);
//
//	strcpy(b1.name, "����");
//	printf("�޸ĺ�������%s\n", b1.name);
//
//	//ָ��
//	struct book* pb = &b1;
//	printf("��.��ָ��ָʾ��������%s\n",(*pb).name);
//	
//	printf("'->'ָ��֪ʶ��������%s\n", pb->name);
//
//
//	return 0;
//}