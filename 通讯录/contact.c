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
		printf("通讯录已满，无法添加\n");
	}
	else
	{
		printf("请输入姓名：>");
		scanf("%s", ps->date[ps->size].name);
		printf("请输入性别：>");
		scanf("%s", ps->date[ps->size].sex);
		printf("请输入年龄：>");
		scanf("%d", &(ps->date[ps->size].age));
		printf("请输入电话：>");
		scanf("%s", ps->date[ps->size].tele);
		printf("请输入住址：>");
		scanf("%s", ps->date[ps->size].addr);

		ps->size++;
		printf("添加成功\n");
	}

}

void ShowContest(const struct Contest* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		printf("%-20s\t%-20s\t%-20s\t%-20s\t%-20s\n", "姓名", "性别", "年龄", "电话", "住址");
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
	printf("请输入删除的姓名：>");
	scanf("%s", name);

	int ret = FindByName(ps, name);

	if (-1 == ret)
	{
		printf("查无此人，无法删除\n");
	}
	else
	{
		int j = 0;
		for (j = ret; j < ps->size - 1; j++)
		{
			ps->date[j] = ps->date[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}

}

void SearchContest(const struct Contest* ps)
{
	char name[MAX_NAME];
	printf("请输入查找的姓名：>");
	scanf("%s", name);

	int ret = FindByName(ps, name);

	if (-1 == ret)
	{
		printf("查无此人，无法查看\n");
	}
	else
	{
		printf("%-20s\t%-20s\t%-20s\t%-20s\t%-20s\n", "姓名", "性别", "年龄", "电话", "住址");
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
	printf("请输入修改的姓名：>");
	scanf("%s", name);

	int ret = FindByName(ps, name);

	if (-1 == ret)
	{
		printf("查无此人，无法修改\n");
	}
	else
	{
		printf("请输入姓名：>");
		scanf("%s", ps->date[ret].name);
		printf("请输入性别：>");
		scanf("%s", ps->date[ret].sex);
		printf("请输入年龄：>");
		scanf("%d", &(ps->date[ret].age));
		printf("请输入电话：>");
		scanf("%s", ps->date[ret].tele);
		printf("请输入住址：>");
		scanf("%s", ps->date[ret].addr);

		printf("修改成功\n");
	}

}



void SortContest(struct Contest* ps)
{
	// 按名字排序
	int i = 0;
	int j = 0;
	for (i = 0; i < ps->size - 1; i++) // 趟数
	{
		for (j = 0; j < ps->size - 1 - i; j++) // 每趟交换的次数
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

	printf("排序成功\n");
}