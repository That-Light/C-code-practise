#define _CRT_SECURE_NO_WARNINGS

// 定义的数据
#define MAX 1000

#define MAX_NAME 10
#define MAX_SEX 5
#define MAX_TELE 15
#define MAX_ADDR 10










// 头文件引用
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// 自定义类型的创建
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	SHOW
};

struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];

};

struct Contest
{
	struct PeoInfo date[MAX];
	int size;
};



// 函数的声明
void InitContest(struct Contest* ps);

void AddContest(struct Contest* ps);

void ShowContest(const struct Contest* ps);

void DelContest(struct Contest* ps);

void SearchContest(const struct Contest* ps);

void ModifyContest(struct Contest* ps);

void SortContest(struct Contest* ps);