#define _CRT_SECURE_NO_WARNINGS

#include "contact.h"

static void CheckCapacity(struct Contest* ps);
// ��Ϊ LoadContact���� �� CheckCapacity���� ֮ǰ��
// �� LoadContact���� Ҫʹ�õ� CheckCapacity���� ��
// ����Ҫ�� LoadContact���� ��ǰ���� CheckCapacity���� ��
static void LoadContact(struct Contest* ps) //�����ļ��е���Ϣ��ͨѶ¼
{
	FILE* pfRead = fopen("contact.dat1", "rb");

	int input = 1; // �״δ򿪳���û��ͨѶ¼�ļ���������¼�û���ѡ��

	if (pfRead == NULL)
	{
		printf("LoadContact:->%s\n", strerror(errno));
		printf("*****************************************************************\n");
		printf("***************      1.Set a new file (default)   ***************\n");
		printf("***************      0.Already have a file        ***************\n");
		printf("*****************************************************************\n");
		printf("-----------------------------WARMING-----------------------------\n");
		printf("If you is the first time to use this Contact ,please input 1 ,\n");
		printf("or not input 0 to exit the Contact to check the Contact_File .\n");
		printf("-----------------------------WARMING-----------------------------\n");

		scanf("%d", &input);

		if (input == 1)
		{
			SaveContact(ps); //���漴�ɴ���һ���ļ�
			printf("Set a new successful\n");
			pfRead = fopen("contact.dat1", "rb");
		}
		else
		{
			// ����ͨѶ¼���ͷŶ�̬���ٵ��ڴ�
			DestroyContact(ps);
			// ��ʱ con.data == NULL ���� test.c ���޷�����ѡ�񣬳������

			printf("�˳�ͨѶ¼\n");
			return;
		}
	}

	// �� ͨѶ¼�ļ��� �����ȡ��Ϣ
	struct PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(struct PeoInfo), 1, pfRead))
		// fread()�⺯�� ���� �ɹ���ȡ��n���ļ� �� n ��ֵ��
		//
		// ����ÿ�ζ�ȡ 1 ����Ϣ���� fread() ���� 0 ��˵����ȡ�������������� whileѭ�� ��Ҫ��
	{
		CheckCapacity(ps);
		ps->data[ps->size] = tmp;
		ps->size++;
	}

	fclose(pfRead);
	pfRead = NULL;
}

void InitContest(struct Contest* ps) // ��ʼ��ͨѶ¼
{
	// memset(ps, 0, sizeof(ps->date));
	ps->data = (struct PeoInfo*)malloc(DEFAULT_SZ * sizeof(struct PeoInfo));
	if (ps->data == NULL)
	{
		printf("ͨѶ¼��ʼ��ʧ��\n");
		return; // �ú����޷������ͣ����޷���ֵ��ֱ�� return ���ɽ����ú�����
	}

	ps->capacity = DEFAULT_SZ;

	ps->size = 0;

	// ��ȡ����ͨѶ¼�ļ��е���Ϣ����������Ϣ
	LoadContact(ps);

}

static void CheckCapacity(struct Contest* ps)
// ��⵱ǰͨѶ¼������
// �����ˣ������ݣ�
// ��δ������ɶ�����ɡ�
{
	if (ps->size == ps->capacity)
	{
		// ����(ÿ������2)
		struct PeoInfo* ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;

			ps->capacity += 2;

			ptr = NULL;

			printf("���ݳɹ�\n");
		}
	}
}

void AddContest(struct Contest* ps) // ���ӳ�Ա
{
	CheckCapacity(ps); // �������

	if (ps->size == ps->capacity) // ������ʧ�ܣ���ʱ ps->size �Ե��� ps->capacity ��
	{
		printf("����ʧ�ܣ��޷����ӳ�Ա\n");
	}
	else
	{
		// ��������
		printf("���������֣�>");
		scanf("%s", ps->data[ps->size].name);

		printf("�������Ա�>");
		scanf("%s", ps->data[ps->size].sex);

		printf("���������䣺>");
		scanf("%d", &(ps->data[ps->size].age));
		// scanf()�⺯�� ��ȡ ���� ��Ҫʹ�� &ȡ��ַ������ ȡ����ַ��
		// �� ������ ������� ��Ԫ�ص�ַ ������ʹ�� &ȡ��ַ������ ȡ����ַ��

		printf("������绰��>");
		scanf("%s", ps->data[ps->size].tele);

		printf("�������ַ��>");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;
		printf("�������\n");
	}
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

		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			printf("%-15s\t%-15s\t%-15d\t%-15s\t%-15s\n",
				ps->data[i].name,
				ps->data[i].sex,
				ps->data[i].age,
				ps->data[i].tele,
				ps->data[i].addr);
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
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i; // �ҵ� �򷵻� i ���� �ýṹ��Ԫ�ص��±�
		}
	}

	return -1; // �Ҳ��� �򷵻� -1 �����ܷ��� 0 ����Ϊ 0 Ҳ���� �ṹ��Ԫ�ص��±ꡣ
}

static void ReleaseContact(struct Contest* ps)
{
	// ��Ϊ����ÿ�� ��2 ��
	// ��������Ҳ���� ���� �� ��Ա���� ��2 �ŵ���(�ͷ�)һ�����ڴ档
	if (ps->capacity - ps->size > 2)
	{
		struct PeoInfo* ptr = realloc(ps->data, (ps->capacity - 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;

			ps->capacity -= 2;

			ptr = NULL;
		}
	}
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
			ps->data[j] = ps->data[j + 1];
		}

		ps->size--;

		// ɾ����Ա��ҲҪ����(�ͷ�)һ���ֶ�̬�ڴ�
		ReleaseContact(ps);

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
			ps->data[pos].name,
			ps->data[pos].sex,
			ps->data[pos].age,
			ps->data[pos].tele,
			ps->data[pos].addr);
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
		scanf("%s", ps->data[pos].name);

		printf("�������Ա�>");
		scanf("%s", ps->data[pos].sex);

		printf("���������䣺>");
		scanf("%d", &(ps->data[pos].age));

		printf("������绰��>");
		scanf("%s", ps->data[pos].tele);

		printf("�������ַ��>");
		scanf("%s", ps->data[pos].addr);

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
			if (strcmp(ps->data[j].name, ps->data[j + 1].name) > 0)
				// ǰ�� ��С ����Ҫ����
			{
				struct PeoInfo tmp;
				tmp = ps->data[j];
				ps->data[j] = ps->data[j + 1];
				ps->data[j + 1] = tmp;
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

void DestroyContact(struct Contest* ps) // ����ͨѶ¼���ͷŶ�̬���ٵ��ڴ�
{
	free(ps->data);
	ps->data = NULL;
}

void SaveContact(struct Contest* ps) // ����ͨѶ¼���ļ���
{
	FILE* pfWrite = fopen("contact.dat1", "wb");
	// ���� "contact.dat1" �� �ļ��� �� �ļ��� ���� �ļ�������contact �� ��׺.dat1 ��
	// ע�⣺��׺����ָ�ļ����� ����׺��ʲô��������ν������ .abcdef ��Ϊ��׺�����ԡ�

	if (pfWrite == NULL)
	{
		printf("SaveContact:->%s\n", strerror(errno));
		return;
	}

	// ��ͨѶ¼���������д���ļ�
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]), sizeof(struct PeoInfo), 1, pfWrite);
	}

	fclose(pfWrite);
	pfWrite = NULL;
}