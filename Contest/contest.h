#define _CRT_SECURE_NO_WARNINGS

// ******定义的数据******
#define MAX_NAME 10 // 成员信息中 名字 的字符数组大小
#define MAX_SEX 5   // 成员信息中 性别 的字符数组大小
#define MAX_TELE 15 // 成员信息中 电话 的字符数组大小
#define MAX_ADDR 15 // 成员信息中 地址 的字符数组大小

#define MAX 1000 // 通讯率大小



// ******头文件引用******
#include <stdio.h>
#include <memory.h>
#include <string.h>


// ******自定义类型******
enum Option // 功能选项
{
	EXIT,    // 默认 值 为 0
	ADD,     // 默认 值 为 1
	DEL,     // 默认 值 为 2
	SEARCH,  // 默认 值 为 3
	MODIFY,  // 默认 值 为 4
	SORT,    // 默认 值 为 5
	SHOW     // 默认 值 为 6

};

struct PeoInfo // 成员信息 
	// 需写在 struct Contest 之前，否则无法被 struct Contest 使用
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

struct Contest // 通讯录
{
	struct PeoInfo date[MAX]; // 成员信息 表
	int size; // 记录通讯录中有多少个成员
};


//******函数的声明******
void InitContest(struct Contest* ps); // 初始化通讯录

void AddContest(struct Contest* ps); // 增加成员

void ShowContest(const struct Contest* ps); // 展示通讯录

void DelContest(struct Contest* ps); // 删除成员

void SearchContest(const struct Contest* ps); // 查找成员

void ModifyContest(struct Contest* ps); // 修改通讯率

void SortContest(struct Contest* ps); // 排序通讯率