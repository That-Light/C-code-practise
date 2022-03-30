#define _CRT_SECURE_NO_WARNINGS

#include "contest.h"

void InitContest(struct Contest* ps) // ��ʼ��ͨѶ¼
{
	memset(ps, 0, sizeof(ps->date));
	ps->size = 0;
}

void AddContest(struct Contest* ps) // ���ӳ�Ա
{
	printf("���������֣�>");
	scanf("%s", ps->date[ps->size].name);

	printf("�������Ա�>");
	scanf("%s", ps->date[ps->size].sex);

	printf("���������䣺>");
	scanf("%d", &(ps->date[ps->size].age));
	// scanf()�⺯�� ��ȡ ���� ��Ҫʹ�� &ȡ��ַ������ ȡ����ַ��
	// �� ������ ������� ��Ԫ�ص�ַ ������ʹ�� &ȡ��ַ������ ȡ����ַ��

	printf("������绰��>");
	scanf("%s", ps->date[ps->size].tele);

	printf("�������ַ��>");
	scanf("%s", ps->date[ps->size].addr);

	ps->size++;
	printf("�������\n");
}

void ShowContest(const struct Contest* ps) // չʾͨѶ¼
{
	if (0 == ps->size)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		printf("%-15s\t%-15s\t%-15s\t%-15s\t%-15s\n", "����", "�Ա�", "����", "�绰", "סַ");
		// ���� %15s �У�
		// ���� ��ʾ�� ��ӡ�Ķ��� Ԥ�� ���ٸ��ַ� ��λ�ã��� ���� Ϊ �Ҷ��룬���� Ϊ ����룬
		// �� %-15s ��ʾ�� ��ӡ���ַ��� Ԥ�� 15 ���ַ� ��λ�ã���Ϊ ����롣
		// 
		// \t ��ʾ ��ӡˮƽ�Ʊ����λ�� �������� �ո� �ճ�һ��λ�á�

		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			printf("%-15s\t%-15s\t%-15d\t%-15s\t%-15s\n",
				ps->date[i].name,
				ps->date[i].sex,
				ps->date[i].age,
				ps->date[i].tele,
				ps->date[i].addr);
		}
	}
}

static int FindByName(const struct Contest* ps, char name[MAX_NAME])
// static ���� ���� ��ʹ ���� �� ���÷�Χ ��С��ֻ���� ��������ļ���(ָ contest.c) ʹ�ã�
// ʹ�ⲿ ���ܵ��� �ú���,�𵽶� �ú��� �ı������á�
{

	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->date[i].name, name))
		{
			return i; // �ҵ� �򷵻� i ���� �ýṹ��Ԫ�ص��±�
		}
	}

	return -1; // �Ҳ��� �򷵻� -1 �����ܷ��� 0 ����Ϊ 0 Ҳ���� �ṹ��Ԫ�ص��±ꡣ
}

void DelContest(struct Contest* ps) // ɾ����Ա
{
	char name[MAX_NAME];
	printf("����ɾ����Ա������\n");
	scanf("%s", name);

	int pos = FindByName(ps, name);

	if (pos == -1)
	{
		printf("���޴��ˣ��޷�ɾ��\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j < ps->size; j++)
		{
			ps->date[j] = ps->date[j + 1];
		}

		ps->size--;
		printf("ɾ�����\n");
	}
}

void SearchContest(const struct Contest* ps) // ���ҳ�Ա
{
	char name[MAX_NAME];
	printf("������ҳ�Ա������\n");
	scanf("%s", name);

	int pos = FindByName(ps, name);

	if (pos == -1)
	{
		printf("���޴��ˣ��޷��鿴\n");
	}
	else
	{
		printf("%-15s\t%-15s\t%-15s\t%-15s\t%-15s\n", "����", "�Ա�", "����", "�绰", "סַ");

		printf("%-15s\t%-15s\t%-15d\t%-15s\t%-15s\n",
			ps->date[pos].name,
			ps->date[pos].sex,
			ps->date[pos].age,
			ps->date[pos].tele,
			ps->date[pos].addr);
	}
}

void ModifyContest(struct Contest* ps) // �޸�ͨѶ��
{
	char name[MAX_NAME];
	printf("�����޸ĳ�Ա������\n");
	scanf("%s", name);

	int pos = FindByName(ps, name);

	if (pos == -1)
	{
		printf("���޴��ˣ��޷��޸�\n");
	}
	else
	{
		printf("���������֣�>");
		scanf("%s", ps->date[pos].name);

		printf("�������Ա�>");
		scanf("%s", ps->date[pos].sex);

		printf("���������䣺>");
		scanf("%d", &(ps->date[pos].age));

		printf("������绰��>");
		scanf("%s", ps->date[pos].tele);

		printf("�������ַ��>");
		scanf("%s", ps->date[pos].addr);

		printf("�޸����\n");
	}
}

void SortContest(struct Contest* ps) // ����ͨѶ��
{
	// ����������
	// ʹ�� ð������ �ķ���

	int i = 0;
	int j = 0;

	for (i = 0; i < ps->size - 1; i++) // ����
	{
		for (j = 0; j < ps->size - 1 - i; j++) // ÿ�˶ԱȵĴ���
		{
			if (strcmp(ps->date[j].name, ps->date[j+1].name) > 0) 
				// ǰ�� ��С ����Ҫ����
			{
				struct PeoInfo tmp;
				tmp = ps->date[j];
				ps->date[j] = ps->date[j + 1];
				ps->date[j + 1] = tmp;
				// ����ʹ�� �м���� �ķ�����
				// ͬһ���ṹ������ ������ �ṹ������������໥ ��ֵ��
				// �൱�ڰ� �ṹ������ �е� �ṹ���Ա ������ ����ȥ��
				// 
				// �ṹ�� �а��� �ṹ�壬һ�㲻ʹ�� qsort()�⺯�� ����
				// ��Ϊ����ȷ��ָ����ָλ�á�

			}
		}
	}

	printf("�������������\n");
}