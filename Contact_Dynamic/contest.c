#define _CRT_SECURE_NO_WARNINGS

#include "contest.h"

void InitContest(struct Contest* ps) // 初始化通讯录
{
	// memset(ps, 0, sizeof(ps->date));
	ps->data = (struct PeoInfo*)malloc(DEFAULT_SZ * sizeof(struct PeoInfo));
	if (ps->data == NULL)
	{
		printf("通讯录初始化失败\n");
		return; // 该函数无返回类型，即无返回值，直接 return 即可结束该函数。
	}

	ps->capacity = DEFAULT_SZ;

	ps->size = 0;
}

static void CheckCapacity(struct Contest* ps)
// 检测当前通讯录容量，
// 若满了，则增容，
// 若未满，则啥都不干。
{
	if (ps->size == ps->capacity)
	{
		// 增容(每次增容2)
		struct PeoInfo* ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;

			ps->capacity += 2;

			ptr = NULL;

			printf("增容成功\n");
		}
	}
}

void AddContest(struct Contest* ps) // 增加成员
{
	CheckCapacity(ps); // 检测容量

	if (ps->size == ps->capacity) // 若增容失败，此时 ps->size 仍等于 ps->capacity 。
	{
		printf("增容失败，无法增加成员\n");
	}
	else
	{
		// 增加数据
		printf("请输入名字：>");
		scanf("%s", ps->data[ps->size].name);

		printf("请输入性别：>");
		scanf("%s", ps->data[ps->size].sex);

		printf("请输入年龄：>");
		scanf("%d", &(ps->data[ps->size].age));
		// scanf()库函数 读取 整型 需要使用 &取地址操作符 取出地址，
		// 而 数组名 本身就是 首元素地址 ，无需使用 &取地址操作符 取出地址。

		printf("请输入电话：>");
		scanf("%s", ps->data[ps->size].tele);

		printf("请输入地址：>");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;
		printf("增加完成\n");
	}
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
// static 修饰 函数 ，使 函数 的 作用范围 变小，只能在 所定义的文件下(指 contest.c) 使用，
// 使外部 不能调用 该函数,起到对 该函数 的保护作用。
{

	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i; // 找到 则返回 i ，即 该结构体元素的下标
		}
	}

	return -1; // 找不到 则返回 -1 ，不能返回 0 ，因为 0 也属于 结构体元素的下标。
}

static void ReleaseContact(struct Contest* ps)
{
	// 因为容量每次 加2 ，
	// 所以这里也满足 容量 比 成员个数 大2 才调整(释放)一部分内存。
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
			ps->data[j] = ps->data[j + 1];
		}

		ps->size--;

		// 删除成员后，也要调整(释放)一部分动态内存
		ReleaseContact(ps);

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
			ps->data[pos].name,
			ps->data[pos].sex,
			ps->data[pos].age,
			ps->data[pos].tele,
			ps->data[pos].addr);
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
		scanf("%s", ps->data[pos].name);

		printf("请输入性别：>");
		scanf("%s", ps->data[pos].sex);

		printf("请输入年龄：>");
		scanf("%d", &(ps->data[pos].age));

		printf("请输入电话：>");
		scanf("%s", ps->data[pos].tele);

		printf("请输入地址：>");
		scanf("%s", ps->data[pos].addr);

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
			if (strcmp(ps->data[j].name, ps->data[j + 1].name) > 0)
				// 前大 后小 ，需要交换
			{
				struct PeoInfo tmp;
				tmp = ps->data[j];
				ps->data[j] = ps->data[j + 1];
				ps->data[j + 1] = tmp;
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

void DestroyContact(struct Contest* ps) // 销毁通讯录，释放动态开辟的内存
{
	free(ps->data);
	ps->data = NULL;
}