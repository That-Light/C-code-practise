#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//
//	for (i = 0; i < 3; i++)
//	{
//		printf("���������룺");
//		scanf("%s", password);
//
//		//   if (password == "123456")   �Ǵ����д������Ϊ ��==�� ���������Ƚ������ַ����Ƿ���ȣ�Ӧ��ʹ�ÿ⺯�� strcmp()
//
//		if (strcmp(password, "123456") == 0)   //��ʹ�� strcmp() ��Ҫ����ͷ�ļ� <string.h>
//		//strcmp(char1,char2) ���Ƚ� char1 �� char2 ������
//		//��� ����������򷵻�ֵ0�� �� char1 ���� char2 �򷵻ش���0��ֵ�� �� char1 С�� char2 �򷵻�С��0��ֵ
//		{
//			printf("��½�ɹ�\n");
//			break;
//		}
//		else
//		{
//			printf("�������\n");
//		}
//	}
//
//	if (i == 3)
//	{
//		printf("��������������˳�����\n");
//	}
//
//	return 0;
//}