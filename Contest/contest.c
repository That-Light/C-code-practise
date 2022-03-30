#define _CRT_SECURE_NO_WARNINGS

#include "contest.h"

void InitContest(struct Contest* ps) // 初始化通讯录
{
	memset(ps, 0, sizeof(ps->date));
	ps->size = 0;
}

void AddContest(struct Contest* ps) // 增加成员
{
	printf("请输入名字：>");
	scanf("%s", ps->date[ps->size].name);

	printf("请输入性别：>");
	scanf("%s", ps->date[ps->size].sex);

	printf("请输入年龄：>");
	scanf("%d", &(ps->date[ps->size].age));
	// scanf()库函数 读取 整型 需要使用 &取地址操作符 取出地址，
	// 而 数组名 本身就是 首元素地址 ，无需使用 &取地址操作符 取出地址。

	printf("请输入电话：>");
	scanf("%s", ps->date[ps->size].tele);

	printf("请输入地址：>");
	scanf("%s", ps->date[ps->size].addr);

	ps->size++;
	printf("增加完成\n");
}

void ShowContest(const struct Contest* ps) // 展示通讯录
{
	if (0 == ps->size)
	{
		printf("通讯录为空\n");
	}
	else
	{
		printf("%-15s\t%-15s\t%-15s\t%-15s\t%-15s\n", "姓名", "性别", "年龄", "电话", "住址");
		// 其中 %15s 中，
		// 数字 表示给 打印的东西 预留 多少个字符 的位置，且 正数 为 右对齐，负数 为 左对齐，
		// 即 %-15s 表示给 打印的字符串 预留 15 个字符 的位置，且为 左对齐。
		// 
		// \t 表示 打印水平制表符的位置 ，就是用 空格 空出一段位置。

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
// static 修饰 函数 ，使 函数 的 作用范围 变小，只能在 所定义的文件下(指 contest.c) 使用，
// 使外部 不能调用 该函数,起到对 该函数 的保护作用。
{

	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->date[i].name, name))
		{
			return i; // 找到 则返回 i ，即 该结构体元素的下标
		}
	}

	return -1; // 找不到 则返回 -1 ，不能返回 0 ，因为 0 也属于 结构体元素的下标。
}

void DelContest(struct Contest* ps) // 删除成员
{
	char name[MAX_NAME];
	printf("输入删除成员的名字\n");
	scanf("%s", name);

	int pos = FindByName(ps, name);

	if (pos == -1)
	{
		printf("查无此人，无法删除\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j < ps->size; j++)
		{
			ps->date[j] = ps->date[j + 1];
		}

		ps->size--;
		printf("删除完成\n");
	}
}

void SearchContest(const struct Contest* ps) // 查找成员
{
	char name[MAX_NAME];
	printf("输入查找成员的名字\n");
	scanf("%s", name);

	int pos = FindByName(ps, name);

	if (pos == -1)
	{
		printf("查无此人，无法查看\n");
	}
	else
	{
		printf("%-15s\t%-15s\t%-15s\t%-15s\t%-15s\n", "姓名", "性别", "年龄", "电话", "住址");

		printf("%-15s\t%-15s\t%-15d\t%-15s\t%-15s\n",
			ps->date[pos].name,
			ps->date[pos].sex,
			ps->date[pos].age,
			ps->date[pos].tele,
			ps->date[pos].addr);
	}
}

void ModifyContest(struct Contest* ps) // 修改通讯率
{
	char name[MAX_NAME];
	printf("输入修改成员的名字\n");
	scanf("%s", name);

	int pos = FindByName(ps, name);

	if (pos == -1)
	{
		printf("查无此人，无法修改\n");
	}
	else
	{
		printf("请输入名字：>");
		scanf("%s", ps->date[pos].name);

		printf("请输入性别：>");
		scanf("%s", ps->date[pos].sex);

		printf("请输入年龄：>");
		scanf("%d", &(ps->date[pos].age));

		printf("请输入电话：>");
		scanf("%s", ps->date[pos].tele);

		printf("请输入地址：>");
		scanf("%s", ps->date[pos].addr);

		printf("修改完成\n");
	}
}

void SortContest(struct Contest* ps) // 排序通讯率
{
	// 按名字排序
	// 使用 冒泡排序 的方法

	int i = 0;
	int j = 0;

	for (i = 0; i < ps->size - 1; i++) // 趟数
	{
		for (j = 0; j < ps->size - 1 - i; j++) // 每趟对比的次数
		{
			if (strcmp(ps->date[j].name, ps->date[j+1].name) > 0) 
				// 前大 后小 ，需要交换
			{
				struct PeoInfo tmp;
				tmp = ps->date[j];
				ps->date[j] = ps->date[j + 1];
				ps->date[j + 1] = tmp;
				// 这里使用 中间变量 的方法，
				// 同一个结构体类型 创建的 结构体变量，可以相互 赋值，
				// 相当于把 结构体类型 中的 结构体成员 都完整 赋过去。
				// 
				// 结构体 中包含 结构体，一般不使用 qsort()库函数 排序，
				// 因为很难确定指针所指位置。

			}
		}
	}

	printf("按名字排序完成\n");
}