#define _CRT_SECURE_NO_WARNINGS

#include "contect.h"

void InitContest(struct Contest* ps)
{
	memset(ps->date, 0, sizeof(ps->date));
	ps->size = 0;

}

void AddContest(struct Contest* ps)
{
	if (ps->size == MAX)
	{
		printf("ͨѶ¼�������޷����\n");
	}
	else
	{
		printf("������������>");
		scanf("%s", ps->date[ps->size].name);
		printf("�������Ա�>");
		scanf("%s", ps->date[ps->size].sex);
		printf("���������䣺>");
		scanf("%d", &(ps->date[ps->size].age));
		printf("������绰��>");
		scanf("%s", ps->date[ps->size].tele);
		printf("������סַ��>");
		scanf("%s", ps->date[ps->size].addr);

		ps->size++;
		printf("��ӳɹ�\n");
	}

}

void ShowContest(const struct Contest* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		printf("%-20s\t%-20s\t%-20s\t%-20s\t%-20s\n", "����", "�Ա�", "����", "�绰", "סַ");
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-20s\t%-20d\t%-20s\t%-20s\n",
				ps->date[i].name,
				ps->date[i].sex,
				ps->date[i].age,
				ps->date[i].tele,
				(ps->date)[i].addr);
		}
	}

}

static int FindByName(const struct Contest* ps, char name[MAX_NAME])
{
	int i = 0;

	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp((ps->date)[i].name, name))
		{
			return i;
		}
	}

	return -1;

}

void DelContest(struct Contest* ps)
{
	char name[MAX_NAME];
	printf("������ɾ����������>");
	scanf("%s", name);

	int ret = FindByName(ps, name);

	if (-1 == ret)
	{
		printf("���޴��ˣ��޷�ɾ��\n");
	}
	else
	{
		int j = 0;
		for (j = ret; j < ps->size - 1; j++)
		{
			ps->date[j] = ps->date[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}

}

void SearchContest(const struct Contest* ps)
{
	char name[MAX_NAME];
	printf("��������ҵ�������>");
	scanf("%s", name);

	int ret = FindByName(ps, name);

	if (-1 == ret)
	{
		printf("���޴��ˣ��޷��鿴\n");
	}
	else
	{
		printf("%-20s\t%-20s\t%-20s\t%-20s\t%-20s\n", "����", "�Ա�", "����", "�绰", "סַ");
		printf("%-20s\t%-20s\t%-20d\t%-20s\t%-20s\n",
			ps->date[ret].name,
			ps->date[ret].sex,
			ps->date[ret].age,
			ps->date[ret].tele,
			(ps->date)[ret].addr);
	}

}

void ModifyContest(struct Contest* ps)
{
	char name[MAX_NAME];
	printf("�������޸ĵ�������>");
	scanf("%s", name);

	int ret = FindByName(ps, name);

	if (-1 == ret)
	{
		printf("���޴��ˣ��޷��޸�\n");
	}
	else
	{
		printf("������������>");
		scanf("%s", ps->date[ret].name);
		printf("�������Ա�>");
		scanf("%s", ps->date[ret].sex);
		printf("���������䣺>");
		scanf("%d", &(ps->date[ret].age));
		printf("������绰��>");
		scanf("%s", ps->date[ret].tele);
		printf("������סַ��>");
		scanf("%s", ps->date[ret].addr);

		printf("�޸ĳɹ�\n");
	}

}



void SortContest(struct Contest* ps)
{
	// ����������
	int i = 0;
	int j = 0;
	for (i = 0; i < ps->size - 1; i++) // ����
	{
		for (j = 0; j < ps->size - 1 - i; j++) // ÿ�˽����Ĵ���
		{
			if (strcmp(ps->date[i].name, ps->date[i + 1].name) > 0)
			{
				struct PeoInfo tmp;
				tmp = ps->date[i];
				ps->date[i] = ps->date[i + 1];
				ps->date[i + 1] = tmp;
			}

		}

	}

	printf("����ɹ�\n");
}